/*
 * riduzione_stato.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "riduzione_stato".
 *
 * Model version              : 2.29
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue May 28 21:00:47 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "riduzione_stato.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "riduzione_stato_private.h"
#include <string.h>

/* Named constants for MATLAB Function: '<Root>/getPositon' */
#define riduzione_stato_CALL_EVENT     (-1)

/* Block signals (default storage) */
B_riduzione_stato_T riduzione_stato_B;

/* Continuous states */
X_riduzione_stato_T riduzione_stato_X;

/* Disabled State Vector */
XDis_riduzione_stato_T riduzione_stato_XDis;

/* Block states (default storage) */
DW_riduzione_stato_T riduzione_stato_DW;

/* Real-time model */
static RT_MODEL_riduzione_stato_T riduzione_stato_M_;
RT_MODEL_riduzione_stato_T *const riduzione_stato_M = &riduzione_stato_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  riduzione_stato_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  riduzione_stato_step();
  riduzione_stato_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  riduzione_stato_step();
  riduzione_stato_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void riduzione_stato_step(void)
{
  real_T rtb_Abs;
  real_T rtb_Add2;
  real_T rtb_Divide;
  real_T rtb_Saturation1;
  uint16_T b_varargout_2;
  boolean_T rEQ0;
  if (rtmIsMajorTimeStep(riduzione_stato_M)) {
    /* set solver stop time */
    if (!(riduzione_stato_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&riduzione_stato_M->solverInfo,
                            ((riduzione_stato_M->Timing.clockTickH0 + 1) *
        riduzione_stato_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&riduzione_stato_M->solverInfo,
                            ((riduzione_stato_M->Timing.clockTick0 + 1) *
        riduzione_stato_M->Timing.stepSize0 +
        riduzione_stato_M->Timing.clockTickH0 *
        riduzione_stato_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(riduzione_stato_M)) {
    riduzione_stato_M->Timing.t[0] = rtsiGetT(&riduzione_stato_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(riduzione_stato_M)) {
    /* MATLABSystem: '<Root>/Qudrature Encoder' */
    if (riduzione_stato_DW.obj.SampleTime != riduzione_stato_P.Ts) {
      riduzione_stato_DW.obj.SampleTime = riduzione_stato_P.Ts;
    }

    /* MATLABSystem: '<Root>/Qudrature Encoder' */
    /* 		%% Define output properties */
    /*  Call C-function implementing device output */
    riduzione_stato_B.QudratureEncoder_o1 = getEncoderCount();

    /* MATLABSystem: '<Root>/Qudrature Encoder' */
    getIndexCount(&b_varargout_2);

    /* MATLAB Function: '<Root>/ticks delta' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Delay: '<Root>/Delay'
     */
    riduzione_stato_DW.sfEvent = riduzione_stato_CALL_EVENT;
    riduzione_stato_B.delta = riduzione_stato_B.QudratureEncoder_o1 -
      riduzione_stato_DW.Delay_DSTATE;
    if (!(fabs(riduzione_stato_B.delta) <= ceil(12600.0 * riduzione_stato_P.Ts)))
    {
      if (riduzione_stato_DW.Delay_DSTATE >
          riduzione_stato_B.QudratureEncoder_o1) {
        riduzione_stato_B.delta += 65535.0;
      } else {
        riduzione_stato_B.delta -= 65535.0;
      }
    }

    /* End of MATLAB Function: '<Root>/ticks delta' */

    /* MATLAB Function: '<Root>/speed' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    riduzione_stato_DW.sfEvent_h = riduzione_stato_CALL_EVENT;
    riduzione_stato_B.speed = riduzione_stato_B.delta * 60.0 / (8400.0 *
      riduzione_stato_P.Ts);

    /* DotProduct: '<Root>/Dot Product' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    riduzione_stato_B.K1x1K2x2 = -riduzione_stato_P.K * riduzione_stato_B.speed;
  }

  /* Sum: '<Root>/Add2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  DotProduct: '<Root>/Dot Product1'
   *  Integrator: '<Root>/Integrator'
   */
  rtb_Add2 = -riduzione_stato_P.Ki * riduzione_stato_X.Integrator_CSTATE +
    riduzione_stato_B.K1x1K2x2;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Add2 > riduzione_stato_P.Saturation1_UpperSat) {
    rtb_Saturation1 = riduzione_stato_P.Saturation1_UpperSat;
  } else if (rtb_Add2 < riduzione_stato_P.Saturation1_LowerSat) {
    rtb_Saturation1 = riduzione_stato_P.Saturation1_LowerSat;
  } else {
    rtb_Saturation1 = rtb_Add2;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Control variable1'
   *  Gain: '<Root>/Gain'
   */
  if (riduzione_stato_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Abs = riduzione_stato_P.Controlvariable1_Value;
  } else {
    rtb_Abs = riduzione_stato_P.Gain_Gain * rtb_Saturation1;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Signum: '<S1>/Sign' */
  if (rtIsNaN(rtb_Abs)) {
    rtb_Divide = (rtNaN);
  } else if (rtb_Abs < 0.0) {
    rtb_Divide = -1.0;
  } else {
    rtb_Divide = (rtb_Abs > 0.0);
  }

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Signum: '<S1>/Sign'
   *  Sum: '<S1>/Sum'
   */
  rtb_Divide = (rtb_Divide + riduzione_stato_P.Constant_Value) /
    riduzione_stato_P.Constant1_Value;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Abs > riduzione_stato_P.Saturation_UpperSat) {
    rtb_Abs = riduzione_stato_P.Saturation_UpperSat;
  } else if (rtb_Abs < riduzione_stato_P.Saturation_LowerSat) {
    rtb_Abs = riduzione_stato_P.Saturation_LowerSat;
  }

  /* Abs: '<Root>/Abs' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  rtb_Abs = fabs(rtb_Abs);

  /* MATLABSystem: '<Root>/IN1A' incorporates:
   *  Product: '<Root>/Product1'
   */
  MW_PWM_SetDutyCycle(riduzione_stato_DW.obj_b.MW_PWM_HANDLE, rtb_Divide *
                      rtb_Abs);

  /* MATLABSystem: '<Root>/IN2A' incorporates:
   *  Logic: '<Root>/NOT'
   *  Product: '<Root>/Product'
   */
  MW_PWM_SetDutyCycle(riduzione_stato_DW.obj_j.MW_PWM_HANDLE, rtb_Abs * (real_T)
                      !(rtb_Divide != 0.0));
  if (rtmIsMajorTimeStep(riduzione_stato_M)) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Control variable'
     */
    riduzione_stato_B.Sum = riduzione_stato_B.speed -
      riduzione_stato_P.Controlvariable_Value;
  }

  /* Sum: '<Root>/Add3' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Sum: '<Root>/Add1'
   */
  riduzione_stato_B.Add3 = riduzione_stato_B.Sum - (rtb_Add2 - rtb_Saturation1) *
    riduzione_stato_P.Gain2_Gain;

  /* RateTransition generated from: '<Root>/speed' */
  if (rtmIsMajorTimeStep(riduzione_stato_M)) {
    /* RateTransition generated from: '<Root>/speed' */
    riduzione_stato_B.HiddenRateTransitionForToWks_In = riduzione_stato_B.speed;

    /* Delay: '<Root>/Delay1' */
    riduzione_stato_B.tick_star = riduzione_stato_DW.Delay1_DSTATE;

    /* MATLAB Function: '<Root>/getPositon' */
    riduzione_stato_DW.sfEvent_hu = riduzione_stato_CALL_EVENT;
    riduzione_stato_B.tick_star += riduzione_stato_B.delta;
    rtb_Divide = 6.2831853071795862 * riduzione_stato_B.tick_star / 8400.0;
    rtb_Saturation1 = fabs(rtb_Divide);
    if (rtIsNaN(rtb_Saturation1) || rtIsInf(rtb_Saturation1)) {
      rtb_Add2 = (rtNaN);
    } else if (rtb_Saturation1 == 0.0) {
      rtb_Add2 = 0.0;
    } else {
      rtb_Add2 = fmod(rtb_Saturation1, 6.2831853071795862);
      rEQ0 = (rtb_Add2 == 0.0);
      if (!rEQ0) {
        rtb_Saturation1 /= 6.2831853071795862;
        rEQ0 = !(fabs(rtb_Saturation1 - floor(rtb_Saturation1 + 0.5)) >
                 2.2204460492503131E-16 * rtb_Saturation1);
      }

      if (rEQ0) {
        rtb_Add2 = 0.0;
      }
    }

    /* RateTransition generated from: '<Root>/getPositon' */
    if (rtmIsMajorTimeStep(riduzione_stato_M)) {
      /* MATLAB Function: '<Root>/getPositon' */
      if (rtIsNaN(rtb_Divide)) {
        rtb_Divide = (rtNaN);
      } else if (rtb_Divide < 0.0) {
        rtb_Divide = -1.0;
      } else {
        rtb_Divide = (rtb_Divide > 0.0);
      }

      /* RateTransition generated from: '<Root>/getPositon' incorporates:
       *  MATLAB Function: '<Root>/getPositon'
       */
      riduzione_stato_B.HiddenRateTransitionForToWks__k = rtb_Divide * rtb_Add2;
    }

    /* End of RateTransition generated from: '<Root>/getPositon' */
    /* RateTransition generated from: '<Root>/Qudrature Encoder' */
    if (rtmIsMajorTimeStep(riduzione_stato_M)) {
      /* RateTransition generated from: '<Root>/Qudrature Encoder' */
      riduzione_stato_B.HiddenRateTransitionForToWks__c =
        riduzione_stato_B.QudratureEncoder_o1;
    }

    /* End of RateTransition generated from: '<Root>/Qudrature Encoder' */
    /* MATLABSystem: '<Root>/ENA' incorporates:
     *  Constant: '<Root>/Constant'
     */
    MW_digitalIO_write(riduzione_stato_DW.obj_p.MW_DIGITALIO_HANDLE,
                       riduzione_stato_P.Constant_Value_a != 0.0);
  }

  /* End of RateTransition generated from: '<Root>/speed' */
  if (rtmIsMajorTimeStep(riduzione_stato_M)) {
    if (rtmIsMajorTimeStep(riduzione_stato_M)) {
      /* Update for Delay: '<Root>/Delay' */
      riduzione_stato_DW.Delay_DSTATE = riduzione_stato_B.QudratureEncoder_o1;

      /* Update for Delay: '<Root>/Delay1' */
      riduzione_stato_DW.Delay1_DSTATE = riduzione_stato_B.tick_star;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        riduzione_stato_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(riduzione_stato_M)) {/* Sample time: [0.005s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((riduzione_stato_M->Timing.clockTick1+
           riduzione_stato_M->Timing.clockTickH1* 4294967296.0)) * 0.005);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(riduzione_stato_M)) {
    rt_ertODEUpdateContinuousStates(&riduzione_stato_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++riduzione_stato_M->Timing.clockTick0)) {
      ++riduzione_stato_M->Timing.clockTickH0;
    }

    riduzione_stato_M->Timing.t[0] = rtsiGetSolverStopTime
      (&riduzione_stato_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      riduzione_stato_M->Timing.clockTick1++;
      if (!riduzione_stato_M->Timing.clockTick1) {
        riduzione_stato_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void riduzione_stato_derivatives(void)
{
  XDot_riduzione_stato_T *_rtXdot;
  _rtXdot = ((XDot_riduzione_stato_T *) riduzione_stato_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = riduzione_stato_B.Add3;
}

/* Model initialize function */
void riduzione_stato_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)riduzione_stato_M, 0,
                sizeof(RT_MODEL_riduzione_stato_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&riduzione_stato_M->solverInfo,
                          &riduzione_stato_M->Timing.simTimeStep);
    rtsiSetTPtr(&riduzione_stato_M->solverInfo, &rtmGetTPtr(riduzione_stato_M));
    rtsiSetStepSizePtr(&riduzione_stato_M->solverInfo,
                       &riduzione_stato_M->Timing.stepSize0);
    rtsiSetdXPtr(&riduzione_stato_M->solverInfo, &riduzione_stato_M->derivs);
    rtsiSetContStatesPtr(&riduzione_stato_M->solverInfo, (real_T **)
                         &riduzione_stato_M->contStates);
    rtsiSetNumContStatesPtr(&riduzione_stato_M->solverInfo,
      &riduzione_stato_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&riduzione_stato_M->solverInfo,
      &riduzione_stato_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&riduzione_stato_M->solverInfo,
      &riduzione_stato_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&riduzione_stato_M->solverInfo,
      &riduzione_stato_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&riduzione_stato_M->solverInfo, (boolean_T**)
      &riduzione_stato_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&riduzione_stato_M->solverInfo, (&rtmGetErrorStatus
      (riduzione_stato_M)));
    rtsiSetRTModelPtr(&riduzione_stato_M->solverInfo, riduzione_stato_M);
  }

  rtsiSetSimTimeStep(&riduzione_stato_M->solverInfo, MAJOR_TIME_STEP);
  riduzione_stato_M->intgData.y = riduzione_stato_M->odeY;
  riduzione_stato_M->intgData.f[0] = riduzione_stato_M->odeF[0];
  riduzione_stato_M->intgData.f[1] = riduzione_stato_M->odeF[1];
  riduzione_stato_M->intgData.f[2] = riduzione_stato_M->odeF[2];
  riduzione_stato_M->contStates = ((X_riduzione_stato_T *) &riduzione_stato_X);
  riduzione_stato_M->contStateDisabled = ((XDis_riduzione_stato_T *)
    &riduzione_stato_XDis);
  riduzione_stato_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&riduzione_stato_M->solverInfo, (void *)
                    &riduzione_stato_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&riduzione_stato_M->solverInfo, false);
  rtsiSetSolverName(&riduzione_stato_M->solverInfo,"ode3");
  rtmSetTPtr(riduzione_stato_M, &riduzione_stato_M->Timing.tArray[0]);
  rtmSetTFinal(riduzione_stato_M, -1);
  riduzione_stato_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  riduzione_stato_M->Sizes.checksums[0] = (1716672150U);
  riduzione_stato_M->Sizes.checksums[1] = (2639843088U);
  riduzione_stato_M->Sizes.checksums[2] = (1777002103U);
  riduzione_stato_M->Sizes.checksums[3] = (31770056U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    riduzione_stato_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(riduzione_stato_M->extModeInfo,
      &riduzione_stato_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(riduzione_stato_M->extModeInfo,
                        riduzione_stato_M->Sizes.checksums);
    rteiSetTPtr(riduzione_stato_M->extModeInfo, rtmGetTPtr(riduzione_stato_M));
  }

  /* block I/O */
  (void) memset(((void *) &riduzione_stato_B), 0,
                sizeof(B_riduzione_stato_T));

  /* states (continuous) */
  {
    (void) memset((void *)&riduzione_stato_X, 0,
                  sizeof(X_riduzione_stato_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&riduzione_stato_XDis, 0,
                  sizeof(XDis_riduzione_stato_T));
  }

  /* states (dwork) */
  (void) memset((void *)&riduzione_stato_DW, 0,
                sizeof(DW_riduzione_stato_T));

  {
    uint32_T pinname;

    /* Start for MATLABSystem: '<Root>/Qudrature Encoder' */
    /*  Constructor */
    riduzione_stato_DW.obj.matlabCodegenIsDeleted = false;
    riduzione_stato_DW.objisempty = true;
    riduzione_stato_DW.obj.SampleTime = riduzione_stato_P.Ts;
    riduzione_stato_DW.obj.isInitialized = 1;

    /* 		%% Define output properties */
    /*  Call C-function implementing device initialization */
    initEncoder();
    riduzione_stato_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/IN1A' */
    riduzione_stato_DW.obj_b.matlabCodegenIsDeleted = false;
    riduzione_stato_DW.objisempty_m = true;
    riduzione_stato_DW.obj_b.isInitialized = 1;
    pinname = 5;
    riduzione_stato_DW.obj_b.MW_PWM_HANDLE = MW_PWM_Open(pinname, 2000.0, 50.0);
    MW_PWM_Start(riduzione_stato_DW.obj_b.MW_PWM_HANDLE);
    riduzione_stato_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/IN2A' */
    riduzione_stato_DW.obj_j.matlabCodegenIsDeleted = false;
    riduzione_stato_DW.objisempty_a = true;
    riduzione_stato_DW.obj_j.isInitialized = 1;
    pinname = 4;
    riduzione_stato_DW.obj_j.MW_PWM_HANDLE = MW_PWM_Open(pinname, 2000.0, 50.0);
    MW_PWM_Start(riduzione_stato_DW.obj_j.MW_PWM_HANDLE);
    riduzione_stato_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/ENA' */
    riduzione_stato_DW.obj_p.matlabCodegenIsDeleted = false;
    riduzione_stato_DW.objisempty_n = true;
    riduzione_stato_DW.obj_p.isInitialized = 1;
    pinname = 2;
    riduzione_stato_DW.obj_p.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    riduzione_stato_DW.obj_p.isSetupComplete = true;
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  riduzione_stato_X.Integrator_CSTATE = riduzione_stato_P.Integrator_IC;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  riduzione_stato_DW.Delay_DSTATE = riduzione_stato_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  riduzione_stato_DW.Delay1_DSTATE = riduzione_stato_P.Delay1_InitialCondition;

  /* SystemInitialize for MATLAB Function: '<Root>/ticks delta' */
  riduzione_stato_DW.doneDoubleBufferReInit = false;
  riduzione_stato_DW.sfEvent = riduzione_stato_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<Root>/speed' */
  riduzione_stato_DW.doneDoubleBufferReInit_k = false;
  riduzione_stato_DW.sfEvent_h = riduzione_stato_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<Root>/getPositon' */
  riduzione_stato_DW.doneDoubleBufferReInit_e = false;
  riduzione_stato_DW.sfEvent_hu = riduzione_stato_CALL_EVENT;
}

/* Model terminate function */
void riduzione_stato_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Qudrature Encoder' */
  if (!riduzione_stato_DW.obj.matlabCodegenIsDeleted) {
    riduzione_stato_DW.obj.matlabCodegenIsDeleted = true;
    if ((riduzione_stato_DW.obj.isInitialized == 1) &&
        riduzione_stato_DW.obj.isSetupComplete) {
      /*  Call C-function implementing device termination */
      releaseEncoder();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Qudrature Encoder' */

  /* Terminate for MATLABSystem: '<Root>/IN1A' */
  if (!riduzione_stato_DW.obj_b.matlabCodegenIsDeleted) {
    riduzione_stato_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((riduzione_stato_DW.obj_b.isInitialized == 1) &&
        riduzione_stato_DW.obj_b.isSetupComplete) {
      MW_PWM_Stop(riduzione_stato_DW.obj_b.MW_PWM_HANDLE);
      MW_PWM_Close(riduzione_stato_DW.obj_b.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN1A' */

  /* Terminate for MATLABSystem: '<Root>/IN2A' */
  if (!riduzione_stato_DW.obj_j.matlabCodegenIsDeleted) {
    riduzione_stato_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((riduzione_stato_DW.obj_j.isInitialized == 1) &&
        riduzione_stato_DW.obj_j.isSetupComplete) {
      MW_PWM_Stop(riduzione_stato_DW.obj_j.MW_PWM_HANDLE);
      MW_PWM_Close(riduzione_stato_DW.obj_j.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN2A' */
  /* Terminate for MATLABSystem: '<Root>/ENA' */
  if (!riduzione_stato_DW.obj_p.matlabCodegenIsDeleted) {
    riduzione_stato_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((riduzione_stato_DW.obj_p.isInitialized == 1) &&
        riduzione_stato_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(riduzione_stato_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ENA' */
}

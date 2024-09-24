/*
 * real_controller_velocity.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "real_controller_velocity".
 *
 * Model version              : 2.30
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue May 28 23:40:41 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "real_controller_velocity.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "real_controller_velocity_private.h"
#include <string.h>

/* Named constants for MATLAB Function: '<Root>/getPositon' */
#define real_controller_velo_CALL_EVENT (-1)

/* Block signals (default storage) */
B_real_controller_velocity_T real_controller_velocity_B;

/* Continuous states */
X_real_controller_velocity_T real_controller_velocity_X;

/* Disabled State Vector */
XDis_real_controller_velocity_T real_controller_velocity_XDis;

/* Block states (default storage) */
DW_real_controller_velocity_T real_controller_velocity_DW;

/* Real-time model */
static RT_MODEL_real_controller_velo_T real_controller_velocity_M_;
RT_MODEL_real_controller_velo_T *const real_controller_velocity_M =
  &real_controller_velocity_M_;

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
  real_controller_velocity_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  real_controller_velocity_step();
  real_controller_velocity_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  real_controller_velocity_step();
  real_controller_velocity_derivatives();

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
void real_controller_velocity_step(void)
{
  real_T q;
  real_T rtb_Abs;
  real_T rtb_Divide;
  uint16_T b_varargout_2;
  boolean_T rEQ0;
  if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
    /* set solver stop time */
    if (!(real_controller_velocity_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&real_controller_velocity_M->solverInfo,
                            ((real_controller_velocity_M->Timing.clockTickH0 + 1)
        * real_controller_velocity_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&real_controller_velocity_M->solverInfo,
                            ((real_controller_velocity_M->Timing.clockTick0 + 1)
        * real_controller_velocity_M->Timing.stepSize0 +
        real_controller_velocity_M->Timing.clockTickH0 *
        real_controller_velocity_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(real_controller_velocity_M)) {
    real_controller_velocity_M->Timing.t[0] = rtsiGetT
      (&real_controller_velocity_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
    /* MATLABSystem: '<Root>/Qudrature Encoder' */
    if (real_controller_velocity_DW.obj.SampleTime !=
        real_controller_velocity_P.Ts) {
      real_controller_velocity_DW.obj.SampleTime = real_controller_velocity_P.Ts;
    }

    /* MATLABSystem: '<Root>/Qudrature Encoder' */
    /* 		%% Define output properties */
    /*  Call C-function implementing device output */
    real_controller_velocity_B.QudratureEncoder_o1 = getEncoderCount();

    /* MATLABSystem: '<Root>/Qudrature Encoder' */
    getIndexCount(&b_varargout_2);

    /* MATLAB Function: '<Root>/ticks delta' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Delay: '<Root>/Delay'
     */
    real_controller_velocity_DW.sfEvent = real_controller_velo_CALL_EVENT;
    real_controller_velocity_B.delta =
      real_controller_velocity_B.QudratureEncoder_o1 -
      real_controller_velocity_DW.Delay_DSTATE;
    if (!(fabs(real_controller_velocity_B.delta) <= ceil(12600.0 *
          real_controller_velocity_P.Ts))) {
      if (real_controller_velocity_DW.Delay_DSTATE >
          real_controller_velocity_B.QudratureEncoder_o1) {
        real_controller_velocity_B.delta += 65535.0;
      } else {
        real_controller_velocity_B.delta -= 65535.0;
      }
    }

    /* End of MATLAB Function: '<Root>/ticks delta' */

    /* MATLAB Function: '<Root>/speed' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    real_controller_velocity_DW.sfEvent_h = real_controller_velo_CALL_EVENT;
    real_controller_velocity_B.speed = real_controller_velocity_B.delta * 60.0 /
      (8400.0 * real_controller_velocity_P.Ts);

    /* DotProduct: '<Root>/Dot Product' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    real_controller_velocity_B.K2x2 = -real_controller_velocity_P.K *
      real_controller_velocity_B.speed;
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant3'
   *  DotProduct: '<Root>/Dot Product1'
   *  Integrator: '<Root>/Integrator'
   */
  real_controller_velocity_B.Add = real_controller_velocity_P.Ki *
    real_controller_velocity_X.Integrator_CSTATE +
    real_controller_velocity_B.K2x2;

  /* Saturate: '<Root>/Saturation1' */
  if (real_controller_velocity_B.Add >
      real_controller_velocity_P.Saturation1_UpperSat) {
    rtb_Divide = real_controller_velocity_P.Saturation1_UpperSat;
  } else if (real_controller_velocity_B.Add <
             real_controller_velocity_P.Saturation1_LowerSat) {
    rtb_Divide = real_controller_velocity_P.Saturation1_LowerSat;
  } else {
    rtb_Divide = real_controller_velocity_B.Add;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  real_controller_velocity_B.Gain = real_controller_velocity_P.Gain_Gain *
    rtb_Divide;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Control variable1'
   */
  if (real_controller_velocity_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Abs = real_controller_velocity_P.Controlvariable1_Value;
  } else {
    rtb_Abs = real_controller_velocity_B.Gain;
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
  rtb_Divide = (rtb_Divide + real_controller_velocity_P.Constant_Value) /
    real_controller_velocity_P.Constant1_Value;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Abs > real_controller_velocity_P.Saturation_UpperSat) {
    rtb_Abs = real_controller_velocity_P.Saturation_UpperSat;
  } else if (rtb_Abs < real_controller_velocity_P.Saturation_LowerSat) {
    rtb_Abs = real_controller_velocity_P.Saturation_LowerSat;
  }

  /* Abs: '<Root>/Abs' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  rtb_Abs = fabs(rtb_Abs);

  /* MATLABSystem: '<Root>/IN1A' incorporates:
   *  Product: '<Root>/Product1'
   */
  MW_PWM_SetDutyCycle(real_controller_velocity_DW.obj_b.MW_PWM_HANDLE,
                      rtb_Divide * rtb_Abs);

  /* MATLABSystem: '<Root>/IN2A' incorporates:
   *  Logic: '<Root>/NOT'
   *  Product: '<Root>/Product'
   */
  MW_PWM_SetDutyCycle(real_controller_velocity_DW.obj_j.MW_PWM_HANDLE, rtb_Abs *
                      (real_T)!(rtb_Divide != 0.0));
  if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
    /* RateTransition generated from: '<Root>/speed' */
    if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
      /* RateTransition generated from: '<Root>/speed' */
      real_controller_velocity_B.HiddenRateTransitionForToWks_In =
        real_controller_velocity_B.speed;
    }

    /* End of RateTransition generated from: '<Root>/speed' */
    /* Sum: '<Root>/Error' incorporates:
     *  Constant: '<Root>/Control variable'
     */
    real_controller_velocity_B.Error = real_controller_velocity_B.speed -
      real_controller_velocity_P.Controlvariable_Value;

    /* Delay: '<Root>/Delay1' */
    real_controller_velocity_B.tick_star =
      real_controller_velocity_DW.Delay1_DSTATE;

    /* MATLAB Function: '<Root>/getPositon' */
    real_controller_velocity_DW.sfEvent_hu = real_controller_velo_CALL_EVENT;
    real_controller_velocity_B.tick_star += real_controller_velocity_B.delta;
    rtb_Divide = 6.2831853071795862 * real_controller_velocity_B.tick_star /
      8400.0;
    q = fabs(rtb_Divide);
    if (rtIsNaN(q) || rtIsInf(q)) {
      rtb_Abs = (rtNaN);
    } else if (q == 0.0) {
      rtb_Abs = 0.0;
    } else {
      rtb_Abs = fmod(q, 6.2831853071795862);
      rEQ0 = (rtb_Abs == 0.0);
      if (!rEQ0) {
        q /= 6.2831853071795862;
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        rtb_Abs = 0.0;
      }
    }

    /* RateTransition generated from: '<Root>/getPositon' */
    if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
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
      real_controller_velocity_B.HiddenRateTransitionForToWks__k = rtb_Divide *
        rtb_Abs;
    }

    /* End of RateTransition generated from: '<Root>/getPositon' */
    /* RateTransition generated from: '<Root>/Qudrature Encoder' */
    if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
      /* RateTransition generated from: '<Root>/Qudrature Encoder' */
      real_controller_velocity_B.HiddenRateTransitionForToWks__c =
        real_controller_velocity_B.QudratureEncoder_o1;
    }

    /* End of RateTransition generated from: '<Root>/Qudrature Encoder' */
    /* Sum: '<Root>/Add1' */
    real_controller_velocity_B.Add1 = 0.0;

    /* Gain: '<Root>/Gain1' */
    real_controller_velocity_B.Gain1 = real_controller_velocity_P.Gain1_Gain *
      real_controller_velocity_B.Add1;

    /* Sum: '<Root>/Error2' */
    real_controller_velocity_B.Error2 = 0.0 - real_controller_velocity_B.Gain1;

    /* MATLABSystem: '<Root>/ENA' incorporates:
     *  Constant: '<Root>/Constant'
     */
    MW_digitalIO_write(real_controller_velocity_DW.obj_p.MW_DIGITALIO_HANDLE,
                       real_controller_velocity_P.Constant_Value_a != 0.0);
  }

  if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
    if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
      /* Update for Delay: '<Root>/Delay' */
      real_controller_velocity_DW.Delay_DSTATE =
        real_controller_velocity_B.QudratureEncoder_o1;

      /* Update for Delay: '<Root>/Delay1' */
      real_controller_velocity_DW.Delay1_DSTATE =
        real_controller_velocity_B.tick_star;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        real_controller_velocity_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(real_controller_velocity_M)) {/* Sample time: [0.005s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((real_controller_velocity_M->Timing.clockTick1+
           real_controller_velocity_M->Timing.clockTickH1* 4294967296.0)) *
         0.005);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(real_controller_velocity_M)) {
    rt_ertODEUpdateContinuousStates(&real_controller_velocity_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++real_controller_velocity_M->Timing.clockTick0)) {
      ++real_controller_velocity_M->Timing.clockTickH0;
    }

    real_controller_velocity_M->Timing.t[0] = rtsiGetSolverStopTime
      (&real_controller_velocity_M->solverInfo);

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
      real_controller_velocity_M->Timing.clockTick1++;
      if (!real_controller_velocity_M->Timing.clockTick1) {
        real_controller_velocity_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void real_controller_velocity_derivatives(void)
{
  XDot_real_controller_velocity_T *_rtXdot;
  _rtXdot = ((XDot_real_controller_velocity_T *)
             real_controller_velocity_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = real_controller_velocity_B.Error;
}

/* Model initialize function */
void real_controller_velocity_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)real_controller_velocity_M, 0,
                sizeof(RT_MODEL_real_controller_velo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&real_controller_velocity_M->solverInfo,
                          &real_controller_velocity_M->Timing.simTimeStep);
    rtsiSetTPtr(&real_controller_velocity_M->solverInfo, &rtmGetTPtr
                (real_controller_velocity_M));
    rtsiSetStepSizePtr(&real_controller_velocity_M->solverInfo,
                       &real_controller_velocity_M->Timing.stepSize0);
    rtsiSetdXPtr(&real_controller_velocity_M->solverInfo,
                 &real_controller_velocity_M->derivs);
    rtsiSetContStatesPtr(&real_controller_velocity_M->solverInfo, (real_T **)
                         &real_controller_velocity_M->contStates);
    rtsiSetNumContStatesPtr(&real_controller_velocity_M->solverInfo,
      &real_controller_velocity_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&real_controller_velocity_M->solverInfo,
      &real_controller_velocity_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&real_controller_velocity_M->solverInfo,
      &real_controller_velocity_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&real_controller_velocity_M->solverInfo,
      &real_controller_velocity_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&real_controller_velocity_M->solverInfo,
      (boolean_T**) &real_controller_velocity_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&real_controller_velocity_M->solverInfo,
                          (&rtmGetErrorStatus(real_controller_velocity_M)));
    rtsiSetRTModelPtr(&real_controller_velocity_M->solverInfo,
                      real_controller_velocity_M);
  }

  rtsiSetSimTimeStep(&real_controller_velocity_M->solverInfo, MAJOR_TIME_STEP);
  real_controller_velocity_M->intgData.y = real_controller_velocity_M->odeY;
  real_controller_velocity_M->intgData.f[0] = real_controller_velocity_M->odeF[0];
  real_controller_velocity_M->intgData.f[1] = real_controller_velocity_M->odeF[1];
  real_controller_velocity_M->intgData.f[2] = real_controller_velocity_M->odeF[2];
  real_controller_velocity_M->contStates = ((X_real_controller_velocity_T *)
    &real_controller_velocity_X);
  real_controller_velocity_M->contStateDisabled =
    ((XDis_real_controller_velocity_T *) &real_controller_velocity_XDis);
  real_controller_velocity_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&real_controller_velocity_M->solverInfo, (void *)
                    &real_controller_velocity_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&real_controller_velocity_M->solverInfo,
    false);
  rtsiSetSolverName(&real_controller_velocity_M->solverInfo,"ode3");
  rtmSetTPtr(real_controller_velocity_M,
             &real_controller_velocity_M->Timing.tArray[0]);
  rtmSetTFinal(real_controller_velocity_M, -1);
  real_controller_velocity_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  real_controller_velocity_M->Sizes.checksums[0] = (580818173U);
  real_controller_velocity_M->Sizes.checksums[1] = (1997968829U);
  real_controller_velocity_M->Sizes.checksums[2] = (3912545329U);
  real_controller_velocity_M->Sizes.checksums[3] = (1161708713U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    real_controller_velocity_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(real_controller_velocity_M->extModeInfo,
      &real_controller_velocity_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(real_controller_velocity_M->extModeInfo,
                        real_controller_velocity_M->Sizes.checksums);
    rteiSetTPtr(real_controller_velocity_M->extModeInfo, rtmGetTPtr
                (real_controller_velocity_M));
  }

  /* block I/O */
  (void) memset(((void *) &real_controller_velocity_B), 0,
                sizeof(B_real_controller_velocity_T));

  /* states (continuous) */
  {
    (void) memset((void *)&real_controller_velocity_X, 0,
                  sizeof(X_real_controller_velocity_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&real_controller_velocity_XDis, 0,
                  sizeof(XDis_real_controller_velocity_T));
  }

  /* states (dwork) */
  (void) memset((void *)&real_controller_velocity_DW, 0,
                sizeof(DW_real_controller_velocity_T));

  {
    uint32_T pinname;

    /* Start for MATLABSystem: '<Root>/Qudrature Encoder' */
    /*  Constructor */
    real_controller_velocity_DW.obj.matlabCodegenIsDeleted = false;
    real_controller_velocity_DW.objisempty = true;
    real_controller_velocity_DW.obj.SampleTime = real_controller_velocity_P.Ts;
    real_controller_velocity_DW.obj.isInitialized = 1;

    /* 		%% Define output properties */
    /*  Call C-function implementing device initialization */
    initEncoder();
    real_controller_velocity_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/IN1A' */
    real_controller_velocity_DW.obj_b.matlabCodegenIsDeleted = false;
    real_controller_velocity_DW.objisempty_m = true;
    real_controller_velocity_DW.obj_b.isInitialized = 1;
    pinname = 5;
    real_controller_velocity_DW.obj_b.MW_PWM_HANDLE = MW_PWM_Open(pinname,
      2000.0, 50.0);
    MW_PWM_Start(real_controller_velocity_DW.obj_b.MW_PWM_HANDLE);
    real_controller_velocity_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/IN2A' */
    real_controller_velocity_DW.obj_j.matlabCodegenIsDeleted = false;
    real_controller_velocity_DW.objisempty_a = true;
    real_controller_velocity_DW.obj_j.isInitialized = 1;
    pinname = 4;
    real_controller_velocity_DW.obj_j.MW_PWM_HANDLE = MW_PWM_Open(pinname,
      2000.0, 50.0);
    MW_PWM_Start(real_controller_velocity_DW.obj_j.MW_PWM_HANDLE);
    real_controller_velocity_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/ENA' */
    real_controller_velocity_DW.obj_p.matlabCodegenIsDeleted = false;
    real_controller_velocity_DW.objisempty_n = true;
    real_controller_velocity_DW.obj_p.isInitialized = 1;
    pinname = 2;
    real_controller_velocity_DW.obj_p.MW_DIGITALIO_HANDLE = MW_digitalIO_open
      (pinname, 1);
    real_controller_velocity_DW.obj_p.isSetupComplete = true;
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  real_controller_velocity_X.Integrator_CSTATE =
    real_controller_velocity_P.Integrator_IC;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  real_controller_velocity_DW.Delay_DSTATE =
    real_controller_velocity_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  real_controller_velocity_DW.Delay1_DSTATE =
    real_controller_velocity_P.Delay1_InitialCondition;

  /* SystemInitialize for MATLAB Function: '<Root>/ticks delta' */
  real_controller_velocity_DW.doneDoubleBufferReInit = false;
  real_controller_velocity_DW.sfEvent = real_controller_velo_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<Root>/speed' */
  real_controller_velocity_DW.doneDoubleBufferReInit_k = false;
  real_controller_velocity_DW.sfEvent_h = real_controller_velo_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<Root>/getPositon' */
  real_controller_velocity_DW.doneDoubleBufferReInit_e = false;
  real_controller_velocity_DW.sfEvent_hu = real_controller_velo_CALL_EVENT;
}

/* Model terminate function */
void real_controller_velocity_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Qudrature Encoder' */
  if (!real_controller_velocity_DW.obj.matlabCodegenIsDeleted) {
    real_controller_velocity_DW.obj.matlabCodegenIsDeleted = true;
    if ((real_controller_velocity_DW.obj.isInitialized == 1) &&
        real_controller_velocity_DW.obj.isSetupComplete) {
      /*  Call C-function implementing device termination */
      releaseEncoder();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Qudrature Encoder' */

  /* Terminate for MATLABSystem: '<Root>/IN1A' */
  if (!real_controller_velocity_DW.obj_b.matlabCodegenIsDeleted) {
    real_controller_velocity_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((real_controller_velocity_DW.obj_b.isInitialized == 1) &&
        real_controller_velocity_DW.obj_b.isSetupComplete) {
      MW_PWM_Stop(real_controller_velocity_DW.obj_b.MW_PWM_HANDLE);
      MW_PWM_Close(real_controller_velocity_DW.obj_b.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN1A' */

  /* Terminate for MATLABSystem: '<Root>/IN2A' */
  if (!real_controller_velocity_DW.obj_j.matlabCodegenIsDeleted) {
    real_controller_velocity_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((real_controller_velocity_DW.obj_j.isInitialized == 1) &&
        real_controller_velocity_DW.obj_j.isSetupComplete) {
      MW_PWM_Stop(real_controller_velocity_DW.obj_j.MW_PWM_HANDLE);
      MW_PWM_Close(real_controller_velocity_DW.obj_j.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN2A' */
  /* Terminate for MATLABSystem: '<Root>/ENA' */
  if (!real_controller_velocity_DW.obj_p.matlabCodegenIsDeleted) {
    real_controller_velocity_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((real_controller_velocity_DW.obj_p.isInitialized == 1) &&
        real_controller_velocity_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(real_controller_velocity_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ENA' */
}

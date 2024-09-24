/*
 * real_controller_velocity.h
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

#ifndef RTW_HEADER_real_controller_velocity_h_
#define RTW_HEADER_real_controller_velocity_h_
#ifndef real_controller_velocity_COMMON_INCLUDES_
#define real_controller_velocity_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "soc_stm_encoder.h"
#endif                           /* real_controller_velocity_COMMON_INCLUDES_ */

#include "real_controller_velocity_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T K2x2;                         /* '<Root>/Dot Product' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T HiddenRateTransitionForToWks_In;
  /* '<Root>/HiddenRateTransitionForToWks_InsertedFor_TAQSigLogging_InsertedFor_speed_at_outport_0_at_inport_0' */
  real_T Error;                        /* '<Root>/Error' */
  real_T HiddenRateTransitionForToWks__k;
  /* '<Root>/HiddenRateTransitionForToWks_InsertedFor_TAQSigLogging_InsertedFor_getPositon_at_outport_0_at_inport_0' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Error2;                       /* '<Root>/Error2' */
  real_T delta;                        /* '<Root>/ticks delta' */
  real_T speed;                        /* '<Root>/speed' */
  real_T tick_star;                    /* '<Root>/getPositon' */
  uint16_T HiddenRateTransitionForToWks__c;
  /* '<Root>/HiddenRateTransitionForToWks_InsertedFor_TAQSigLogging_InsertedFor_Qudrature Encoder_at_outport_0_at_inport_0' */
  uint16_T QudratureEncoder_o1;        /* '<Root>/Qudrature Encoder' */
} B_real_controller_velocity_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  soc_stm_QEP_real_controller_v_T obj; /* '<Root>/Qudrature Encoder' */
  mbed_DigitalWrite_real_contro_T obj_p;/* '<Root>/ENA' */
  mbed_PWMOutput_real_controlle_T obj_j;/* '<Root>/IN2A' */
  mbed_PWMOutput_real_controlle_T obj_b;/* '<Root>/IN1A' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  int32_T sfEvent;                     /* '<Root>/ticks delta' */
  int32_T sfEvent_h;                   /* '<Root>/speed' */
  int32_T sfEvent_hu;                  /* '<Root>/getPositon' */
  uint16_T Delay_DSTATE;               /* '<Root>/Delay' */
  uint8_T is_active_c2_real_controller_ve;/* '<Root>/ticks delta' */
  uint8_T is_active_c1_real_controller_ve;/* '<Root>/speed' */
  uint8_T is_active_c3_real_controller_ve;/* '<Root>/getPositon' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/ticks delta' */
  boolean_T doneDoubleBufferReInit_k;  /* '<Root>/speed' */
  boolean_T doneDoubleBufferReInit_e;  /* '<Root>/getPositon' */
  boolean_T objisempty;                /* '<Root>/Qudrature Encoder' */
  boolean_T objisempty_a;              /* '<Root>/IN2A' */
  boolean_T objisempty_m;              /* '<Root>/IN1A' */
  boolean_T objisempty_n;              /* '<Root>/ENA' */
} DW_real_controller_velocity_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X_real_controller_velocity_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot_real_controller_velocity_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis_real_controller_velocity_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_real_controller_velocity_T_ {
  real_T K;                            /* Variable: K
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<Root>/Constant1'
                                        *   '<Root>/Qudrature Encoder'
                                        */
  real_T Controlvariable1_Value;       /* Expression: 69.79129819596744
                                        * Referenced by: '<Root>/Control variable1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Gain_Gain;                    /* Expression: 100/12
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Controlvariable_Value;        /* Expression: -0.3891050583657574
                                        * Referenced by: '<Root>/Control variable'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -0.00001
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint16_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_real_controller_veloc_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_real_controller_velocity_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_real_controller_velocity_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_real_controller_velocity_T real_controller_velocity_P;

/* Block signals (default storage) */
extern B_real_controller_velocity_T real_controller_velocity_B;

/* Continuous states (default storage) */
extern X_real_controller_velocity_T real_controller_velocity_X;

/* Disabled states (default storage) */
extern XDis_real_controller_velocity_T real_controller_velocity_XDis;

/* Block states (default storage) */
extern DW_real_controller_velocity_T real_controller_velocity_DW;

/* Model entry point functions */
extern void real_controller_velocity_initialize(void);
extern void real_controller_velocity_step(void);
extern void real_controller_velocity_terminate(void);

/* Real-time Model object */
extern RT_MODEL_real_controller_velo_T *const real_controller_velocity_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'real_controller_velocity'
 * '<S1>'   : 'real_controller_velocity/Subsystem'
 * '<S2>'   : 'real_controller_velocity/getPositon'
 * '<S3>'   : 'real_controller_velocity/speed'
 * '<S4>'   : 'real_controller_velocity/ticks delta'
 */
#endif                              /* RTW_HEADER_real_controller_velocity_h_ */

/*
 * real_controller_velocity_types.h
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

#ifndef RTW_HEADER_real_controller_velocity_types_h_
#define RTW_HEADER_real_controller_velocity_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/IN2A' */
#include "MW_SVD.h"
#ifndef struct_tag_KxFW01GBdhqk5JOEHU3GlD
#define struct_tag_KxFW01GBdhqk5JOEHU3GlD

struct tag_KxFW01GBdhqk5JOEHU3GlD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_KxFW01GBdhqk5JOEHU3GlD */

#ifndef typedef_mbed_DigitalWrite_real_contro_T
#define typedef_mbed_DigitalWrite_real_contro_T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_real_contro_T;

#endif                             /* typedef_mbed_DigitalWrite_real_contro_T */

#ifndef struct_tag_UndvUYqhBVOhRRpUse3fWF
#define struct_tag_UndvUYqhBVOhRRpUse3fWF

struct tag_UndvUYqhBVOhRRpUse3fWF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_UndvUYqhBVOhRRpUse3fWF */

#ifndef typedef_mbed_PWMOutput_real_controlle_T
#define typedef_mbed_PWMOutput_real_controlle_T

typedef struct tag_UndvUYqhBVOhRRpUse3fWF mbed_PWMOutput_real_controlle_T;

#endif                             /* typedef_mbed_PWMOutput_real_controlle_T */

#ifndef struct_tag_sGWFgQTjADKFs5f99dqloH
#define struct_tag_sGWFgQTjADKFs5f99dqloH

struct tag_sGWFgQTjADKFs5f99dqloH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /* struct_tag_sGWFgQTjADKFs5f99dqloH */

#ifndef typedef_soc_stm_QEP_real_controller_v_T
#define typedef_soc_stm_QEP_real_controller_v_T

typedef struct tag_sGWFgQTjADKFs5f99dqloH soc_stm_QEP_real_controller_v_T;

#endif                             /* typedef_soc_stm_QEP_real_controller_v_T */

/* Parameters (default storage) */
typedef struct P_real_controller_velocity_T_ P_real_controller_velocity_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_real_controller_veloc_T RT_MODEL_real_controller_velo_T;

#endif                        /* RTW_HEADER_real_controller_velocity_types_h_ */

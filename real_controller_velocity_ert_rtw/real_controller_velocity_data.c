/*
 * real_controller_velocity_data.c
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

/* Block parameters (default storage) */
P_real_controller_velocity_T real_controller_velocity_P = {
  /* Variable: K
   * Referenced by: '<Root>/Constant2'
   */
  2.6147783251231544,

  /* Variable: Ki
   * Referenced by: '<Root>/Constant3'
   */
  -14.400000000000009,

  /* Variable: Ts
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<Root>/Qudrature Encoder'
   */
  0.005,

  /* Expression: 69.79129819596744
   * Referenced by: '<Root>/Control variable1'
   */
  69.791298195967443,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation1'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<Root>/Saturation1'
   */
  -12.0,

  /* Expression: 100/12
   * Referenced by: '<Root>/Gain'
   */
  8.3333333333333339,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant1'
   */
  2.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<Root>/Saturation'
   */
  -100.0,

  /* Expression: -0.3891050583657574
   * Referenced by: '<Root>/Control variable'
   */
  -0.38910505836575737,

  /* Expression: 0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Expression: -0.00001
   * Referenced by: '<Root>/Gain1'
   */
  -1.0E-5,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U
};

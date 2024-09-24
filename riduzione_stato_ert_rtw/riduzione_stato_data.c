/*
 * riduzione_stato_data.c
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

/* Block parameters (default storage) */
P_riduzione_stato_T riduzione_stato_P = {
  /* Variable: K
   * Referenced by: '<Root>/Constant2'
   */
  20.166157080713123,

  /* Variable: Ki
   * Referenced by: '<Root>/Constant3'
   */
  -173.20508075688775,

  /* Variable: Ts
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<Root>/Qudrature Encoder'
   */
  0.005,

  /* Expression: 100/12
   * Referenced by: '<Root>/Gain'
   */
  8.3333333333333339,

  /* Expression: 90.10678777464096
   * Referenced by: '<Root>/Control variable1'
   */
  90.106787774640964,

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

  /* Expression: -1
   * Referenced by: '<Root>/Gain2'
   */
  -1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Control variable'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

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
  1U
};

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * p_hip.c
 *
 * Code generation for function 'p_hip'
 *
 */

/* Include files */
#include "p_hip.h"
#include <math.h>

/* Function Definitions */
void p_hip(const double in1[5], double phip[2])
{
  double t4;

  /* P_HIP */
  /*     PHIP = P_HIP(IN1) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.3. */
  /*     09-Nov-2020 22:00:39 */
  t4 = in1[1] + (in1[0] + 1.5707963267948966);
  phip[0] = cos(in1[0] + 1.5707963267948966) * 0.4667 + cos(t4) * 0.4064;
  phip[1] = sin(in1[0] + 1.5707963267948966) * 0.4667 + sin(t4) * 0.4064;
}

/* End of code generation (p_hip.c) */

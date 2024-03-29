/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dz_2.c
 *
 * Code generation for function 'dz_2'
 *
 */

/* Include files */
#include "dz_2.h"
#include <math.h>

/* Function Definitions */
double dz_2(const double in1[5])
{
  double ksi_2_dot_tmp;
  double t5;
  double t6;
  /* DZ_2 */
  /*     KSI_2_DOT = DZ_2(IN1) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.6.
   */
  /*     07-Nov-2021 01:39:39 */
  t5 = in1[1] * 0.47262313860252;
  t6 = in1[0] * 1.1454753722794959;
  ksi_2_dot_tmp = (t5 + 1.5707963267948966) + -t6;
  t5 = (((-in1[3] + 4.71238898038469) + t5) + -t6) + in1[2];
  return (((cos(t5) * 8.41871797884 + cos(ksi_2_dot_tmp) * 77.52247105284) +
           cos(ksi_2_dot_tmp + in1[2]) * 36.3549771) +
          cos((t6 + -1.5707963267948966) + in1[1] * 0.52737686139748) *
              97.255892295144) +
         cos(t5 - in1[4]) * 1.436905246896;
}

/* End of code generation (dz_2.c) */

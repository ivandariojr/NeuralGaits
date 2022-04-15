/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * p_cm.c
 *
 * Code generation for function 'p_cm'
 *
 */

/* Include files */
#include "p_cm.h"
#include <math.h>

/* Function Definitions */
void p_cm(const double in1[5], double pcm[2])
{
  double t9;
  double t7;
  double t10;
  double t8;

  /* P_CM */
  /*     PCM = P_CM(IN1) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.3. */
  /*     09-Nov-2020 22:00:39 */
  t9 = (((in1[0] + in1[2]) + in1[1]) + -in1[3]) + 4.71238898038469;
  t7 = in1[1] + (in1[0] + 1.5707963267948966);
  t10 = -in1[4] + t9;
  t8 = in1[2] + t7;
  pcm[0] = (((cos(in1[0] + 1.5707963267948966) * 0.45990514064422272 + cos(t7) *
              0.36658943855501719) + cos(t8) * 0.1719159678834988) + cos(t9) *
            0.039810561444982767) + cos(t10) * 0.0067948593557772777;
  pcm[1] = (((sin(in1[0] + 1.5707963267948966) * 0.45990514064422272 + sin(t7) *
              0.36658943855501719) + sin(t8) * 0.1719159678834988) + sin(t9) *
            0.039810561444982767) + sin(t10) * 0.0067948593557772777;
}

/* End of code generation (p_cm.c) */
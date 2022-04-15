/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CBF_Lf2s1_initialize.c
 *
 * Code generation for function 'CBF_Lf2s1_initialize'
 *
 */

/* Include files */
#include "CBF_Lf2s1_initialize.h"
#include "CBF_Lf2s1.h"
#include "CBF_Lf2s1_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void CBF_Lf2s1_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_CBF_Lf2s1 = true;
}

/* End of code generation (CBF_Lf2s1_initialize.c) */

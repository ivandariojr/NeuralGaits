/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CBF_ds2edx_initialize.c
 *
 * Code generation for function 'CBF_ds2edx_initialize'
 *
 */

/* Include files */
#include "CBF_ds2edx_initialize.h"
#include "CBF_ds2edx.h"
#include "CBF_ds2edx_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void CBF_ds2edx_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_CBF_ds2edx = true;
}

/* End of code generation (CBF_ds2edx_initialize.c) */

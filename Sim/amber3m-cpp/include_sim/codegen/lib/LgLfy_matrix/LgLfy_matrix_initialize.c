/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LgLfy_matrix_initialize.c
 *
 * Code generation for function 'LgLfy_matrix_initialize'
 *
 */

/* Include files */
#include "LgLfy_matrix_initialize.h"
#include "LgLfy_matrix.h"
#include "LgLfy_matrix_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void LgLfy_matrix_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_LgLfy_matrix = true;
}

/* End of code generation (LgLfy_matrix_initialize.c) */

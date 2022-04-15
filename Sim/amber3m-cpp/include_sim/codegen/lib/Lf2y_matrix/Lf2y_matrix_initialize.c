/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Lf2y_matrix_initialize.c
 *
 * Code generation for function 'Lf2y_matrix_initialize'
 *
 */

/* Include files */
#include "Lf2y_matrix_initialize.h"
#include "Lf2y_matrix.h"
#include "Lf2y_matrix_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Lf2y_matrix_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_Lf2y_matrix = true;
}

/* End of code generation (Lf2y_matrix_initialize.c) */

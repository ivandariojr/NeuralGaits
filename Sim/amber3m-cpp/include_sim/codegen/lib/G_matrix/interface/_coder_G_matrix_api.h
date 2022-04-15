/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_G_matrix_api.h
 *
 * Code generation for function '_coder_G_matrix_api'
 *
 */

#ifndef _CODER_G_MATRIX_API_H
#define _CODER_G_MATRIX_API_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void G_matrix(real_T in1[5], real_T G[5]);
extern void G_matrix_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1]);
extern void G_matrix_atexit(void);
extern void G_matrix_initialize(void);
extern void G_matrix_terminate(void);
extern void G_matrix_xil_shutdown(void);
extern void G_matrix_xil_terminate(void);

#endif

/* End of code generation (_coder_G_matrix_api.h) */

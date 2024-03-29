/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LgLfy_matrix_api.h
 *
 * Code generation for function '_coder_LgLfy_matrix_api'
 *
 */

#ifndef _CODER_LGLFY_MATRIX_API_H
#define _CODER_LGLFY_MATRIX_API_H

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
extern void LgLfy_matrix(real_T in1[10], real_T in2[5], real_T in3[2], real_T
  in4[20], real_T LgLfy[16]);
extern void LgLfy_matrix_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[1]);
extern void LgLfy_matrix_atexit(void);
extern void LgLfy_matrix_initialize(void);
extern void LgLfy_matrix_terminate(void);
extern void LgLfy_matrix_xil_shutdown(void);
extern void LgLfy_matrix_xil_terminate(void);

#endif

/* End of code generation (_coder_LgLfy_matrix_api.h) */

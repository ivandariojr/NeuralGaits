/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_LgLfs3_api.h
 *
 * Code generation for function '_coder_CBF_LgLfs3_api'
 *
 */

#ifndef _CODER_CBF_LGLFS3_API_H
#define _CODER_CBF_LGLFS3_API_H

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
extern void CBF_LgLfs3(real_T in1[10], real_T xmin, real_T LgLfs3[4]);
extern void CBF_LgLfs3_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void CBF_LgLfs3_atexit(void);
extern void CBF_LgLfs3_initialize(void);
extern void CBF_LgLfs3_terminate(void);
extern void CBF_LgLfs3_xil_shutdown(void);
extern void CBF_LgLfs3_xil_terminate(void);

#endif

/* End of code generation (_coder_CBF_LgLfs3_api.h) */

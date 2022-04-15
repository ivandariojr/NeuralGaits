/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_LgLfs2_api.h
 *
 * Code generation for function '_coder_CBF_LgLfs2_api'
 *
 */

#ifndef _CODER_CBF_LGLFS2_API_H
#define _CODER_CBF_LGLFS2_API_H

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
extern void CBF_LgLfs2(real_T in1[10], real_T in2[5], real_T in3[2], real_T ldes,
  real_T r, real_T m1, real_T a, real_T LgLfs2[4]);
extern void CBF_LgLfs2_api(const mxArray * const prhs[7], int32_T nlhs, const
  mxArray *plhs[1]);
extern void CBF_LgLfs2_atexit(void);
extern void CBF_LgLfs2_initialize(void);
extern void CBF_LgLfs2_terminate(void);
extern void CBF_LgLfs2_xil_shutdown(void);
extern void CBF_LgLfs2_xil_terminate(void);

#endif

/* End of code generation (_coder_CBF_LgLfs2_api.h) */

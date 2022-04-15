/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_p_swing_api.h
 *
 * Code generation for function '_coder_p_swing_api'
 *
 */

#ifndef _CODER_P_SWING_API_H
#define _CODER_P_SWING_API_H

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
extern void p_swing(real_T in1[5], real_T pfoot2[2]);
extern void p_swing_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1]);
extern void p_swing_atexit(void);
extern void p_swing_initialize(void);
extern void p_swing_terminate(void);
extern void p_swing_xil_shutdown(void);
extern void p_swing_xil_terminate(void);

#endif

/* End of code generation (_coder_p_swing_api.h) */

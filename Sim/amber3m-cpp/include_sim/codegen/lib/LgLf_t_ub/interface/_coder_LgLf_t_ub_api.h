/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LgLf_t_ub_api.h
 *
 * Code generation for function 'LgLf_t_ub'
 *
 */

#ifndef _CODER_LGLF_T_UB_API_H
#define _CODER_LGLF_T_UB_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void LgLf_t_ub(real_T in1[10], real_T ub, real_T b_LgLf_t_ub[4]);

void LgLf_t_ub_api(const mxArray *const prhs[2], const mxArray **plhs);

void LgLf_t_ub_atexit(void);

void LgLf_t_ub_initialize(void);

void LgLf_t_ub_terminate(void);

void LgLf_t_ub_xil_shutdown(void);

void LgLf_t_ub_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_LgLf_t_ub_api.h) */

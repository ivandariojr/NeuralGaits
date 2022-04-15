/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Lf_psw_ub_api.h
 *
 * Code generation for function 'Lf_psw_ub'
 *
 */

#ifndef _CODER_LF_PSW_UB_API_H
#define _CODER_LF_PSW_UB_API_H

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
real_T Lf_psw_ub(real_T in1[10], real_T h, real_T k, real_T r, real_T ub);

void Lf_psw_ub_api(const mxArray *const prhs[5], const mxArray **plhs);

void Lf_psw_ub_atexit(void);

void Lf_psw_ub_initialize(void);

void Lf_psw_ub_terminate(void);

void Lf_psw_ub_xil_shutdown(void);

void Lf_psw_ub_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_Lf_psw_ub_api.h) */

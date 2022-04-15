/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Lf_t_ub_api.h
 *
 * Code generation for function 'Lf_t_ub'
 *
 */

#ifndef _CODER_LF_T_UB_API_H
#define _CODER_LF_T_UB_API_H

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
real_T Lf_t_ub(real_T in1[10], real_T ub);

void Lf_t_ub_api(const mxArray *const prhs[2], const mxArray **plhs);

void Lf_t_ub_atexit(void);

void Lf_t_ub_initialize(void);

void Lf_t_ub_terminate(void);

void Lf_t_ub_xil_shutdown(void);

void Lf_t_ub_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_Lf_t_ub_api.h) */

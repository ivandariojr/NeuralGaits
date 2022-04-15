/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_psw_lb_api.h
 *
 * Code generation for function 'psw_lb'
 *
 */

#ifndef _CODER_PSW_LB_API_H
#define _CODER_PSW_LB_API_H

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
real_T psw_lb(real_T in1[10], real_T h, real_T k, real_T r, real_T lb);

void psw_lb_api(const mxArray *const prhs[5], const mxArray **plhs);

void psw_lb_atexit(void);

void psw_lb_initialize(void);

void psw_lb_terminate(void);

void psw_lb_xil_shutdown(void);

void psw_lb_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_psw_lb_api.h) */

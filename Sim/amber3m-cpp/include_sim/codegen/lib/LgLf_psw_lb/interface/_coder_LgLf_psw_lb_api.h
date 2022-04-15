/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LgLf_psw_lb_api.h
 *
 * Code generation for function 'LgLf_psw_lb'
 *
 */

#ifndef _CODER_LGLF_PSW_LB_API_H
#define _CODER_LGLF_PSW_LB_API_H

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
void LgLf_psw_lb(real_T in1[10], real_T h, real_T k, real_T r, real_T lb,
                 real_T b_LgLf_psw_lb[4]);

void LgLf_psw_lb_api(const mxArray *const prhs[5], const mxArray **plhs);

void LgLf_psw_lb_atexit(void);

void LgLf_psw_lb_initialize(void);

void LgLf_psw_lb_terminate(void);

void LgLf_psw_lb_xil_shutdown(void);

void LgLf_psw_lb_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_LgLf_psw_lb_api.h) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Lf_t_lb_api.h
 *
 * Code generation for function 'Lf_t_lb'
 *
 */

#ifndef _CODER_LF_T_LB_API_H
#define _CODER_LF_T_LB_API_H

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
real_T Lf_t_lb(real_T in1[10], real_T lb);

void Lf_t_lb_api(const mxArray *const prhs[2], const mxArray **plhs);

void Lf_t_lb_atexit(void);

void Lf_t_lb_initialize(void);

void Lf_t_lb_terminate(void);

void Lf_t_lb_xil_shutdown(void);

void Lf_t_lb_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_Lf_t_lb_api.h) */

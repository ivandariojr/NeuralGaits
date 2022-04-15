/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_dz_2_api.h
 *
 * Code generation for function 'dz_2'
 *
 */

#ifndef _CODER_DZ_2_API_H
#define _CODER_DZ_2_API_H

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
real_T dz_2(real_T in1[5]);

void dz_2_api(const mxArray *prhs, const mxArray **plhs);

void dz_2_atexit(void);

void dz_2_initialize(void);

void dz_2_terminate(void);

void dz_2_xil_shutdown(void);

void dz_2_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_dz_2_api.h) */

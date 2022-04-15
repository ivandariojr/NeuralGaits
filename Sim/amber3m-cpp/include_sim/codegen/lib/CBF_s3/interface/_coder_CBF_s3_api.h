/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_s3_api.h
 *
 * Code generation for function '_coder_CBF_s3_api'
 *
 */

#ifndef _CODER_CBF_S3_API_H
#define _CODER_CBF_S3_API_H

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
extern real_T CBF_s3(real_T in1[5], real_T xmin);
extern void CBF_s3_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void CBF_s3_atexit(void);
extern void CBF_s3_initialize(void);
extern void CBF_s3_terminate(void);
extern void CBF_s3_xil_shutdown(void);
extern void CBF_s3_xil_terminate(void);

#endif

/* End of code generation (_coder_CBF_s3_api.h) */

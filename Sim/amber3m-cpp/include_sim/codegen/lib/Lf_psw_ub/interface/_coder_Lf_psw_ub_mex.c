/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Lf_psw_ub_mex.c
 *
 * Code generation for function 'Lf_psw_ub'
 *
 */

/* Include files */
#include "_coder_Lf_psw_ub_mex.h"
#include "_coder_Lf_psw_ub_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Lf_psw_ub_atexit);
  /* Module initialization. */
  Lf_psw_ub_initialize();
  /* Dispatch the entry-point. */
  unsafe_Lf_psw_ub_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  Lf_psw_ub_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void unsafe_Lf_psw_ub_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        9, "Lf_psw_ub");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "Lf_psw_ub");
  }
  /* Call the function. */
  Lf_psw_ub_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_Lf_psw_ub_mex.c) */

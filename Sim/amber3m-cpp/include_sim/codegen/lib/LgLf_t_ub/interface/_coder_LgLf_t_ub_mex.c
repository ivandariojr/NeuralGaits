/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LgLf_t_ub_mex.c
 *
 * Code generation for function 'LgLf_t_ub'
 *
 */

/* Include files */
#include "_coder_LgLf_t_ub_mex.h"
#include "_coder_LgLf_t_ub_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&LgLf_t_ub_atexit);
  /* Module initialization. */
  LgLf_t_ub_initialize();
  /* Dispatch the entry-point. */
  unsafe_LgLf_t_ub_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  LgLf_t_ub_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void unsafe_LgLf_t_ub_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        9, "LgLf_t_ub");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "LgLf_t_ub");
  }
  /* Call the function. */
  LgLf_t_ub_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_LgLf_t_ub_mex.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LgLf_psw_lb_mex.c
 *
 * Code generation for function 'LgLf_psw_lb'
 *
 */

/* Include files */
#include "_coder_LgLf_psw_lb_mex.h"
#include "_coder_LgLf_psw_lb_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&LgLf_psw_lb_atexit);
  /* Module initialization. */
  LgLf_psw_lb_initialize();
  /* Dispatch the entry-point. */
  unsafe_LgLf_psw_lb_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  LgLf_psw_lb_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void unsafe_LgLf_psw_lb_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                    int32_T nrhs, const mxArray *prhs[5])
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
                        11, "LgLf_psw_lb");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "LgLf_psw_lb");
  }
  /* Call the function. */
  LgLf_psw_lb_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_LgLf_psw_lb_mex.c) */

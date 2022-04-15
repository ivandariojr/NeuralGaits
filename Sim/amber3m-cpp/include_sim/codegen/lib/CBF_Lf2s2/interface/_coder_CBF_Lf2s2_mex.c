/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_Lf2s2_mex.c
 *
 * Code generation for function '_coder_CBF_Lf2s2_mex'
 *
 */

/* Include files */
#include "_coder_CBF_Lf2s2_mex.h"
#include "_coder_CBF_Lf2s2_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void CBF_Lf2s2_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */
void CBF_Lf2s2_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[7])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4, 9,
                        "CBF_Lf2s2");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "CBF_Lf2s2");
  }

  /* Call the function. */
  CBF_Lf2s2_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&CBF_Lf2s2_atexit);

  /* Module initialization. */
  CBF_Lf2s2_initialize();

  /* Dispatch the entry-point. */
  CBF_Lf2s2_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  CBF_Lf2s2_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_CBF_Lf2s2_mex.c) */

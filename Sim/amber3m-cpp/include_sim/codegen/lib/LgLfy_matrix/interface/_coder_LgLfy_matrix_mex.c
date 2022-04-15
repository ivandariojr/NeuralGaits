/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LgLfy_matrix_mex.c
 *
 * Code generation for function '_coder_LgLfy_matrix_mex'
 *
 */

/* Include files */
#include "_coder_LgLfy_matrix_mex.h"
#include "_coder_LgLfy_matrix_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void LgLfy_matrix_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
void LgLfy_matrix_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[4])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        12, "LgLfy_matrix");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "LgLfy_matrix");
  }

  /* Call the function. */
  LgLfy_matrix_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&LgLfy_matrix_atexit);

  /* Module initialization. */
  LgLfy_matrix_initialize();

  /* Dispatch the entry-point. */
  LgLfy_matrix_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  LgLfy_matrix_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_LgLfy_matrix_mex.c) */

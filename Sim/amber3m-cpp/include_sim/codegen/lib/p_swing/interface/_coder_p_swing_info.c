/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_p_swing_info.c
 *
 * Code generation for function '_coder_p_swing_info'
 *
 */

/* Include files */
#include "_coder_p_swing_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[8] = {
    "789ced59dd6e1241185db49a9aa8e546131fc00bd3c850a8d05e426d0bb53408d81f5ad3ceee0eb2e9ec4ff787b65c28f105eaad4fa0973e425f41132ff5595c"
    "5806cac611ec942dd09964337c39ec9c33dfb0673f66845036171204e1a17bfdfc20088d98d06a0fbc4e08b7fb5b426ff3e3a1767fcf1793764798eab92fd4e6",
    "3b6bc792aed9e8c4f6020daaa873a7acab8a0635bb746a20c144968e6b486e211505a392a2a2e2c560a319a92b17a04ed0849a9f97aa483a2c3aaa6056adae42"
    "7c3168e5a3d93e51e63b35603e00251f611fbebbfc16547515014d4718405544665c7d2e19065034093b32dab7141518fbd6b1a2bd8ba81d7d078cfa6e53f579",
    "88a47b59b92abebb543e0f917547c4a8cbf795912f45e5ebc577b3ebdbee12389609b02e410c72a9d27a2a0d0ab1682c0a81adeb58d44f005231c08a08546863"
    "2802842b8e06dc1cb92be2b57e799a1950b7bfef7e7fbad5ffbaff792f483ed26e0adf0965bc417f778f297c611f7e1a7b8d92c74eb50e0bf1b5b972d191711d",
    "2e7775e4fbf0f4d32150e2a0c61fd7e7b7c1a8fb491fdd049774199911c57df9991ac411cb950ecd08715d76dff5379a1ed208dfb74bf291f1737df808fe1feb"
    "d6bc665bf902b3246160d6cb58670d83f28b8f675fb8ff0e912f28ffada716b295b9c4522db9b6b59988cfdb0b75e94d9afbef75fb2f6bddfdac8f6e82fbfc17",
    "1a063e2db62c65c5d1245bd1b5ac96c75022ff47883e8351df8c2ff6eb2378a5ad62bf0a35d92d8c09ff3923ff5e1f7e82b3fa333da1de9207e52f3fbebfe77e"
    "3d44bea0fc3a71f8e270abb82d6b222e2faee95679279f565627c7afcf29f74fda733de87ca67d71773e1ea25896014d0b8debfe4486cad78b5feefddacc4df3",
    "0d4bb2145183f287d85383fbed10f982f2dba325bd904f88d1c242265790a3d5cda4834b2fb9df8eaadf3618e7332afb1697f563be6ff177fd7cdf22183ebe6f"
    "7135e3b3feff1ff773374bd15afdb8d6b541ec1bb9390afcdced373f771b2a5f50fe59ce2847b056a9e65e65779637b73376da30e65726c73fc7f5f96d30ea66",
    "ab5f89ebf273b741eb57b28681f92faf5f87cac7eabf8f287c611f9e94c575395d4adab58d55750e57a0998bcf0bdc7fafdb7f59eb6e7eeef66ffe51db2f3aa0"
    "e8e5e76ee3c1c7cfddae66fc73cafde3fa5c3718e7332a75f44dd907e675f464f1f13a9a6dfc3fca670dd9",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 12952U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * epFieldName[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * propFieldName[4] = { "Version", "ResolvedFunctions",
    "EntryPoints", "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, epFieldName);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("p_swing"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/p_swing.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738105.04211805551));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1323502 (R2020a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_p_swing_info.c) */

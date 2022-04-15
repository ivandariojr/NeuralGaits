/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_p_hip_info.c
 *
 * Code generation for function '_coder_p_hip_info'
 *
 */

/* Include files */
#include "_coder_p_hip_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[8] = {
    "789ced59dd6e1241185db49a9aa8e546131fc00bd394a150012fa1b6855a1a04ec0fad69677787eca6b33fdd1f6cb950e20bd45b9f402f7d84be82265eeab3c8"
    "ee320536ae60a76c81ce249be1cb61e79cf9863dfb31c3450ac508c7710fdbd7cf0f1cd74a706e7be0755cb4d3dfe2fa9b1f8f74fa7bbe98b43bdc4cdf7d910e",
    "df59271634d542279617a8504117778a9a22ab50b5aaa73ae20c646ab8814417a9cb18556505557a834d2752567ba08bc0819ccfcb12128e2ab6c21992d95588"
    "7b03371f4efb1430df9921f3b110908fa80fdf5b790b244d4140d5100650e191915416045d07b22a605b4407a6ac00fd4092f598d2a3ef9052dfed407d1e2268",
    "5e56ae8aef6e209f87889acd63d4e5fb4ac9970de4ebc7f70a1b3bed25b04d03604d801814b3d58d6c0e9413f1441c024bd330af9d00a46080651e28d0c29007"
    "08d76d15b473e4ae89d306e5696e48ddfebefbfd59b7ff75fff37e987ca4dd14be9380f186fddd3d0ee08bfaf0d3c46b947e674b4d584eae2fd62ab6889b70a5",
    "aba3348067900e2e200e6bfc497d7e5b94ba9f0cd04d704113911193db2f3f43853866b6a54323465c97de77fd2d480f6984efdb25f9c8f8c5017c04ff8f7573"
    "ae79375f609e240ccc7b19bb58c3b0fce2e3d917e6bf23e40bcb7f9bd94ca1be985a6ea4d7b7b752c9252bd314dee498ff5eb7ffd2d6ddcf06e826b8cf7fa1ae",
    "e3d38a6b29abb62a58b2a616d4128602f93f42f4e994fae67cb15f1fc1eb1d15071254c576614cf8cf29f9f707f0139cd69f8313ea2d7958fef2e3fb7be6d723"
    "e40bcbaf5347cf8fb62b3ba2cae3da8b75cdaced9672f2daf4f8f579c0fdd3f65c0f3b9f595fdc9d8f87c8a6a943c34493ba3f910fe4ebc72ff77e7572e3bc61",
    "4996624a58fe9078aa33bf1d215f587e7bbcac954b293e5ecee48b65312e6da56d5c7dc9fc765cfdb645399f71d9b7b8ac1fb37d8bbfeb67fb16e1f0b17d8bab"
    "199ff6ffffa49fbb99b2eaf6935ad786b16fd4ce51e8e76ebfd9b9db48f9c2f2cf5a5e3e868dba547c55d85dd9dac95b395d5f5a9d1eff9cd4e7b745a99bae7e",
    "25aecbcedd86ad5fc91a86e6bfac7e1d291fadff3e0ae08bfaf0b4c86f88b96ada6a6cae298bb80e8d62728963fe7bddfe4b5b77b373b77ff38fdb7ed161805e"
    "76ee36197cecdced6ac63f0fb87f529feb16e57cc6a58ebe29fbc0ac8e9e2e3e5647d38dff073a170c03",
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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("p_hip"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/p_hip.m"));
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

/* End of code generation (_coder_p_hip_info.c) */

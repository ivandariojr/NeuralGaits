/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_s3_info.c
 *
 * Code generation for function '_coder_CBF_s3_info'
 *
 */

/* Include files */
#include "_coder_CBF_s3_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[7] = {
    "789ced58dd6e1241181db49a5ea8e5cac4c45b2f0c91a1a0b45e02160b290601db4a6b707677089bcecfba3f15b8d0c617a8b73e815efa087d054dbcf45d6477"
    "19281b378bac5ddbba5fb2193e0e33e7cc37bb679601894a2d0100b835ba7ebc07a07f173871d36d4072dc5e01b3e1c513e3f69a270793ef9766fa25c67cc7e3",
    "5ce6ccc47dd34d18a278d253e154658899ad8186818e0d4e0eb1e2205d95e0964a71f374f2ccce68f91434496cc8fe5cea61f9a06951a0f78ca942723a71ea61"
    "c7479ff92ecd598fb44f3d921e7c6fe315ec718a21e398404425ace7e80359d3a0ca646229b863a814968ae58e914bd3a9bed721f55df5d5e7223277abf2b7f8",
    "aefbf2b988c22d89e029df97907c055fbe597cafb2b53b5a02cbd021e13222b056686d158ab091cd6433089a9c1389f721a604125582149904491093aec5e0a8"
    "46f692381154a79539757bdbe9ef979df6e78d4ffb51f289f85ff8fa3ee3cd7bdfddf6e14b7af041f6395e7b6bf586a891abaeb69b9642866863aaa31ec013a4",
    "03f8e4518d7f519fdfa390baef04e816b8cc15aca7d5d1e6a73344d2c6483ad2d3c275c3fbae37fcf488107c5f17e413e3d702f804fe07eb665f29a75e30250a"
    "06536ec5266b18955f7c38fe1cfbef19f245e5bfc3c27aa5bb9a2f1dae5577b6f3b987e6fa507e518cfdf75ffb6fd8f7eefb01ba05eef15fa46964d0742ca56c",
    "31d95439abb03a41b2f83f22f46921f5ad7872af3e8177c72a3a3dc494d18bb1e03f09c9bf1fc02ff0b0feec5f5077c9a3f297efdfdec57e7d867c51f975fee0"
    "d1c14e73576112693fae72a3fdb25e549f5e1ebf3ef1e97fd99eeb79e7b3ecc9a7f37111d53034a41bf8a29e4f6cfaf2cde28bedaf766dec1d5654294da3f287",
    "ec3d2df6db33e48bca6fdf9478a39e97328df5cd5a43c9f4b6d72cd27a12fbed79f5dba390f3392fe7168bfa717c6ef17bfdf1b945347cf1b945b8f17f0130c7"
    "c252", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 7312U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("CBF_s3"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/CBF_s3.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738105.04304398154));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1323502 (R2020a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_CBF_s3_info.c) */

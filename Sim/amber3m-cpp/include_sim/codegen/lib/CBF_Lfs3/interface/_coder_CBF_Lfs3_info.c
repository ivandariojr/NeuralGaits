/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_Lfs3_info.c
 *
 * Code generation for function '_coder_CBF_Lfs3_info'
 *
 */

/* Include files */
#include "_coder_CBF_Lfs3_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[7] = {
    "789ced58cb6ed340149d40415d00cd062424b62c504426a4a58565529a269054511295be5018db13c5ca3c5c3faa7403fd83b2e50b60c927f4174062cbb710db"
    "993c2c460e716bdae291acc9cdc9cc3973c73ee35c90aad45200807b83ebe74700fa8f80d7eefa1d480ffb1b60ba05f1d4b0bf1588c1e8fb85a971a921dfe930",
    "5639b371dff60386281e8dd438d5196276ebd8c0c0c416274758f3908e4e704ba7b839196cb9112d4d40a3c085dccfeb5dacf69a0e0566d71a2b249381970fb7"
    "7d92ac7761c67ce424f94807f0fd8d77b0cb29868c63021155b0b94c9faa860175a61247c36d4ba770bd586a573bd672960a7def23eabb29d5e72396cebcfebc",
    "f86e4bf97c44e38e42f098ef6b44be82946f1adfaf5477065be05826245c4504d60aad6aa1081bf95c3e87a0cd3951781f624a20d11548914d900231e9380c0e"
    "7294a5c379c2f2b434a3ee603ffefda2d7ffbaf3f9204e3ed1fe17bebe64be59efbb0712be7400df2beb87e8a8d3adbda9ec6e6cef94eda261ac94c63aea213c",
    "613a80248e6bfeabfafc9e44d4fd3044b7c055ae6133ab0f0e3f932192b506d2919915ae1bdd77834da64734c1f76d4e3e317f2d844fe07fb16fee95f1f20533"
    "226130e3676cb487b1f9efe997c47f2f902faaffde97f0a503f89aa654b5626bcd3edadaa4cf480799b5e51590f8efbff6dfa8efdd4f42740b3ce0bfc830c871",
    "d3b39492c3545be7acc2ea04a9e2ff88d06744d4b7148883fa04de19aa687711d3062fc682ff2c22ff4108bfc0a3fab33ca1fe96c7e52f3fbe7f48fcfa02f9e2"
    "7a5f5eed3defbd6dee684c217b2f5f736b6fb75ed437af8f5f9f49c65fb7e77ad6f52c06e2f17a7c44b72c039916beaaf589b2946f1a9fef7c7573e39eb0224b",
    "e175a3f3f287fc6323f1db0be48bcb6f0fd779a3beaae41a2fcab58696eb6eaf39a4f52af1dbcbeab72711d77359ea16f3fa7152b7f8b3fea46e110f5f52b788"
    "36ff6f1621c438", "" };

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("CBF_Lfs3"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/CBF_Lfs3.m"));
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

/* End of code generation (_coder_CBF_Lfs3_info.c) */

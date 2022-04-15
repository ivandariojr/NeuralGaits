/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_s2_info.c
 *
 * Code generation for function '_coder_CBF_s2_info'
 *
 */

/* Include files */
#include "_coder_CBF_s2_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[8] = {
    "789ced59dd6e1241145eb49a9aa8ed95890fe085696428b4b45e02fda32986b2d87fd3ceee0e61d3d999757f9072a1c417a8b73e815efa087d054d8c57be8b2c"
    "cb94b271053bed16e84cb2194e0e33df3767986f0f67a458be109324e971ebf9f941929a49a9dd1ef99d34dde9ef48bd2de88f75fa07019bb57bd244cfb85807",
    "efb463ab9438a8eef80681063a1fa95143279038e513134916b229ae21adeda9e818957503c9178d579e65ac5c709d1b9ecbfb9cab22f558760dc9aada5d86f8"
    "a2d18e87d73e85ac7762c078c443e2311df0ef2fbf01556a204028c2001a0ab252c60bd534814e54ec6ae8d0d60d90cbae1cdac9b8d1e577c4c9ef6e283fdfa3",
    "523f2a5785773f14cff768d45530eae27de5c4cb84e2f5faf7f31b3bad2d706d0b60aa420c0a99f246260b4ac944320181432956681d200303ac2bc0800e860a"
    "40b8e212d08a91b725edd62f4e5303f20ef6ddef4fb6fbdf0f3f1f4489c7da6dc1ab87cc37e8efee4908de74c07f92dc440befdc6a039652ebb37bb2abe1065c",
    "eef228f6c1e9c7430ab1a39a7f54cf6f9393f7d33ebc995fa51ab2e27aebe5671188e3768b3ab4e24c75f97537d8c2f8b0c6f0be5d128fcd5fe883c7fcffb16f"
    "de33d38e1798610103337ec4cef7302abdf878fa45e8ef35e245a5bf8dcc62be329bced516d6b7b7d2a93967b1a1bece0afdbd69fde5cdbb9ff7e1cdfc01fd85",
    "a6894fe4b6a4acb84475744af2a488a1cafe8f307e2627bfa9801de4c7fc950e8bc32a245a2b3166f8679cf8077df0999f579fc303ea6f7954faf2e3fb7ba1d7"
    "d78817955ea78fe78fb7e51d8d2878efe53ab5f7768b597d757cf4fa2c64fcb89deb41d73319b0bbebf13dba6d9bd0b2d1a8d627d642f17afd977bbf7ab1f1de",
    "b02c4a71232a7d483e3385de5e235e547afb36474bc5b492282dae154a5aa2bab5e0e2f292d0db61d5db26e77a86a56e71593d16758bbff317758b68f044dde2"
    "6ae6e7fdff3feaf76ea8ee57184635af8da26ed48a91b8771b33bca8f4734eb7e689a224559ca6a9523a97aa3972658cea08a37a7e9b9cbcf9f257a6bae2de6d",
    "d0fc95ed61547af14be8efb5e245a5bf55bb90d577915c5a5daac9bbcbb841706353e8ef8deb2f6fde2deeddfe8d3f6cf5a2a310bee2de6d34f0c4bddbd5cc7f"
    "16327e54cf7593733dc39247df963ab0c8a3c70b4fe4d17cf3ff010ed80c15", "" };

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
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("CBF_s2"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/CBF_s2.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738105.04289351846));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1323502 (R2020a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_CBF_s2_info.c) */

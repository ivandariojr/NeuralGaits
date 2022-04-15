/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_p_cm_info.c
 *
 * Code generation for function '_coder_p_cm_info'
 *
 */

/* Include files */
#include "_coder_p_cm_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[8] = {
    "789ced59dd6e1241181db49a9aa8e546131fc00b53652854a89750db422d0d02f687d6b4b3bb43d874f6a7fb832d174a7c817aeb13e8a58fd057d0c44b7d1659"
    "9629b071053bb0053a9390e1cb61e79cf9863dfbed0c0865732100c0fde6e7e707001a31d06af7dc0e84dbfd0dd0dbbc78a8dddff1c4b4dd02333dd785da7c67",
    "ed58d4540b9f586ea022055f5c29698aac22d52a9dea1818d8d4480d4b2da422135c92155cec0e369d4859ed822e020772be2f57b17854b4156054cd8e42d21d"
    "b4f2e1b44f3ef39d19301f4f7df211f6e07b2b6f6155533054354c2052046cc49567a2ae435915892de1035356a07e202a11a55bdf21a3be9bbefa5c44d4dcac",
    "0c8befb62f9f8b489a2d10dce1fbcac897f2e5ebc5f7b21b3bcd25b04d03124d4404e652a58d541a1662d15814414bd388a09d40ac104864012ac82248809854"
    "6c153673e42e0ae89fa7b901757bfbceef675bfdafbb9ff783e4a3edbaf09df88c37e8ffeea10f5fd8839fc65ee3e43bbb5a4785f8fa42b9684ba48e563a3af2",
    "7d78fae9003e7150e34feafddb60d4fda88f6e8a8b9a848d88dc7cf8192a2211b3291d1911eabaecbeeb6d7e7a68a37cdf2ec947c7cff5e1a3f87fac9bf3996f"
    "e50bced384c1793763176b18945f7c3cfbc2fd77847c41f96f3db594ad2c24966bc9f5edad447cd15aaa8b6fd2dc7fafda7f59ebee277d7453dce3bf48d7c969",
    "b16529abb62a5ab2a666d53c41227d1fa1fa74467d739ed8ab8fe295b68a832a52a566614cf9cf19f9f7fbf0539cd59ffd133ad87bccb0fce5c7f7f7dcaf47c8"
    "17945f278e9e1f6d1777245520e517eb9a59decda7e5b5e9f1eb739feba7edbe1e743eb39eb8331f17914d5347868927757f22e3cbd78b5feef9eae4c679c2d2",
    "2c4594a0fc21f658e77e3b42bea0fcf678592be41342b4b094c915a468752b6993d24beeb7e3eab70dc6f98ccbbec565fd98ef5bfc5d3fdfb708868fef5b0c67"
    "7cd6f7ff493f773365150c936f1acfdd9a390afcdced373f771b295f50fe59cec8c7a856a9e65e657757b67632565ad71757a7c73f27f5fe6d30ea66ab5fa9eb",
    "f273b741eb57ba8681f92faf5f47cac7eabf0f7cf8c21e3c29091b52ba94b46a9b6bca02a92023175f04dc7fafda7f59eb6e7eeef66ffe71db2f3af4d1cbcfdd"
    "26838f9fbb0d67fc739feb27f5be6e30ce675ceae8ebb20fccebe8e9e2e37534dbf87f00a09d0b1d",
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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("p_cm"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/p_cm.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738105.04212962964));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1323502 (R2020a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_p_cm_info.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CBF_s1_info.c
 *
 * Code generation for function '_coder_CBF_s1_info'
 *
 */

/* Include files */
#include "_coder_CBF_s1_info.h"
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
    "a2d18e87d73e85ac7762c078c443e2311df0ef2fbf01556a204028c2001a0ab252c60bd534814e54ec6ae8d0d60d90cbae1cdab371a3cbef8893dfdd507ebe47",
    "a57e54ae0aef7e289eefd1a8ab60d4c5fbca899709c5ebf5efe737765a5be0da16c05485181432e58d4c169492896402028752acd03a400606585780011d0c15"
    "8070c525a015236f4bdaad5f9ca606e41decbbdf9f6cf7bf1f7e3e88128fb5db82570f996fd0dfdd9310bce980ff24b98916deb9d5062ca5d667f76457c30db8",
    "dce551ec83d38f8714624735ffa89edf2627efa77d7833bf4a3564c5f5d6cbcf2210c7ed167568c599eaf2eb6eb085f1618de17dbb241e9bbfd0078ff9ff63df"
    "bc67a61d2f30c3020666fc889def61547af1f1f48bd0df6bc48b4a7f1b99c57c65369dab2dac6f6fa55373ce62437d9d15fa7bd3facb9b773fefc39bf903fa0b",
    "4d139fc86d49597189eae894e449114395fd1f61fc4c4e7e53013bc88ff92b1d16875548b45662ccf0cf38f10ffae0333faf3e8707d4dff2a8f4e5c7f7f742af"
    "af112f2abd4e1fcf1f6fcb3b1a51f0decb756aefed16b3faeaf8e8f559c8f8713bd783ae67326077d7e37b74db36a165a351ad4fac85e2f5fa2ff77ef562e3bd",
    "615994e24654fa907c660abdbd46bca8f4f66d8e968a6925515a5c2b94b444756bc1c5e525a1b7c3aab74dcef50c4bdde2b27a2cea167fe72fea16d1e089bac5"
    "d5cccffbff7fd4efdd50ddaf308c6a5e1b45dda8152371ef36667851e9e79c6ecd134549aa384d53a5742e5573e4ca18d51146f5fc363979f3e5af4c75c5bddb",
    "a0f92bdbc3a8f4e297d0df6bc58b4a7fab7621abef22b9b4ba549377977183e0c6a6d0df1bd75fdebc5bdcbbfd1b7fd8ea4547217cc5bddb68e0897bb7ab99ff"
    "2c64fca89eeb26e77a86258fbe2d756091478f179ec8a3f9e6ff03c8770c13", "" };

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("CBF_s1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/CBF_s1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738105.0427430555));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1323502 (R2020a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_CBF_s1_info.c) */

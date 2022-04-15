/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_G_matrix_info.c
 *
 * Code generation for function '_coder_G_matrix_info'
 *
 */

/* Include files */
#include "_coder_G_matrix_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[7] = {
    "789ced58cb6ed340149d40415d00cd062424b62c504526b4a58565529a26d054511295be5019db1365d479b87e44e906fa0765cb17c0924fe82f80c4966fc18f"
    "4cd2588c1cead6b4c52359939b939973e68e7dc6b92057abe70000f7bcebe74700fa8f40d0ee861dc80ffa1b60bc45f1dca0bf1589c1f0fba9b171b901dff120",
    "d6057770df09038e181e8e3404231c71a77d686260615bd01e3602a443286e13865ba783753f629553d030f021fff37217ebfb2d9701ab6b8f14d2d341900fbf"
    "7d52ac776ac27c1415f9c847f09d9577b02b18865c600a11d3b035cf9eeaa60909d7a96be03d9b30b8bac79063917e81497def13eabba9d4172236e1417f5e7c",
    "b7957c21620857a378c4f735215f49c9378eefd4d636bd2d706d0b52a1230aeba5f65aa90c9b73c5b922828e1054137d8819859468d0db068a348869c7e5d0cb"
    "51810de689cbd3cc84baa3fde8f7d341ffebcee7dd34f964fb5ff8fa8af926bdef1e28f8f2117cbb4a0e50afd3adbfa96dad6c6c569db2692e54463a1a313c71",
    "3a80224e6bfeabfafc1e25d4fd3046b7c4756160ab40bcc3cfe288166c4f3ab20ad27593fb6eb4a9f4c826f9be9d914fce5f8fe193f85fec9b7fcd06f982b332"
    "617036ccd8700f53f3dfe32f99ff5e205f52ffbdafe0cb47f025435b33caed25a7b7beca9ed10eb2eaf30b20f3df7fedbf49dfbb9fc4e89678c47f9169d2c356",
    "60291597eb0e11bcc61b14e9f2ff88d46726d4371389a3fa24de19a8d8eb226e782fc692ff2421ff6e0cbfc493fab33aa1e196a7e52f3fbe7fc8fcfa02f9d27a"
    "5f5edc7fbeffb6b569708d6ebf7c2decedad4699ac5e1fbf3e518cbf6ecff5a4eb998ec4a3f58408b16d135936beaaf589aa926f1c3fdbf9eae7c63f616596e2",
    "eb46e7e50f738fcdcc6f2f902f2dbf3d5816cdc6a2566cbea8d69b46b1bbb1e4d2f6abcc6f2fabdf1e255ccf65a95b9cd58fb3bac59ff567758b74f8b2ba45b2"
    "f97f03819cc4f1", "" };

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
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("G_matrix"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/noel/amber3m-cpp/include_sim/G_matrix.m"));
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

/* End of code generation (_coder_G_matrix_info.c) */

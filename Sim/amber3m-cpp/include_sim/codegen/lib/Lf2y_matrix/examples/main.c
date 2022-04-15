/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "Lf2y_matrix.h"
#include "Lf2y_matrix_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_10x1_real_T(double result[10]);
static void argInit_1x2_real_T(double result[2]);
static void argInit_1x5_real_T(double result[5]);
static void argInit_20x1_real_T(double result[20]);
static double argInit_real_T(void);
static void main_Lf2y_matrix(void);

/* Function Definitions */
static void argInit_10x1_real_T(double result[10])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 10; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static void argInit_1x2_real_T(double result[2])
{
  double result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;
}

static void argInit_1x5_real_T(double result[5])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_20x1_real_T(double result[20])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 20; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_Lf2y_matrix(void)
{
  double dv[10];
  double dv1[5];
  double dv2[2];
  double dv3[20];
  double Lf2y[4];

  /* Initialize function 'Lf2y_matrix' input arguments. */
  /* Initialize function input argument 'in1'. */
  /* Initialize function input argument 'in2'. */
  /* Initialize function input argument 'in3'. */
  /* Initialize function input argument 'in4'. */
  /* Call the entry-point 'Lf2y_matrix'. */
  argInit_10x1_real_T(dv);
  argInit_1x5_real_T(dv1);
  argInit_1x2_real_T(dv2);
  argInit_20x1_real_T(dv3);
  Lf2y_matrix(dv, dv1, dv2, dv3, Lf2y);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_Lf2y_matrix();

  /* Terminate the application.
     You do not need to do this more than one time. */
  Lf2y_matrix_terminate();
  return 0;
}

/* End of code generation (main.c) */

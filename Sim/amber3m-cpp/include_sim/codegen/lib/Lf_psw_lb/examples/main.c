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
#include "Lf_psw_lb.h"
#include "Lf_psw_lb_terminate.h"

/* Function Declarations */
static void argInit_10x1_real_T(double result[10]);

static double argInit_real_T(void);

static void main_Lf_psw_lb(void);

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

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_Lf_psw_lb(void)
{
  double dv[10];
  double h_tmp;
  /* Initialize function 'Lf_psw_lb' input arguments. */
  /* Initialize function input argument 'in1'. */
  h_tmp = argInit_real_T();
  /* Call the entry-point 'Lf_psw_lb'. */
  argInit_10x1_real_T(dv);
  h_tmp = Lf_psw_lb(dv, h_tmp, h_tmp, h_tmp, h_tmp);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_Lf_psw_lb();
  /* Terminate the application.
You do not need to do this more than one time. */
  Lf_psw_lb_terminate();
  return 0;
}

/* End of code generation (main.c) */

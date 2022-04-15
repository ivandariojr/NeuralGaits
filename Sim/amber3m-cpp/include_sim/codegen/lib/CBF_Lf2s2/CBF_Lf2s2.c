/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CBF_Lf2s2.c
 *
 * Code generation for function 'CBF_Lf2s2'
 *
 */

/* Include files */
#include "CBF_Lf2s2.h"
#include "CBF_Lf2s2_data.h"
#include "CBF_Lf2s2_initialize.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_powd_snf(double u0, double u1);

/* Function Definitions */
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d;
  double d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

double CBF_Lf2s2(const double in1[10], const double in2[5], const double in3[2],
                 double ldes, double r, double m1, double a)
{
  double t2;
  double t3;
  double t4;
  double t5;
  double t7;
  double t9;
  double t15;
  double t16;
  double t22;
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t29;
  double t45;
  double t49;
  double t54;
  double t91;
  double t93;
  double t135;
  double t136_tmp;
  double t136;
  double t137_tmp;
  double t142;
  double t169_tmp;
  double t169;
  double t285;
  double t43;
  double t47;
  double t48;
  double t50;
  double t56;
  double t57;
  double t59;
  double t61;
  double t70;
  double t71;
  double t73;
  double t81;
  double t97;
  double t99;
  double t138;
  double t168;
  double t180_tmp;
  double t180;
  double t182_tmp;
  double t182;
  double t307_tmp;
  double t307;
  double t315_tmp;
  double t315;
  double t337_tmp;
  double t337;
  double t366_tmp;
  double b_t366_tmp;
  double t366;
  double t55;
  double t58;
  double t62;
  double t64;
  double t68;
  double t72;
  double t79;
  double t96;
  double t108;
  double t110;
  double t114;
  double t118;
  double t157;
  double t160;
  double t166;
  double t224_tmp;
  double b_t224_tmp;
  double t224;
  double t253_tmp_tmp;
  double t797;
  double t253;
  double t294;
  double t322_tmp;
  double t322;
  double t752;
  double t353;
  double t378_tmp;
  double t378;
  double t409_tmp;
  double t409;
  double t411;
  double t413_tmp;
  double t413;
  double t424_tmp;
  double t424;
  double t438_tmp;
  double t438;
  double t443_tmp;
  double b_t443_tmp;
  double t443;
  double t447;
  double t461_tmp;
  double b_t461_tmp;
  double t461;
  double t462_tmp;
  double t462;
  double t482;
  double t521_tmp;
  double b_t521_tmp;
  double t521;
  double t530_tmp;
  double b_t530_tmp;
  double t530;
  double t532;
  double t533_tmp;
  double b_t533_tmp;
  double t533;
  double t541_tmp;
  double t541;
  double t751;
  double t568_tmp;
  double t568;
  double t571_tmp;
  double t571;
  double t750;
  double t609_tmp;
  double t609;
  double t627_tmp;
  double t627;
  double t634_tmp;
  double t634;
  double t667_tmp;
  double t667;
  double t67;
  double t129;
  double t147;
  double t149;
  double t206_tmp;
  double t206;
  double t234_tmp;
  double t798;
  double t234;
  double t124;
  double t244;
  double t247_tmp;
  double t155;
  double t247;
  double t317;
  double t339;
  double t341;
  double t359_tmp;
  double t359;
  double t365;
  double t387_tmp;
  double t387;
  double t406;
  double t454;
  double t471_tmp;
  double t471;
  double t477_tmp;
  double t477;
  double t481_tmp_tmp;
  double t481_tmp;
  double t481;
  double t492_tmp;
  double t492;
  double t519;
  double t551_tmp;
  double t551;
  double t753;
  double t569_tmp;
  double t569;
  double t597_tmp;
  double t597;
  double t793;
  double t602;
  double t617_tmp;
  double t617;
  double t626_tmp;
  double t626;
  double t670_tmp;
  double t670;
  double t695_tmp;
  double t695;
  double t702_tmp;
  double b_t702_tmp;
  double t702;
  double t715_tmp_tmp;
  double t776;
  double t715_tmp;
  double t715;
  double t94;
  double t95;
  double t113;
  double t192;
  double t746;
  double t235;
  double t283;
  double t527_tmp;
  double t527;
  double t594_tmp;
  double t594;
  double t727;
  double t102;
  double t103;
  double t257;
  double t258;
  double t260;
  double t297;
  double t319;
  double t321;
  double t728;
  double t730;
  double t734;
  double t785_tmp;
  double b_t785_tmp;
  double c_t785_tmp;
  double d_t785_tmp;
  double e_t785_tmp;
  double t785;
  double t786;
  double t787_tmp;
  double b_t787_tmp;
  double c_t787_tmp;
  double t790;
  double d_t787_tmp;
  double e_t787_tmp;
  double f_t787_tmp;
  double t787;
  double t788;
  double t794;
  double t795;
  double t123;
  double t350;
  double t351;
  double t352;
  double t735;
  double t736;
  double t791;
  (void)ldes;
  if (!isInitialized_CBF_Lf2s2) {
    CBF_Lf2s2_initialize();
  }

  /* CBF_LF2S2 */
  /*     LF2S2 = CBF_LF2S2(IN1,IN2,IN3,LDES,R,M1,A) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.3. */
  /*     09-Nov-2020 22:01:51 */
  t2 = cos(in1[4]);
  t3 = cos(in1[2]);
  t4 = cos(in1[1]);
  t5 = sin(in1[4]);
  t7 = sin(in1[2]);
  t9 = a * r;
  t15 = in1[0] + in1[1];
  t16 = in1[2] + in1[1];
  t22 = m1 * m1;
  t23 = t2 * t2;
  t24 = t3 * t3;
  t25 = t4 * t4;
  t26 = cos(t16);
  t27 = in1[2] + t15;
  t29 = sin(t16);
  t45 = in1[3] + -in1[2];
  t49 = t16 + -in1[3];
  t54 = ((in1[5] + in1[7]) + in1[6]) + -in1[8];
  t16 = (in1[3] + in1[4]) - t16;
  t91 = in1[5] * t7 * 1.506081824;
  t93 = in1[6] * t7 * 1.506081824;
  t135 = in1[8] * t5 * 0.05952683917824;
  t136_tmp = in1[9] * t5;
  t136 = t136_tmp * 0.05952683917824;
  t137_tmp = in1[7] * t5;
  t142 = in1[9] * in1[7] * t5 * -0.05952683917824;
  t169_tmp = t3 * t4;
  t169 = t169_tmp * 4.295141349249055E+65;
  t285 = t3 * 4.9553499115050528E+100;
  t43 = t26 * t26;
  t47 = cos(t45);
  t48 = in1[4] + t45;
  t50 = sin(t45);
  t56 = cos(t49);
  t57 = t27 + -in1[3];
  t59 = sin(t49);
  t61 = 1.0 / (-in3[1] + in3[0]);
  t70 = -in1[9] + t54;
  t71 = cos(t16);
  t73 = sin(t16);
  t81 = (t9 - 1.0) / t9;
  t97 = t29 * 3.459096394;
  t99 = in1[5] * t29 * 1.729548197;
  t138 = in1[9] * t135;
  t168 = t26 * 4.1712330178969239E+65;
  t180_tmp = t23 * t26;
  t180 = t180_tmp * 1.2979542310402759E+65;
  t182_tmp = t169_tmp * t23;
  t182 = t182_tmp * 1.3365105385516521E+65;
  t307_tmp = t3 * t23;
  t307 = t307_tmp * 1.5419463157121509E+100;
  t315_tmp = t4 * t26;
  t315 = t315_tmp * 4.5595182205090542E+100;
  t337_tmp = t23 * t25;
  t337 = t337_tmp * 1.5126819298048749E+100;
  t366_tmp = t4 * t23;
  b_t366_tmp = t366_tmp * t26;
  t366 = b_t366_tmp * 1.4187761605317239E+100;
  t55 = cos(t48);
  t58 = sin(t48);
  t62 = t61 * t61;
  t64 = t47 * t47;
  t68 = t56 * t56;
  t72 = -in1[4] + t57;
  t79 = t71 * t71;
  t96 = sin(t27) * 36.3549771;
  t108 = in1[5] * t50 * 0.3487631994496;
  t110 = in1[6] * t50 * 0.3487631994496;
  t114 = t59 * 0.8010225648776;
  t118 = in1[5] * t59 * 0.4005112824388;
  t157 = t73 * 0.13671838506144;
  t160 = in1[5] * t73 * 0.06835919253072;
  t166 = t136_tmp * t70 * -0.05952683917824;
  t224_tmp = t3 * t47;
  b_t224_tmp = t224_tmp * t56;
  t224 = b_t224_tmp * 6.3517129173536425E+64;
  t16 = t2 * t3;
  t253_tmp_tmp = t16 * t47;
  t797 = t253_tmp_tmp * t71;
  t253 = t797 * 1.45141210632265E+64;
  t294 = t43 * 1.7105871703254159E+98;
  t322_tmp = t23 * t43;
  t322 = t322_tmp * 5.3227998669959494E+97;
  t752 = t2 * t47;
  t353 = t224_tmp * 6.7479114227517073E+100;
  t378_tmp = t4 * t56;
  t378 = t378_tmp * 1.6109409497405221E+100;
  t409_tmp = t26 * t56;
  t409 = t409_tmp * 6.0297734184381112E+100;
  t49 = t2 * t4;
  t411 = t49 * t56 * 2.156737712244608E+100;
  t413_tmp = t169_tmp * t56;
  t413 = t413_tmp * 6.2088905187066541E+100;
  t424_tmp = t43 * t47;
  t424 = t424_tmp * 9.0991388351019223E+99;
  t438_tmp = t315_tmp * t47;
  t438 = t438_tmp * 6.2088905187066541E+100;
  t443_tmp = t3 * t26;
  b_t443_tmp = t443_tmp * t56;
  t443 = b_t443_tmp * 9.0991388351019223E+99;
  t447 = t4 * t71 * 1.5838071014798171E+100;
  t461_tmp = t2 * t43;
  b_t461_tmp = t461_tmp * t47;
  t461 = b_t461_tmp * 1.2181983379201291E+100;
  t462_tmp = t49 * t71;
  t462 = t462_tmp * 3.6811159878404221E+99;
  t27 = t16 * t26;
  t482 = t27 * t56 * 1.2181983379201291E+100;
  t521_tmp = t4 * t47;
  b_t521_tmp = t521_tmp * t56;
  t521 = b_t521_tmp * 1.4377920826275229E+100;
  t530_tmp = t2 * t26;
  b_t530_tmp = t530_tmp * t71;
  t530 = b_t530_tmp * 1.3778466142562791E+100;
  t532 = t443_tmp * t71 * 8.9458776913619762E+99;
  t533_tmp = t16 * t4;
  b_t533_tmp = t533_tmp * t71;
  t533 = b_t533_tmp * 1.4187761605317239E+100;
  t9 = t26 * t47;
  t541_tmp = t9 * t56;
  t541 = t541_tmp * 6.7426769978548048E+99;
  t751 = t2 * t56;
  t568_tmp = t751 * t71;
  t568 = t568_tmp * 2.046764220388046E+97;
  t571_tmp = t27 * t71;
  t571 = t571_tmp * 2.0792186980452931E+99;
  t750 = t49 * t47;
  t609_tmp = t750 * t71;
  t609 = t609_tmp * 3.2854583672995942E+99;
  t627_tmp = t16 * t56 * t71;
  t627 = t627_tmp * 3.0815004239162308E+99;
  t45 = t530_tmp * t47;
  t634_tmp = t45 * t71;
  t634 = t634_tmp * 1.5407502119581159E+99;
  t667_tmp = t47 * t56;
  t667 = t667_tmp * t71 * 2.3421552882827978E+99;
  t67 = t55 * t55;
  t129 = sin(t57) * 8.41871797884;
  t48 = t58 * 0.11905367835648;
  t147 = in1[5] * t58 * 0.05952683917824;
  t149 = in1[6] * t58 * 0.05952683917824;
  t206_tmp = t26 * t64;
  t206 = t206_tmp * 6.3517129173536425E+64;
  t234_tmp = t16 * t55;
  t798 = t234_tmp * t56;
  t234 = t798 * 1.45141210632265E+64;
  t124 = t45 * t55;
  t244 = t124 * 2.9028242126453008E+64;
  t247_tmp = t3 * t55;
  t155 = t247_tmp * t71;
  t247 = t155 * 1.06584903120889E+64;
  t317 = t68 * 4.478555291354996E+97;
  t339 = t55 * 1.7213043134374949E+100;
  t341 = t64 * 7.81306546529768E+99;
  t359_tmp = t2 * t55;
  t359 = t359_tmp * 4.0006897444853951E+99;
  t365 = t79 * 7.5152386145546549E+96;
  t387_tmp = t3 * t68;
  t387 = t387_tmp * 6.7426769978548048E+99;
  t406 = t234_tmp * 1.5419463157121509E+100;
  t454 = t43 * t55 * 8.9458776913619762E+99;
  t471_tmp = t461_tmp * t55;
  t471 = t471_tmp * 2.0792186980452931E+99;
  t477_tmp = t3 * t79;
  t477 = t477_tmp * 1.131454749203659E+99;
  t481_tmp_tmp = t49 * t26;
  t481_tmp = t481_tmp_tmp * t55;
  t481 = t481_tmp * 1.4187761605317239E+100;
  t492_tmp = t752 * t55;
  t492 = t492_tmp * 3.5706833578206228E+99;
  t519 = t55 * t68 * 2.3421552882827978E+99;
  t551_tmp = t47 * t79;
  t551 = t551_tmp * 3.9975863679454022E+98;
  t753 = t49 * t55;
  t569_tmp = t753 * t56;
  t569 = t569_tmp * 3.2854583672995942E+99;
  t597_tmp = t64 * t79;
  t597 = t597_tmp * 1.783956770847936E+98;
  t793 = t530_tmp * t55 * t56;
  t602 = t793 * 1.5407502119581159E+99;
  t617_tmp = t224_tmp * t79;
  t617 = t617_tmp * 1.5407502119581159E+99;
  t626_tmp = t26 * t55 * t71;
  t626 = t626_tmp * 1.131454749203659E+99;
  t670_tmp = t55 * t56 * t71;
  t670 = t670_tmp * 3.9975863679454022E+98;
  t695_tmp = t247_tmp * t56 * t71;
  t695 = t695_tmp * 1.5407502119581159E+99;
  t702_tmp = t9 * t55;
  b_t702_tmp = t702_tmp * t71;
  t702 = b_t702_tmp * 1.5407502119581159E+99;
  t715_tmp_tmp = t47 * t55;
  t776 = t715_tmp_tmp * t56;
  t715_tmp = t776 * t71;
  t715 = t715_tmp * 3.5679135416958708E+98;
  t94 = sin(t57 + 4.71238898038469) * 0.4064;
  t95 = cos(t57 + 4.71238898038469) * 0.4064;
  t113 = m1 * (t61 * (((((in2[3] * in1[3] + in2[4] * in1[4]) + in2[0] * in1[0])
                        + in2[2] * in1[2]) + in2[1] * in1[1]) + -in3[1]) - 1.0);
  t192 = sin(t72) * 1.436905246896;
  t746 = t26 * t67;
  t49 = t746 * 1.06584903120889E+64;
  t235 = t50 * 0.6975263988992 + t48;
  t283 = -(t5 * 0.11905367835648) + t48;
  t527_tmp = t67 * t68;
  t527 = t527_tmp * 1.783956770847936E+98;
  t594_tmp = t409_tmp * t67;
  t594 = t594_tmp * 1.5407502119581159E+99;
  t727 = ((t97 + sin(in1[1]) * 7.3760932192376) + -t114) + t157;
  t102 = cos(t72 + 4.71238898038469) * 0.4667;
  t103 = sin(t72 + 4.71238898038469) * 0.4667;
  t257 = in1[8] * t235 / 2.0;
  t258 = in1[5] * t235 / 2.0;
  t260 = in1[6] * t235 / 2.0;
  t297 = t7 * 3.012163648 + t235;
  t319 = in1[9] * t283 / 2.0;
  t321 = in1[6] * t283 / 2.0;
  t728 = in1[5] * t727 / 2.0;
  t730 = t157 + t283;
  t734 = (-t114 + t157) + t235;
  t785_tmp = t307_tmp * t26;
  b_t785_tmp = t359_tmp * t56;
  c_t785_tmp = t752 * t71;
  d_t785_tmp = t55 * t71;
  e_t785_tmp = t23 * t24;
  t785 = (((((((((((((-(t4 * 1.664297110460606E+69) + t23 *
                      4.3795417961373631E+68) + t24 * 8.1859187141425319E+68) +
                    t366_tmp * 5.178760014034365E+68) + t443_tmp *
                   9.4005124603600386E+68) + t67 * 3.5963751794318893E+67) +
                 -(e_t785_tmp * 2.5471959452723208E+68)) + t64 *
                2.1431874509412249E+68) + -(t785_tmp * 2.9251386507347238E+68))
              + t667_tmp * 2.4611849984110969E+68) + -(t492_tmp *
              9.7946750833659731E+67)) + -(b_t785_tmp * 5.6239848196443146E+67))
           + d_t785_tmp * 4.1299908864194451E+67) + -(c_t785_tmp *
           5.6239848196443146E+67)) - 1.407452505368112E+69;
  t786 = (((((((((((((((((t4 * 3.566096229827739E+65 + t169) + -t168) +
                        -(t366_tmp * 1.1096550276482461E+65)) + -(t443_tmp *
    2.0142516521020009E+65)) + t180) + -t182) + t785_tmp * 6.26770655824882E+64)
                   + t206) + t49) + -(t667_tmp * 5.27359116865459E+64)) +
                b_t785_tmp * 1.205053528957428E+64) + -t224) + t234) +
             c_t785_tmp * 1.205053528957428E+64) + -(d_t785_tmp *
             8.84934837458634E+63)) + -t244) + -t247) + t253;
  t787_tmp = t2 * t24;
  t72 = t24 * t56;
  b_t787_tmp = t443_tmp * t47;
  t9 = t2 * t71;
  c_t787_tmp = t27 * t55;
  t48 = t56 * t67;
  t136_tmp = t787_tmp * t71;
  t790 = t715_tmp_tmp * t71;
  t57 = t4 * t55;
  d_t787_tmp = t443_tmp * t55;
  e_t787_tmp = t787_tmp * t56;
  f_t787_tmp = t27 * t47;
  t16 = t24 * t71;
  t45 = t64 * t71;
  t787 = ((((((((((((((((((-(t56 * 2.9475088175827819E+68) + t521_tmp *
    3.0350658774893788E+68) + t750 * 4.0633649782026259E+68) + -(t57 *
    2.983944812502915E+68)) + -(t751 * 3.94614304458412E+68)) + t72 *
                       1.7143077651235159E+68) + t71 * 2.8978625179985142E+68) +
                     -(t753 * 6.935343922801539E+67)) + t9 *
                    6.7352697406147925E+67) + d_t787_tmp *
                   1.6854328601938829E+68) + -(b_t787_tmp *
    1.7143077651235159E+68)) + e_t787_tmp * 2.2951258443279339E+68) + c_t787_tmp
                * 3.9173165989055133E+67) + -(f_t787_tmp *
    2.2951258443279339E+68)) + t48 * 7.531584555983923E+66) + -(t16 *
              1.6854328601938829E+68)) + -(t136_tmp * 3.9173165989055133E+67)) +
           -(t45 * 4.412697806454926E+67)) + t776 * 4.412697806454926E+67) +
    -(t790 * 7.531584555983923E+66);
  t788 = (((((((((((((((((((t169 + -t168) + t180) + -(t56 *
    4.716014108132451E+65)) + t521_tmp * 4.8561054039830056E+65) + -t182) + t72 *
                       2.742892424197626E+65) + -(t753 * 1.1096550276482461E+65))
                     + t206) + t49) + -(b_t787_tmp * 2.742892424197626E+65)) +
                  t9 * 1.0776431584983669E+65) + c_t787_tmp *
                 6.26770655824882E+64) + t48 * 1.205053528957428E+64) + -t224) +
              t234) + -(t136_tmp * 6.26770655824882E+64)) + -t244) + -t247) +
          t253) + -(t790 * 1.205053528957428E+64);
  t752 = t47 * 1.7507937695762331E+100 + t752 * 2.3439735328698211E+100;
  t794 = (((((((((((((((((((((((((((((((((((((t752 + t521_tmp *
    1.402799232857399E+100) + -t339) + -(t56 * 1.362330596779613E+100)) + -t359)
    + t72 * 7.9234840852483846E+99) + t750 * 1.8780762936708988E+100) + -(t57 *
    1.3791712150019229E+100)) + -(t751 * 1.8238966332642771E+100)) + -t378) +
    -(t753 * 3.2054971876116289E+99)) + t71 * 1.3393842115009421E+100) +
    d_t787_tmp * 7.7900250562877808E+99) + t9 * 3.113023442192204E+99) + -t411)
    + -(b_t787_tmp * 7.9234840852483846E+99)) + t443) + -t424) + t447) + t454) +
    e_t787_tmp * 1.060800952497837E+100) + c_t787_tmp * 1.810573128102865E+99) +
    t462) + t471) + t482) + -t461) + t48 * 3.4810779942854331E+98) +
                    -(f_t787_tmp * 1.060800952497837E+100)) + -(t16 *
    7.7900250562877808E+99)) + t519) + -(t136_tmp * 1.810573128102865E+99)) +
                -t532) + -t551) + -t571) + -(t45 * 2.0395369812687571E+99)) +
            t776 * 2.0395369812687571E+99) + -(t790 * 3.4810779942854331E+98)) +
          t670) + -t667;
  t795 = ((((((((((((((((((((((((((((((((((((((((t3 * 2.477674955752527E+97 +
    t169_tmp * 1.9852027049655879E+97) + -(t26 * 1.9279326096261111E+97)) +
    -(t307_tmp * 7.7097315785607553E+96)) + t47 * 2.8012700313219719E+97) +
    t180_tmp * 5.9991093211244009E+96) + -(t315_tmp * 2.2797591102545272E+97)) +
    -(t182_tmp * 6.1773155307487974E+96)) + b_t366_tmp * 7.0938808026586212E+96)
    + t521_tmp * 2.2444787725718392E+97) + -(t56 * 2.1797289548473819E+97)) +
    -(t359_tmp * 6.4011035911766324E+96)) + -(t378_tmp * 2.5775055195848361E+97))
    + t72 * 1.267757453639742E+97) + -(t387_tmp * 3.3713384989274018E+96)) +
    t206_tmp * 2.9357445167432959E+96) + -(t753 * 5.1287955001786067E+96)) +
    t746 * 4.9263253704346168E+95) + t9 * 4.9808375075075263E+96) + b_t443_tmp *
    1.4558622136163079E+97) + -(t424_tmp * 1.4558622136163079E+97)) +
    -(b_t787_tmp * 1.267757453639742E+97)) + c_t787_tmp * 2.8969170049645831E+96)
    + t462_tmp * 5.8897855805446754E+96) + t471_tmp * 3.3267499168724679E+96) +
    -(t477_tmp * 5.6572737460182967E+95)) + t48 * 5.5697247908566932E+95) +
                       -(b_t224_tmp * 2.9357445167432959E+96)) + t541_tmp *
                      3.3713384989274018E+96) + -(t136_tmp *
    2.8969170049645831E+96)) + t798 * 6.7083874666785744E+95) + -(t571_tmp *
    3.3267499168724679E+96)) + -(t551_tmp * 6.3961381887126438E+95)) + -(t124 *
    1.3416774933357149E+96)) + -(t155 * 4.9263253704346168E+95)) + t797 *
               6.7083874666785744E+95) + -(t793 * 7.7037510597905785E+95)) +
             t626_tmp * 5.6572737460182967E+95) + t627_tmp *
            1.5407502119581159E+96) + -(t634_tmp * 7.7037510597905785E+95)) +
          -(t790 * 5.5697247908566932E+95)) + t670_tmp * 6.3961381887126438E+95;
  t123 = exp(-t113);
  t350 = in1[5] * t297 / 2.0;
  t351 = in1[7] * t297 / 2.0;
  t352 = in1[6] * t297 / 2.0;
  t244 = in1[9] * t730 / 2.0;
  t735 = in1[8] * t734 / 2.0;
  t736 = in1[5] * t734 / 2.0;
  t791 = (((((((((((((((((((((((((((((((((((-(t4 * 2.6371840387918691E+98) +
    -(t3 * 3.9642799292040432E+98)) + t26 * 3.0846921754017772E+98) + t23 *
    1.024176574588261E+98) + -(t169_tmp * 3.17632432794494E+98)) + t294) +
    t366_tmp * 8.20607280028577E+97) + t307_tmp * 1.233557052569721E+98) +
    t443_tmp * 1.4895706578535441E+98) + t315_tmp * 3.6476145764072429E+98) +
    t182_tmp * 9.8837048491980743E+97) + t317) + -(t180_tmp *
    9.5985749137990415E+97)) + -(t785_tmp * 4.6350672079433329E+97)) + -t322) +
    t387_tmp * 5.3941415982838437E+97) + -(b_t366_tmp * 1.1350209284253789E+98))
    + t365) + -(t206_tmp * 4.6971912267892741E+97)) + -(t746 *
    7.8821205926953869E+96)) + t667_tmp * 3.899903300635676E+97) + t477_tmp *
                        9.0516379936292747E+96) + b_t224_tmp *
                       4.6971912267892741E+97) + d_t785_tmp *
                      6.5442317826334076E+96) + -(b_t785_tmp *
    8.9115596653707073E+96)) + -(t541_tmp * 5.3941415982838437E+97)) + t124 *
                   2.1466839893371438E+97) + t155 * 7.8821205926953869E+96) +
                 -(t798 * 1.0733419946685719E+97)) + -(c_t785_tmp *
    8.9115596653707073E+96)) + t793 * 1.2326001695664929E+97) + -t568) + -(t797 *
              1.0733419946685719E+97)) + t634_tmp * 1.2326001695664929E+97) +
           -(t626_tmp * 9.0516379936292747E+96)) + -(t627_tmp *
           2.4652003391329851E+97)) - 3.2913942895006169E+98;
  t790 = t533_tmp * t56;
  t627_tmp = t315_tmp * t55;
  t541_tmp = t530_tmp * t56;
  t9 = t481_tmp_tmp * t47;
  t48 = t26 * t71;
  t27 = t169_tmp * t71;
  t136_tmp = t247_tmp * t68;
  t49 = t206_tmp * t71;
  t45 = t702_tmp * t56;
  t16 = b_t224_tmp * t71;
  t454 = (((((((((((((((((((((((((((((((((((((((((t752 + -t339) + t224_tmp *
    2.1087223196099079E+100) + -t359) + t253_tmp_tmp * 2.823170490567743E+100) +
    -(t247_tmp * 2.0732041018543329E+100)) + -t378) + t409_tmp *
    1.88430419326191E+100) + -(t234_tmp * 4.8185822366004722E+99)) + -t411) +
    -(t413_tmp * 1.9402782870958291E+100)) + t627_tmp * 1.9075972526767341E+100)
    + t541_tmp * 2.5227181142817188E+100) + t443) + -t424) + t447) + t454) +
    -(t438_tmp * 1.9402782870958291E+100)) + t481_tmp * 4.433675501661638E+99) +
    t462) + -(t790 * 2.5976565774822351E+100)) + t471) + t482) + -t461) + t27 *
    1.9075972526767341E+100) + -(t9 * 2.5976565774822351E+100)) + b_t533_tmp *
    4.433675501661638E+99) + -(t48 * 1.852565957254429E+100)) + t519) +
                      -(b_t530_tmp * 4.30577066955087E+99)) + -t532) + t136_tmp *
                    2.8209805279292E+99) + -t551) + -t571) + -(t594_tmp *
    4.8148444123691118E+98)) + -(t617_tmp * 4.8148444123691118E+98)) + t49 *
               2.8209805279292E+99) + t670) + -t667) + -(t45 *
             2.8209805279292E+99)) + t695_tmp * 4.8148444123691118E+98) +
          b_t702_tmp * 4.8148444123691118E+98) + -(t16 * 2.8209805279292E+99);
  t471 = t57 * t71;
  t702_tmp = t169_tmp * t26;
  t3 = t43 * t67;
  t206_tmp = t24 * t79;
  t670 = d_t787_tmp * t71;
  t339 = t2 * t25;
  t359 = t56 * t71;
  t315_tmp = t57 * t56;
  b_t366_tmp = t521_tmp * t71;
  t530_tmp = t424_tmp * t55;
  t307_tmp = t72 * t71;
  t180_tmp = t533_tmp * t26;
  t634_tmp = d_t787_tmp * t56;
  t481_tmp_tmp = b_t787_tmp * t71;
  t797 = ((((((((((((((((((((((((((((((((((((((((((((((-(t2 *
    3.3538321486300018E+102) + t24 * 1.456992417750339E+102) + t25 *
    2.373456356808413E+102) + t43 * 1.301933828265091E+102) + t787_tmp *
    1.9506304649607119E+102) + t339 * 3.1775980577810222E+102) + t461_tmp *
    1.74303706583323E+102) + t67 * 6.4011035911766322E+100) + -(t224_tmp *
    3.3739557113758533E+101)) + t247_tmp * 3.3171265629669321E+101) + -(t702_tmp
    * 2.6812167029627671E+102)) + -(t253_tmp_tmp * 4.5170727849083889E+101)) +
    t413_tmp * 3.1044452593533271E+101) + -(t180_tmp * 3.5896295136773182E+102))
    + t234_tmp * 7.7097315785607555E+100) + t79 * 5.7198741750830758E+100) +
    -(t409_tmp * 3.0148867092190553E+101)) + t438_tmp * 3.1044452593533271E+101)
    + t790 * 4.1562505239715749E+101) + -(t627_tmp * 3.0521556042827752E+101)) +
    -(t541_tmp * 4.0363489828507507E+101)) + t9 * 4.1562505239715749E+101) +
    t715_tmp_tmp * 3.7503576525917138E+101) + -(t3 * 3.3267499168724678E+100)) +
    t48 * 2.964105531607087E+101) + b_t530_tmp * 6.8892330712813928E+100) +
    -(t481_tmp * 7.09388080265862E+100)) + -(t27 * 3.0521556042827752E+101)) +
    -(t206_tmp * 3.3267499168724678E+100)) + -(t315_tmp *
    3.4507803395913723E+101)) + -(b_t533_tmp * 7.09388080265862E+100)) + t359 *
    3.3512305462379441E+101) + t594_tmp * 7.7037510597905788E+99) + -(t136_tmp *
    4.51356884468672E+100)) + t617_tmp * 7.7037510597905788E+99) + -(b_t366_tmp *
    3.4507803395913723E+101)) + t634_tmp * 1.9491173406722068E+101) + -(t530_tmp
    * 1.9491173406722068E+101)) + -(t471 * 1.1779571161089351E+101)) +
                 t481_tmp_tmp * 1.9491173406722068E+101) + -(t307_tmp *
    1.9491173406722068E+101)) + t670 * 6.6534998337449356E+100) + -(t49 *
    4.51356884468672E+100)) + t45 * 4.51356884468672E+100) + t16 *
            4.51356884468672E+100) + -(t695_tmp * 7.7037510597905788E+99)) +
          -(b_t702_tmp * 7.7037510597905788E+99)) - 2.5050916094759448E+102;
  t798 = ((((((((((((((((((((((((((((((((((((((((((((((((-t285 + t23 *
    3.193154826116699E+100) + t25 * 9.7226060215097672E+100) + t307) + t315) +
    -(t47 * 5.6025400626439448E+100)) + t64 * 1.562613093059536E+100) + t67 *
    2.622142519762599E+99) + -(t337_tmp * 3.02536385960975E+100)) + t68 *
    1.3963139557619591E+100) + -t353) + t378_tmp * 5.1550110391696713E+100) +
    t359_tmp * 1.2802207182353259E+100) + t387) + -t366) + t406) + t413) + t79 *
    2.3430842929727389E+99) + t424_tmp * 2.9117244272326148E+100) + -t409) +
    t438) + -(b_t443_tmp * 2.9117244272326148E+100)) + t477) + -(t471_tmp *
    6.6534998337449362E+99)) + -t481) + -(t462_tmp * 1.1779571161089351E+100)) +
    -(t492_tmp * 7.1413667156412446E+99)) + t530) + -(b_t521_tmp *
    2.875584165255047E+100)) + -(t527_tmp * 3.5679135416958708E+98)) + -t533) +
    -t541) + t569_tmp * 6.5709167345991884E+99) + t571_tmp *
    6.6534998337449362E+99) + t551_tmp * 1.279227637742529E+99) + t594) + t602)
                     + t609_tmp * 6.5709167345991884E+99) + -(t597_tmp *
    3.5679135416958708E+98)) + t617) + -(t471 * 4.8253733072899684E+99)) +
                 -(t568_tmp * 6.3813557255813289E+99)) + t634) + -t626) + -t627)
             + -(t670_tmp * 1.279227637742529E+99)) + -t695) + -t702) + t715_tmp
          * 7.1358270833917428E+98) - 1.0261835528113919E+101;
  t124 = exp(-(t113 * 2.0));
  t45 = t81 - t123;
  t155 = 1.0 / (t45 * t45);
  t387_tmp = t24 * t68;
  t477_tmp = t43 * t64;
  t626_tmp = b_t787_tmp * t56;
  t793 = 1.0 / ((((((((((((((((((((((((((((((((-(t23 * 3.9928605388461837E+110)
    + -(t25 * 1.215757206650896E+111)) + -(t24 * 7.46316243327777E+110)) + -(t43
    * 6.66890473783269E+110)) + t337_tmp * 3.7830473711723741E+110) + e_t785_tmp
    * 2.3222973196778359E+110) + t702_tmp * 1.373401503621102E+111) + -(t64 *
    1.953959797292265E+110)) + t322_tmp * 2.07514974199132E+110) + -(t67 *
    3.2788417613697459E+109)) + -(t68 * 1.74601207814982E+110)) + -(t182_tmp *
    t26 * 4.273585975402672E+110)) + -(t79 * 2.9298951419711852E+109)) +
    t387_tmp * 1.015502327157201E+110) + t3 * 1.70406343245411E+109) + t477_tmp *
    1.015502327157201E+110) + t206_tmp * 1.70406343245411E+109) + t492_tmp *
    8.9298774738683466E+109) + b_t521_tmp * 3.5957562864376437E+110) + t527_tmp *
    4.4614752376343817E+108) + t597_tmp * 4.4614752376343817E+108) + t471 *
    6.0338579596251836E+109) + -(t569_tmp * 8.2165618525715213E+109)) +
    -(t626_tmp * 2.0310046543144019E+110)) + t568_tmp * 7.9795264710044618E+109)
                       + c_t787_tmp * t56 * 4.6409917791085313E+109) +
                      -(b_t461_tmp * t55 * 4.6409917791085313E+109)) +
                     -(t609_tmp * 8.2165618525715213E+109)) + -(e_t787_tmp * t71
    * 4.6409917791085313E+109)) + -(t670 * 3.40812686490822E+109)) + f_t787_tmp *
                  t71 * 4.6409917791085313E+109) + -(t715_tmp *
    8.9229504752687635E+108)) + 1.283184824024515E+111);
  t9 = in2[3] * in2[4] * t22 * t62 * t81;
  t48 = (t257 + t319) + -t351;
  t49 = ((in1[6] * t727 / 2.0 + -t244) + -t735) + in1[7] * (((t97 + -t114) +
    t157) + t297) / 2.0;
  t16 = in2[0] * in2[4] * t22 * t62 * t81;
  t169 = rt_powd_snf(t45, 3.0);
  t746 = (t102 + t16 * t123 * t155) + t16 * t124 / t169 * 2.0;
  t16 = in2[1] * in2[4] * t22 * t62 * t81;
  t182 = (t102 + t16 * t123 * t155) + t16 * t124 / t169 * 2.0;
  t16 = in2[2] * in2[4] * t22 * t62 * t81;
  t168 = (t102 + t16 * t123 * t155) + t16 * t124 / t169 * 2.0;
  t16 = in2[0] * in2[3] * t22 * t62 * t81;
  t180 = t95 + t102;
  t750 = (t180 + t16 * t123 * t155) + t16 * t124 / t169 * 2.0;
  t16 = in2[1] * in2[3] * t22 * t62 * t81;
  t751 = (t180 + t16 * t123 * t155) + t16 * t124 / t169 * 2.0;
  t16 = in2[2] * in2[3] * t22 * t62 * t81;
  t752 = (t180 + t16 * t123 * t155) + t16 * t124 / t169 * 2.0;
  t16 = in2[0] * in2[2] * t22 * t62;
  t753 = (t180 + t16 * t81 * t124 / t169 * -2.0) + t16 * -t81 * t123 * t155;
  t16 = in2[1] * in2[2] * t22 * t62;
  t206 = (t180 + t16 * t81 * t124 / t169 * -2.0) + t16 * -t81 * t123 * t155;
  t16 = in2[0] * in2[1] * t22 * t62;
  t253 = (cos(t15 + 1.5707963267948966) * 0.4064 + t95) + t102;
  t234 = (t253 + t16 * t81 * t124 / t169 * -2.0) + t16 * -t81 * t123 * t155;
  t224 = (((((t129 + t138) + t142) + t166) + t192) + in1[6] * ((-t136 + t258) +
           t260)) + in1[5] * ((-t136 + t260) + t736);
  t16 = t135 + -(t137_tmp * 0.05952683917824);
  t776 = (((t54 * t135 + t137_tmp * t54 * -0.05952683917824) + t192) + in1[6] *
          ((t16 + in1[5] * t283 / 2.0) + t321)) + in1[5] * ((t16 + t321) + in1[5]
    * t730 / 2.0);
  t247 = ((((((-t96 + t129) + t138) + t142) + t166) + t192) + in1[6] * ((-t136 +
            t350) + t352)) + in1[5] * (((((((((t91 + t93) + t99) + t108) + t110)
    + -t118) + -t136) + t147) + t149) + t160);
  t45 = (t96 + -t129) + sin(t15) * 77.52247105284;
  t16 = in1[9] * t70;
  t790 = ((((((t45 + sin(in1[0]) * 97.255892295144) + -t192) + -(t16 * ((-(t5 *
    4064.0) + t58 * 4064.0) + t73 * 4667.0) * 1.464735216E-5)) + in1[5] * t49) +
           in1[6] * (t728 + t49)) + -in1[8] * ((((-t244 + t736) + in1[7] * t734 /
             2.0) + in1[6] * t734 / 2.0) + -t735)) + in1[7] *
    ((((((((((((((((((((((((t91 + in1[7] * t7 * 1.506081824) + t93) + t99) +
    in1[7] * t29 * 1.729548197) + in1[6] * t29 * 1.729548197) + t108) + in1[7] *
                      t50 * 0.3487631994496) + t110) + -(in1[8] * t50 *
    0.3487631994496)) + in1[8] * t59 * 0.4005112824388) + -t118) + -(in1[7] *
    t59 * 0.4005112824388)) + -(in1[6] * t59 * 0.4005112824388)) + t136) + t147)
             + in1[7] * t58 * 0.05952683917824) + t149) + -(in1[8] * t58 *
            0.05952683917824)) + -(in1[9] * t58 * 0.05952683917824)) + t160) +
        in1[7] * t73 * 0.06835919253072) + in1[6] * t73 * 0.06835919253072) +
      -(in1[8] * t73 * 0.06835919253072)) + -(in1[9] * t73 * 0.06835919253072));
  t244 = in2[4] * in2[4] * t22 * t62 * t81;
  t541_tmp = (-t102 + t9 * t123 * t155) + t9 * t124 / t169 * 2.0;
  t627_tmp = in2[3] * in2[3] * t22 * t62;
  t49 = (((((t45 + -t192) - in1[6] * t48) - in1[5] * (t728 + t48)) + in1[7] *
          ((((-t257 + -t319) + t350) + t351) + t352)) + -in1[8] * ((((t258 +
             in1[7] * t235 / 2.0) + t260) + -t257) + -t319)) + t16 * (t5 - t58) *
    0.05952683917824;
  t9 = t224 * t793;
  t48 = t776 * t793;
  t27 = in2[1] * in2[1] * t22 * t62;
  t136_tmp = in2[0] * in2[0] * t22 * t62;
  t57 = t94 + t103;
  t72 = t247 * t793;
  t45 = (sin(t15 + 1.5707963267948966) * 0.4064 + t94) + t103;
  t16 = in2[2] * in2[2] * t22 * t62;
  return ((((((((-in1[9] * ((((in1[5] * t746 + in1[7] * t168) + in1[6] * t182) -
    -in1[8] * t541_tmp) - -in1[9] * ((-t102 + t244 * t123 * t155) + t244 * t124 /
    t169 * 2.0)) - (t57 + in2[3] * m1 * t61 * -t81 * t123 * t155) * ((((t9 *
    ((((((((((((((((((((((((((((((((((t23 * 1.59657741305835E+100 + t24 *
    1.4569924177503392E+101) + t25 * 2.8595866578839019E+101) + t43 *
    1.301933828265091E+101) + t67 * 7.7121748510579323E+99) + t68 *
    6.9815697788097973E+99) + t79 * 6.8914163215694463E+99) + t341) + -t337) +
    -t353) + t406) + t413) + -t409) + t438) + -t481) + -t492) + t530) + -t521) +
    -t527) + -t533) + t569) + t594) + t609) + -t597) + t617) + -t695) + -t702) +
    t715) - t206_tmp * 3.3267499168724681E+99) - t3 * 3.3267499168724681E+99) -
         t702_tmp * 2.681216702962767E+101) - t568_tmp * 3.190677862790664E+99)
       - t471 * 1.4192257814734329E+100) + t670 * 6.6534998337449362E+99) -
     3.018183385881641E+101) * -2.0E+10 + t48 * t797 * 2.0E+9) + t788 * t790 *
    t793 * 9.2439458613517916E+44) + t72 * t798 * 1.0E+10) - t793 * t795 * t49 *
    2.0E+13)) + -in1[8] * ((((in1[5] * t750 + in1[7] * t752) + in1[6] * t751) -
    -in1[9] * t541_tmp) + -in1[8] * ((t180 + t627_tmp * -t81 * t123 * t155) -
    t627_tmp * t81 * t124 / t169 * 2.0))) - (t45 + in2[1] * m1 * t61 * t81 *
    t123 * t155) * ((((t793 * t49 * (((((((((((((((((((t4 *
    -5.2743680775837369E+98 + t23 * 1.7181426729130289E+98) + t24 *
    1.2971105964252839E+98) + t64 * 3.3960160732340671E+97) + t67 *
    5.6986839435659248E+96) + t294) + t317) + -t322) + t365) + -t568) + t366_tmp
    * 1.6412145600571541E+98) + t443_tmp * 2.9791413157070881E+98) - e_t785_tmp *
    4.036193086154212E+97) + t667_tmp * 7.7998066012713534E+97) + d_t785_tmp *
    1.3088463565266821E+97) - t785_tmp * 9.2701344158866658E+97) - t492_tmp *
    1.55202821855867E+97) - b_t785_tmp * 1.7823119330741418E+97) - c_t785_tmp *
    1.7823119330741418E+97) - 5.5215918060288816E+98) * 1.25E+12 + t9 * t795 *
                       2.0E+13) - t48 * t794 * 3.2E+10) + t247 * t791 * t793 *
                     1.25E+12) - t785 * t790 * t793 * 1.9807040628566081E+41)) +
              in1[6] * ((((in1[7] * t206 + in1[5] * t234) + in1[6] * ((t253 +
    t27 * -t81 * t123 * t155) - t27 * t81 * t124 / t169 * 2.0)) + -in1[9] * t182)
                        + -in1[8] * t751)) + in1[5] * ((((in1[7] * t753 + in1[6]
    * t234) + -in1[9] * t746) + -in1[8] * t750) + in1[5] * (((t253 + cos(in1[0]
    + 1.5707963267948966) * 0.4667) + t136_tmp * -t81 * t123 * t155) - t136_tmp *
    t81 * t124 / t169 * 2.0))) + (t57 + in2[2] * m1 * t61 * t81 * t123 * t155) *
            ((((t72 * (((((((((((((((((((((((((((((t23 * 2.2366877721760131E+100
    + t25 * 4.8613030107548844E+100) + t43 * 1.069116981453385E+100) + t67 *
    1.3110712598813E+99) + t68 * 9.78066683590667E+99) + t79 *
    1.641244559896035E+99) + -t285) + t307) + t315) + t341) + -t337) + t387) +
    -t366) + t477) + -t492) + -t521) + -t527) + -t541) + t569) + t602) + t609) +
    -t597) + t634) + -t626) + -t627) + t715) - t322_tmp * 3.3267499168724681E+99)
    - t568_tmp * 4.4699055005331928E+99) - t471 * 2.4126866536449842E+99) -
                       7.1880391949948467E+100) * 2.0E+10 - t48 * t454 * 3.2E+10)
               - t9 * t798 * 1.0E+10) + t786 * t790 * t793 *
              9.2439458613517916E+44) + t791 * t793 * t49 * 1.25E+12)) - (t103 +
            in2[4] * m1 * t61 * -t81 * t123 * t155) * ((((t9 * t797 * 2.0E+9 -
    t787 * t790 * t793 * 1.479031337816287E+42) + t72 * t454 * 3.2E+10) + t793 *
             t794 * t49 * 3.2E+10) - t48 * (((((((((((((((((((((((((((((t2 *
    -4.1922901857875019E+105 + t24 * 6.1560105058131068E+105) + t25 *
    1.002820748385332E+106) + t43 * 5.50086481372941E+105) + t64 *
    1.3733161713845791E+105) + t67 * 4.0006897444853948E+103) + t68 *
    1.2271627214023409E+105) + t79 * 3.574921359426923E+103) + t787_tmp *
    2.43828808120089E+105) + t339 * 3.9719975722262778E+105) + t461_tmp *
    2.1787963322915381E+105) - t387_tmp * 7.1373309210161707E+104) +
    t715_tmp_tmp * 4.687947065739642E+104) - t206_tmp * 2.0792186980452929E+103)
    - t477_tmp * 7.1373309210161707E+104) - t3 * 2.0792186980452929E+103) + t359
    * 4.1890381827974309E+104) - t702_tmp * 1.1328540897478209E+106) -
    b_t521_tmp * 2.5272322712911758E+105) - t315_tmp * 4.3134754244892159E+104)
    - b_t366_tmp * 4.3134754244892159E+104) - t471 * 7.3622319756808429E+103) -
    t530_tmp * 2.436396675840258E+104) - t307_tmp * 2.436396675840258E+104) -
    t180_tmp * 4.487036892096648E+105) + t626_tmp * 1.4274661842032339E+105) +
    t634_tmp * 2.436396675840258E+104) + t481_tmp_tmp * 2.436396675840258E+104)
              + t670 * 4.158437396090585E+103) - 1.0584386080587479E+106) *
            3.2E+6)) - ((t45 + sin(in1[0] + 1.5707963267948966) * 0.4667) + in2
                        [0] * m1 * t61 * t81 * t123 * t155) * ((((t790 * t793 *
              ((((((t23 * 2.1897708980686811E+68 + t24 * 4.0929593570712659E+68)
                   + t64 * 1.071593725470613E+68) + t67 * 1.798187589715944E+67)
                 - e_t785_tmp * 1.27359797263616E+68) - t492_tmp *
                4.8973375416829859E+67) - 7.0372625268405592E+68) *
              3.9614081257132169E+41 - t224 * t788 * t793 *
              9.2439458613517916E+44) + t776 * t787 * t793 *
             1.479031337816287E+42) + t247 * t786 * t793 *
            9.2439458613517916E+44) - t785 * t793 * t49 * 1.9807040628566081E+41))
    + in1[7] * ((((in1[5] * t753 + in1[6] * t206) + -in1[9] * t168) + -in1[8] *
                 t752) + in1[7] * ((t180 + t16 * -t81 * t123 * t155) - t16 * t81
    * t124 / t169 * 2.0));
}

/* End of code generation (CBF_Lf2s2.c) */

function Lf2_t_lb = Lf2_t_lb(in1,lb)
%Lf2_t_lb
%    Lf2_t_lb = Lf2_t_lb(IN1,LB)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    05-Dec-2021 00:43:45

dqnsh = in1(9,:);
dqnsk = in1(10,:);
dqsf = in1(6,:);
dqsh = in1(8,:);
dqsk = in1(7,:);
qnsh = in1(4,:);
qnsk = in1(5,:);
qsf = in1(1,:);
qsh = in1(3,:);
qsk = in1(2,:);
t2 = cos(qnsk);
t3 = cos(qsh);
t4 = cos(qsk);
t5 = sin(qnsk);
t6 = sin(qsf);
t7 = sin(qsh);
t8 = sin(qsk);
t9 = qsf+qsk;
t10 = qsh+qsk;
t18 = -dqnsh;
t19 = -dqnsk;
t20 = -qnsh;
t21 = -qnsk;
t22 = -qsh;
t23 = -qsk;
t11 = t2.^2;
t12 = t3.^2;
t13 = t4.^2;
t14 = cos(t10);
t15 = qsh+t9;
t16 = sin(t9);
t17 = sin(t10);
t25 = -t5;
t27 = qnsh+t22;
t30 = t10+t20;
t32 = t5.*4.064e+3;
t34 = dqsf+dqsh+dqsk+t18;
t44 = qnsh+qnsk-t10;
t54 = t7.*3.012163648;
t55 = dqsf.*t7.*1.506081824;
t56 = dqsh.*t7.*1.506081824;
t57 = dqsk.*t7.*1.506081824;
t64 = t8.*7.3760932192376;
t83 = t5.*1.1905367835648e-1;
t87 = dqnsh.*t5.*5.952683917824e-2;
t88 = dqnsk.*t5.*5.952683917824e-2;
t89 = dqsh.*t5.*5.952683917824e-2;
t94 = dqnsk.*dqsh.*t5.*(-5.952683917824e-2);
t116 = t4.*3.566096229827739e+65;
t118 = t3.*t4.*4.295141349249055e+65;
t120 = t4.*1.664297110460606e+69;
t135 = t6.*9.7255892295144e+1;
t176 = t4.*2.637184038791869e+98;
t177 = t3.*3.964279929204043e+98;
t181 = t3.*t4.*3.17632432794494e+98;
t184 = t3.*4.955349911505053e+100;
t24 = sin(t15);
t26 = t14.^2;
t28 = cos(t27);
t29 = qnsk+t27;
t31 = sin(t27);
t33 = -t32;
t36 = cos(t30);
t37 = t15+t20;
t39 = sin(t30);
t45 = t19+t34;
t46 = cos(t44);
t48 = sin(t44);
t59 = t17.*3.459096394;
t61 = dqsf.*t17.*1.729548197;
t62 = dqsh.*t17.*1.729548197;
t63 = dqsk.*t17.*1.729548197;
t84 = t16.*7.752247105284e+1;
t85 = -t83;
t90 = dqnsk.*t87;
t91 = dqsh.*t88;
t92 = -t88;
t93 = -t89;
t103 = t34.*t87;
t104 = t34.*t89;
t105 = dqsh.*t5.*t34.*(-5.952683917824e-2);
t117 = t14.*4.171233017896924e+65;
t121 = t4.*t11.*1.109655027648246e+65;
t122 = t3.*t14.*2.014251652102001e+65;
t124 = -t120;
t127 = t11.*4.379541796137363e+68;
t128 = t12.*8.185918714142532e+68;
t129 = t11.*t14.*1.297954231040276e+65;
t130 = t3.*t4.*t11.*1.336510538551652e+65;
t131 = t4.*t11.*5.178760014034365e+68;
t133 = t3.*t11.*t14.*6.26770655824882e+64;
t134 = t3.*t14.*9.400512460360038e+68;
t136 = t11.*t12.*2.547195945272321e+68;
t142 = t3.*t11.*t14.*2.925138650734724e+68;
t178 = -t176;
t179 = -t177;
t180 = t14.*3.084692175401777e+98;
t183 = t11.*1.024176574588261e+98;
t185 = -t181;
t186 = -t184;
t188 = t4.*t11.*8.206072800285771e+97;
t190 = t3.*t11.*1.233557052569721e+98;
t191 = t3.*t14.*1.489570657853544e+98;
t192 = t4.*t14.*3.647614576407243e+98;
t193 = t3.*t11.*1.541946315712151e+100;
t194 = t11.*t14.*9.598574913799042e+97;
t195 = t3.*t4.*t11.*9.883704849198075e+97;
t196 = t4.*t14.*4.559518220509054e+100;
t197 = t3.*t11.*t14.*4.635067207943333e+97;
t206 = t4.*t11.*t14.*1.135020928425379e+98;
t219 = t4.*t11.*t14.*1.418776160531724e+100;
t239 = t11.*3.992860538846184e+110;
t244 = t13.*1.215757206650896e+111;
t248 = t12.*7.463162433277769e+110;
t265 = t11.*t13.*3.783047371172374e+110;
t267 = t11.*t12.*2.322297319677836e+110;
t275 = t3.*t4.*t14.*1.373401503621102e+111;
t295 = t3.*t4.*t11.*t14.*4.273585975402672e+110;
t35 = cos(t29);
t38 = sin(t29);
t40 = t28.^2;
t41 = sin(t37);
t43 = t36.^2;
t47 = t21+t37;
t52 = t46.^2;
t53 = t48.*4.667e+3;
t58 = t24.*3.63549771e+1;
t65 = t31.*6.975263988992e-1;
t66 = dqnsh.*t31.*3.487631994496e-1;
t67 = dqsf.*t31.*3.487631994496e-1;
t68 = dqsh.*t31.*3.487631994496e-1;
t69 = dqsk.*t31.*3.487631994496e-1;
t71 = t39.*8.010225648776e-1;
t73 = dqnsh.*t39.*4.005112824388e-1;
t74 = dqsf.*t39.*4.005112824388e-1;
t75 = dqsh.*t39.*4.005112824388e-1;
t76 = dqsk.*t39.*4.005112824388e-1;
t86 = -t84;
t106 = t48.*1.3671838506144e-1;
t107 = dqnsh.*t48.*6.835919253072e-2;
t108 = dqnsk.*t48.*6.835919253072e-2;
t109 = dqsf.*t48.*6.835919253072e-2;
t110 = dqsh.*t48.*6.835919253072e-2;
t111 = dqsk.*t48.*6.835919253072e-2;
t112 = t45.*t88;
t115 = dqnsk.*t5.*t45.*(-5.952683917824e-2);
t119 = -t117;
t125 = -t121;
t126 = -t122;
t132 = -t130;
t139 = -t136;
t145 = -t142;
t146 = t28.*t36.*5.27359116865459e+64;
t149 = t3.*t28.*t36.*6.351712917353643e+64;
t151 = t28.*t36.*2.461184998411097e+68;
t155 = t2.*t28.*t46.*1.205053528957428e+64;
t164 = t2.*t3.*t28.*t46.*1.45141210632265e+64;
t171 = t2.*t28.*t46.*5.623984819644315e+67;
t187 = t26.*1.710587170325416e+98;
t199 = -t194;
t203 = t11.*t26.*5.322799866995949e+97;
t204 = t28.*1.750793769576233e+100;
t205 = -t197;
t211 = -t206;
t212 = t2.*t28.*2.343973532869821e+100;
t222 = t4.*t36.*1.610940949740522e+100;
t226 = -t219;
t230 = t2.*t4.*t36.*2.156737712244608e+100;
t231 = t28.*t36.*3.899903300635676e+97;
t232 = t26.*t28.*9.099138835101922e+99;
t235 = t3.*t14.*t36.*9.099138835101922e+99;
t237 = t4.*t46.*1.583807101479817e+100;
t238 = t3.*t28.*t36.*4.697191226789274e+97;
t242 = t2.*t26.*t28.*1.218198337920129e+100;
t243 = t2.*t4.*t46.*3.681115987840422e+99;
t246 = -t239;
t251 = t2.*t3.*t14.*t36.*1.218198337920129e+100;
t253 = t14.*t28.*t36.*5.394141598283844e+97;
t254 = -t244;
t255 = -t248;
t256 = t26.*6.66890473783269e+110;
t260 = t3.*t14.*t46.*8.945877691361976e+99;
t263 = t2.*t28.*t46.*8.911559665370708e+96;
t264 = t14.*t28.*t36.*6.742676997854805e+99;
t277 = t2.*t36.*t46.*2.046764220388046e+97;
t278 = t2.*t3.*t14.*t46.*2.079218698045293e+99;
t281 = t2.*t3.*t28.*t46.*1.073341994668572e+97;
t283 = t11.*t26.*2.07514974199132e+110;
t290 = t2.*t3.*t36.*t46.*2.465200339132985e+97;
t292 = t2.*t14.*t28.*t46.*1.232600169566493e+97;
t298 = t2.*t3.*t36.*t46.*3.081500423916231e+99;
t299 = -t295;
t301 = t2.*t14.*t28.*t46.*1.540750211958116e+99;
t307 = t28.*t36.*t46.*2.342155288282798e+99;
t312 = t4.*t28.*t36.*3.595756286437644e+110;
t315 = t3.*t14.*t28.*t36.*2.031004654314402e+110;
t321 = t2.*t36.*t46.*7.979526471004461e+109;
t322 = t2.*t4.*t28.*t46.*8.216561852571522e+109;
t326 = t2.*t12.*t36.*t46.*4.640991779108531e+109;
t330 = t2.*t3.*t14.*t28.*t46.*4.640991779108531e+109;
t42 = t35.^2;
t49 = sin(t47);
t50 = t38.*4.064e+3;
t51 = t25+t38;
t60 = -t58;
t70 = -t66;
t72 = -t71;
t77 = -t74;
t78 = -t75;
t79 = -t76;
t81 = t41.*8.418717978840001;
t95 = t38.*1.1905367835648e-1;
t96 = dqnsh.*t38.*5.952683917824e-2;
t97 = dqnsk.*t38.*5.952683917824e-2;
t98 = dqsf.*t38.*5.952683917824e-2;
t99 = dqsh.*t38.*5.952683917824e-2;
t100 = dqsk.*t38.*5.952683917824e-2;
t113 = -t107;
t114 = -t108;
t123 = dqnsk.*t45.*(t5-t38).*(-5.952683917824e-2);
t140 = t40.*2.143187450941225e+68;
t143 = t14.*t40.*6.351712917353643e+64;
t147 = -t146;
t148 = t2.*t35.*t36.*1.205053528957428e+64;
t150 = -t149;
t152 = t2.*t3.*t35.*t36.*1.45141210632265e+64;
t154 = t35.*t46.*8.84934837458634e+63;
t157 = t2.*t14.*t28.*t35.*2.902824212645301e+64;
t158 = t2.*t28.*t35.*9.794675083365973e+67;
t159 = t3.*t35.*t46.*1.06584903120889e+64;
t160 = t2.*t35.*t36.*5.623984819644315e+67;
t166 = t35.*t46.*4.129990886419445e+67;
t173 = -t171;
t198 = t43.*4.478555291354996e+97;
t208 = -t203;
t209 = t35.*1.721304313437495e+100;
t210 = t3.*t43.*5.394141598283844e+97;
t216 = t2.*t35.*4.000689744485395e+99;
t218 = t52.*7.515238614554655e+96;
t221 = t14.*t40.*4.697191226789274e+97;
t225 = t3.*t43.*6.742676997854805e+99;
t228 = -t222;
t233 = -t230;
t234 = t3.*t52.*9.051637993629275e+96;
t236 = -t232;
t240 = t26.*t35.*8.945877691361976e+99;
t241 = t2.*t35.*t36.*8.911559665370708e+96;
t245 = t2.*t26.*t35.*2.079218698045293e+99;
t247 = t3.*t52.*1.131454749203659e+99;
t249 = t35.*t46.*6.544231782633408e+96;
t252 = -t242;
t257 = -t253;
t258 = t35.*t43.*2.342155288282798e+99;
t259 = t2.*t3.*t35.*t36.*1.073341994668572e+97;
t261 = t2.*t14.*t28.*t35.*2.146683989337144e+97;
t262 = -t256;
t266 = t3.*t35.*t46.*7.882120592695387e+96;
t269 = t28.*t52.*3.997586367945402e+98;
t270 = -t260;
t271 = t40.*1.953959797292265e+110;
t272 = -t263;
t273 = -t264;
t276 = t2.*t14.*t35.*t36.*1.232600169566493e+97;
t280 = t43.*1.74601207814982e+110;
t285 = -t277;
t286 = -t278;
t288 = -t281;
t289 = t14.*t35.*t46.*9.051637993629275e+96;
t291 = t2.*t14.*t35.*t36.*1.540750211958116e+99;
t294 = -t290;
t296 = t52.*2.929895141971185e+109;
t297 = t14.*t35.*t46.*1.131454749203659e+99;
t302 = t12.*t43.*1.015502327157201e+110;
t304 = -t298;
t306 = t26.*t40.*1.015502327157201e+110;
t308 = t35.*t36.*t46.*3.997586367945402e+98;
t309 = -t307;
t310 = t12.*t52.*1.70406343245411e+109;
t311 = t2.*t28.*t35.*8.929877473868346e+109;
t314 = t2.*t4.*t35.*t36.*8.216561852571522e+109;
t316 = t40.*t52.*4.461475237634382e+108;
t317 = t4.*t35.*t46.*6.033857959625184e+109;
t319 = -t315;
t320 = t2.*t26.*t28.*t35.*4.640991779108531e+109;
t323 = t2.*t3.*t14.*t35.*t36.*4.640991779108531e+109;
t325 = -t322;
t327 = t3.*t14.*t35.*t46.*3.40812686490822e+109;
t328 = -t326;
t331 = t28.*t35.*t36.*t46.*8.922950475268764e+108;
t80 = t33+t50+t53;
t82 = -t81;
t101 = -t96;
t102 = -t97;
t137 = t49.*1.436905246896;
t138 = t42.*3.596375179431889e+67;
t144 = t14.*t42.*1.06584903120889e+64;
t153 = t65+t95;
t156 = -t154;
t161 = -t157;
t162 = -t158;
t163 = -t159;
t165 = -t160;
t182 = t85+t95;
t217 = -t209;
t223 = -t216;
t224 = t14.*t42.*7.882120592695387e+96;
t227 = -t221;
t250 = -t241;
t268 = -t259;
t274 = t42.*3.278841761369746e+109;
t279 = -t269;
t282 = -t271;
t287 = -t280;
t293 = -t289;
t300 = -t296;
t303 = -t297;
t305 = t26.*t42.*1.70406343245411e+109;
t313 = t42.*t43.*4.461475237634382e+108;
t318 = -t314;
t324 = -t320;
t329 = -t327;
t332 = -t331;
t333 = t59+t64+t72+t106;
t360 = t55+t57+t61+t67+t69+t77+t92+t98+t100+t109;
t141 = -t137;
t167 = (dqnsh.*t153)./2.0;
t168 = (dqsf.*t153)./2.0;
t169 = (dqsh.*t153)./2.0;
t170 = (dqsk.*t153)./2.0;
t174 = dqnsk.*t45.*t80.*1.464735216e-5;
t189 = t54+t153;
t200 = (dqnsk.*t182)./2.0;
t201 = (dqsf.*t182)./2.0;
t202 = (dqsk.*t182)./2.0;
t229 = -t224;
t284 = -t274;
t334 = (dqsf.*t333)./2.0;
t335 = (dqsk.*t333)./2.0;
t336 = t106+t182;
t340 = t72+t106+t153;
t361 = dqsf.*t360;
t379 = t55+t56+t57+t61+t62+t63+t67+t68+t69+t70+t73+t77+t78+t79+t88+t98+t99+t100+t101+t102+t109+t110+t111+t113+t114;
t381 = t124+t127+t128+t131+t134+t138+t139+t140+t145+t151+t162+t165+t166+t173-1.407452505368112e+69;
t382 = t116+t118+t119+t125+t126+t129+t132+t133+t143+t144+t147+t148+t150+t152+t155+t156+t161+t163+t164;
t172 = -t167;
t175 = -t174;
t207 = -t200;
t213 = (dqsf.*t189)./2.0;
t214 = (dqsh.*t189)./2.0;
t215 = (dqsk.*t189)./2.0;
t337 = (dqnsk.*t336)./2.0;
t338 = (dqsf.*t336)./2.0;
t341 = (dqnsh.*t340)./2.0;
t342 = (dqsf.*t340)./2.0;
t343 = (dqsh.*t340)./2.0;
t344 = (dqsk.*t340)./2.0;
t346 = t59+t72+t106+t189;
t347 = t92+t168+t170;
t354 = t87+t93+t201+t202;
t380 = dqsh.*t379;
t385 = t178+t179+t180+t183+t185+t187+t188+t190+t191+t192+t195+t198+t199+t205+t208+t210+t211+t218+t227+t229+t231+t234+t238+t249+t250+t257+t261+t266+t268+t272+t276+t285+t288+t292+t293+t294-3.291394289500617e+98;
t386 = t246+t254+t255+t262+t265+t267+t275+t282+t283+t284+t287+t299+t300+t302+t305+t306+t310+t311+t312+t313+t316+t317+t318+t319+t321+t323+t324+t325+t328+t329+t330+t332+1.283184824024515e+111;
t220 = -t214;
t339 = -t337;
t345 = -t341;
t348 = (dqsh.*t346)./2.0;
t349 = dqsk.*t347;
t350 = t92+t213+t215;
t355 = dqsk.*t354;
t356 = t92+t170+t342;
t358 = t87+t93+t202+t338;
t364 = t168+t169+t170+t172+t207;
t366 = t172+t207+t213+t214+t215;
t387 = 1.0./t386;
t351 = dqsk.*t350;
t352 = t167+t200+t220;
t357 = dqsf.*t356;
t359 = dqsf.*t358;
t365 = dqnsh.*t364;
t367 = dqsh.*t366;
t369 = t335+t339+t345+t348;
t375 = t339+t342+t343+t344+t345;
t353 = dqsk.*t352;
t362 = t334+t352;
t368 = -t367;
t370 = dqsf.*t369;
t371 = t81+t90+t94+t115+t137+t349+t357;
t372 = t103+t105+t137+t355+t359;
t373 = t334+t369;
t376 = dqnsh.*t375;
t377 = t18.*t375;
t378 = t60+t81+t90+t94+t115+t137+t351+t361;
t363 = dqsf.*t362;
t374 = dqsk.*t373;
t383 = t60+t81+t86+t123+t137+t353+t363+t365+t368;
t384 = t58+t82+t84+t135+t141+t175+t370+t374+t377+t380;
et1 = t11.*2.189770898068681e+68+t12.*4.092959357071266e+68;
et2 = t40.*1.071593725470613e+68+t42.*1.798187589715944e+67;
et3 = t11.*t12.*-1.27359797263616e+68-t2.*t28.*t35.*4.897337541682986e+67;
et4 = -7.037262526840559e+68;
et5 = t36.*2.947508817582782e+68-t46.*2.897862517998514e+68;
et6 = t4.*t28.*-3.035065877489379e+68+t2.*t36.*3.94614304458412e+68;
et7 = t4.*t35.*2.983944812502915e+68-t2.*t46.*6.735269740614793e+67;
et8 = t12.*t36.*-1.714307765123516e+68+t12.*t46.*1.685432860193883e+68;
et9 = t36.*t42.*-7.531584555983923e+66+t40.*t46.*4.412697806454926e+67;
et10 = t2.*t4.*t28.*-4.063364978202626e+68+t2.*t4.*t35.*6.935343922801539e+67;
et11 = t3.*t14.*t28.*1.714307765123516e+68-t2.*t12.*t36.*2.295125844327934e+68;
et12 = t3.*t14.*t35.*-1.685432860193883e+68+t2.*t12.*t46.*3.917316598905513e+67;
et13 = t28.*t35.*t36.*-4.412697806454926e+67+t28.*t35.*t46.*7.531584555983923e+66;
et14 = t2.*t3.*t14.*t28.*2.295125844327934e+68-t2.*t3.*t14.*t35.*3.917316598905513e+67;
et15 = t11.*3.193154826116699e+100;
et16 = t13.*9.722606021509767e+100;
et17 = t28.*-5.602540062643945e+100;
et18 = t40.*1.562613093059536e+100;
et19 = t42.*2.622142519762599e+99;
et20 = t43.*1.396313955761959e+100;
et21 = t52.*2.343084292972739e+99+t186+t193+t196+t225+t226+t247+t273+t291+t301+t303+t304;
et22 = t11.*t13.*-3.02536385960975e+100;
et23 = t3.*t28.*-6.747911422751707e+100;
et24 = t2.*t35.*1.280220718235326e+100;
et25 = t4.*t36.*5.155011039169671e+100;
et26 = t14.*t36.*-6.029773418438111e+100;
et27 = t26.*t28.*2.911724427232615e+100;
et28 = t28.*t52.*1.279227637742529e+99;
et29 = t42.*t43.*-3.567913541695871e+98;
et30 = t40.*t52.*-3.567913541695871e+98;
et31 = t2.*t3.*t35.*1.541946315712151e+100;
et32 = t3.*t4.*t36.*6.208890518706654e+100;
et33 = t4.*t14.*t28.*6.208890518706654e+100;
et34 = t2.*t4.*t46.*-1.177957116108935e+100;
et35 = t3.*t14.*t36.*-2.911724427232615e+100;
et36 = t2.*t14.*t46.*1.377846614256279e+100;
et37 = t2.*t26.*t35.*-6.653499833744936e+99;
et38 = t2.*t28.*t35.*-7.141366715641245e+99;
et39 = t4.*t28.*t36.*-2.875584165255047e+100;
et40 = t3.*t28.*t52.*1.540750211958116e+99;
et41 = t2.*t36.*t46.*-6.381355725581329e+99;
et42 = t4.*t35.*t46.*-4.825373307289968e+99;
et43 = t14.*t36.*t42.*1.540750211958116e+99;
et44 = t35.*t36.*t46.*-1.279227637742529e+99;
et45 = t2.*t3.*t4.*t46.*-1.418776160531724e+100;
et46 = t2.*t4.*t14.*t35.*-1.418776160531724e+100;
et47 = t2.*t3.*t14.*t46.*6.653499833744936e+99;
et48 = t2.*t4.*t35.*t36.*6.570916734599188e+99;
et49 = t2.*t4.*t28.*t46.*6.570916734599188e+99;
et50 = t3.*t35.*t36.*t46.*-1.540750211958116e+99;
et51 = t14.*t28.*t35.*t46.*-1.540750211958116e+99;
et52 = t28.*t35.*t36.*t46.*7.135827083391743e+98;
et53 = -1.026183552811392e+101;
et54 = t36.*1.362330596779613e+100;
et55 = t46.*-1.339384211500942e+100-t204+t209-t212+t216+t222+t230+t232-t235-t237-t240+t242-t243-t245-t251-t258+t260+t269+t278+t307-t308;
et56 = t4.*t28.*-1.402799232857399e+100;
et57 = t2.*t36.*1.823896633264277e+100;
et58 = t4.*t35.*1.379171215001923e+100;
et59 = t2.*t46.*-3.113023442192204e+99;
et60 = t12.*t36.*-7.923484085248385e+99;
et61 = t12.*t46.*7.790025056287781e+99;
et62 = t36.*t42.*-3.481077994285433e+98;
et63 = t40.*t46.*2.039536981268757e+99;
et64 = t2.*t4.*t28.*-1.878076293670899e+100;
et65 = t2.*t4.*t35.*3.205497187611629e+99;
et66 = t3.*t14.*t28.*7.923484085248385e+99;
et67 = t2.*t12.*t36.*-1.060800952497837e+100;
et68 = t3.*t14.*t35.*-7.790025056287781e+99;
et69 = t2.*t12.*t46.*1.810573128102865e+99;
et70 = t28.*t35.*t36.*-2.039536981268757e+99;
et71 = t28.*t35.*t46.*3.481077994285433e+98;
et72 = t2.*t3.*t14.*t28.*1.060800952497837e+100;
et73 = t2.*t3.*t14.*t35.*-1.810573128102865e+99;
et74 = t4.*-5.274368077583737e+98;
et75 = t11.*1.718142672913029e+98;
et76 = t12.*1.297110596425284e+98;
et77 = t40.*3.396016073234067e+97+t42.*5.698683943565925e+96+t187;
et78 = t198+t208+t218+t285+t4.*t11.*1.641214560057154e+98;
et79 = t3.*t14.*2.979141315707088e+98;
et80 = t11.*t12.*-4.036193086154212e+97;
et81 = t28.*t36.*7.799806601271353e+97;
et82 = t35.*t46.*1.308846356526682e+97;
et83 = t3.*t11.*t14.*-9.270134415886666e+97;
et84 = t2.*t28.*t35.*-1.55202821855867e+97;
et85 = t2.*t35.*t36.*-1.782311933074142e+97;
et86 = t2.*t28.*t46.*-1.782311933074142e+97;
et87 = -5.521591806028882e+98;
et88 = t3.*2.477674955752527e+97;
et89 = t14.*-1.927932609626111e+97;
et90 = t28.*2.801270031321972e+97;
et91 = t36.*-2.179728954847382e+97;
et92 = t3.*t4.*1.985202704965588e+97;
et93 = t3.*t11.*-7.709731578560755e+96;
et94 = t4.*t14.*-2.279759110254527e+97;
et95 = t11.*t14.*5.999109321124401e+96;
et96 = t4.*t28.*2.244478772571839e+97;
et97 = t2.*t35.*-6.401103591176632e+96;
et98 = t4.*t36.*-2.577505519584836e+97;
et99 = t3.*t43.*-3.371338498927402e+96;
et100 = t2.*t46.*4.980837507507526e+96;
et101 = t12.*t36.*1.267757453639742e+97;
et102 = t14.*t40.*2.935744516743296e+96;
et103 = t26.*t28.*-1.455862213616308e+97;
et104 = t3.*t52.*-5.657273746018297e+95+t14.*t42.*4.926325370434617e+95;
Lf2_t_lb = ft_1({dqnsk,et1,et10,et100,et101,et102,et103,et104,et11,et12,et13,et14,et15,et16,et17,et18,et19,et2,et20,et21,et22,et23,et24,et25,et26,et27,et28,et29,et3,et30,et31,et32,et33,et34,et35,et36,et37,et38,et39,et4,et40,et41,et42,et43,et44,et45,et46,et47,et48,et49,et5,et50,et51,et52,et53,et54,et55,et56,et57,et58,et59,et6,et60,et61,et62,et63,et64,et65,et66,et67,et68,et69,et7,et70,et71,et72,et73,et74,et75,et76,et77,et78,et79,et8,et80,et81,et82,et83,et84,et85,et86,et87,et88,et89,et9,et90,et91,et92,et93,et94,et95,et96,et97,et98,et99,t11,t118,t119,t12,t129,t13,t132,t14,t141,t143,t144,t150,t152,t161,t163,t164,t18,t186,t193,t196,t2,t204,t212,t217,t223,t225,t226,t228,t233,t235,t236,t237,t240,t243,t245,t247,t251,t252,t258,t26,t270,t273,t279,t28,t286,t291,t3,t301,t303,t304,t308,t309,t35,t353,t36,t363,t364,t367,t371,t372,t378,t38,t381,t382,t384,t385,t387,t4,t40,t42,t43,t45,t46,t5,t52,t58,t82,t84});
end
function Lf2_t_lb = ft_1(ct)
dqnsk = ct{1};
et1 = ct{2};
et10 = ct{3};
et100 = ct{4};
et101 = ct{5};
et102 = ct{6};
et103 = ct{7};
et104 = ct{8};
et11 = ct{9};
et12 = ct{10};
et13 = ct{11};
et14 = ct{12};
et15 = ct{13};
et16 = ct{14};
et17 = ct{15};
et18 = ct{16};
et19 = ct{17};
et2 = ct{18};
et20 = ct{19};
et21 = ct{20};
et22 = ct{21};
et23 = ct{22};
et24 = ct{23};
et25 = ct{24};
et26 = ct{25};
et27 = ct{26};
et28 = ct{27};
et29 = ct{28};
et3 = ct{29};
et30 = ct{30};
et31 = ct{31};
et32 = ct{32};
et33 = ct{33};
et34 = ct{34};
et35 = ct{35};
et36 = ct{36};
et37 = ct{37};
et38 = ct{38};
et39 = ct{39};
et4 = ct{40};
et40 = ct{41};
et41 = ct{42};
et42 = ct{43};
et43 = ct{44};
et44 = ct{45};
et45 = ct{46};
et46 = ct{47};
et47 = ct{48};
et48 = ct{49};
et49 = ct{50};
et5 = ct{51};
et50 = ct{52};
et51 = ct{53};
et52 = ct{54};
et53 = ct{55};
et54 = ct{56};
et55 = ct{57};
et56 = ct{58};
et57 = ct{59};
et58 = ct{60};
et59 = ct{61};
et6 = ct{62};
et60 = ct{63};
et61 = ct{64};
et62 = ct{65};
et63 = ct{66};
et64 = ct{67};
et65 = ct{68};
et66 = ct{69};
et67 = ct{70};
et68 = ct{71};
et69 = ct{72};
et7 = ct{73};
et70 = ct{74};
et71 = ct{75};
et72 = ct{76};
et73 = ct{77};
et74 = ct{78};
et75 = ct{79};
et76 = ct{80};
et77 = ct{81};
et78 = ct{82};
et79 = ct{83};
et8 = ct{84};
et80 = ct{85};
et81 = ct{86};
et82 = ct{87};
et83 = ct{88};
et84 = ct{89};
et85 = ct{90};
et86 = ct{91};
et87 = ct{92};
et88 = ct{93};
et89 = ct{94};
et9 = ct{95};
et90 = ct{96};
et91 = ct{97};
et92 = ct{98};
et93 = ct{99};
et94 = ct{100};
et95 = ct{101};
et96 = ct{102};
et97 = ct{103};
et98 = ct{104};
et99 = ct{105};
t11 = ct{106};
t118 = ct{107};
t119 = ct{108};
t12 = ct{109};
t129 = ct{110};
t13 = ct{111};
t132 = ct{112};
t14 = ct{113};
t141 = ct{114};
t143 = ct{115};
t144 = ct{116};
t150 = ct{117};
t152 = ct{118};
t161 = ct{119};
t163 = ct{120};
t164 = ct{121};
t18 = ct{122};
t186 = ct{123};
t193 = ct{124};
t196 = ct{125};
t2 = ct{126};
t204 = ct{127};
t212 = ct{128};
t217 = ct{129};
t223 = ct{130};
t225 = ct{131};
t226 = ct{132};
t228 = ct{133};
t233 = ct{134};
t235 = ct{135};
t236 = ct{136};
t237 = ct{137};
t240 = ct{138};
t243 = ct{139};
t245 = ct{140};
t247 = ct{141};
t251 = ct{142};
t252 = ct{143};
t258 = ct{144};
t26 = ct{145};
t270 = ct{146};
t273 = ct{147};
t279 = ct{148};
t28 = ct{149};
t286 = ct{150};
t291 = ct{151};
t3 = ct{152};
t301 = ct{153};
t303 = ct{154};
t304 = ct{155};
t308 = ct{156};
t309 = ct{157};
t35 = ct{158};
t353 = ct{159};
t36 = ct{160};
t363 = ct{161};
t364 = ct{162};
t367 = ct{163};
t371 = ct{164};
t372 = ct{165};
t378 = ct{166};
t38 = ct{167};
t381 = ct{168};
t382 = ct{169};
t384 = ct{170};
t385 = ct{171};
t387 = ct{172};
t4 = ct{173};
t40 = ct{174};
t42 = ct{175};
t43 = ct{176};
t45 = ct{177};
t46 = ct{178};
t5 = ct{179};
t52 = ct{180};
t58 = ct{181};
t82 = ct{182};
t84 = ct{183};
et105 = t36.*t42.*5.569724790856693e+95;
et106 = t28.*t52.*-6.396138188712644e+95;
et107 = t3.*t4.*t11.*-6.177315530748797e+96;
et108 = t4.*t11.*t14.*7.093880802658621e+96;
et109 = t2.*t4.*t35.*-5.128795500178607e+96;
et110 = t3.*t14.*t28.*-1.267757453639742e+97;
et111 = t2.*t4.*t46.*5.889785580544675e+96;
et112 = t3.*t14.*t36.*1.455862213616308e+97;
et113 = t2.*t12.*t46.*-2.896917004964583e+96;
et114 = t2.*t26.*t35.*3.326749916872468e+96;
et115 = t3.*t28.*t36.*-2.935744516743296e+96;
et116 = t14.*t28.*t36.*3.371338498927402e+96;
et117 = t3.*t35.*t46.*-4.926325370434617e+95;
et118 = t14.*t35.*t46.*5.657273746018297e+95;
et119 = t28.*t35.*t46.*-5.569724790856693e+95;
et120 = t35.*t36.*t46.*6.396138188712644e+95;
et121 = t2.*t3.*t14.*t35.*2.896917004964583e+96;
et122 = t2.*t3.*t14.*t46.*-3.326749916872468e+96;
et123 = t2.*t3.*t35.*t36.*6.708387466678575e+95;
et124 = t2.*t3.*t28.*t46.*6.708387466678575e+95;
et125 = t2.*t14.*t28.*t35.*-1.341677493335715e+96;
et126 = t2.*t3.*t36.*t46.*1.540750211958116e+96;
et127 = t2.*t14.*t35.*t36.*-7.703751059790579e+95;
et128 = t2.*t14.*t28.*t46.*-7.703751059790579e+95;
et129 = t36.*-4.716014108132451e+65+t118+t119+t129+t132+t143+t144+t150+t152+t161+t163+t164+t4.*t28.*4.856105403983006e+65;
et130 = t2.*t46.*1.077643158498367e+65+t12.*t36.*2.742892424197626e+65;
et131 = t36.*t42.*1.205053528957428e+64-t2.*t4.*t35.*1.109655027648246e+65;
et132 = t3.*t14.*t28.*-2.742892424197626e+65-t2.*t12.*t46.*6.26770655824882e+64;
et133 = t28.*t35.*t46.*-1.205053528957428e+64+t2.*t3.*t14.*t35.*6.26770655824882e+64;
et134 = t204+t212+t217+t223+t228+t233+t235+t236+t237+t240+t243+t245+t251+t252+t258+t270+t279+t286+t308+t309+t3.*t28.*2.108722319609908e+100;
et135 = t3.*t35.*-2.073204101854333e+100;
et136 = t14.*t36.*1.88430419326191e+100;
et137 = t14.*t46.*-1.852565957254429e+100;
et138 = t2.*t3.*t28.*2.823170490567743e+100;
et139 = t2.*t3.*t35.*-4.818582236600472e+99;
et140 = t3.*t4.*t36.*-1.940278287095829e+100;
et141 = t4.*t14.*t28.*-1.940278287095829e+100;
et142 = t2.*t14.*t36.*2.522718114281719e+100;
et143 = t3.*t4.*t46.*1.907597252676734e+100;
et144 = t4.*t14.*t35.*1.907597252676734e+100;
et145 = t2.*t14.*t46.*-4.30577066955087e+99;
et146 = t3.*t35.*t43.*2.8209805279292e+99;
et147 = t3.*t28.*t52.*-4.814844412369112e+98;
et148 = t14.*t36.*t42.*-4.814844412369112e+98;
et149 = t14.*t40.*t46.*2.8209805279292e+99;
et150 = t2.*t3.*t4.*t36.*-2.597656577482235e+100;
et151 = t2.*t4.*t14.*t28.*-2.597656577482235e+100;
et152 = t2.*t3.*t4.*t46.*4.433675501661638e+99;
et153 = t2.*t4.*t14.*t35.*4.433675501661638e+99;
et154 = t3.*t28.*t36.*t46.*-2.8209805279292e+99;
et155 = t14.*t28.*t35.*t36.*-2.8209805279292e+99;
et156 = t3.*t35.*t36.*t46.*4.814844412369112e+98;
et157 = t14.*t28.*t35.*t46.*4.814844412369112e+98;
et158 = t11.*2.236687772176013e+100;
et159 = t13.*4.861303010754884e+100;
et160 = t26.*1.069116981453385e+100;
et161 = t40.*7.81306546529768e+99;
et162 = t42.*1.3110712598813e+99;
et163 = t43.*9.78066683590667e+99;
et164 = t52.*1.641244559896035e+99+t186+t193+t196+t225+t226+t247+t273+t291+t301+t303+t304;
et165 = t11.*t13.*-1.512681929804875e+100;
et166 = t11.*t26.*-3.326749916872468e+99;
et167 = t42.*t43.*-1.783956770847936e+98;
et168 = t40.*t52.*-1.783956770847936e+98;
et169 = t2.*t28.*t35.*-3.570683357820623e+99;
et170 = t4.*t28.*t36.*-1.437792082627523e+100;
et171 = t2.*t36.*t46.*-4.469905500533193e+99;
et172 = t4.*t35.*t46.*-2.412686653644984e+99;
et173 = t2.*t4.*t35.*t36.*3.285458367299594e+99;
et174 = t2.*t4.*t28.*t46.*3.285458367299594e+99;
et175 = t28.*t35.*t36.*t46.*3.567913541695871e+98;
et176 = -7.188039194994847e+100;
et177 = t384.*t387.*(et1+et2+et3+et4).*-3.961408125713217e+41+t372.*t387.*(et5+et6+et7+et8+et9+et10+et11+et12+et13+et14).*1.479031337816287e+42-t371.*t387.*(et15+et16+et17+et18+et19+et20+et21+et22+et23+et24+et25+et26+et27+et28+et29+et30+et31+et32+et33+et34+et35+et36+et37+et38+et39+et40+et41+et42+et43+et44+et45+et46+et47+et48+et49+et50+et51+et52+et53).*1.0e+10-t372.*t387.*(et54+et55+et56+et57+et58+et59+et60+et61+et62+et63+et64+et65+et66+et67+et68+et69+et70+et71+et72+et73).*3.2e+10;
et178 = t387.*(t58+t82+t84+t141-t353-t363+t367+t18.*t364+dqnsk.*t45.*(t5-t38).*5.952683917824e-2).*(et74+et75+et76+et77+et78+et79+et80+et81+et82+et83+et84+et85+et86+et87).*-1.25e+12-t371.*t387.*(et88+et89+et90+et91+et92+et93+et94+et95+et96+et97+et98+et99+et100+et101+et102+et103+et104+et105+et106+et107+et108+et109+et110+et111+et112+et113+et114+et115+et116+et117+et118+et119+et120+et121+et122+et123+et124+et125+et126+et127+et128).*2.0e+13;
et179 = t378.*t382.*t387.*-9.243945861351792e+44-t378.*t385.*t387.*1.25e+12+t381.*t384.*t387.*1.980704062856608e+41+t382.*t384.*t387.*9.243945861351792e+44;
et180 = t371.*t387.*(et129+et130+et131+et132+et133).*9.243945861351792e+44+t381.*t387.*(t58+t82+t84+t141-t353-t363+t367+t18.*t364+dqnsk.*t45.*(t5-t38).*5.952683917824e-2).*1.980704062856608e+41;
et181 = t385.*t387.*(t58+t82+t84+t141-t353-t363+t367+t18.*t364+dqnsk.*t45.*(t5-t38).*5.952683917824e-2).*1.25e+12-t372.*t387.*(et134+et135+et136+et137+et138+et139+et140+et141+et142+et143+et144+et145+et146+et147+et148+et149+et150+et151+et152+et153+et154+et155+et156+et157).*3.2e+10+t378.*t387.*(et158+et159+et160+et161+et162+et163+et164+et165+et166+et167+et168+et169+et170+et171+et172+et173+et174+et175+et176).*2.0e+10;
Lf2_t_lb = et177+et178+et179+et180+et181;
end
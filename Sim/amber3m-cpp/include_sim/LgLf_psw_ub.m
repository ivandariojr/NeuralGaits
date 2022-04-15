function LgLf_psw_ub = LgLf_psw_ub(in1,h,k,r,ub)
%LgLf_psw_ub
%    LgLf_psw_ub = LgLf_psw_ub(IN1,H,K,R,UB)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    05-Dec-2021 00:44:07

qnsh = in1(4,:);
qnsk = in1(5,:);
qsf = in1(1,:);
qsh = in1(3,:);
qsk = in1(2,:);
t2 = cos(qnsk);
t3 = cos(qsh);
t4 = cos(qsk);
t5 = qsh+qsk;
t10 = -h;
t11 = -k;
t12 = -qnsh;
t13 = -qnsk;
t14 = -qsh;
t15 = -qsk;
t16 = pi./2.0;
t17 = pi.*(3.0./2.0);
t6 = t2.^2;
t7 = t3.^2;
t8 = t4.^2;
t9 = cos(t5);
t19 = qnsh+t14;
t22 = t5+t12;
t23 = qsf+t16;
t34 = qnsh+qnsk-t5;
t56 = t3.*t4.*4.295141349249055e+65;
t75 = t3.*2.477674955752527e+97;
t76 = t4.*2.637184038791869e+98;
t77 = t3.*3.964279929204043e+98;
t79 = t3.*t4.*1.985202704965588e+97;
t84 = t3.*t4.*3.17632432794494e+98;
t87 = t3.*4.955349911505053e+100;
t92 = t2.*3.353832148630002e+102;
t18 = t9.^2;
t20 = cos(t19);
t21 = qnsk+t19;
t25 = cos(t22);
t26 = cos(t23);
t27 = qsk+t23;
t28 = sin(t23);
t35 = cos(t34);
t36 = qsf+t17+t22;
t54 = t9.*4.171233017896924e+65;
t58 = t6.*t9.*1.297954231040276e+65;
t59 = t3.*t4.*t6.*1.336510538551652e+65;
t78 = t9.*1.927932609626111e+97;
t80 = -t76;
t81 = -t77;
t83 = t9.*3.084692175401777e+98;
t85 = t3.*t6.*7.709731578560755e+96;
t86 = t6.*1.024176574588261e+98;
t88 = -t84;
t90 = t4.*t9.*2.279759110254527e+97;
t91 = -t87;
t94 = t6.*t9.*5.999109321124401e+96;
t95 = t3.*t4.*t6.*6.177315530748797e+96;
t97 = t4.*t6.*8.206072800285771e+97;
t98 = t6.*3.193154826116699e+100;
t99 = t3.*t6.*1.233557052569721e+98;
t100 = t3.*t9.*1.489570657853544e+98;
t102 = t4.*t9.*3.647614576407243e+98;
t103 = -t92;
t105 = t8.*9.722606021509767e+100;
t107 = t4.*t6.*t9.*7.093880802658621e+96;
t108 = t3.*t6.*1.541946315712151e+100;
t110 = t6.*t9.*9.598574913799042e+97;
t111 = t7.*1.456992417750339e+102;
t112 = t3.*t4.*t6.*9.883704849198075e+97;
t113 = t8.*2.373456356808413e+102;
t116 = t4.*t9.*4.559518220509054e+100;
t117 = t3.*t6.*t9.*4.635067207943333e+97;
t127 = t4.*t6.*t9.*1.135020928425379e+98;
t129 = t2.*t7.*1.950630464960712e+102;
t130 = t2.*t8.*3.177598057781022e+102;
t134 = t6.*t8.*1.512681929804875e+100;
t135 = t6.*t8.*3.02536385960975e+100;
t160 = t4.*t6.*t9.*1.418776160531724e+100;
t173 = t3.*t4.*t9.*2.681216702962767e+102;
t207 = t2.*t3.*t4.*t9.*3.589629513677318e+102;
t246 = t6.*3.992860538846184e+110;
t262 = t8.*1.215757206650896e+111;
t271 = t7.*7.463162433277769e+110;
t339 = t6.*t8.*3.783047371172374e+110;
t342 = t6.*t7.*2.322297319677836e+110;
t358 = t3.*t4.*t9.*1.373401503621102e+111;
t416 = t3.*t4.*t6.*t9.*4.273585975402672e+110;
t24 = cos(t21);
t29 = cos(t27);
t30 = t20.^2;
t31 = sin(t27);
t33 = t25.^2;
t37 = cos(t36);
t38 = t35.^2;
t39 = sin(t36);
t40 = t13+t36;
t45 = t26.*4.667e-1;
t46 = t28.*4.667e-1;
t57 = -t54;
t60 = -t59;
t63 = t3.*t20.*t25.*6.351712917353643e+64;
t70 = t2.*t3.*t20.*t35.*1.45141210632265e+64;
t82 = -t78;
t89 = -t85;
t93 = t20.*2.801270031321972e+97;
t96 = t18.*1.710587170325416e+98;
t101 = -t90;
t104 = -t95;
t106 = t25.*2.179728954847382e+97;
t109 = t4.*t20.*2.244478772571839e+97;
t119 = -t110;
t120 = t6.*t18.*5.322799866995949e+97;
t121 = t4.*t25.*2.577505519584836e+97;
t123 = t20.*5.602540062643945e+100;
t124 = t20.*1.750793769576233e+100;
t126 = -t117;
t128 = t18.*1.301933828265091e+102;
t137 = t25.*1.362330596779613e+100;
t140 = t7.*t25.*1.267757453639742e+97;
t144 = -t127;
t145 = t2.*t20.*2.343973532869821e+100;
t146 = t4.*t20.*1.402799232857399e+100;
t147 = t3.*t20.*6.747911422751707e+100;
t151 = -t135;
t152 = -t134;
t157 = t3.*t20.*2.108722319609908e+100;
t158 = t3.*t20.*3.373955711375853e+101;
t162 = t2.*t18.*1.74303706583323e+102;
t164 = t18.*t20.*1.455862213616308e+97;
t166 = t2.*t35.*4.980837507507526e+96;
t170 = t2.*t25.*1.823896633264277e+100;
t171 = t4.*t25.*1.610940949740522e+100;
t172 = t4.*t25.*5.155011039169671e+100;
t177 = t3.*t9.*t20.*1.267757453639742e+97;
t179 = t7.*t25.*7.923484085248385e+99;
t181 = t2.*t3.*t20.*2.823170490567743e+100;
t182 = t2.*t4.*t20.*1.878076293670899e+100;
t183 = -t160;
t184 = t3.*t9.*t25.*1.455862213616308e+97;
t194 = -t173;
t197 = t2.*t3.*t20.*4.517072784908389e+101;
t200 = t2.*t4.*t35.*5.889785580544675e+96;
t201 = t9.*t25.*1.88430419326191e+100;
t202 = t9.*t25.*6.029773418438111e+100;
t204 = t2.*t4.*t25.*2.156737712244608e+100;
t205 = t3.*t4.*t25.*1.940278287095829e+100;
t206 = t3.*t4.*t25.*6.208890518706654e+100;
t209 = t35.*1.339384211500942e+100;
t211 = t20.*t25.*3.899903300635676e+97;
t213 = t3.*t9.*t20.*7.923484085248385e+99;
t217 = t18.*t20.*9.099138835101922e+99;
t218 = t18.*t20.*2.911724427232615e+100;
t219 = t2.*t35.*3.113023442192204e+99;
t221 = t9.*t25.*3.014886709219055e+101;
t224 = t3.*t4.*t25.*3.104445259353327e+101;
t225 = -t207;
t226 = t3.*t20.*t25.*2.935744516743296e+96;
t230 = t4.*t9.*t20.*1.940278287095829e+100;
t231 = t4.*t9.*t20.*6.208890518706654e+100;
t235 = t2.*t9.*t25.*2.522718114281719e+100;
t236 = t3.*t9.*t25.*9.099138835101922e+99;
t237 = t3.*t9.*t25.*2.911724427232615e+100;
t238 = t2.*t3.*t4.*t25.*2.597656577482235e+100;
t240 = t4.*t35.*1.583807101479817e+100;
t243 = t2.*t7.*t35.*2.896917004964583e+96;
t245 = t3.*t20.*t25.*4.697191226789274e+97;
t248 = t2.*t7.*t25.*1.060800952497837e+100;
t250 = t4.*t9.*t20.*3.104445259353327e+101;
t254 = t2.*t18.*t20.*1.218198337920129e+100;
t255 = t2.*t4.*t35.*3.681115987840422e+99;
t257 = t2.*t9.*t25.*4.036348982850751e+101;
t260 = t2.*t3.*t4.*t25.*4.156250523971575e+101;
t261 = t9.*t20.*t25.*3.371338498927402e+96;
t266 = t2.*t3.*t9.*t20.*1.060800952497837e+100;
t267 = t2.*t4.*t9.*t20.*2.597656577482235e+100;
t268 = -t246;
t269 = t7.*t35.*7.790025056287781e+99;
t275 = t2.*t3.*t9.*t25.*1.218198337920129e+100;
t278 = t9.*t35.*1.852565957254429e+100;
t279 = t2.*t4.*t35.*1.177957116108935e+100;
t280 = t3.*t4.*t35.*1.907597252676734e+100;
t284 = t9.*t20.*t25.*5.394141598283844e+97;
t286 = -t262;
t291 = t2.*t4.*t9.*t20.*4.156250523971575e+101;
t294 = -t271;
t296 = t2.*t3.*t9.*t35.*3.326749916872468e+96;
t298 = t2.*t9.*t35.*4.30577066955087e+99;
t299 = t2.*t3.*t4.*t35.*4.433675501661638e+99;
t304 = t9.*t35.*2.964105531607087e+101;
t306 = t3.*t4.*t35.*3.052155604282775e+101;
t309 = t18.*6.66890473783269e+110;
t313 = t2.*t7.*t35.*1.810573128102865e+99;
t314 = t4.*t20.*t25.*1.437792082627523e+100;
t315 = t4.*t20.*t25.*2.875584165255047e+100;
t323 = t2.*t9.*t35.*1.377846614256279e+100;
t324 = t2.*t9.*t35.*6.889233071281393e+100;
t325 = t3.*t9.*t35.*8.945877691361976e+99;
t326 = t2.*t3.*t4.*t35.*1.418776160531724e+100;
t333 = t2.*t20.*t35.*8.911559665370708e+96;
t334 = t9.*t20.*t25.*6.742676997854805e+99;
t350 = t2.*t3.*t4.*t35.*7.093880802658621e+100;
t352 = t2.*t3.*t20.*t35.*6.708387466678575e+95;
t361 = t2.*t25.*t35.*2.046764220388046e+97;
t364 = t2.*t3.*t9.*t35.*2.079218698045293e+99;
t365 = t2.*t3.*t9.*t35.*6.653499833744936e+99;
t373 = t2.*t3.*t20.*t35.*1.073341994668572e+97;
t376 = t6.*t18.*2.07514974199132e+110;
t380 = t2.*t3.*t25.*t35.*1.540750211958116e+96;
t385 = t25.*t35.*3.351230546237944e+101;
t386 = t2.*t9.*t20.*t35.*7.703751059790579e+95;
t396 = t2.*t3.*t25.*t35.*2.465200339132985e+97;
t401 = t2.*t25.*t35.*6.381355725581329e+99;
t403 = t2.*t9.*t20.*t35.*1.232600169566493e+97;
t405 = t2.*t4.*t20.*t35.*3.285458367299594e+99;
t406 = t2.*t4.*t20.*t35.*6.570916734599188e+99;
t409 = t4.*t20.*t35.*3.450780339591372e+101;
t423 = t2.*t3.*t25.*t35.*3.081500423916231e+99;
t426 = -t416;
t430 = t2.*t9.*t20.*t35.*1.540750211958116e+99;
t439 = t7.*t25.*t35.*1.949117340672207e+101;
t443 = t20.*t25.*t35.*2.342155288282798e+99;
t444 = t3.*t9.*t20.*t35.*1.949117340672207e+101;
t454 = t4.*t20.*t25.*3.595756286437644e+110;
t460 = t3.*t20.*t25.*t35.*2.8209805279292e+99;
t465 = t3.*t20.*t25.*t35.*4.51356884468672e+100;
t471 = t3.*t9.*t20.*t25.*2.031004654314402e+110;
t479 = t2.*t25.*t35.*7.979526471004461e+109;
t480 = t2.*t4.*t20.*t35.*8.216561852571522e+109;
t486 = t2.*t7.*t25.*t35.*4.640991779108531e+109;
t490 = t2.*t3.*t9.*t20.*t35.*4.640991779108531e+109;
t32 = t24.^2;
t41 = cos(t40);
t42 = sin(t40);
t43 = t29.*(2.54e+2./6.25e+2);
t44 = t31.*(2.54e+2./6.25e+2);
t47 = t39.*(2.54e+2./6.25e+2);
t48 = t37.*(2.54e+2./6.25e+2);
t61 = t9.*t30.*6.351712917353643e+64;
t64 = -t63;
t65 = t2.*t3.*t24.*t25.*1.45141210632265e+64;
t66 = t2.*t9.*t20.*t24.*2.902824212645301e+64;
t67 = t3.*t24.*t35.*1.06584903120889e+64;
t114 = t2.*t24.*6.401103591176632e+96;
t115 = -t106;
t118 = t33.*4.478555291354996e+97;
t125 = t3.*t33.*3.371338498927402e+96;
t131 = t2.*t4.*t24.*5.128795500178607e+96;
t132 = -t120;
t133 = -t121;
t136 = t24.*1.721304313437495e+100;
t138 = t30.*7.81306546529768e+99;
t139 = -t123;
t142 = t3.*t33.*5.394141598283844e+97;
t143 = t30.*1.562613093059536e+100;
t148 = t9.*t30.*2.935744516743296e+96;
t153 = t2.*t24.*4.000689744485395e+99;
t155 = -t137;
t159 = t38.*7.515238614554655e+96;
t161 = t33.*1.396313955761959e+100;
t163 = -t147;
t165 = t9.*t30.*4.697191226789274e+97;
t168 = t3.*t24.*2.073204101854333e+100;
t169 = t4.*t24.*1.379171215001923e+100;
t174 = t2.*t24.*1.280220718235326e+100;
t178 = -t158;
t180 = t3.*t33.*6.742676997854805e+99;
t185 = -t164;
t187 = t2.*t4.*t24.*3.205497187611629e+99;
t188 = t2.*t3.*t24.*4.818582236600472e+99;
t190 = t3.*t24.*3.317126562966932e+101;
t192 = -t170;
t193 = -t171;
t196 = -t177;
t198 = t2.*t3.*t9.*t24.*2.896917004964583e+96;
t199 = t2.*t3.*t24.*1.541946315712151e+100;
t210 = t2.*t18.*t24.*3.326749916872468e+96;
t212 = t3.*t38.*5.657273746018297e+95;
t214 = t38.*2.343084292972739e+99;
t215 = -t197;
t216 = t3.*t9.*t24.*7.790025056287781e+99;
t220 = -t202;
t222 = -t204;
t223 = -t205;
t228 = t3.*t38.*9.051637993629275e+96;
t229 = -t213;
t232 = t2.*t3.*t24.*7.709731578560755e+100;
t233 = t38.*5.719874175083076e+100;
t234 = t4.*t9.*t24.*1.907597252676734e+100;
t239 = -t217;
t241 = -t221;
t244 = -t226;
t247 = t18.*t24.*8.945877691361976e+99;
t249 = -t230;
t251 = t2.*t24.*t25.*8.911559665370708e+96;
t252 = t2.*t3.*t9.*t24.*1.810573128102865e+99;
t253 = t2.*t4.*t9.*t24.*4.433675501661638e+99;
t256 = t4.*t9.*t24.*3.052155604282775e+101;
t258 = -t237;
t259 = -t238;
t263 = -t243;
t264 = t2.*t18.*t24.*2.079218698045293e+99;
t265 = t2.*t18.*t24.*6.653499833744936e+99;
t270 = t3.*t38.*1.131454749203659e+99;
t272 = t24.*t35.*6.544231782633408e+96;
t274 = t2.*t4.*t9.*t24.*1.418776160531724e+100;
t277 = -t254;
t282 = -t257;
t283 = t2.*t20.*t24.*7.141366715641245e+99;
t285 = t2.*t20.*t24.*3.570683357820623e+99;
t289 = -t266;
t290 = -t267;
t292 = t20.*t24.*3.750357652591714e+101;
t293 = -t269;
t295 = t2.*t3.*t24.*t25.*6.708387466678575e+95;
t297 = t20.*t38.*6.396138188712644e+95;
t301 = t2.*t4.*t9.*t24.*7.093880802658621e+100;
t303 = -t278;
t305 = -t279;
t307 = t2.*t9.*t20.*t24.*1.341677493335715e+96;
t310 = -t284;
t312 = t24.*t33.*2.342155288282798e+99;
t316 = t3.*t24.*t35.*4.926325370434617e+95;
t317 = t2.*t3.*t24.*t25.*1.073341994668572e+97;
t318 = -t296;
t322 = -t298;
t328 = t7.*t38.*3.326749916872468e+100;
t329 = -t306;
t331 = t2.*t9.*t20.*t24.*2.146683989337144e+97;
t332 = -t309;
t335 = -t313;
t336 = -t315;
t337 = -t314;
t338 = t2.*t9.*t24.*t25.*7.703751059790579e+95;
t341 = t3.*t24.*t35.*7.882120592695387e+96;
t344 = t20.*t38.*3.997586367945402e+98;
t347 = t4.*t24.*t25.*3.450780339591372e+101;
t348 = -t325;
t349 = -t326;
t353 = t30.*1.953959797292265e+110;
t354 = -t333;
t355 = t3.*t24.*t33.*2.8209805279292e+99;
t356 = -t334;
t360 = t2.*t9.*t24.*t25.*1.232600169566493e+97;
t362 = t2.*t4.*t24.*t25.*3.285458367299594e+99;
t363 = t2.*t4.*t24.*t25.*6.570916734599188e+99;
t367 = t20.*t38.*1.279227637742529e+99;
t368 = t30.*t35.*2.039536981268757e+99;
t370 = -t350;
t371 = t33.*1.74601207814982e+110;
t375 = t3.*t24.*t33.*4.51356884468672e+100;
t379 = t9.*t24.*t35.*5.657273746018297e+95;
t382 = -t361;
t383 = -t364;
t391 = -t373;
t392 = t30.*t38.*1.783956770847936e+98;
t393 = t30.*t38.*3.567913541695871e+98;
t395 = t9.*t24.*t35.*9.051637993629275e+96;
t397 = t2.*t9.*t24.*t25.*1.540750211958116e+99;
t398 = t3.*t20.*t38.*4.814844412369112e+98;
t400 = t4.*t24.*t35.*4.825373307289968e+99;
t402 = -t386;
t404 = t20.*t24.*t25.*2.039536981268757e+99;
t411 = -t396;
t413 = t3.*t20.*t38.*1.540750211958116e+99;
t414 = t3.*t20.*t38.*7.703751059790579e+99;
t415 = t18.*t20.*t24.*1.949117340672207e+101;
t418 = -t401;
t419 = t38.*2.929895141971185e+109;
t420 = t20.*t24.*t35.*5.569724790856693e+95;
t421 = -t409;
t422 = t9.*t24.*t35.*1.131454749203659e+99;
t424 = t3.*t9.*t24.*t25.*1.949117340672207e+101;
t427 = t4.*t24.*t35.*1.177957116108935e+101;
t431 = t7.*t33.*1.015502327157201e+110;
t432 = t24.*t25.*t35.*6.396138188712644e+95;
t433 = t9.*t30.*t35.*2.8209805279292e+99;
t435 = -t423;
t437 = t20.*t24.*t35.*3.481077994285433e+98;
t440 = t9.*t30.*t35.*4.51356884468672e+100;
t441 = t18.*t30.*1.015502327157201e+110;
t445 = -t439;
t446 = t24.*t25.*t35.*3.997586367945402e+98;
t447 = t3.*t9.*t24.*t35.*6.653499833744936e+100;
t449 = t9.*t20.*t24.*t25.*2.8209805279292e+99;
t450 = -t443;
t451 = t7.*t38.*1.70406343245411e+109;
t452 = t2.*t20.*t24.*8.929877473868346e+109;
t453 = t24.*t25.*t35.*1.279227637742529e+99;
t456 = t9.*t20.*t24.*t25.*4.51356884468672e+100;
t458 = t3.*t24.*t25.*t35.*4.814844412369112e+98;
t461 = t3.*t24.*t25.*t35.*1.540750211958116e+99;
t462 = t3.*t24.*t25.*t35.*7.703751059790579e+99;
t463 = t9.*t20.*t24.*t35.*4.814844412369112e+98;
t464 = -t460;
t468 = t9.*t20.*t24.*t35.*1.540750211958116e+99;
t469 = t9.*t20.*t24.*t35.*7.703751059790579e+99;
t470 = t2.*t4.*t24.*t25.*8.216561852571522e+109;
t472 = t30.*t38.*4.461475237634382e+108;
t475 = t4.*t24.*t35.*6.033857959625184e+109;
t477 = -t471;
t478 = t2.*t18.*t20.*t24.*4.640991779108531e+109;
t481 = t20.*t24.*t25.*t35.*3.567913541695871e+98;
t482 = t2.*t3.*t9.*t24.*t25.*4.640991779108531e+109;
t484 = -t480;
t485 = t20.*t24.*t25.*t35.*7.135827083391743e+98;
t487 = t3.*t9.*t24.*t35.*3.40812686490822e+109;
t488 = -t486;
t491 = t20.*t24.*t25.*t35.*8.922950475268764e+108;
t49 = t41.*4.667e-1;
t50 = t42.*4.667e-1;
t62 = t9.*t32.*1.06584903120889e+64;
t68 = -t66;
t69 = -t67;
t122 = -t114;
t141 = -t125;
t149 = -t131;
t150 = t32.*2.622142519762599e+99;
t154 = -t136;
t156 = t9.*t32.*4.926325370434617e+95;
t167 = t32.*6.401103591176632e+100;
t175 = -t153;
t176 = t9.*t32.*7.882120592695387e+96;
t186 = -t165;
t189 = -t168;
t191 = -t169;
t203 = -t187;
t208 = -t188;
t227 = -t212;
t242 = t25.*t32.*5.569724790856693e+95;
t273 = -t251;
t276 = t18.*t32.*3.326749916872468e+100;
t281 = -t256;
t287 = t25.*t32.*3.481077994285433e+98;
t288 = -t265;
t300 = -t274;
t308 = -t283;
t311 = -t285;
t319 = -t297;
t320 = t32.*t33.*1.783956770847936e+98;
t321 = t32.*t33.*3.567913541695871e+98;
t327 = -t301;
t330 = -t307;
t340 = -t316;
t343 = -t317;
t351 = -t328;
t357 = t32.*3.278841761369746e+109;
t359 = -t338;
t366 = -t344;
t369 = -t347;
t372 = t9.*t25.*t32.*4.814844412369112e+98;
t374 = -t353;
t384 = -t368;
t387 = -t371;
t389 = t9.*t25.*t32.*1.540750211958116e+99;
t390 = t9.*t25.*t32.*7.703751059790579e+99;
t394 = -t375;
t407 = -t393;
t408 = -t392;
t410 = -t395;
t412 = -t398;
t417 = -t400;
t425 = -t415;
t428 = -t419;
t429 = -t420;
t434 = -t422;
t436 = -t427;
t438 = t18.*t32.*1.70406343245411e+109;
t442 = -t437;
t448 = -t440;
t455 = -t449;
t457 = t32.*t33.*4.461475237634382e+108;
t459 = -t453;
t466 = -t462;
t467 = -t461;
t473 = -t469;
t474 = -t468;
t476 = -t470;
t483 = -t478;
t489 = -t487;
t492 = -t491;
t51 = t48+t49;
t52 = t47+t50;
t195 = -t176;
t302 = -t276;
t345 = -t321;
t346 = -t320;
t377 = -t357;
t388 = -t372;
t509 = t124+t145+t146+t154+t155+t175+t179+t182+t191+t192+t193+t203+t209+t216+t219+t222+t229+t236+t239+t240+t247+t248+t252+t255+t264+t275+t277+t287+t289+t293+t312+t335+t348+t366+t383+t384+t404+t442+t446+t450;
t510 = t75+t79+t82+t89+t93+t94+t101+t104+t107+t109+t115+t122+t133+t140+t141+t148+t149+t156+t166+t184+t185+t196+t198+t200+t210+t227+t242+t244+t261+t263+t295+t318+t319+t330+t340+t352+t359+t379+t380+t402+t429+t432;
t53 = t44+t52;
t55 = t43+t51;
t506 = t80+t81+t83+t86+t88+t96+t97+t99+t100+t102+t112+t118+t119+t126+t132+t142+t144+t159+t186+t195+t211+t228+t245+t272+t273+t310+t331+t341+t343+t354+t360+t382+t391+t403+t410+t411-3.291394289500617e+98;
t507 = t268+t286+t294+t332+t339+t342+t358+t374+t376+t377+t387+t426+t428+t431+t438+t441+t451+t452+t454+t457+t472+t475+t476+t477+t479+t482+t483+t484+t488+t489+t490+t492+1.283184824024515e+111;
t511 = t124+t145+t154+t157+t175+t181+t189+t193+t201+t208+t222+t223+t234+t235+t236+t239+t240+t247+t249+t253+t255+t259+t264+t275+t277+t280+t290+t299+t303+t312+t322+t348+t355+t366+t383+t388+t412+t433+t446+t450+t455+t458+t463+t464;
t512 = t103+t111+t113+t128+t129+t130+t162+t167+t178+t190+t194+t215+t224+t225+t232+t233+t241+t250+t260+t281+t282+t291+t292+t302+t304+t324+t327+t329+t351+t369+t370+t385+t390+t394+t414+t421+t424+t425+t436+t444+t445+t447+t448+t456+t465+t466+t473-2.505091609475945e+102;
t513 = t91+t98+t105+t108+t116+t139+t143+t150+t151+t161+t163+t172+t174+t180+t183+t199+t206+t214+t218+t220+t231+t258+t270+t288+t300+t305+t308+t323+t336+t345+t349+t356+t363+t365+t367+t389+t397+t406+t407+t413+t417+t418+t430+t434+t435+t459+t467+t474+t485-1.026183552811392e+101;
t71 = t45+t55;
t72 = t46+t53;
t508 = 1.0./t507;
t73 = t11+t72;
LgLf_psw_ub = ft_1({t10,t108,t116,t118,t132,t138,t152,t159,t163,t18,t180,t183,t199,t2,t20,t206,t220,t231,t24,t25,t270,t3,t30,t300,t311,t32,t323,t33,t337,t346,t349,t35,t356,t362,t38,t382,t389,t397,t4,t405,t408,t41,t413,t42,t430,t434,t435,t467,t474,t481,t506,t508,t509,t51,t510,t511,t512,t513,t52,t53,t55,t56,t57,t58,t6,t60,t61,t62,t64,t65,t68,t69,t7,t70,t71,t72,t73,t8,t9,t91,t96});
end
function LgLf_psw_ub = ft_1(ct)
t10 = ct{1};
t108 = ct{2};
t116 = ct{3};
t118 = ct{4};
t132 = ct{5};
t138 = ct{6};
t152 = ct{7};
t159 = ct{8};
t163 = ct{9};
t18 = ct{10};
t180 = ct{11};
t183 = ct{12};
t199 = ct{13};
t2 = ct{14};
t20 = ct{15};
t206 = ct{16};
t220 = ct{17};
t231 = ct{18};
t24 = ct{19};
t25 = ct{20};
t270 = ct{21};
t3 = ct{22};
t30 = ct{23};
t300 = ct{24};
t311 = ct{25};
t32 = ct{26};
t323 = ct{27};
t33 = ct{28};
t337 = ct{29};
t346 = ct{30};
t349 = ct{31};
t35 = ct{32};
t356 = ct{33};
t362 = ct{34};
t38 = ct{35};
t382 = ct{36};
t389 = ct{37};
t397 = ct{38};
t4 = ct{39};
t405 = ct{40};
t408 = ct{41};
t41 = ct{42};
t413 = ct{43};
t42 = ct{44};
t430 = ct{45};
t434 = ct{46};
t435 = ct{47};
t467 = ct{48};
t474 = ct{49};
t481 = ct{50};
t506 = ct{51};
t508 = ct{52};
t509 = ct{53};
t51 = ct{54};
t510 = ct{55};
t511 = ct{56};
t512 = ct{57};
t513 = ct{58};
t52 = ct{59};
t53 = ct{60};
t55 = ct{61};
t56 = ct{62};
t57 = ct{63};
t58 = ct{64};
t6 = ct{65};
t60 = ct{66};
t61 = ct{67};
t62 = ct{68};
t64 = ct{69};
t65 = ct{70};
t68 = ct{71};
t69 = ct{72};
t7 = ct{73};
t70 = ct{74};
t71 = ct{75};
t72 = ct{76};
t73 = ct{77};
t8 = ct{78};
t9 = ct{79};
t91 = ct{80};
t96 = ct{81};
t74 = t10+t71;
t378 = t42.*t74.*9.334e-1;
t381 = t41.*t73.*9.334e-1;
t493 = t52.*t74.*2.0;
t494 = t51.*t73.*2.0;
t496 = t53.*t74.*2.0;
t497 = t55.*t73.*2.0;
t499 = t72.*t74.*2.0;
t500 = t71.*t73.*2.0;
t399 = -t381;
t495 = -t494;
t498 = -t497;
t501 = -t500;
t502 = t378+t399;
t503 = t493+t495;
t504 = t496+t498;
t505 = t499+t501;
t514 = t503.*t508.*t513.*1.0e+10;
et1 = t4.*-1.664297110460606e+69+t6.*4.379541796137363e+68;
et2 = t7.*8.185918714142532e+68+t30.*2.143187450941225e+68;
et3 = t32.*3.596375179431889e+67+t4.*t6.*5.178760014034365e+68;
et4 = t3.*t9.*9.400512460360038e+68-t6.*t7.*2.547195945272321e+68;
et5 = t20.*t25.*2.461184998411097e+68+t24.*t35.*4.129990886419445e+67;
et6 = t3.*t6.*t9.*-2.925138650734724e+68-t2.*t20.*t24.*9.794675083365973e+67;
et7 = t2.*t24.*t25.*-5.623984819644315e+67-t2.*t20.*t35.*5.623984819644315e+67;
et8 = -1.407452505368112e+69;
et9 = t4.*-5.274368077583737e+98;
et10 = t6.*1.718142672913029e+98;
et11 = t7.*1.297110596425284e+98;
et12 = t30.*3.396016073234067e+97+t32.*5.698683943565925e+96+t96;
et13 = t118+t132+t159+t382+t4.*t6.*1.641214560057154e+98;
et14 = t3.*t9.*2.979141315707088e+98;
et15 = t6.*t7.*-4.036193086154212e+97;
et16 = t20.*t25.*7.799806601271353e+97;
et17 = t24.*t35.*1.308846356526682e+97;
et18 = t3.*t6.*t9.*-9.270134415886666e+97;
et19 = t2.*t20.*t24.*-1.55202821855867e+97;
et20 = t2.*t24.*t25.*-1.782311933074142e+97;
et21 = t2.*t20.*t35.*-1.782311933074142e+97;
et22 = -5.521591806028882e+98;
et23 = t6.*2.236687772176013e+100;
et24 = t8.*4.861303010754884e+100;
et25 = t18.*1.069116981453385e+100;
et26 = t32.*1.3110712598813e+99;
et27 = t33.*9.78066683590667e+99;
et28 = t38.*1.641244559896035e+99+t91+t108+t116+t138+t152+t180+t183+t270+t311+t337+t346+t356+t362+t397+t405+t408+t430+t434+t435+t481;
et29 = t6.*t18.*-3.326749916872468e+99;
et30 = t2.*t25.*t35.*-4.469905500533193e+99;
et31 = t4.*t24.*t35.*-2.412686653644984e+99;
et32 = -7.188039194994847e+100;
et33 = t4.*3.566096229827739e+65+t56+t57+t58+t60+t61+t62+t64+t65+t68+t69+t70-t4.*t6.*1.109655027648246e+65;
et34 = t3.*t9.*-2.014251652102001e+65-t20.*t25.*5.27359116865459e+64;
et35 = t24.*t35.*-8.84934837458634e+63+t3.*t6.*t9.*6.26770655824882e+64;
et36 = t2.*t24.*t25.*1.205053528957428e+64+t2.*t20.*t35.*1.205053528957428e+64;
et37 = t6.*1.59657741305835e+100;
et38 = t7.*1.456992417750339e+101;
et39 = t8.*2.859586657883902e+101;
et40 = t18.*1.301933828265091e+101;
et41 = t32.*7.712174851057932e+99;
et42 = t33.*6.981569778809797e+99;
et43 = t38.*6.891416321569446e+99+t138+t152+t163+t199+t206+t220+t231+t300+t311+t323+t337+t346+t349+t362+t389+t405+t408+t413+t467+t474+t481;
et44 = t7.*t38.*-3.326749916872468e+99;
et45 = t18.*t32.*-3.326749916872468e+99;
et46 = t3.*t4.*t9.*-2.681216702962767e+101;
et47 = t2.*t25.*t35.*-3.190677862790664e+99;
et48 = t4.*t24.*t35.*-1.419225781473433e+100;
et49 = t3.*t9.*t24.*t35.*6.653499833744936e+99;
et50 = -3.018183385881641e+101;
et51 = t25.*-4.716014108132451e+65+t56+t57+t58+t60+t61+t62+t64+t65+t68+t69+t70+t4.*t20.*4.856105403983006e+65;
et52 = t7.*t25.*2.742892424197626e+65+t2.*t35.*1.077643158498367e+65;
et53 = t25.*t32.*1.205053528957428e+64-t2.*t4.*t24.*1.109655027648246e+65;
et54 = t3.*t9.*t20.*-2.742892424197626e+65-t2.*t7.*t35.*6.26770655824882e+64;
et55 = t20.*t24.*t35.*-1.205053528957428e+64+t2.*t3.*t9.*t24.*6.26770655824882e+64;
et56 = t25.*2.947508817582782e+68-t35.*2.897862517998514e+68;
et57 = t4.*t20.*-3.035065877489379e+68+t2.*t25.*3.94614304458412e+68;
et58 = t4.*t24.*2.983944812502915e+68-t7.*t25.*1.714307765123516e+68;
et59 = t2.*t35.*-6.735269740614793e+67+t7.*t35.*1.685432860193883e+68;
et60 = t25.*t32.*-7.531584555983923e+66+t30.*t35.*4.412697806454926e+67;
et61 = t2.*t4.*t20.*-4.063364978202626e+68+t2.*t4.*t24.*6.935343922801539e+67;
et62 = t3.*t9.*t20.*1.714307765123516e+68-t2.*t7.*t25.*2.295125844327934e+68;
et63 = t3.*t9.*t24.*-1.685432860193883e+68+t2.*t7.*t35.*3.917316598905513e+67;
et64 = t20.*t24.*t25.*-4.412697806454926e+67+t20.*t24.*t35.*7.531584555983923e+66;
et65 = t2.*t3.*t9.*t20.*2.295125844327934e+68-t2.*t3.*t9.*t24.*3.917316598905513e+67;
et66 = t2.*-4.192290185787502e+105;
et67 = t7.*6.156010505813107e+105;
et68 = t8.*1.002820748385332e+106;
et69 = t18.*5.500864813729409e+105;
et70 = t30.*1.373316171384579e+105;
et71 = t32.*4.000689744485395e+103;
et72 = t33.*1.227162721402341e+105;
et73 = t38.*3.574921359426923e+103;
et74 = t2.*t7.*2.43828808120089e+105;
et75 = t2.*t8.*3.971997572226278e+105;
et76 = t2.*t18.*2.178796332291538e+105;
et77 = t7.*t33.*-7.137330921016171e+104;
et78 = t20.*t24.*4.687947065739642e+104;
et79 = t7.*t38.*-2.079218698045293e+103;
et80 = t18.*t30.*-7.137330921016171e+104;
et81 = t18.*t32.*-2.079218698045293e+103;
et82 = t25.*t35.*4.189038182797431e+104;
et83 = t3.*t4.*t9.*-1.132854089747821e+106;
et84 = t4.*t20.*t25.*-2.527232271291176e+105;
et85 = t4.*t24.*t25.*-4.313475424489216e+104;
et86 = t4.*t20.*t35.*-4.313475424489216e+104;
et87 = t18.*t20.*t24.*-2.436396675840258e+104;
et88 = t4.*t24.*t35.*-7.362231975680843e+103;
et89 = t7.*t25.*t35.*-2.436396675840258e+104;
et90 = t2.*t3.*t4.*t9.*-4.487036892096648e+105;
et91 = t3.*t9.*t20.*t25.*1.427466184203234e+105;
et92 = t3.*t9.*t24.*t25.*2.436396675840258e+104;
et93 = t3.*t9.*t20.*t35.*2.436396675840258e+104;
et94 = t3.*t9.*t24.*t35.*4.158437396090585e+103;
et95 = -1.058438608058748e+106;
mt1 = [t505.*t508.*(et1+et2+et3+et4+et5+et6+et7+et8).*1.980704062856608e+41-t504.*t508.*(et9+et10+et11+et12+et13+et14+et15+et16+et17+et18+et19+et20+et21+et22).*1.25e+12+t503.*t506.*t508.*1.25e+12-t502.*t508.*t509.*3.2e+10+t503.*t508.*t510.*2.0e+13];
mt2 = [t514-t503.*t508.*(et23+et24+et25+et26+et27+et28+et29+et30+et31+et32).*2.0e+10+t504.*t506.*t508.*1.25e+12+t502.*t508.*t511.*3.2e+10+t505.*t508.*(et33+et34+et35+et36).*9.243945861351792e+44];
mt3 = [-t514+t503.*t508.*(et37+et38+et39+et40+et41+et42+et43+et44+et45+et46+et47+et48+et49+et50).*2.0e+10-t502.*t508.*t512.*2.0e+9-t504.*t508.*t510.*2.0e+13+t505.*t508.*(et51+et52+et53+et54+et55).*9.243945861351792e+44];
mt4 = [t505.*t508.*(et56+et57+et58+et59+et60+et61+et62+et63+et64+et65).*1.479031337816287e+42+t504.*t508.*t509.*3.2e+10-t503.*t508.*t511.*3.2e+10-t503.*t508.*t512.*2.0e+9+t502.*t508.*(et66+et67+et68+et69+et70+et71+et72+et73+et74+et75+et76+et77+et78+et79+et80+et81+et82+et83+et84+et85+et86+et87+et88+et89+et90+et91+et92+et93+et94+et95).*3.2e+6];
LgLf_psw_ub = reshape([mt1,mt2,mt3,mt4],1,4);
end
function LgLfs1 = CBF_LgLfs1(in1,in2,in3,ldes,r,m1,a)
%CBF_LGLFS1
%    LGLFS1 = CBF_LGLFS1(IN1,IN2,IN3,LDES,R,M1,A)

%    This function was generated by the Symbolic Math Toolbox version 8.3.
%    09-Nov-2020 22:01:44

c1 = in2(:,1);
c2 = in2(:,2);
c3 = in2(:,3);
c4 = in2(:,4);
c5 = in2(:,5);
qnsh = in1(4,:);
qnsk = in1(5,:);
qsf = in1(1,:);
qsh = in1(3,:);
qsk = in1(2,:);
thetamp1 = in3(:,1);
thetamp2 = in3(:,2);
t2 = cos(qnsk);
t3 = cos(qsh);
t4 = cos(qsk);
t5 = a.*r;
t6 = c4.*qnsh;
t7 = c5.*qnsk;
t8 = c1.*qsf;
t9 = c3.*qsh;
t10 = c2.*qsk;
t11 = qsh+qsk;
t16 = 1.0./a;
t17 = -qnsh;
t18 = -qnsk;
t19 = -qsh;
t20 = -qsk;
t21 = 1.0./r;
t22 = -thetamp2;
t23 = pi./2.0;
t24 = pi.*(3.0./2.0);
t12 = t2.^2;
t13 = t3.^2;
t14 = t4.^2;
t15 = cos(t11);
t26 = t5-1.0;
t27 = qnsh+t19;
t28 = t22+thetamp1;
t31 = t11+t17;
t32 = qsf+t23;
t42 = qnsh+qnsk-t11;
t53 = t6+t7+t8+t9+t10+t22;
t64 = t3.*t4.*4.295141349249055e+65;
t79 = t3.*2.477674955752527e+97;
t80 = t4.*2.637184038791869e+98;
t81 = t3.*3.964279929204043e+98;
t83 = t3.*t4.*1.985202704965588e+97;
t88 = t3.*t4.*3.17632432794494e+98;
t91 = t3.*4.955349911505053e+100;
t96 = t2.*3.353832148630002e+102;
t25 = t15.^2;
t29 = cos(t27);
t30 = qnsk+t27;
t34 = cos(t31);
t35 = qsk+t32;
t36 = sin(t32);
t37 = 1.0./t28;
t43 = cos(t42);
t44 = qsf+t24+t31;
t47 = t26./t5;
t63 = t15.*4.171233017896924e+65;
t66 = t12.*t15.*1.297954231040276e+65;
t67 = t3.*t4.*t12.*1.336510538551652e+65;
t82 = t15.*1.927932609626111e+97;
t84 = -t80;
t85 = -t81;
t87 = t15.*3.084692175401777e+98;
t89 = t3.*t12.*7.709731578560755e+96;
t90 = t12.*1.024176574588261e+98;
t92 = -t88;
t94 = t4.*t15.*2.279759110254527e+97;
t95 = -t91;
t98 = t12.*t15.*5.999109321124401e+96;
t99 = t3.*t4.*t12.*6.177315530748797e+96;
t101 = t4.*t12.*8.206072800285771e+97;
t102 = t12.*3.193154826116699e+100;
t103 = t3.*t12.*1.233557052569721e+98;
t104 = t3.*t15.*1.489570657853544e+98;
t106 = t4.*t15.*3.647614576407243e+98;
t107 = -t96;
t109 = t14.*9.722606021509767e+100;
t111 = t4.*t12.*t15.*7.093880802658621e+96;
t112 = t3.*t12.*1.541946315712151e+100;
t114 = t12.*t15.*9.598574913799042e+97;
t115 = t13.*1.456992417750339e+102;
t116 = t3.*t4.*t12.*9.883704849198075e+97;
t117 = t14.*2.373456356808413e+102;
t120 = t4.*t15.*4.559518220509054e+100;
t121 = t3.*t12.*t15.*4.635067207943333e+97;
t131 = t4.*t12.*t15.*1.135020928425379e+98;
t133 = t2.*t13.*1.950630464960712e+102;
t134 = t2.*t14.*3.177598057781022e+102;
t138 = t12.*t14.*1.512681929804875e+100;
t139 = t12.*t14.*3.02536385960975e+100;
t164 = t4.*t12.*t15.*1.418776160531724e+100;
t177 = t3.*t4.*t15.*2.681216702962767e+102;
t211 = t2.*t3.*t4.*t15.*3.589629513677318e+102;
t250 = t12.*3.992860538846184e+110;
t266 = t14.*1.215757206650896e+111;
t275 = t13.*7.463162433277769e+110;
t343 = t12.*t14.*3.783047371172374e+110;
t346 = t12.*t13.*2.322297319677836e+110;
t362 = t3.*t4.*t15.*1.373401503621102e+111;
t422 = t3.*t4.*t12.*t15.*4.273585975402672e+110;
t33 = cos(t30);
t38 = t29.^2;
t39 = sin(t35);
t41 = t34.^2;
t45 = t43.^2;
t46 = sin(t44);
t48 = t18+t44;
t49 = -t47;
t52 = t36.*4.667e-1;
t56 = t37.*t53;
t65 = -t63;
t68 = -t67;
t71 = t3.*t29.*t34.*6.351712917353643e+64;
t78 = t2.*t3.*t29.*t43.*1.45141210632265e+64;
t86 = -t82;
t93 = -t89;
t97 = t29.*2.801270031321972e+97;
t100 = t25.*1.710587170325416e+98;
t105 = -t94;
t108 = -t99;
t110 = t34.*2.179728954847382e+97;
t113 = t4.*t29.*2.244478772571839e+97;
t123 = -t114;
t124 = t12.*t25.*5.322799866995949e+97;
t125 = t4.*t34.*2.577505519584836e+97;
t127 = t29.*5.602540062643945e+100;
t128 = t29.*1.750793769576233e+100;
t130 = -t121;
t132 = t25.*1.301933828265091e+102;
t141 = t34.*1.362330596779613e+100;
t144 = t13.*t34.*1.267757453639742e+97;
t148 = -t131;
t149 = t2.*t29.*2.343973532869821e+100;
t150 = t4.*t29.*1.402799232857399e+100;
t151 = t3.*t29.*6.747911422751707e+100;
t155 = -t139;
t156 = -t138;
t161 = t3.*t29.*2.108722319609908e+100;
t162 = t3.*t29.*3.373955711375853e+101;
t166 = t2.*t25.*1.74303706583323e+102;
t168 = t25.*t29.*1.455862213616308e+97;
t170 = t2.*t43.*4.980837507507526e+96;
t174 = t2.*t34.*1.823896633264277e+100;
t175 = t4.*t34.*1.610940949740522e+100;
t176 = t4.*t34.*5.155011039169671e+100;
t181 = t3.*t15.*t29.*1.267757453639742e+97;
t183 = t13.*t34.*7.923484085248385e+99;
t185 = t2.*t3.*t29.*2.823170490567743e+100;
t186 = t2.*t4.*t29.*1.878076293670899e+100;
t187 = -t164;
t188 = t3.*t15.*t34.*1.455862213616308e+97;
t198 = -t177;
t201 = t2.*t3.*t29.*4.517072784908389e+101;
t204 = t2.*t4.*t43.*5.889785580544675e+96;
t205 = t15.*t34.*1.88430419326191e+100;
t206 = t15.*t34.*6.029773418438111e+100;
t208 = t2.*t4.*t34.*2.156737712244608e+100;
t209 = t3.*t4.*t34.*1.940278287095829e+100;
t210 = t3.*t4.*t34.*6.208890518706654e+100;
t213 = t43.*1.339384211500942e+100;
t215 = t29.*t34.*3.899903300635676e+97;
t217 = t3.*t15.*t29.*7.923484085248385e+99;
t221 = t25.*t29.*9.099138835101922e+99;
t222 = t25.*t29.*2.911724427232615e+100;
t223 = t2.*t43.*3.113023442192204e+99;
t225 = t15.*t34.*3.014886709219055e+101;
t228 = t3.*t4.*t34.*3.104445259353327e+101;
t229 = -t211;
t230 = t3.*t29.*t34.*2.935744516743296e+96;
t234 = t4.*t15.*t29.*1.940278287095829e+100;
t235 = t4.*t15.*t29.*6.208890518706654e+100;
t239 = t2.*t15.*t34.*2.522718114281719e+100;
t240 = t3.*t15.*t34.*9.099138835101922e+99;
t241 = t3.*t15.*t34.*2.911724427232615e+100;
t242 = t2.*t3.*t4.*t34.*2.597656577482235e+100;
t244 = t4.*t43.*1.583807101479817e+100;
t247 = t2.*t13.*t43.*2.896917004964583e+96;
t249 = t3.*t29.*t34.*4.697191226789274e+97;
t252 = t2.*t13.*t34.*1.060800952497837e+100;
t254 = t4.*t15.*t29.*3.104445259353327e+101;
t258 = t2.*t25.*t29.*1.218198337920129e+100;
t259 = t2.*t4.*t43.*3.681115987840422e+99;
t261 = t2.*t15.*t34.*4.036348982850751e+101;
t264 = t2.*t3.*t4.*t34.*4.156250523971575e+101;
t265 = t15.*t29.*t34.*3.371338498927402e+96;
t270 = t2.*t3.*t15.*t29.*1.060800952497837e+100;
t271 = t2.*t4.*t15.*t29.*2.597656577482235e+100;
t272 = -t250;
t273 = t13.*t43.*7.790025056287781e+99;
t279 = t2.*t3.*t15.*t34.*1.218198337920129e+100;
t282 = t15.*t43.*1.852565957254429e+100;
t283 = t2.*t4.*t43.*1.177957116108935e+100;
t284 = t3.*t4.*t43.*1.907597252676734e+100;
t288 = t15.*t29.*t34.*5.394141598283844e+97;
t290 = -t266;
t295 = t2.*t4.*t15.*t29.*4.156250523971575e+101;
t298 = -t275;
t300 = t2.*t3.*t15.*t43.*3.326749916872468e+96;
t302 = t2.*t15.*t43.*4.30577066955087e+99;
t303 = t2.*t3.*t4.*t43.*4.433675501661638e+99;
t308 = t15.*t43.*2.964105531607087e+101;
t310 = t3.*t4.*t43.*3.052155604282775e+101;
t313 = t25.*6.66890473783269e+110;
t317 = t2.*t13.*t43.*1.810573128102865e+99;
t318 = t4.*t29.*t34.*1.437792082627523e+100;
t319 = t4.*t29.*t34.*2.875584165255047e+100;
t327 = t2.*t15.*t43.*1.377846614256279e+100;
t328 = t2.*t15.*t43.*6.889233071281393e+100;
t329 = t3.*t15.*t43.*8.945877691361976e+99;
t330 = t2.*t3.*t4.*t43.*1.418776160531724e+100;
t337 = t2.*t29.*t43.*8.911559665370708e+96;
t338 = t15.*t29.*t34.*6.742676997854805e+99;
t354 = t2.*t3.*t4.*t43.*7.093880802658621e+100;
t356 = t2.*t3.*t29.*t43.*6.708387466678575e+95;
t365 = t2.*t34.*t43.*2.046764220388046e+97;
t368 = t2.*t3.*t15.*t43.*2.079218698045293e+99;
t369 = t2.*t3.*t15.*t43.*6.653499833744936e+99;
t377 = t2.*t3.*t29.*t43.*1.073341994668572e+97;
t380 = t12.*t25.*2.07514974199132e+110;
t383 = t2.*t3.*t34.*t43.*1.540750211958116e+96;
t387 = t34.*t43.*3.351230546237944e+101;
t388 = t2.*t15.*t29.*t43.*7.703751059790579e+95;
t398 = t2.*t3.*t34.*t43.*2.465200339132985e+97;
t402 = t2.*t34.*t43.*6.381355725581329e+99;
t409 = t2.*t15.*t29.*t43.*1.232600169566493e+97;
t411 = t2.*t4.*t29.*t43.*3.285458367299594e+99;
t412 = t2.*t4.*t29.*t43.*6.570916734599188e+99;
t415 = t4.*t29.*t43.*3.450780339591372e+101;
t429 = t2.*t3.*t34.*t43.*3.081500423916231e+99;
t432 = -t422;
t439 = t2.*t15.*t29.*t43.*1.540750211958116e+99;
t448 = t13.*t34.*t43.*1.949117340672207e+101;
t452 = t29.*t34.*t43.*2.342155288282798e+99;
t453 = t3.*t15.*t29.*t43.*1.949117340672207e+101;
t463 = t4.*t29.*t34.*3.595756286437644e+110;
t469 = t3.*t29.*t34.*t43.*2.8209805279292e+99;
t474 = t3.*t29.*t34.*t43.*4.51356884468672e+100;
t480 = t3.*t15.*t29.*t34.*2.031004654314402e+110;
t488 = t2.*t34.*t43.*7.979526471004461e+109;
t489 = t2.*t4.*t29.*t43.*8.216561852571522e+109;
t495 = t2.*t13.*t34.*t43.*4.640991779108531e+109;
t499 = t2.*t3.*t15.*t29.*t43.*4.640991779108531e+109;
t40 = t33.^2;
t50 = sin(t48);
t51 = t39.*(2.54e+2./6.25e+2);
t54 = t46.*(2.54e+2./6.25e+2);
t57 = t56-1.0;
t69 = t15.*t38.*6.351712917353643e+64;
t72 = -t71;
t73 = t2.*t3.*t33.*t34.*1.45141210632265e+64;
t74 = t2.*t15.*t29.*t33.*2.902824212645301e+64;
t75 = t3.*t33.*t43.*1.06584903120889e+64;
t118 = t2.*t33.*6.401103591176632e+96;
t119 = -t110;
t122 = t41.*4.478555291354996e+97;
t129 = t3.*t41.*3.371338498927402e+96;
t135 = t2.*t4.*t33.*5.128795500178607e+96;
t136 = -t124;
t137 = -t125;
t140 = t33.*1.721304313437495e+100;
t142 = t38.*7.81306546529768e+99;
t143 = -t127;
t146 = t3.*t41.*5.394141598283844e+97;
t147 = t38.*1.562613093059536e+100;
t152 = t15.*t38.*2.935744516743296e+96;
t157 = t2.*t33.*4.000689744485395e+99;
t159 = -t141;
t163 = t45.*7.515238614554655e+96;
t165 = t41.*1.396313955761959e+100;
t167 = -t151;
t169 = t15.*t38.*4.697191226789274e+97;
t172 = t3.*t33.*2.073204101854333e+100;
t173 = t4.*t33.*1.379171215001923e+100;
t178 = t2.*t33.*1.280220718235326e+100;
t182 = -t162;
t184 = t3.*t41.*6.742676997854805e+99;
t189 = -t168;
t191 = t2.*t4.*t33.*3.205497187611629e+99;
t192 = t2.*t3.*t33.*4.818582236600472e+99;
t194 = t3.*t33.*3.317126562966932e+101;
t196 = -t174;
t197 = -t175;
t200 = -t181;
t202 = t2.*t3.*t15.*t33.*2.896917004964583e+96;
t203 = t2.*t3.*t33.*1.541946315712151e+100;
t214 = t2.*t25.*t33.*3.326749916872468e+96;
t216 = t3.*t45.*5.657273746018297e+95;
t218 = t45.*2.343084292972739e+99;
t219 = -t201;
t220 = t3.*t15.*t33.*7.790025056287781e+99;
t224 = -t206;
t226 = -t208;
t227 = -t209;
t232 = t3.*t45.*9.051637993629275e+96;
t233 = -t217;
t236 = t2.*t3.*t33.*7.709731578560755e+100;
t237 = t45.*5.719874175083076e+100;
t238 = t4.*t15.*t33.*1.907597252676734e+100;
t243 = -t221;
t245 = -t225;
t248 = -t230;
t251 = t25.*t33.*8.945877691361976e+99;
t253 = -t234;
t255 = t2.*t33.*t34.*8.911559665370708e+96;
t256 = t2.*t3.*t15.*t33.*1.810573128102865e+99;
t257 = t2.*t4.*t15.*t33.*4.433675501661638e+99;
t260 = t4.*t15.*t33.*3.052155604282775e+101;
t262 = -t241;
t263 = -t242;
t267 = -t247;
t268 = t2.*t25.*t33.*2.079218698045293e+99;
t269 = t2.*t25.*t33.*6.653499833744936e+99;
t274 = t3.*t45.*1.131454749203659e+99;
t276 = t33.*t43.*6.544231782633408e+96;
t278 = t2.*t4.*t15.*t33.*1.418776160531724e+100;
t281 = -t258;
t286 = -t261;
t287 = t2.*t29.*t33.*7.141366715641245e+99;
t289 = t2.*t29.*t33.*3.570683357820623e+99;
t293 = -t270;
t294 = -t271;
t296 = t29.*t33.*3.750357652591714e+101;
t297 = -t273;
t299 = t2.*t3.*t33.*t34.*6.708387466678575e+95;
t301 = t29.*t45.*6.396138188712644e+95;
t305 = t2.*t4.*t15.*t33.*7.093880802658621e+100;
t307 = -t282;
t309 = -t283;
t311 = t2.*t15.*t29.*t33.*1.341677493335715e+96;
t314 = -t288;
t316 = t33.*t41.*2.342155288282798e+99;
t320 = t3.*t33.*t43.*4.926325370434617e+95;
t321 = t2.*t3.*t33.*t34.*1.073341994668572e+97;
t322 = -t300;
t326 = -t302;
t332 = t13.*t45.*3.326749916872468e+100;
t333 = -t310;
t335 = t2.*t15.*t29.*t33.*2.146683989337144e+97;
t336 = -t313;
t339 = -t317;
t340 = -t319;
t341 = -t318;
t342 = t2.*t15.*t33.*t34.*7.703751059790579e+95;
t345 = t3.*t33.*t43.*7.882120592695387e+96;
t348 = t29.*t45.*3.997586367945402e+98;
t351 = t4.*t33.*t34.*3.450780339591372e+101;
t352 = -t329;
t353 = -t330;
t357 = t38.*1.953959797292265e+110;
t358 = -t337;
t359 = t3.*t33.*t41.*2.8209805279292e+99;
t360 = -t338;
t364 = t2.*t15.*t33.*t34.*1.232600169566493e+97;
t366 = t2.*t4.*t33.*t34.*3.285458367299594e+99;
t367 = t2.*t4.*t33.*t34.*6.570916734599188e+99;
t371 = t29.*t45.*1.279227637742529e+99;
t372 = t38.*t43.*2.039536981268757e+99;
t374 = -t354;
t375 = t41.*1.74601207814982e+110;
t379 = t3.*t33.*t41.*4.51356884468672e+100;
t382 = t15.*t33.*t43.*5.657273746018297e+95;
t384 = -t365;
t385 = -t368;
t393 = -t377;
t394 = t38.*t45.*1.783956770847936e+98;
t395 = t38.*t45.*3.567913541695871e+98;
t397 = t15.*t33.*t43.*9.051637993629275e+96;
t399 = t2.*t15.*t33.*t34.*1.540750211958116e+99;
t400 = t3.*t29.*t45.*4.814844412369112e+98;
t401 = t4.*t33.*t43.*4.825373307289968e+99;
t408 = -t388;
t410 = t29.*t33.*t34.*2.039536981268757e+99;
t417 = -t398;
t419 = t3.*t29.*t45.*1.540750211958116e+99;
t420 = t3.*t29.*t45.*7.703751059790579e+99;
t421 = t25.*t29.*t33.*1.949117340672207e+101;
t424 = -t402;
t425 = t45.*2.929895141971185e+109;
t426 = t29.*t33.*t43.*5.569724790856693e+95;
t427 = -t415;
t428 = t15.*t33.*t43.*1.131454749203659e+99;
t430 = t3.*t15.*t33.*t34.*1.949117340672207e+101;
t433 = t4.*t33.*t43.*1.177957116108935e+101;
t440 = t13.*t41.*1.015502327157201e+110;
t441 = t33.*t34.*t43.*6.396138188712644e+95;
t442 = t15.*t38.*t43.*2.8209805279292e+99;
t444 = -t429;
t446 = t29.*t33.*t43.*3.481077994285433e+98;
t449 = t15.*t38.*t43.*4.51356884468672e+100;
t450 = t25.*t38.*1.015502327157201e+110;
t454 = -t448;
t455 = t33.*t34.*t43.*3.997586367945402e+98;
t456 = t3.*t15.*t33.*t43.*6.653499833744936e+100;
t458 = t15.*t29.*t33.*t34.*2.8209805279292e+99;
t459 = -t452;
t460 = t13.*t45.*1.70406343245411e+109;
t461 = t2.*t29.*t33.*8.929877473868346e+109;
t462 = t33.*t34.*t43.*1.279227637742529e+99;
t465 = t15.*t29.*t33.*t34.*4.51356884468672e+100;
t467 = t3.*t33.*t34.*t43.*4.814844412369112e+98;
t470 = t3.*t33.*t34.*t43.*1.540750211958116e+99;
t471 = t3.*t33.*t34.*t43.*7.703751059790579e+99;
t472 = t15.*t29.*t33.*t43.*4.814844412369112e+98;
t473 = -t469;
t477 = t15.*t29.*t33.*t43.*1.540750211958116e+99;
t478 = t15.*t29.*t33.*t43.*7.703751059790579e+99;
t479 = t2.*t4.*t33.*t34.*8.216561852571522e+109;
t481 = t38.*t45.*4.461475237634382e+108;
t484 = t4.*t33.*t43.*6.033857959625184e+109;
t486 = -t480;
t487 = t2.*t25.*t29.*t33.*4.640991779108531e+109;
t490 = t29.*t33.*t34.*t43.*3.567913541695871e+98;
t491 = t2.*t3.*t15.*t33.*t34.*4.640991779108531e+109;
t493 = -t489;
t494 = t29.*t33.*t34.*t43.*7.135827083391743e+98;
t496 = t3.*t15.*t33.*t43.*3.40812686490822e+109;
t497 = -t495;
t500 = t29.*t33.*t34.*t43.*8.922950475268764e+108;
t55 = t50.*4.667e-1;
t58 = m1.*t57;
t70 = t15.*t40.*1.06584903120889e+64;
t76 = -t74;
t77 = -t75;
t126 = -t118;
t145 = -t129;
t153 = -t135;
t154 = t40.*2.622142519762599e+99;
t158 = -t140;
t160 = t15.*t40.*4.926325370434617e+95;
t171 = t40.*6.401103591176632e+100;
t179 = -t157;
t180 = t15.*t40.*7.882120592695387e+96;
t190 = -t169;
t193 = -t172;
t195 = -t173;
t207 = -t191;
t212 = -t192;
t231 = -t216;
t246 = t34.*t40.*5.569724790856693e+95;
t277 = -t255;
t280 = t25.*t40.*3.326749916872468e+100;
t285 = -t260;
t291 = t34.*t40.*3.481077994285433e+98;
t292 = -t269;
t304 = -t278;
t312 = -t287;
t315 = -t289;
t323 = -t301;
t324 = t40.*t41.*1.783956770847936e+98;
t325 = t40.*t41.*3.567913541695871e+98;
t331 = -t305;
t334 = -t311;
t344 = -t320;
t347 = -t321;
t355 = -t332;
t361 = t40.*3.278841761369746e+109;
t363 = -t342;
t370 = -t348;
t373 = -t351;
t376 = t15.*t34.*t40.*4.814844412369112e+98;
t378 = -t357;
t386 = -t372;
t389 = -t375;
t391 = t15.*t34.*t40.*1.540750211958116e+99;
t392 = t15.*t34.*t40.*7.703751059790579e+99;
t396 = -t379;
t413 = -t395;
t414 = -t394;
t416 = -t397;
t418 = -t400;
t423 = -t401;
t431 = -t421;
t437 = -t425;
t438 = -t426;
t443 = -t428;
t445 = -t433;
t447 = t25.*t40.*1.70406343245411e+109;
t451 = -t446;
t457 = -t449;
t464 = -t458;
t466 = t40.*t41.*4.461475237634382e+108;
t468 = -t462;
t475 = -t471;
t476 = -t470;
t482 = -t478;
t483 = -t477;
t485 = -t479;
t492 = -t487;
t498 = -t496;
t501 = -t500;
t59 = -t58;
t199 = -t180;
t306 = -t280;
t349 = -t325;
t350 = -t324;
t381 = -t361;
t390 = -t376;
t510 = t128+t149+t150+t158+t159+t179+t183+t186+t195+t196+t197+t207+t213+t220+t223+t226+t233+t240+t243+t244+t251+t252+t256+t259+t268+t279+t281+t291+t293+t297+t316+t339+t352+t370+t385+t386+t410+t451+t455+t459;
t511 = t79+t83+t86+t93+t97+t98+t105+t108+t111+t113+t119+t126+t137+t144+t145+t152+t153+t160+t170+t188+t189+t200+t202+t204+t214+t231+t246+t248+t265+t267+t299+t322+t323+t334+t344+t356+t363+t382+t383+t408+t438+t441;
t60 = exp(t59);
t507 = t84+t85+t87+t90+t92+t100+t101+t103+t104+t106+t116+t122+t123+t130+t136+t146+t148+t163+t190+t199+t215+t232+t249+t276+t277+t314+t335+t345+t347+t358+t364+t384+t393+t409+t416+t417-3.291394289500617e+98;
t508 = t272+t290+t298+t336+t343+t346+t362+t378+t380+t381+t389+t432+t437+t440+t447+t450+t460+t461+t463+t466+t481+t484+t485+t486+t488+t491+t492+t493+t497+t498+t499+t501+1.283184824024515e+111;
t512 = t128+t149+t158+t161+t179+t185+t193+t197+t205+t212+t226+t227+t238+t239+t240+t243+t244+t251+t253+t257+t259+t263+t268+t279+t281+t284+t294+t303+t307+t316+t326+t352+t359+t370+t385+t390+t418+t442+t455+t459+t464+t467+t472+t473;
t513 = t107+t115+t117+t132+t133+t134+t166+t171+t182+t194+t198+t219+t228+t229+t236+t237+t245+t254+t264+t285+t286+t295+t296+t306+t308+t328+t331+t333+t355+t373+t374+t387+t392+t396+t420+t427+t430+t431+t445+t453+t454+t456+t457+t465+t474+t475+t482-2.505091609475945e+102;
t514 = t95+t102+t109+t112+t120+t143+t147+t154+t155+t165+t167+t176+t178+t184+t187+t203+t210+t218+t222+t224+t235+t262+t274+t292+t304+t309+t312+t327+t340+t349+t353+t360+t367+t369+t371+t391+t399+t412+t413+t419+t423+t424+t439+t443+t444+t468+t476+t483+t494-1.026183552811392e+101;
t61 = t49+t60;
t62 = 1.0./(t47-t60).^2;
t509 = 1.0./t508;
t403 = c1.*m1.*t37.*t47.*t60.*t62;
t404 = c2.*m1.*t37.*t47.*t60.*t62;
t405 = c3.*m1.*t37.*t47.*t60.*t62;
t406 = c4.*m1.*t37.*t47.*t60.*t62;
t407 = c5.*m1.*t37.*t47.*t60.*t62;
t434 = c1.*m1.*t37.*t49.*t60.*t62;
t435 = c2.*m1.*t37.*t49.*t60.*t62;
t436 = c3.*m1.*t37.*t49.*t60.*t62;
t502 = t55+t407;
t503 = t54+t55+t406;
t504 = t54+t55+t436;
t505 = t51+t54+t55+t435;
t506 = t51+t52+t54+t55+t434;
LgLfs1 = [t506.*t509.*(t4.*-1.664297110460606e+69+t12.*4.379541796137363e+68+t13.*8.185918714142532e+68+t38.*2.143187450941225e+68+t40.*3.596375179431889e+67+t4.*t12.*5.178760014034365e+68+t3.*t15.*9.400512460360038e+68-t12.*t13.*2.547195945272321e+68+t29.*t34.*2.461184998411097e+68+t33.*t43.*4.129990886419445e+67-t3.*t12.*t15.*2.925138650734724e+68-t2.*t29.*t33.*9.794675083365973e+67-t2.*t33.*t34.*5.623984819644315e+67-t2.*t29.*t43.*5.623984819644315e+67-1.407452505368112e+69).*-1.980704062856608e+41+t505.*t509.*(t4.*-5.274368077583737e+98+t12.*1.718142672913029e+98+t13.*1.297110596425284e+98+t38.*3.396016073234067e+97+t40.*5.698683943565925e+96+t100+t122+t136+t163+t384+t4.*t12.*1.641214560057154e+98+t3.*t15.*2.979141315707088e+98-t12.*t13.*4.036193086154212e+97+t29.*t34.*7.799806601271353e+97+t33.*t43.*1.308846356526682e+97-t3.*t12.*t15.*9.270134415886666e+97-t2.*t29.*t33.*1.55202821855867e+97-t2.*t33.*t34.*1.782311933074142e+97-t2.*t29.*t43.*1.782311933074142e+97-5.521591806028882e+98).*1.25e+12-t504.*t507.*t509.*1.25e+12+t502.*t509.*t510.*3.2e+10-t503.*t509.*t511.*2.0e+13,t504.*t509.*(t12.*2.236687772176013e+100+t14.*4.861303010754884e+100+t25.*1.069116981453385e+100+t40.*1.3110712598813e+99+t41.*9.78066683590667e+99+t45.*1.641244559896035e+99+t95+t112+t120+t142+t156+t184+t187+t274+t315+t341+t350+t360+t366+t399+t411+t414+t439+t443+t444+t490-t12.*t25.*3.326749916872468e+99-t2.*t34.*t43.*4.469905500533193e+99-t4.*t33.*t43.*2.412686653644984e+99-7.188039194994847e+100).*2.0e+10-t505.*t507.*t509.*1.25e+12-t502.*t509.*t512.*3.2e+10-t503.*t509.*t514.*1.0e+10-t506.*t509.*(t4.*3.566096229827739e+65+t64+t65+t66+t68+t69+t70+t72+t73+t76+t77+t78-t4.*t12.*1.109655027648246e+65-t3.*t15.*2.014251652102001e+65-t29.*t34.*5.27359116865459e+64-t33.*t43.*8.84934837458634e+63+t3.*t12.*t15.*6.26770655824882e+64+t2.*t33.*t34.*1.205053528957428e+64+t2.*t29.*t43.*1.205053528957428e+64).*9.243945861351792e+44,t503.*t509.*(t12.*1.59657741305835e+100+t13.*1.456992417750339e+101+t14.*2.859586657883902e+101+t25.*1.301933828265091e+101+t40.*7.712174851057932e+99+t41.*6.981569778809797e+99+t45.*6.891416321569446e+99+t142+t156+t167+t203+t210+t224+t235+t304+t315+t327+t341+t350+t353+t366+t391+t411+t414+t419+t476+t483+t490-t13.*t45.*3.326749916872468e+99-t25.*t40.*3.326749916872468e+99-t3.*t4.*t15.*2.681216702962767e+101-t2.*t34.*t43.*3.190677862790664e+99-t4.*t33.*t43.*1.419225781473433e+100+t3.*t15.*t33.*t43.*6.653499833744936e+99-3.018183385881641e+101).*-2.0e+10+t502.*t509.*t513.*2.0e+9+t505.*t509.*t511.*2.0e+13+t504.*t509.*t514.*1.0e+10-t506.*t509.*(t34.*-4.716014108132451e+65+t64+t65+t66+t68+t69+t70+t72+t73+t76+t77+t78+t4.*t29.*4.856105403983006e+65+t2.*t43.*1.077643158498367e+65+t13.*t34.*2.742892424197626e+65+t34.*t40.*1.205053528957428e+64-t2.*t4.*t33.*1.109655027648246e+65-t3.*t15.*t29.*2.742892424197626e+65-t2.*t13.*t43.*6.26770655824882e+64-t29.*t33.*t43.*1.205053528957428e+64+t2.*t3.*t15.*t33.*6.26770655824882e+64).*9.243945861351792e+44,t506.*t509.*(t34.*2.947508817582782e+68-t43.*2.897862517998514e+68-t4.*t29.*3.035065877489379e+68+t2.*t34.*3.94614304458412e+68+t4.*t33.*2.983944812502915e+68-t2.*t43.*6.735269740614793e+67-t13.*t34.*1.714307765123516e+68+t13.*t43.*1.685432860193883e+68-t34.*t40.*7.531584555983923e+66+t38.*t43.*4.412697806454926e+67-t2.*t4.*t29.*4.063364978202626e+68+t2.*t4.*t33.*6.935343922801539e+67+t3.*t15.*t29.*1.714307765123516e+68-t2.*t13.*t34.*2.295125844327934e+68-t3.*t15.*t33.*1.685432860193883e+68+t2.*t13.*t43.*3.917316598905513e+67-t29.*t33.*t34.*4.412697806454926e+67+t29.*t33.*t43.*7.531584555983923e+66+t2.*t3.*t15.*t29.*2.295125844327934e+68-t2.*t3.*t15.*t33.*3.917316598905513e+67).*-1.479031337816287e+42-t505.*t509.*t510.*3.2e+10+t503.*t509.*t513.*2.0e+9+t504.*t509.*t512.*3.2e+10-t502.*t509.*(t2.*-4.192290185787502e+105+t13.*6.156010505813107e+105+t14.*1.002820748385332e+106+t25.*5.500864813729409e+105+t38.*1.373316171384579e+105+t40.*4.000689744485395e+103+t41.*1.227162721402341e+105+t45.*3.574921359426923e+103+t2.*t13.*2.43828808120089e+105+t2.*t14.*3.971997572226278e+105+t2.*t25.*2.178796332291538e+105-t13.*t41.*7.137330921016171e+104-t13.*t45.*2.079218698045293e+103+t29.*t33.*4.687947065739642e+104-t25.*t38.*7.137330921016171e+104-t25.*t40.*2.079218698045293e+103+t34.*t43.*4.189038182797431e+104-t3.*t4.*t15.*1.132854089747821e+106-t4.*t29.*t34.*2.527232271291176e+105-t4.*t33.*t34.*4.313475424489216e+104-t4.*t29.*t43.*4.313475424489216e+104-t4.*t33.*t43.*7.362231975680843e+103-t25.*t29.*t33.*2.436396675840258e+104-t13.*t34.*t43.*2.436396675840258e+104-t2.*t3.*t4.*t15.*4.487036892096648e+105+t3.*t15.*t29.*t34.*1.427466184203234e+105+t3.*t15.*t33.*t34.*2.436396675840258e+104+t3.*t15.*t29.*t43.*2.436396675840258e+104+t3.*t15.*t33.*t43.*4.158437396090585e+103-1.058438608058748e+106).*3.2e+6];

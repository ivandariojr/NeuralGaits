function ds2edx = CBF_ds2edx(in1,in2,in3,ldes,r,m1,a)
%CBF_DS2EDX
%    DS2EDX = CBF_DS2EDX(IN1,IN2,IN3,LDES,R,M1,A)

%    This function was generated by the Symbolic Math Toolbox version 8.3.
%    09-Nov-2020 22:05:40

c1 = in2(:,1);
c2 = in2(:,2);
c3 = in2(:,3);
c4 = in2(:,4);
c5 = in2(:,5);
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
thetamp1 = in3(:,1);
thetamp2 = in3(:,2);
t2 = a.*r;
t3 = c4.*qnsh;
t4 = c5.*qnsk;
t5 = c1.*qsf;
t6 = c3.*qsh;
t7 = c2.*qsk;
t8 = c1.^2;
t9 = c2.^2;
t10 = c3.^2;
t11 = c4.^2;
t12 = c5.^2;
t13 = m1.^2;
t14 = 1.0./a;
t15 = -qnsh;
t16 = -qnsk;
t17 = 1.0./r;
t18 = -thetamp2;
t19 = pi./2.0;
t20 = pi.*(3.0./2.0);
t21 = t2-1.0;
t22 = t18+thetamp1;
t23 = qsf+t19;
t30 = qsf+qsh+qsk+t15+t20;
t41 = t3+t4+t5+t6+t7+t18;
t24 = qsk+t23;
t25 = sin(t23);
t26 = 1.0./t22;
t31 = cos(t30);
t32 = sin(t30);
t33 = t21./t2;
t34 = t16+t30;
t27 = t26.^2;
t28 = cos(t24);
t29 = sin(t24);
t35 = -t33;
t36 = cos(t34);
t37 = sin(t34);
t42 = t32.*(2.54e+2./6.25e+2);
t43 = t32.*3.2512e+1;
t44 = t31.*(2.54e+2./6.25e+2);
t49 = t26.*t41;
t38 = t28.*(2.54e+2./6.25e+2);
t39 = t29.*(2.54e+2./6.25e+2);
t40 = t29.*3.2512e+1;
t45 = t37.*3.7336e+1;
t47 = t36.*4.667e-1;
t48 = t37.*4.667e-1;
t51 = t49-1.0;
t46 = -t45;
t50 = -t48;
t52 = m1.*t51;
t53 = t52.*2.0;
t54 = -t52;
t55 = -t53;
t56 = exp(t54);
t57 = exp(t55);
t58 = t35+t56;
t59 = 1.0./(t33-t56).^2;
t60 = -1.0./(t33-t56).^3;
t61 = c1.*c2.*t13.*t27.*t33.*t56.*t59;
t62 = c1.*c3.*t13.*t27.*t33.*t56.*t59;
t63 = c1.*c4.*t13.*t27.*t33.*t56.*t59;
t64 = c2.*c3.*t13.*t27.*t33.*t56.*t59;
t65 = c1.*c5.*t13.*t27.*t33.*t56.*t59;
t66 = c2.*c4.*t13.*t27.*t33.*t56.*t59;
t67 = c2.*c5.*t13.*t27.*t33.*t56.*t59;
t68 = c3.*c4.*t13.*t27.*t33.*t56.*t59;
t69 = c3.*c5.*t13.*t27.*t33.*t56.*t59;
t70 = c4.*c5.*t13.*t27.*t33.*t56.*t59;
t71 = c1.*c2.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t72 = c1.*c3.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t73 = c1.*c4.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t74 = c2.*c3.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t75 = c1.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t76 = c2.*c4.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t77 = c2.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t78 = c3.*c4.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t79 = c3.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t80 = c4.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*-2.0;
t81 = c1.*c2.*t13.*t27.*t35.*t56.*t59;
t82 = c1.*c3.*t13.*t27.*t35.*t56.*t59;
t83 = c2.*c3.*t13.*t27.*t35.*t56.*t59;
t84 = c1.*c4.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0;
t85 = c1.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0;
t86 = c2.*c4.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0;
t87 = c4.*c5.*t13.*t27.*t35.*t56.*t59;
t88 = c2.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0;
t89 = c3.*c4.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0;
t90 = c3.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0;
t91 = t47+t65+t85;
t92 = t47+t67+t88;
t93 = t47+t69+t90;
t94 = t47+t80+t87;
t95 = t44+t47+t63+t84;
t96 = t44+t47+t66+t86;
t97 = t44+t47+t68+t89;
t98 = t44+t47+t72+t82;
t99 = t44+t47+t74+t83;
t100 = t38+t44+t47+t71+t81;
ds2edx = [t25.*3.7336e+1+t40+t43+t45-dqnsk.*t91-dqnsh.*t95+dqsh.*t98+dqsk.*t100+dqsf.*(t38+t44+t47+cos(t23).*4.667e-1+t8.*t13.*t27.*t35.*t56.*t59-t8.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0)+c1.*m1.*t26.*t33.*t56.*t59.*8.0e+1,t40+t43+t45-dqnsk.*t92-dqnsh.*t96+dqsf.*t100+dqsh.*t99+dqsk.*(t38+t44+t47+t9.*t13.*t27.*t35.*t56.*t59-t9.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0)+c2.*m1.*t26.*t33.*t56.*t59.*8.0e+1,t43+t45-dqnsk.*t93-dqnsh.*t97+dqsf.*t98+dqsk.*t99+dqsh.*(t44+t47+t10.*t13.*t27.*t35.*t56.*t59-t10.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0)+c3.*m1.*t26.*t33.*t56.*t59.*8.0e+1,-t43+t46-dqsf.*t95-dqsh.*t97-dqsk.*t96-dqnsk.*(-t47+t70+c4.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0)+dqnsh.*(t44+t47+t11.*t13.*t27.*t35.*t56.*t59-t11.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0)+c4.*m1.*t26.*t33.*t56.*t59.*8.0e+1,t46-dqsf.*t91-dqsh.*t93-dqsk.*t92-dqnsh.*(-t47+t70+c4.*c5.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0)-dqnsk.*(-t47+t12.*t13.*t27.*t33.*t56.*t59+t12.*t13.*t27.*t33.*t57.*1.0./(t33-t56).^3.*2.0)+c5.*m1.*t26.*t33.*t56.*t59.*8.0e+1,t25.*4.667e-1+t39+t42+t48+c1.*m1.*t26.*t33.*t56.*t59,t39+t42+t48+c2.*m1.*t26.*t33.*t56.*t59,t42+t48+c3.*m1.*t26.*t33.*t56.*t59,-t42+t50+c4.*m1.*t26.*t33.*t56.*t59,t50+c5.*m1.*t26.*t33.*t56.*t59];

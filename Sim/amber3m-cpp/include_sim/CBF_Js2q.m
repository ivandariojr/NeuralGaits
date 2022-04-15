function Js2q = CBF_Js2q(in1,in2,in3,ldes,r,m1,a)
%CBF_JS2Q
%    JS2Q = CBF_JS2Q(IN1,IN2,IN3,LDES,R,M1,A)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    04-Nov-2020 17:23:37

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
t2 = a.*r;
t3 = c4.*qnsh;
t4 = c5.*qnsk;
t5 = c1.*qsf;
t6 = c3.*qsh;
t7 = c2.*qsk;
t8 = 1.0./a;
t9 = -qnsh;
t10 = -qnsk;
t11 = 1.0./r;
t12 = -thetamp2;
t13 = pi./2.0;
t14 = pi.*(3.0./2.0);
t15 = t2-1.0;
t16 = t12+thetamp1;
t17 = qsf+qsk+t13;
t20 = qsf+qsh+qsk+t9+t14;
t27 = t3+t4+t5+t6+t7+t12;
t18 = 1.0./t16;
t19 = sin(t17);
t21 = sin(t20);
t22 = t15./t2;
t23 = t10+t20;
t24 = -t22;
t25 = sin(t23);
t26 = t19.*(2.54e+2./6.25e+2);
t28 = t21.*(2.54e+2./6.25e+2);
t30 = t18.*t27;
t29 = t25.*4.667e-1;
t32 = t30-1.0;
t31 = -t29;
t33 = m1.*t32;
t34 = -t33;
t35 = exp(t34);
t36 = t24+t35;
t37 = 1.0./(t22-t35).^2;
Js2q = [t26+t28+t29+sin(qsf+t13).*4.667e-1+c1.*m1.*t18.*t22.*t35.*t37,t26+t28+t29+c2.*m1.*t18.*t22.*t35.*t37,t28+t29+c3.*m1.*t18.*t22.*t35.*t37,-t28+t31+c4.*m1.*t18.*t22.*t35.*t37,t31+c5.*m1.*t18.*t22.*t35.*t37];

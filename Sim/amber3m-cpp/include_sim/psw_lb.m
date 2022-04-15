function psw_lb = psw_lb(in1,h,k,r,lb)
%PSW_LB
%    PSW_LB = PSW_LB(IN1,H,K,R,LB)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    05-Dec-2021 00:43:51

qnsh = in1(4,:);
qnsk = in1(5,:);
qsf = in1(1,:);
qsh = in1(3,:);
qsk = in1(2,:);
t2 = -qnsh;
t3 = -qnsk;
t4 = pi./2.0;
t5 = pi.*(3.0./2.0);
t6 = qsf+t4;
t8 = qsf+qsh+qsk+t2+t5;
t7 = qsk+t6;
t9 = t3+t8;
psw_lb = -lb+(-h+cos(t6).*4.667e-1+cos(t7).*(2.54e+2./6.25e+2)+cos(t8).*(2.54e+2./6.25e+2)+cos(t9).*4.667e-1).^2+(-k+sin(t6).*4.667e-1+sin(t7).*(2.54e+2./6.25e+2)+sin(t8).*(2.54e+2./6.25e+2)+sin(t9).*4.667e-1).^2-r.^2;
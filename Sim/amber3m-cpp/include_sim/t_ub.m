function t_ub = t_ub(in1,ub)
%T_UB
%    T_UB = T_UB(IN1,UB)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    05-Dec-2021 00:43:48

qsf = in1(1,:);
qsh = in1(3,:);
qsk = in1(2,:);
t_ub = -qsf-qsh-qsk+ub;
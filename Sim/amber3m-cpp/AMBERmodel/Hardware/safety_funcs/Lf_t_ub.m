function Lf_t_ub = Lf_t_ub(in1,ub)
%Lf_t_ub
%    Lf_t_ub = Lf_t_ub(IN1,UB)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    05-Dec-2021 00:44:28

dqsf = in1(6,:);
dqsh = in1(8,:);
dqsk = in1(7,:);
Lf_t_ub = -dqsf-dqsh-dqsk;

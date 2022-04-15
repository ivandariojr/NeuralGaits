q = [1 2 3 4 5]';
dq = [1 2 3 4 5]';
x = [q; dq];
c = [1 2 3 4 5]';
O = [1 2]';
alpha = (1:20)';
tau_plus = 0;
tau_minus = 0;
ldes = 0;
r = 0;
m1 = 0; 
a = 0;
xmin = 0;
lb = 0;
ub = 0;
%%

codegen -config coder.config('lib') D_matrix -args {q}
codegen -config coder.config('lib') C_matrix -args {q,dq}
codegen -config coder.config('lib') G_matrix -args {q}
codegen -config coder.config('lib') Lf2y_matrix -args {x, c', O', alpha}
codegen -config coder.config('lib') LgLfy_matrix -args {x, c', O', alpha}
%%
codegen -config coder.config('lib') p_cm -args {q}
codegen -config coder.config('lib') p_hip -args {q}
codegen -config coder.config('lib') p_swing -args {q}
%%
% Add #include "tmwtypes.h" to _data.h file.
% Some weird $#!* is going on...
% Get rid of all "extern"s in helper and rt*.h files
% Add .c files and remove dredefnition of vars in rt_nonfinite.c

cfg = coder.config('lib');
cfg.DataTypeReplacement = 'CBuiltIn';
cfg.GenCodeOnly = true;
codegen -config cfg t_lb -args {x,lb}
codegen -config cfg Lf_t_lb -args {x,lb}
codegen -config cfg Lf2_t_lb -args {x,lb}
codegen -config cfg LgLf_t_lb -args {x,lb}
codegen -config cfg t_ub -args {x,ub}
codegen -config cfg Lf_t_ub -args {x,ub}
codegen -config cfg Lf2_t_ub -args {x,ub}
codegen -config cfg LgLf_t_ub -args {x,ub}

%% 
codegen -config cfg dz_2 -args {q}
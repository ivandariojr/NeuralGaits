Q = diag([1,1,1,1,1,1,1,1]);
eps = 0.02;

A = [zeros(4) eye(4); zeros(4,8)];
B = [zeros(4);eye(4)];

P = icare(A,B,Q);
I_eps = [(1/eps)*eye(4) zeros(4); zeros(4) eye(4)];
P_e = I_eps*P*I_eps;

gamma = min(eig(Q))/(eps*max(eig(P)));

P_diag = diag(P_e);
P_offdiag = diag(P_e(1:4,5:end));

% fileID = fopen('../UDPTest/Q.yaml','w');
% fprintf(fileID,["P_diag: 

vpa(P_diag',4)
vpa(P_offdiag',4)
gamma
eps


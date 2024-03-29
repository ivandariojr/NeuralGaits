clear;clc;close all;
version = 'Hardware';
%version: 'RaiSim','Hardware', or 'MatSim'
run('physicalparams.m')
if ~exist(version)
    mkdir(version)
end
if ~exist(fullfile(pwd,version,'/dynamics'))
    mkdir([version '/dynamics'])
end
if ~exist(fullfile(pwd,version,'/output'))
    mkdir([version '/output'])
end
if ~exist(fullfile(pwd,version,'/safety_funcs'))
    mkdir([version '/safety_funcs'])
end
% if ~exist(fullfile(pwd,version,'/safety_funcs_tau'))
% 	mkdir MatSim/safety_funcs_tau
% end
%% stance dynamics
syms qsf qsk qsh qnsh qnsk dqsf dqsk dqsh dqnsh dqnsk 'real'
N = 5;
qs = [qsf,qsk,qsh,qnsh,qnsk]';
dqs = [dqsf,dqsk,dqsh,dqnsh,dqnsk]';
x = [qs;dqs];
theta = [qsf qsf+qsk qsf+qsk+qsh pi+qsf+qsk+qsh-qnsh pi+qsf+qsk+qsh-qnsh-qnsk]';
pknee1 = Rot(theta(1)+pi/2)*[lt;0];
phip = pknee1 + Rot(theta(2)+pi/2)*[lf;0];
pknee2 = phip + Rot(theta(4)+pi/2)*[lf;0];
pfoot2 = pknee2 + Rot(theta(5)+pi/2)*[lt;0];

pcm1 = Rot(theta(1)+pi/2)*[lt-pMt;0];
pcm2 = pknee1 + Rot(theta(2)+pi/2)*[lf-pMf;0];
pcm3 = phip + Rot(theta(3)+pi/2)*[pMT;0];
pcm4 = phip + Rot(theta(4)+pi/2)*[pMf;0];
pcm5 = pknee2 + Rot(theta(5)+pi/2)*[pMt;0];
pcm = (Mt*pcm1+Mf*pcm2+MT*pcm3+Mf*pcm4+Mt*pcm5)/(Mf*2+Mt*2+MT);

p = [pcm1;pcm2;pcm3;pcm4;pcm5];
Dm1 = Mt*jacobian(pcm1,qs)'*jacobian(pcm1,qs) + Mf*jacobian(pcm2,qs)'*jacobian(pcm2,qs) +MT*jacobian(pcm3,qs)'*jacobian(pcm3,qs) + Mf*jacobian(pcm4,qs)'*jacobian(pcm4,qs)+ Mt*jacobian(pcm5,qs)'*jacobian(pcm5,qs);
DJ1 = It*jacobian(theta(1),qs)'*jacobian(theta(1),qs) + If*jacobian(theta(2),qs)'*jacobian(theta(2),qs) + IT*jacobian(theta(3),qs)'*jacobian(theta(3),qs) + If*jacobian(theta(4),qs)'*jacobian(theta(4),qs) + It*jacobian(theta(5),qs)'*jacobian(theta(5),qs) ;
Drobot = simplify(Dm1+DJ1);
P = [0 Mt 0 Mf 0 MT 0 Mf 0 Mt]*g*p;
Ng = diag([1 ng ng ng ng]);
Nua = 1;
Ifull = Ia*eye(N); Ifull(Nua,Nua)=0;
for j = 1:N
    for k = 1:N
        for i = 1:N
            Ctemp(i) = (diff(Drobot(k,j),qs(i))+diff(Drobot(k,i),qs(j))-diff(Drobot(i,j),qs(k)))*dqs(i);
        end
        C(k,j) = 1/2*sum(Ctemp);
    end
end
C = simplify(C);
G = simplify(jacobian(P,qs)');
switch version
    case 'RaiSim'
        D = Drobot;
        B = [zeros(1,N-1);eye(N-1)];
    case 'Hardware'
        D = Drobot+Ng*Ifull*Ng;
        B = [zeros(1,N-1);eye(N-1)];
    case 'MatSim'
        D = Drobot+Ng*Ifull*Ng;
        B = 91.4286*[zeros(1,N-1);eye(N-1)];
    otherwise
        fprintf('ERROR!!!Model version nonspecified!!!')
end
fx = [dqs; -inv(D)*(C*dqs+G)];
gx = [zeros(N,N-1); inv(D)*B];

% matlabFunction(D,'File',[version,'/dynamics/D_matrix.m'],'Vars',{qs});
% matlabFunction(C,'File',[version,'/dynamics/C_matrix.m'],'Vars',{qs,dqs});
% matlabFunction(G,'File',[version,'/dynamics/G_matrix.m'],'Vars',{qs});
%
% matlabFunction(fx,'File',[version,'/dynamics/f_vector.m'],'Vars',{qs,dqs});
% matlabFunction(gx,'File',[version,'/dynamics/g_vector.m'],'Vars',{qs,dqs});

% matlabFunction(pfoot2,'File',[version,'/dynamics/p_swing.m'],'Vars',{qs});
% matlabFunction(phip,'File',[version,'/dynamics/p_hip.m'],'Vars',{qs});
% matlabFunction(pcm,'File',[version,'/dynamics/p_cm.m'],'Vars',{qs});
% J_phip = jacobian(phip,qs);
% matlabFunction(J_phip,'File',[version,'/dynamics/J_phip.m'],'Vars',{qs});
% J_pcm = jacobian(pcm,qs);
% matlabFunction(J_pcm,'File',[version,'/dynamics/J_pcm.m'],'Vars',{qs});
fprintf('done exporting dynamics \n')

%% safety function
syms lb ub
t_lb = qs(1) + qs(2) + qs(3) - lb;
Lf_t_lb = jacobian(t_lb,x)*fx;
Lf2_t_lb = jacobian(Lf_t_lb,x)*fx;
LgLf_t_lb = jacobian(Lf_t_lb,x)*gx;
matlabFunction(t_lb,'File',[version,'/safety_funcs/t_lb.m'],'Vars',{x,lb});
matlabFunction(Lf_t_lb,'File',[version,'/safety_funcs/Lf_t_lb.m'],'Vars',{x,lb});
matlabFunction(Lf2_t_lb,'File',[version,'/safety_funcs/Lf2_t_lb.m'],'Vars',{x,lb});
matlabFunction(LgLf_t_lb,'File',[version,'/safety_funcs/LgLf_t_lb.m'],'Vars',{x,lb});

t_ub = ub - (qs(1) + qs(2) + qs(3));
Lf_t_ub = jacobian(t_ub,x)*fx;
Lf2_t_ub = jacobian(Lf_t_ub,x)*fx;
LgLf_t_ub = jacobian(Lf_t_ub,x)*gx;
matlabFunction(t_ub,'File',[version,'/safety_funcs/t_ub.m'],'Vars',{x,ub});
matlabFunction(Lf_t_ub,'File',[version,'/safety_funcs/Lf_t_ub.m'],'Vars',{x,ub});
matlabFunction(Lf2_t_ub,'File',[version,'/safety_funcs/Lf2_t_ub.m'],'Vars',{x,ub});
matlabFunction(LgLf_t_ub,'File',[version,'/safety_funcs/LgLf_t_ub.m'],'Vars',{x,ub});

syms h k r
swing_barrier = (pfoot2(1) - h) ^ 2 + (pfoot2(2) - k) ^ 2 - r ^ 2;
psw_lb = swing_barrier - lb;
Lf_psw_lb = jacobian(psw_lb,x)*fx;
Lf2_psw_lb = jacobian(Lf_psw_lb,x)*fx;
LgLf_psw_lb = jacobian(Lf_psw_lb,x)*gx;
matlabFunction(psw_lb,'File',[version,'/safety_funcs/psw_lb.m'],'Vars',{x,h,k,r,lb});
matlabFunction(Lf_psw_lb,'File',[version,'/safety_funcs/Lf_psw_lb.m'],'Vars',{x,h,k,r,lb});
matlabFunction(Lf2_psw_lb,'File',[version,'/safety_funcs/Lf2_psw_lb.m'],'Vars',{x,h,k,r,lb});
matlabFunction(LgLf_psw_lb,'File',[version,'/safety_funcs/LgLf_psw_lb.m'],'Vars',{x,h,k,r,lb});
psw_ub = ub - swing_barrier;
Lf_psw_ub = jacobian(psw_ub,x)*fx;
Lf2_psw_ub = jacobian(Lf_psw_ub,x)*fx;
LgLf_psw_ub = jacobian(Lf_psw_ub,x)*gx;
matlabFunction(psw_ub,'File',[version,'/safety_funcs/psw_ub.m'],'Vars',{x,h,k,r,ub});
matlabFunction(Lf_psw_ub,'File',[version,'/safety_funcs/Lf_psw_ub.m'],'Vars',{x,h,k,r,ub});
matlabFunction(Lf2_psw_ub,'File',[version,'/safety_funcs/Lf2_psw_ub.m'],'Vars',{x,h,k,r,ub});
matlabFunction(LgLf_psw_ub,'File',[version,'/safety_funcs/LgLf_psw_ub.m'],'Vars',{x,h,k,r,ub});
fprintf('done exporting safety Functions \n')
%% Outputs
%state-based
%phasing variable tau: linearized com position in x direction
syms thetamp [1 2] 'real'
syms alpha [4 5]  'real'
syms hdtemp [4 5] 'real'
syms c [1 5] 'real'

theta = c*qs;
% tau = (theta-thetamp(2))/(thetamp(1)-thetamp(2));
syms tau 'real'
M = size(alpha,2)-1;
ha = qs(2:end);
for i = 1:N-1 %N-1 outputs
    for j=1:M+1
        k = j-1;
        hdtemp(i,j) = alpha(i,j) * (factorial(M) / (factorial(k)*factorial(M-k))) ...
            * tau^(k) * (1-tau)^(M-k);
    end
end
hd = sum(hdtemp,2);
% this should be multiplied by dtau/dt
d_hd = jacobian(hd,tau); % not function of velocity, rel deg 2

matlabFunction(hd,'File',[version,'/output/yd_matrix.m'],'Vars',{tau,alpha});
matlabFunction(d_hd,'File',[version,'/output/d_yd_matrix.m'],'Vars',{tau,alpha});

%% Zero Dynamics
% following notation from: http://ames.caltech.edu/TAC_Human-Inspired_Final.pdf

% syms alpha [4 5]  'real'        % Bezier coefficients (outputs x order)

c = [-0.873, -0.4604, 0,0,0]; % linearized position of the hip

ksi_1 = c*qs;                   % first zero dynamics coordinate
ksi_2 = D(1,:)*dqs;              % second zero dynamics coordinate

H = [zeros(4,1) eye(4)];        % our choise of outputs: joint angles
eta_1 = H*qs;                   % y_a
eta_2 = H*dqs;                  % \dot y_a

syms z1 z2 yd1 yd2 yd3 yd4 dyd1 dyd2 dyd3 dyd4 yd dyd dyd_dz1_c 'real'
yd = [yd1 yd2 yd3 yd4]';
dyd = [dyd1 dyd2 dyd3 dyd4]';
z = [z1, z2];

y_a = [eta_1; eta_2];
% y_d = [yd_2; hd_dot];

eta_1d = [yd1 yd2 yd3 yd4]';
eta_2d = [dyd1 dyd2 dyd3 dyd4]';
y_d = [eta_1d eta_2d]';

Phi_Z = inv([c; H])*[z1; eta_1d];
gamma_0_Phi_Z = subs(D(1,:),[qsf,qsk,qsh,qnsh,qnsk],Phi_Z');
H_minus_dyd_dxi_c = H-dyd_dz1_c;
% Psi_Z = inv([gamma_0_Phi_Z; H-d_hd_d_q*c])

dV_dtheta_sf = diff(P,qsf); % 
kappa_2 = subs(dV_dtheta_sf,[qsf,qsk,qsh,qnsh,qnsk],Phi_Z'); 

% ksi_1_dot = c*Psi_Z*ksi_2;
ksi_2_dot = kappa_2;

% matlabFunction(___, 'File',[version,'/matlab/dynamics/zero_dynamics.m'],'Vars',{qs});

matlabFunction(ksi_2_dot,'File',[version,'/dynamics/dz_2'], 'Vars', {[z1; eta_1d]})
matlabFunction(gamma_0_Phi_Z,'File',[version,'/dynamics/zero_dynamics'], 'Vars', {[z1; eta_1d]})

fprintf('done exporting zero dynamics \n')

%%
% matlabFunction(hd,'File',[version,'/output/yd_matrix.m'],'Vars',{x,c,thetamp,alpha});
% matlabFunction(d_hd,'File',[version,'/output/d_yd_matrix.m'],'Vars',{x,c,thetamp,alpha});

y = ha - hd;

Lfy = jacobian(y,x)*fx;
Lf2y = jacobian(Lfy,x)*fx;
LgLfy = jacobian(Lfy,x)*gx;
% dydq = jacobian(y,qs);
% ddydq = jacobian(Lfy,qs);

matlabFunction(y,'File',[version,'/output/y_matrix.m'],'Vars',{x,c,thetamp,alpha});
matlabFunction(Lfy,'File',[version,'/output/Lfy_matrix.m'],'Vars',{x,c,thetamp,alpha});
% matlabFunction(dydq,'File',[version,'/output/dydq_matrix.m'],'Vars',{x,c,thetamp,alpha});
% matlabFunction(ddydq,'File',[version,'/output/ddydq_matrix.m'],'Vars',{x,c,thetamp,alpha});
matlabFunction(Lf2y,'File',[version,'/output/Lf2y_matrix.m'],'Vars',{x,c,thetamp,alpha});
matlabFunction(LgLfy,'File',[version,'/output/LgLfy_matrix.m'],'Vars',{x,c,thetamp,alpha});
fprintf('done exporting output related functions \n')
%% impact model only useful for MatSim
switch version
    case 'MatSim'
        %pe is pfoot1
        syms pe dpe [2 1] 'real'
        
        qe = [qsf,qsk,qsh,qnsh,qnsk,pe']';
        dqe = [dqsf,dqsk,dqsh,dqnsh,dqnsk,dpe']';
        xe = [qe;dqe];
        theta = [qsf qsf+qsk qsf+qsk+qsh pi+qsf+qsk+qsh-qnsh pi+qsf+qsk+qsh-qnsh-qnsk]';
        
        pknee1 = pe+Rot(theta(1)+pi/2)*[lt;0];
        phip = pknee1 + Rot(theta(2)+pi/2)*[lf;0];
        pknee2 = phip + Rot(theta(4)+pi/2)*[lf;0];
        pfoot2 = pknee2 + Rot(theta(5)+pi/2)*[lt;0];
        
        pcm1 = Rot(theta(1)+pi/2)*[lt-pMt;0];
        pcm2 = pknee1 + Rot(theta(2)+pi/2)*[lf-pMf;0];
        pcm3 = phip + Rot(theta(3)+pi/2)*[pMT;0];
        pcm4 = phip + Rot(theta(4)+pi/2)*[pMf;0];
        pcm5 = pknee2 + Rot(theta(5)+pi/2)*[pMt;0];
        pcm = (Mt*pcm1+Mf*pcm2+MT*pcm3+Mf*pcm4+Mt*pcm5)/(Mf*2+Mt*2+MT);
        p = [pcm1;pcm2;pcm3;pcm4;pcm5];
        Dm2 = Mf*jacobian(pcm1,qe)'*jacobian(pcm1,qe) + Mf*jacobian(pcm2,qe)'*jacobian(pcm2,qe) +Mt*jacobian(pcm3,qe)'*jacobian(pcm3,qe) + Mt*jacobian(pcm4,qe)'*jacobian(pcm4,qe)+ MT*jacobian(pcm5,qe)'*jacobian(pcm5,qe);
        DJ2 = If*jacobian(theta(1),qe)'*jacobian(theta(1),qe) + If*jacobian(theta(2),qe)'*jacobian(theta(2),qe) + It*jacobian(theta(3),qe)'*jacobian(theta(3),qe) + It*jacobian(theta(4),qe)'*jacobian(theta(4),qe) + IT*jacobian(theta(5),qe)'*jacobian(theta(5),qe) ;
        Derobot = simplify(Dm2+DJ2);
        
        ng = 91.4286;
        Ng = diag([1 ng ng ng ng 1 1]);
        Ia = 0.000051;
        Nua = 1;
        Ifull = Ia*eye(N+2); Ifull(Nua,Nua)=0;Ifull(N+1,N+1)=0;Ifull(N+2,N+2)=0;
        
        De = Derobot+Ng*Ifull*Ng;
        J = jacobian(pfoot2,qe);
        
%         P = [0 Mt 0 Mf 0 MT 0 Mf 0 Mt]*g*p;
%         
%         for j = 1:N+2
%             for k = 1:N+2
%                 for i = 1:N+2
%                     Ctemp(i) = (diff(Derobot(k,j),qe(i))+diff(Derobot(k,i),qe(j))-diff(Derobot(i,j),qe(k)))*dqe(i);
%                 end
%                 Ce(k,j) = 1/2*sum(Ctemp);
%             end
%         end
%         Ce = simplify(Ce);
%         Ge = simplify(jacobian(P,qe)');
%         
%         invDe = inv(De);
%         fe = [dqe;invDe*(-Ce*dqe-Ge)];
%         Be = jacobian(pe,qe)';
%         ge = [zeros((N+2),2); invDe*Be];
%         he = pe;
%         
%         Lfhe = jacobian(he,xe)*fe;
%         LgLfhe = jacobian(Lfhe,xe)*ge;
%         Lf2he = jacobian(Lfhe,xe)*fe;



        % Fstance = -inv(LgLfhe)*Lf2he %(5.83)too slow, do inversion numerically
%         matlabFunction(De,'File',[version,'/dynamics/De_matrix.m'],'Vars',{qs});
%         matlabFunction(J,'File',[version,'/dynamics/Je_matrix.m'],'Vars',{qs});
        fprintf('done exporting impact dynamics \n')
%         matlabFunction(LgLfhe,'File',[version,'/dynamics/LgLfhe_matrix.m'],'Vars',{x});
%         matlabFunction(Lf2he,'File',[version,'/dynamics/Lf2he_matrix.m'],'Vars',{x});
        fprintf('done exporting stance contact force \n')
        
        N = length(qs);
        R = [1 1 1 -1 -1; 0 0 0 0 1; 0 0 0 1 0; 0 0 1 0 0; 0 1 0 0 0];
        
        A = [De -J'; J zeros(2)];
        b = [De; zeros(2,7)]*[dqs;zeros(2,1)];
%         y = A\b;
%         
%         F = y((N+1):end);
%         
%         dqn = R*y(1:N);
%         qn = R*q;
%         
%         xn = [qn;dqn];
end



function output = Rot(x)
% rotation matrix
output = [cos(x) -sin(x); sin(x) cos(x)];
end

%% DataPlot
% A script to parse and plot data from the AMBER 3M robot.
%
% Written by: Noel Csomay-Shanklin
% Date of last edit: 10/24/20

%% Read Data
% A = readmatrix('../LearTrajopt__bk0_v999_trial30_Ref2_REALREF_with_no_bugs.csv');
% A = readmatrix('../LearnTrajopt_mh25_v519_trial5.csv');
% A = readmatrix('../DistilledBezHardware.csv');
% A = readmatrix('../cmake-build-debug/data.csv');
time_to_sleep = 0.001;
fh = figure(1);
set(fh,'Renderer', 'painters')
set(fh,'Position', [0 1920 640 480])
for iter = [1:289 291:1000]
    if iter == 1
        pause()
    end
    if iter == 290
A = readmatrix(['/home/noel/Videos/NeuralGaits/data_' num2str(289) '.csv']);
    else
A = readmatrix(['/home/noel/Videos/NeuralGaits/data_' num2str(iter) '.csv']);
    end
% A = readmatrix('../cmake-build-debug/data.csv');

data_indeces = find(A(:,1)~=0);

ind = 1;
t = (A(data_indeces,ind)-A(1,ind))*1e-3;        ind=ind+1; % Sample time
tau =  A(data_indeces,ind);                ind=ind+1;
switchBack =  A(data_indeces,ind);         ind=ind+1;
tau_d =  A(data_indeces,ind);              ind=ind+1; % State variable used by controller
tau_a =  A(data_indeces,ind);              ind=ind+1; % Measured state variable
stance = A(data_indeces,ind);              ind=ind+1; % Stance leg (1 for right)
a_pos = A(data_indeces,ind:ind+4);         ind=ind+5; % Meas. pos. [Torso, LK, LH, RH, RK]
a_vel = A(data_indeces,ind:ind+4);         ind=ind+5; % Meas. vel.
d_pos = A(data_indeces,ind:ind+3);         ind=ind+4; % Desired pos.
d_vel = A(data_indeces,ind:ind+3);         ind=ind+4; % Desired vel.
torque = A(data_indeces,ind:ind+3);        ind=ind+4; % Torque [Nm]
udes = A(data_indeces,ind:ind+3);          ind=ind+4; % Torque [Nm]
foot_pos = A(data_indeces,ind:ind+1);          ind=ind+2; % Torque [Nm]
hip_pos = A(data_indeces,ind:ind+1);          ind=ind+2; % Torque [Nm]
%%
state = [a_pos a_vel];
state(stance == 1,[2:5 7:10]) = [state(stance == 1,5) state(stance == 1,4) state(stance == 1,3) state(stance == 1,2)...
    state(stance == 1,10) state(stance == 1,9) state(stance == 1,8) state(stance == 1,7) ];

x = state;

%% Zero Dynamics

clear z1 z2 z1_dot z2_dot

c = [-0.873, -0.4604, 0,0,0];
N = [1 0 0 0 0];

x = noel2min(x);

for i=1:size(a_pos,1)
    q = x(i,1:5);
    dq = x(i,6:10);
    z1(i) = c*q';
    z1_dot(i) = c*dq';
    z2(i) = N*D_matrix(q')*dq';
    z2_dot(i) = partial_Ddq_partial_q(q',dq')*dq' - N*H_vector(q',dq');
end

%% Plotting
states = {'Torso','Left Knee','Left Hip','Rigth Hip','Right Knee'};

% figure(1)
% clf
% subplot(221);
% hold on;
% plot(t,a_pos,'linewidth',2)
% % plot(t,a_vel,'linewidth',2)
% plot(t,d_pos,'--','linewidth',2)
% % plot(t,d_vel,'--','linewidth',2)
% xlabel('Time','interpreter','latex')
% ylabel('$\theta$','interpreter','latex')
% set(gca,'TickLabelInterpreter', 'latex');
% set(gca,'FontSize',17)
% set(gca,'linewidth',2)
% legend(states,'interpreter','latex');
% title('Joint Angles vs Desired','interpreter','latex')
% subplot(223);
% hold on;
% plot(t,a_vel,'linewidth',2)
% % plot(t,a_vel,'linewidth',2)
% plot(t,d_vel,'--','linewidth',2)
% % plot(t,d_vel,'--','linewidth',2)
% xlabel('Time','interpreter','latex')
% ylabel('$\theta$','interpreter','latex')
% set(gca,'TickLabelInterpreter', 'latex');
% set(gca,'FontSize',17)
% set(gca,'linewidth',2)
% legend(states,'interpreter','latex');
% title('Joint Velocities vs Desired','interpreter','latex')
% subplot(2,2,[2 4]); hold on;
% plot(t,torque,'linewidth',2)
% xlabel('Time','interpreter','latex')
% ylabel('Torque','interpreter','latex')
% set(gca,'TickLabelInterpreter', 'latex');
% set(gca,'FontSize',17)
% set(gca,'linewidth',2)
% legend(states(2:end),'interpreter','latex');
% title('Joint Torque','interpreter','latex')
%% Swing foot
% figure(2)
% subplot(1,2,1)
p_sw = p_swing(x(:,1:5)');
p_sw(1,:) = -p_sw(1,:);
% [~,ind] = findpeaks(p_sw(1,:),'MinPeakProminence',0.3);
% ind_new = [];
% buffer = 0;
% for i = 1:length(ind)
%     ind_new = [ind_new (ind(i)-buffer):(ind(i)+buffer)];
% end
% p_sw(:,ind_new) = NaN;
% hold on;
% plot(p_sw(1,:),p_sw(2,:),'.')
% hold on;
% % 
% left=-0.2;
% right=0.3;
% center=0.2;
% apex=0.03;
% buffer=0.3;
% 
% [h,k,r] = findCircle(left, 0, right, 0, center, apex);
% scatter([left right center],[0 0 apex])
% plotCircleToMakeIvanHappy(h,k,r)
% plotCircleToMakeIvanHappy(h,k,r+buffer^2)
% pause()
%%
% subplot(1,2,2)
% alpha = 10;
% hold on;
% plot(state(:,1)+0.3)
% plot(0.05-state(:,1))
% yline(0)
%% joint angles
% % % clf
% % % plot(t, a_pos,'lineWidth',2)
% % % xlabel('Time','interpreter','latex')
% % % ylabel('Joint Angles','interpreter','latex')
% % % set(gca,'TickLabelInterpreter', 'latex');
% % % set(gca,'FontSize',17)
% % % set(gca,'linewidth',2)
% % % legend(states(1:end),'interpreter','latex','Location','SouthEast');
% % % xlabel('Time [s]','interpreter','latex')
% % % ylabel('$\theta$ [rad]','interpreter','latex')
% % % title(['Joint Angles Iteration ' num2str(iter-1)],'interpreter','latex')
% % % set(gca,'TickLabelInterpreter', 'latex');
% % % set(gca,'FontSize',17)
% % % set(gca,'linewidth',2)
% % % % legend(states(1:end),'interpreter','latex','Location','SouthEast');
% % % % hold on;
% % % % plot(d_pos,d_vel,'--')
% % % % axis([-1 1 -5 5])
% % % % axis([0 8 -0.05 0.1])
% % % axis([0 8 -2 1.5])
% % % saveas(gcf,['JointAngles_v2/' num2str(iter-1) '.png'])

% hold on;
% plot(d_pos,d_vel,'--')
% axis([-1 1 -5 5])
% pause();
% pause(time_to_sleep)
%% zero dynamics space
% clf
% plotOrbitalEnergy(state)
% plot(z1, z2,'.','lineWidth',2)
% xlabel('z_1','interpreter','latex')
% ylabel('z_2','interpreter','latex')
% set(gca,'TickLabelInterpreter', 'latex');
% set(gca,'FontSize',17)
% set(gca,'linewidth',2)
% % legend(states(1:end),'interpreter','latex','Location','SouthEast');
% % hold on;
% % plot(d_pos,d_vel,'--')
% % axis([-1 1 -5 5])
% axis([-0.25 0.2 -30 0])
%%
% [~,ind] = findpeaks([stance; 0]);
% 
% %% barrier space
% left=-0.2;
% right=0.3;
% center=0.2;
% apex=0.03;
% buffer=0.3;
% [h,k,r] = findCircle(left, 0, right, 0, center, apex);
% 
clf
h1 = -state(:,1) + 0.05;
h2 = state(:,1) + pi/10;
b_f = ((p_sw(1,:)-h).^2 + (p_sw(2,:)-k).^2 - r^2)';
h3 = b_f - 0;
h4 = 0.3 - b_f;
d_t = t(ind);
h5 = -vecnorm(d_pos(ind,:) - d_pos(ind-1,:),2,2);
d_b = (z1(ind)+z1(ind-1))';
h6 = d_b + 0.15;
h7 = - d_b + 0.15;
plot(t, min([h1,h2,h3,h4]')','.','lineWidth',2)
hold on
% scatter(d_t, min([h5,h6,h7]')',20,'b','filled')
% hold on;
% plot(t, h1,'.','lineWidth',2)
% plot(t, h2,'.','lineWidth',2)
% plot(t, h3,'.','lineWidth',2)
% plot(t, h4,'.','lineWidth',2)
xlabel('Time [s]','interpreter','latex')
ylabel('h','interpreter','latex')
title(['Barrier Function Iteration ' num2str(iter-1)],'interpreter','latex')
set(gca,'TickLabelInterpreter', 'latex');
set(gca,'FontSize',17)
set(gca,'linewidth',2)
% legend(states(1:end),'interpreter','latex','Location','SouthEast');
% hold on;
% plot(d_pos,d_vel,'--')
% axis([-1 1 -5 5])
axis([0 8 -0.05 0.1])
yline(0,'r','linewidth',2)
saveas(gcf,['Barrier_Integration/' num2str(iter-1) '.png'])
pause(time_to_sleep)
end

%% Interesting code for later use.

% %% Verify impact stuff
% 
% % d_state = [d_pos d_vel];
% % d_state(stance == 1,[2:5 7:10]) = [d_state(stance == 1,5) d_state(stance == 1,4) d_state(stance == 1,3) d_state(stance == 1,2)...
% %     d_state(stance == 1,10) d_state(stance == 1,9) d_state(stance == 1,8) d_state(stance == 1,7) ];
% % 
% % d_x = d_state;
% 
% ind = find(diff(stance)~=0,1);
% 
% i = ind-1;
% q = x(i,1:5);
% dq = x(i,6:10);
% q_minus = [q(1) - q(2) - q(3), q(2), q(3), q(4), q(5)];
% dq_minus = [dq(1) - dq(2) - dq(3), dq(2), dq(3), dq(4), dq(5)];
% 
% % q_des_minus = [0 d_x(i,2:5)];
% 
% qsf_impact = qsf_at_impact([0; q_minus(2:5)']);
% [qsf_impact q_minus(1)]
% 
% i = ind+1;
% q = x(i,1:5);
% dq = x(i,6:10);
% q_plus = [q(1) - q(2) - q(3), q(2), q(3), q(4), q(5)];
% dq_plus = [dq(1) - dq(2) - dq(3), dq(2), dq(3), dq(4), dq(5)];
% qsf_liftoff = qsf_at_liftoff([0; q_minus(2:5)']);
% [qsf_liftoff q_plus(1)]

function state_out = noel2min(state_in)
    state_out = state_in;
    state_out(:,1) = state_in(:,1) - state_in(:,2) - state_in(:,3);
    state_out(:,6) = state_in(:,6) - state_in(:,7) - state_in(:,8);

end

function [h,k,r] = findCircle(x1, y1, x2, y2, x3, y3)
    M = ([[x1 ^ 2 + y1 ^ 2, x1, y1, 1]; [x2 ^ 2 + y2 ^ 2, x2, y2, 1]; [x3 ^ 2 + y3 ^ 2, x3, y3, 1]]);
    M11 = det(M(:, [1, 2, 3]+1));
    M12 = det(M(:, [0, 2, 3]+1));
    M13 = det(M(:, [0, 1, 3]+1));
    M14 = det(M(:, [0, 1, 2]+1));

    h = 1./2.*M12/M11;
    k = -1. / 2. * M13 / M11;
    r = sqrt(h^2 + k^2 + M14/M11);

end

function plotCircleToMakeIvanHappy(h,k,r)
    theta = linspace(0,2*pi)
    x = r*cos(theta)+h;
    y = r*sin(theta)+k;
    plot(x,y)
end

function plotOrbitalEnergy(state)
g = 9.81;
mass = 21.5562;
z = 0.862;

z1_ = linspace(-0.3,0.3);

orbital_energy = [0, 1];
for i=1:length(z1_)
    z2_l(i) = -sqrt(orbital_energy(1)+g/z*z1_(i)^2)*mass*z;
    z2_u(i) = -sqrt(orbital_energy(2)+g/z*z1_(i)^2)*mass*z;
end

% clf
plot(z1_,z2_l,'r','linewidth',2)
hold on
plot(z1_,z2_u,'r','linewidth',2)
end
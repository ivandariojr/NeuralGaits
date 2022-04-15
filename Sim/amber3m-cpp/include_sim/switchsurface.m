function [p_swing_v,isterminal,direction] = switchsurface(t,x)
p_swing_xy = p_swing(x(1:5));
p_swing_v = p_swing_xy(2);

% isforward = (p_swing_xy(1)>0)-1;
isterminal = [1];  % Halt integration
direction = [-1];  %when decrease to zero
% direction =0;
%TODO implement p_swing_h>0



% %for kinematic barrier to exit ode45 when too slow
% function [M,isterminal,direction] = switchsurface2(t,x)
% tooslow = (norm(x(6:end))>.15); %=0 if slow
% p_swing_xy = p_swing(x(1:5));
% p_swing_v = p_swing_xy(2);
% M = tooslow && (p_swing_v>0);
% % isforward = (p_swing_xy(1)>0)-1;
% isterminal = [1];  % Halt integration
% direction = -1;
% %TODO implement p_swing_h>0
% end
end
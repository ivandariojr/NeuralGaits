
left=-0.1;
right=0.5;
center=0.1;
apex=0.1;
buffer=0.4;

[h,k,r] = findCircle(left, 0, right, 0, center, apex);

hold on
scatter([left right center],[0 0 apex])
plotCircleToMakeIvanHappy(h,k,r)
plotCircleToMakeIvanHappy(h,k,r+buffer^2)

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
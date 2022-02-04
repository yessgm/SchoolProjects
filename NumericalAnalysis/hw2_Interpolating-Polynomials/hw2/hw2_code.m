%
% Interpolating Polynomial for f(x,y) = x^5 y^3 + sin^2(pi x) cos(pi y) at (x0,y0) = (1,1)
%

clear all;

n = 20;
x = linspace(0, 2, n)
y = linspace (0, 2, n)

f = zeros(n,n,1);
f0 = zeros(n,n,1);
f1 = zeros(n,n,1);
f2 = zeros(n,n,1);

for i=1:n
    for j=1:n
        f(i,j) = (x(i)^5)*(y(j)^3) + sin(pi*x(i))^2 * cos(pi*y(j));
    end
end 

%size(x)
%size(y)
%size(f)

figure(1)
mesh(x,y,f);
colorbar;
title ('Interpolating Polynomial for f(x,y) = x^5 y^3 + sin^2(pi x) cos(pi y) at (x0,y0) = (1,1)');
hold on;

% figure(2)
% mesh(x,y,f);
% colorbar;
% title ('Interpolating Polynomial for f(x,y) = x^5 y^3 + sin^2(pi x) cos(pi y) at (x0,y0) = (1,1)');
% hold on;

for i=1:n 
    for j=1:n
        f0(i,j) = 1;
        f1(i,j) = 1 + 5*(x(i)-1) + 3*(y(j)-1);
        f2(i,j) = f1(i,j) + (10-pi^2)*(x(i)-1)^2+ 15*(x(i)-1)*(y(j)-1) + 3*(y(j)-1)^2;
    end
end

mesh(x,y,f2);
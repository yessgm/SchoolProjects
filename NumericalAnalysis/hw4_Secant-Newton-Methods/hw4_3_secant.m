%
% Solve f(x) = x - cos(x) using secant method.
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all;

x(1) = 0.;
x(2) = pi/2;

xexact = 0.739085133215161;

e(1) = abs(xexact - x(1));
e(2) = abs(xexact - x(2));

maxit = 1000; 
itnum = 1; 
error = 1; 
tol = 1.e-5; 

while (itnum < maxit & error > tol)

%   z1 = x(i-1) - cos(x(i-1));

   itnum = itnum + 1;

   z1 = feval('fcn',x(itnum-1));

%   z2 = x(i) - cos(x(i));

   z2 = feval('fcn',x(itnum));

   x(itnum+1) = x(itnum) - ((x(itnum) - x(itnum-1))/(z2 - z1))*z2;

   e(itnum+1) = abs(xexact - x(itnum+1))

   error = e(itnum+1);

end

for i=2:itnum

     ratio(i+1) = e(i+1)/e(i);

     ratio(i) = e(i)/e(i-1);

     order = log(ratio(i+1))/log(ratio(i))

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% OUTPUT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% hw4_3a_secant_code
% 
% e =
% 
%     0.7391    0.8317    0.1281
% 
% 
% e =
% 
%     0.7391    0.8317    0.1281    0.0158
% 
% 
% e =
% 
%     0.7391    0.8317    0.1281    0.0158    0.0005
% 
% 
% e =
% 
%     0.7391    0.8317    0.1281    0.0158    0.0005    0.0000
% 
% 
% order =
% 
%   -15.8455
% 
% 
% order =
% 
%     1.1179
% 
% 
% order =
% 
%     1.6690
% 
% 
% order =
% 
%     1.6183

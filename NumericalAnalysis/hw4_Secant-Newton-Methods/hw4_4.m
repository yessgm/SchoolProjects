% 
% Solve F(x,y) = x - x^2 - y^2 \\ y - x^2 + y^2 using newton method.
% 
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all; 

xexact = 1;
yexact = 1;

% Newton iteration begins here !

itnum = 1; 
x = 0.8;
y = 0.8;
tol = 1.e-5; 
maxit = 1000; 
error(itnum) = max(abs(xexact - x),abs(yexact - y));

while (itnum < maxit & error > tol)
   
   itnum = itnum + 1;  
   f = [x*y^2 + x*y - x^4 - 1; 
        x^2 + y - 2];

   delf = [y^2 + y - 4*x^3      2*x*y + x; 
           2*x                   1];
      
   del = -1 * delf\f;   %gradient of f. Equivalent to:
   % del = -1 *inv(delf)*f;
   
   x = x + del(1);
   y = y + del(2); 

   error(itnum) = max(abs(xexact - x),abs(yexact - y)) 
   
end

for i=3:itnum
   
    ratio(i+1) = error(i)/error(i-1);   
    ratio(i) = error(i-1)/error(i-2);
    order = log(ratio(i+1))/log(ratio(i))
   
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% OUTPUT
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% hw4_4
% 
% error =
% 
%     0.2000    0.0305
% 
% 
% error =
% 
%     0.2000    0.0305    0.0013
% 
% 
% error =
% 
%     0.2000    0.0305    0.0013    0.0000
% 
% 
% order =
% 
%     1.6839
% 
% 
% order =
% 
%     2.0318

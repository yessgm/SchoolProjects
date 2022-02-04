% 
% Solve f(x) = x - cos(x) using newton method. 
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all; 

x(1) = 0.;

xexact = 0.739085133215161;

e(1) = abs(xexact - x(1));

maxit = 1000; 
itnum = 0; 
error = 1; 
tol = 1.e-5; 

while (itnum < maxit & error > tol) 
   
%   z1 = x(i-1) - cos(x(i-1));

   itnum = itnum + 1; 

   z1 = 1 + sin(x(itnum)); 

   z2 = feval('fcn',x(itnum)); 
   
   x(itnum+1) = x(itnum) - z2/z1;  
   
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
% >> hw4_3a_newton_code
% 
% e =
% 
%     0.7391    0.2609
% 
% 
% e =
% 
%     0.7391    0.2609    0.0113
% 
% 
% e =
% 
%     0.7391    0.2609    0.0113    0.0000
% 
% 
% e =
% 
%     0.7391    0.2609    0.0113    0.0000    0.0000
% 
% 
% order =
% 
%     3.0169
% 
% 
% order =
% 
%     1.9123
% 
% 
% order =
% 
%     1.9980
% 





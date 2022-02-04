% 
% Solve f(x) = x − cos x by using newton method and secant method
% 


clear all; 

% Newton Method
x(0) = 0.0;
maxit = 100; 
for i=0:maxit 
   
   f(i) = x(i) - cos(x(i));
   x(i+1) = x(i) - f(i)/(1 + sin(x(i)))
   
   e(i) = abs(f(i));
   
%    pause 
   
   if (e(i) = 0.739085133215161)
 
       break;
   
   end

end

%Secant Method
x(0)= 0;
x(1)= pi/2;

while err != 0.739085133215161
    x(2) = 



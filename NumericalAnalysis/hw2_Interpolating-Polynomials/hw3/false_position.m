% Sept/2016 
% 
% Solve f(x) = 0 using false-position method.
%
% The function is defined in func(x); 
%
% Input

tol = 1.e-10;

a = 3.0; 
b = 4.0;
nmax = 100;

% Initialization 

itcount = 0;
error = 1.0;

% Graph of the function

xval = linspace(a,b,100);
for i=1:100
    fval(i) = func(xval(i));
end

plot(xval,fval);
grid on; 
hold on; 

% iteration begins here

while (itcount <= nmax && error >= tol)

   itcount = itcount + 1;
   xold = x;

   % Generate and save iteratres
  
   fa = func(a); 
   fb = func(b);
  
   x = a - ((b - a)/(fb - fa))*fa;
   z(itcount) = x;
  
   fx = func(x);
   
   error = abs(fx);
%  error = abs(x - xold);
   
   if (error < tol)
      x_final = x;
   else
      if (fa*fx < 0)
      % root is between a and x
         b = x;
      else
      % root is between x and b
         a = x;
      end
   end
   
   plot(z(1:itcount),zeros(itcount,1),'r+');

   pause(2)   
end
 

if (itcount < nmax);

  val = func(x);
  
  fprintf(1,'Converged solution after %5d iterations',itcount);

  fprintf(1,' is %15.7e, %e \n',x_final, val);

else

  fprintf(1,'Not converged after %3d iterations',nmax);

end
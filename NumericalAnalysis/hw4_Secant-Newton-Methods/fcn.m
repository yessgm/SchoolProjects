%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% func.m will generate the function value at the nodal points.  
%
% Note*: We need to specify time 't' and 'y', nodal point. 
%         
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function val = fcn(x)

   %val = x^3 + 4 * x^2 - 10;
   val = x - cos(x);
   %val = sin(x); 
      
   
           
   

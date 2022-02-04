% 
% Interpolating Polynomial for f(x) = sin(x) 
%

clear all; 

a = -pi/4;
b = pi/4;

n = 200; 
x = linspace(a,b,n);

y0 = zeros(n,1); 
y1 = zeros(n,1); 
y2 = zeros(n,1); 
y3 = zeros(n,1); 
y4 = zeros(n,1);

y = sin(x); 

plot(x,y,'black'); 

hold on;

for i=1:n
    y0(i) = 0;
end

%y0 = 0.0; 
y1 = 0 + x; 
y2 = 0 + x + 0; 
y3 = 0 + x + 0 - x.^3/6; 
y4 = 0 + x + 0 - x.^3/6 + 0;

plot(x,y0,'r-'); 
plot(x,y1,'g-'); 
plot(x,y2,'y-');
plot(x,y3,'b-');
plot(x,y4,'c-');

title('Taylor Interpolating Polynomial of F(x) = sin(x)'); 

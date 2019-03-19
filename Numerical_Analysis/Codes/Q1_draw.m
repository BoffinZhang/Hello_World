clc;
x = -2:0.01:2;
y = f(x);
axis on;
grid on;
plot(x,y);


function y = f(x)
    y = exp(x)+4*x.^3-2*x.^2+x-2;
end
clc;
x1 = 0.5;
x0 = 1;
eps = 1e-4;
count = 1;
fprintf("n     x           f(x)\n")
while(abs(x1-x0)>eps)
   x0 = x1;
   x1 = g(x0);
   fprintf("%d  %.8f  %.8f\n",count,x0,f(x0));
   count = count+1;
end

function y = g(x)  %迭代公式
    y = x - f(x)/ff(x);
end

function y = f(x)  %原函数
    y = exp(x)+4*x^3-2*x^2+x-2;
end

function y = ff(x) %一阶导数
     y = exp(x) + 12*x^2 - 4*x + 1;
end
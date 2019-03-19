clc;
x1 = 0;
x0 = 1;
x2 = 3;
eps = 1e-4;
count = 1;
while(abs(x2-x1)>eps)
   x0 = x1;
   x1 = x2;
   x2 = g(x0,x1);
   fprintf("%d  %.8f  %.8f\n",count,x2,f(x2));
   count = count+1;
end

function y = g(x0,x1)  %迭代公式
    y = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
end

function y = f(x)  %原函数
    y = exp(x)+4*x^3-2*x^2+x-2;
end


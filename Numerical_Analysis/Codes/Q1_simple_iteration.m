x = 1;
xx = 0.5;
eps = 1e-4;
MAXN = 50;
count = 1;
while(abs(xx-x)>eps&&count<=MAXN)
    x = xx;
    xx = g(x);
    fprintf("%d  %.8f  %.8f\n",count,x,f(x));
    count = count+1;
end

function y = f(x)  %Ô­º¯Êı
    y = exp(x)+4*x^3-2*x^2+x-2;
end

function y = g(x)
    y = (0.25*(-exp(x)+2*x^2-x+2))^(1/3);
end
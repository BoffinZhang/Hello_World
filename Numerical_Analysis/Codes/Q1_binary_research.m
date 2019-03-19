a = 0;
b = 1;
res = (a+b)/2;
eps = 1e-4;
count = 1
last_res = 2

while(abs(last_res-res)>1e-4)
    fprintf("%d   %f   %f\n",count,res,f(res));
    if(f(res)>0)
        b = res;
    else 
        a = res;
    end
    last_res = res;
    res = (a+b)/2;
    count = count+1;
end
fprintf("%d   %f   %f\n",count,res,f(res));
function y = f(x)
    y = exp(x)+4*x^3-2*x^2+x-2;
end
function main
[x,fval,flag] = fminsearch(@myfun,[1,4])
    function f = myfun(x)
        f = x(1)^2+x(2)^2-x(1)-x(2)+x(2)^3;
        

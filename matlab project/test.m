function test

        f = @(x)(x(2)-x(1)^2)^2+(1-x(1))^2;
        [x,fval,flag] = fminsearch(f,[-1.2, 1])
function f=myfun(x)
x = rand()
f=sin(x)+3;
x0=2;%��ʼ��
[x,fval]=fminsearch(@myfun,x0)
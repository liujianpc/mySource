#include<stdio.h>
int fact(int n);
int main()
{
	int m;
	while(1)
	{
		printf("input a number:\n");
		scanf("%d",&m);
		printf("%d\n",fact(m));
	}
	return 0;


}

int fact(int n)
{
	int f;
	if(n<0){
		printf("error\n");
	}
	else if(n==0||n==1)f=1;
	else f=n*fact(n-1);
	return f;
}

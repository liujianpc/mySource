#include<stdio.h>
void matrix(int *p);
int main()
{
	int *p,i;
	int a[25]={0};
	p=a;
	i=0;

	while(1)
	{
	puts("input a matrix of 25 numbers:");
	for(p=a;p<a+25;p++)
	{
		scanf("%d",p);//输入一个长度为25的整型数组
	}


	printf("the matrix is:\n");
	for(p=a;p<a+25;p++)
	{
		i++;
		if(i%5==0) printf("%d\n",*p);//输出该矩阵
		else printf("%d\t",*p);
	}
	printf("\n");

	matrix(a);
	}
	return 0;
}

void matrix(int *p)
{
	int i,j,temp,change=0;
/*	for(pt=x+1;pt<=x+24;pt++)
	 {
		if(*pt > max) max=*p;
	 }
*/ 
	for(i=1;i<25;i++)
	 {
		for(j=0;j<25-i;j++)
		 {
			if(*(p+j)>*(p+j+1))
			{
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
				change=1;
			}
			if(change==0) break;
		 }
	 }

	temp=*(p+4);
	*(p+4)=*(p+1);
	*(p+1)=temp;

	temp=*(p+20);
	*(p+20)=*(p+2);
	*(p+2)=temp;

	temp=*(p+12);
	*(p+12)=*(p+24);
	*(p+24)=*(p+3);
	*(p+3)=temp;

	printf("the changed matrix is:\n");
	j=0;
	for(i=0;i<25;i++)
	{
		j++;
		if(j%5==0)printf("%d\n",*(p+i));
		else printf("%d\t",*(p+i));
	}
	printf("\n");


}

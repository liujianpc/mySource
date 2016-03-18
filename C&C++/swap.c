#include<stdio.h>
void swap(float a,float b);
void main()
{
	float a,b;
	printf("please input two floatNumbers\n");
	scanf("%f%f",&a,&b);
	swap(a,b);
}

void swap(float a,float b)
{
	float t;
	t=a;
	a=b;
	b=t;
	printf("result is:\na=%f\nb=%f\n",a,b);

}
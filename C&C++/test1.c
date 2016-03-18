#include<stdio.h>
int main()
{
	int a[6]={0},i,j,t;
	printf("input ten numbers:\n");
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<6;j++)
	{
		for(i=0;i<6-j;i++)
		{
			if(a[i]<a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}

	for(i=0;i<6;i++)
	{
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}


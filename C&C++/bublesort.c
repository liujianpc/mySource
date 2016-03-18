#include<stdio.h>
int main()
{
	int a[10],i,j,t;
	printf("input ten numbers:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	int change = 0;
	for(j=0;j<=9;j++)
	{
		for(i=0;i<=9-j-1;i++)
		{
			if(a[i]<a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				change=1;
			}
			if(change==0) break;
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);

	}
	printf("\n");
	return 0;
}

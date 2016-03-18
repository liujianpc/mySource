#include<stdio.h>
int main()
{
	int a[10],i,j,t;
	printf("input ten numbers:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=1;j<10;j++)
	{
		for(i=0;i<10-j;i++)
		{
			if(a[i]<a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}

	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}

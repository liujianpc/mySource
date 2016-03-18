*
 * =====================================================================================
 *       Filename:  bubbleSort.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 15:08:46
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: bubbleSort.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/20 15:08:46
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,j,k,t,change=0;
	int a[6];
	while(1)
	{


		printf("input six integers:");
		for(i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("\nUP(1) or DOWN(0):");
		scanf("%d",&k);
		if(k==1)
		{


			for(i=1;i<6;i++)
			{


				for(j=0;j<6-i;j++)
				{
					if(a[j]>a[j+1])
					{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
						change=1;
					}

				}
				if(change==0) break;
			}
			for(i=0;i<6;i++) printf("%d  ",a[i]);
			printf("\n");

		}

		else if(k==0)
		{


			for(i=1;i<6;i++)
			{


				for(j=0;j<6-i;j++)
				{
					if(a[j]<a[j+1])
					{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
						change=1;
					}

				}
				if(change==0) break;
			}
			for(i=0;i<6;i++) printf("%d  ",a[i]);
			printf("\n");

		}

		else printf("error!");

	}
	return 0;

}

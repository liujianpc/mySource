/*
 * =====================================================================================
 *       Filename:  threeDemension.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/25 15:49:43
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: threeDemension.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/25 15:49:43
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,j,k,max,p,q,r;
	int a[2][2][2]={0};
	while(1)
	{
		printf("input a 3_D array:\n");
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++) scanf("%d",&a[i][j][k]);
		max=a[0][0][0];
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
				{
					if(a[i][j][k]>max)
					{
						max=a[i][j][k];
						p=i;
						q=j;
						r=k+1;
					}
				}
		printf("max=a[%d][%d][%d]=%d\n",p,q,r,max);
	}
	return 0;
}

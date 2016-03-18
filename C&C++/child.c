/*
 * =====================================================================================
 *       Filename:  child.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/5/24 1:22:18
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: child.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/5/24 1:22:18
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,j,k,last=0;
	int a[4][4];
	a[1][1]=7;
	a[2][1]=8;
	a[3][1]=9;
	for(i=4;i<6;i++)
	{
		for(j=4;j<7;j++)
		for(k=4;i!=j&&k<6;k++)
		{
			if(i!=k&&j!=k&&15-a[1][1]-i!=15-a[2][1]-j&&15-a[1][1]-i!=15-a[3][1]-k&&15-a[2][1]-j!=15-a[3][1]-k)
			{
				if(15-a[1][1]-i==1) printf("张家\n");
				else if(15-a[2][1]-j==1) printf("王家\n");
				else printf("李家\n");
			}
		}

	}
	return 0;
}

/*
 * =====================================================================================
 *       Filename:  1.cpp
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/5/21 22:57:40
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: 1.cpp
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/5/21 22:57:40
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,j,n;
	char c=' ';
	printf("input a number:");
	scanf("%d",&n);
	printf("%*c*\n",2*n,c);
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf("  ");
		}
		for(j=n-i+1;j<=n;j++)
		{
			printf("* ");
		}
		printf("\n");
		
	}
return 0;
}

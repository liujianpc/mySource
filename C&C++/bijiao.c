/*
 * =====================================================================================
 *       Filename:  bijiao.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/7/13 22:54:34
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: bijiao.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/7/13 22:54:34
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,j,t,a[10]={0};
	puts("input ten numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("before action:\n");
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	printf("\n");
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	printf("after action:\n");
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	printf("\n");
	return 0;

}

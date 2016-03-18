/*
 * =====================================================================================
 *       Filename:  insert-sort.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/12/16 14:53:16
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: insert-sort.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/12/16 14:53:16
 ************************************************************************/

#include<stdio.h>
int main()
{
	int a[11]={0},i=0,j=0,k=0;
	printf("input ten numbers:\n");
	for(i=1;i<11;i++)
		scanf("%d",&a[i]);
	for(j=2;j<11;j++)
	{
		if(a[j]<a[j-1])
		{
			a[0]=a[j];
			for(k=j-1;a[0]<a[k];k--)
			{
				a[k+1]=a[k];
			}
			a[k+1]=a[0];
		}
	}
	for(i=1;i<11;i++)
		printf("%d  ",a[i]);
	return 0;
}

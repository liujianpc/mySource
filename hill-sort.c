/*
 * =====================================================================================
 *       Filename:  hill-sort.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/12/16 19:43:21
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: hill-sort.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/12/16 19:43:21
 ************************************************************************/

#include<stdio.h>
int main()
{
 	int d[3] = {0};
	int a[11] = {0};
	int i = 0,j = 0,k = 0;
	printf("input 10 numbers:\n");
	for(i = 1;i < 11;i++)
		scanf("%d",&a[i]);
	printf("input 3 distant-bumbers:\n");
	for(i = 0;i < 3;i++)
		scanf("%d",&d[i]);
	for(i = 0;i < 3;i++)
		for(j = d[i]+1;j < 11;j++)
		{
			if(a[j] < a[j-d[i]])
			{
				a[0] = a[j];
				for(k = j-d[i];(k>0)&&(a[k]>a[0]);k = k-d[i])
				{
					a[k+d[i]] = a[k];
				}
				a[k+d[i]] = a[0];
			}
		}
	for(i = 1;i < 11;i++)
		printf("%d  ",a[i]);
}


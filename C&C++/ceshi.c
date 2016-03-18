/*
 * =====================================================================================
 *       Filename:  ceshi.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/13 13:53:48
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: ceshi.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/13 13:53:48
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,a[3];
	printf("input 3 integers:\n");
	for(i=0;i<3;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);

	}
	for(i=0;i<3;i++)
	{
		printf("a[%d]=%d\t",i,a[i]);
	}
	printf("\n");

	return 0;

}

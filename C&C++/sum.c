/*
 * =====================================================================================
 *       Filename:  sum.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/25 16:21:26
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: sum.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/25 16:21:25
 ************************************************************************/

#include<stdio.h>
int sum(int x);
int main()
{
	int n;
	n=sum(33);
	printf("%d\n",n);
	return 0;
}

int sum(int x)
{
	if(x==1) return 3;
	else return (sum(x-1)+3*x);
}

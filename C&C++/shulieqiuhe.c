/*
 * =====================================================================================
 *       Filename:  shulieqiuhe.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/12 1:09:28
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: shulieqiuhe.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/12 1:09:28
 ************************************************************************/

#include<stdio.h>
int func(int x);
int main()
{
	int sum;
	sum=func(33);
	printf("%d\n",sum);
	return 0;
}

int func(int x)
{
	if(x==1) return 3;
	else return (func(x-1)+3*x);
}

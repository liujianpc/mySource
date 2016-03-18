/*
 * =====================================================================================
 *       Filename:  123.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/13 22:26:23
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: 123.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/13 22:26:23
 ************************************************************************/

#include<stdio.h>
int main()
{
	int x,*p1,**p2;
	x=10;
	p1=&x;
	p2=&p1;
	printf("%d\t%p\t%p\n",**p2,*p2,p1);
	return 0;
}

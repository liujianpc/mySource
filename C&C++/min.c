/*
 * =====================================================================================
 *       Filename:  min.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 15:57:56
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: min.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/20 15:57:56
 ************************************************************************/

#include<stdio.h>
int min(int x,int y,int z);
int main()
{
	int a,b,c;
	while(1)
	{
		printf("输入三个数\n");
		scanf("%d%d%d",&a,&b,&c);
		int i=min(a,b,c);
		printf("这三个数中最小的数是\n") ;
		printf("%d\n",i);
	}
	return 0;
}

int min(int x,int y,int z)
{
	int m;
	if(x>y)
		m=y;
	else
		m=x;
	if(m>z)
		m=z;
	return m;
}

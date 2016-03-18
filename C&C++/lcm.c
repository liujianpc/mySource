/*
 * =====================================================================================
 *       Filename:  lcm.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/19 23:12:53
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: lcm.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/19 23:12:53
 ************************************************************************/

#include<stdio.h>
int lcd(int m,int n);
int main()
{
	int i,j,k;
	while(1)
	{

		printf("input two integer:");
		scanf("%d%d",&i,&j);
		k=lcd(i,j);
		printf("the LCM of %d  %d is:  %d\n",i,j,k);

	}
	return 0;
}

int lcd(int m,int n)
{
	int x,y,z,t;
	x=m;
	y=n;
	if(x<y){t=x;x=y;y=t;}
	while(y!=0)
	{
		z=x%y;
		x=y;
		y=z;
	}
	return (m*n/x);
}


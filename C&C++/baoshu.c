/*
 * =====================================================================================
 *       Filename:  baoshu.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/5/31 0:46:12
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: baoshu.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/5/31 0:46:12
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n,i,j,k,m,*p;
	int a[100];//数组用语存储编号
	p=a;//指向数组

	while(1)
	{

		printf("input a number n(n<=100):");
		printf("\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			*(p+i)=i+1;//给所有人从1-n编号
		}
           i=0;//重要！！！将i重新设为0
		   j=0;
		   m=0;
		while(m<n-1)
		{
			if(*(p+i)!=0)
			{
				j++;
			}
			if(j==3)
			{
				*(p+i)=0;
				m++;
				j=0;
			}
			i++;
			if(i==n) i=0;//重要
		}//while(m==n-1);
		while(*p==0) p++;
		printf("last one is %d\n",*p);

	}

	return 0;
}

/*
 * =====================================================================================
 *       Filename:  NumberOfCar.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/5/22 22:38:10
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: NumberOfCar.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/5/22 22:38:10
 ************************************************************************/

#include<stdio.h>
int main()
{
	int m,n,i,j;
	for(i=1;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			m=i*1000+i*100+j*10+j;
			for(n=31;n<m;n++)
			{
				if(m==n*n)
				{
					printf("the number is %d\n",m);
				}
			}
		}
	}
	return 0;

}

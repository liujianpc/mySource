/*
 * =====================================================================================
 *       Filename:  monkey.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2015/5/29 11:01:27
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
*    File Name: monkey.c
*    Author: liujianpc
*    Email: zhouhu8899@163.com 
*    Created: 2015/5/29 11:01:27
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int monkey[88] ={0};
	int i,j,k,m;
	for(i = 0;i< 88;i++)
	{
		monkey[i] = i + 1;
	}
	i = 0;
	m = 0;
	k = 0;
	//printf("%d",m);
	while(m < 87)
	{
		if(monkey[i] != 0)
		{
			k++;
		}
		if(k==3)
		{
			k = 0;
			m++;
			monkey[i] = 0;
		}
		i++;
		if(i==88) i = 0;
	}
	j = 0;
	while(monkey[j] == 0) j++;
	printf("%d\n",j);
    return 0;
}

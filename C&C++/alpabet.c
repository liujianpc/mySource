/*
 * =====================================================================================
 *       Filename:  alpabet.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/25 15:41:52
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: alpabet.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/25 15:41:52
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,j;
	for(i=1;i<=26;i++)
	{

		for(j=1;j<=i;j++)
		{
			printf("%c",64+i);
		}
		printf("\n");
	}
	return 0;
}

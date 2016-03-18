/*
 * =====================================================================================
 *       Filename:  test_local.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2015/5/22 23:42:24
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: test_local.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2015/5/22 23:42:24
 ************************************************************************/
#include<stdio.h>
void modify(int i,int j,int *a)
{

	a[i] = 0;
	a[j] = 0;
}
int main()
{
	int a[10] = {
		0,1,2,3,4,5,6,7,8,9
	};
	int i=1,j=2;
	modify(i,j,a);
	int k;
	for(k = 0; k < 10;k++)
	{
		printf("%d\t",a[k]);
	}

	

	return 0;
}

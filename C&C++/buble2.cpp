/*
 * =====================================================================================
 *
 *       Filename:  buble2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/5/21 13:04:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liujianpc (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*************************************************************************
  > File Name: buble2.cpp
  > Author: liujianpc
  > Mail: zhouhu8899@163.com 
  > Created Time: 2014/5/21 13:04:15
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
const int n=6;
int main()
{
	int a[n]={0};
	int i;
	int j;
	int temp;
	printf("请输入6个等待排序的元素：\n");
	for(i=0;i<n;i++)
	{

		scanf("%d",&a[i]);

	}

	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

	printf("\n");
	getch();
	return 0;
	//getch();
}

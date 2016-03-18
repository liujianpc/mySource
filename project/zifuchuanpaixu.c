/*
 * =====================================================================================
 *       Filename:  zifupaixu.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/13 13:39:21
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: zifupaixu.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/13 13:39:21
 ************************************************************************/
#include<stdio.h>
#include<string.h>
void sort(char (*pt)[20]);
int main()
{
	int i,j;
	char (*p)[20];//一个指向数组的指针（数组长度为10）
	char a[10][20];
	while(1)
	{

		puts("input 10 strings of the same length:");
		for(i=0;i<10;i++)
		{
			printf("string_%d:\n",i);
			gets(a[i]);
		}
		p=a;
		sort(p);
		printf("****************************************************\n");
		printf("sorted strings:\n");
		for(i=0;i<10;i++)
		{
			printf("%s\n",a[i]);
		}

	}

	return 0;

}

void sort(char (*pt)[20])
{
	int i,j,change=0;
	char *p_temp;
	char temp[20];
	p_temp=temp;
	for(i=1;i<10;i++)

		for(j=0;j<10-i;j++)
		{
			if(strcmp(pt[j],pt[j+1]) > 0)
			{
				strcpy(p_temp,pt[j]);
				strcpy(pt[j],pt[j+1]);
				strcpy(pt[j+1],p_temp);
				change=1;
			}
			if(change==0) break;
		}
}



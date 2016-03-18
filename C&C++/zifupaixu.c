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
void sort(char **pt);
int main()
{
	//int i,j;
	char *a[10];
	char **p;
	p=a;	
	puts("input 10 strings of the same length:");
	for(*p=a[0];*p<a[10];(*p)++)
	{
			gets(*p);
	}
	p=a;
	sort(p);
	printf("sorted string:\n");
for(*p=a[0];*p<a[10];(*p)++)
	{
		//printf("%s\n",p);
		puts(*p);
	}

	return 0;

}

void sort(char **pt)
{
	int i,j,change=0;
	char **temp;
	for(i=1;i<10;i++)

		for(j=0;j<10-i;j++)
		{
			if(strcmp(*pt+j,*pt+j+1) > 0)
			{
				strcpy(*temp,*pt+j);
				strcpy(*pt+j,*pt+j+1);
				strcpy(*pt+j+1,*temp);
				change=1;
			}
			if(change==0) break;
		}
}



/*
 * =====================================================================================
 *       Filename:  char.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2015/4/14 12:11:25
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: char.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2015/4/14 12:11:25
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	int i,j;//微软雅黑，哈哈。试试看是不是有这种效果啊
	char * buffer = NULL;
	printf("input the number:");
	scanf("%d",&j);
	buffer = (char *)malloc((j+1)*sizeof(char));
	if(buffer == NULL) exit(1);
	for(i = 0;i < j;i++)
	{
		buffer[i] = rand()%26 + 'a';
	}
	buffer[j] = '\0';
	printf("%s",buffer);
	free(buffer);
	system("pause");
	return 0;
}

/*
 * =====================================================================================
 *       Filename:  lowTOup.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 15:34:18
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: lowTOup.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/20 15:34:18
 ************************************************************************/
#include<stdio.h>
void lowchTOup(char *str);
int main()
{
	char *string;
	while(1)
	{
		printf("input a string: ");
		gets(string);
		lowchTOup(string);
		puts(string);
	}
	return 0;
}

void lowchTOup(char *str)
{
	while(*str!='\0')
	{
		if(*str>='a'&&*str<='z')
			*str -= 32;
		str++;
	}
}

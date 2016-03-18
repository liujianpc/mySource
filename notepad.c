/*
 * =====================================================================================
 *       Filename:  notepad.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/10/17 21:01:46
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: notepad.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/10/17 21:01:46
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{

	FILE *fp = fopen("C:\\1.txt","r");
	char str[300] = {0};
	fgets(str,300,fp);
	fclose(fp);
	printf("%s",str);
	getch();
	
	return 0;
}


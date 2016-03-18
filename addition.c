/*
 * =====================================================================================
 *       Filename:  addition.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/11/14 11:00:12
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: addition.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/11/14 11:00:12
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101
//构造线性表 ，采用结构体，也可以直接采用一维数组 
typedef struct Sqlist{
	char oprt[MAX];
};

int main()
{
	int number[MAX] = {0};
	int i = 0,l = 0,k = 0;
	struct Sqlist sq;
	while(1)
	{
		int sum = 0;
		printf("please input (less than 100) integers:\n");//提示输入少于100位数字 
		scanf("%s",sq.oprt);
		//puts(sq.oprt);
		//l = strlen(sq.oprt);
		//printf("%d",l);
		l = strlen(sq.oprt);
		
		//一下for循环是将输入的字符串转成一维整型数组 
		for(i = 0,k = 0;i < l;i++,k++)
		{
			if(sq.oprt[i] == '-')//识别负号'-' 
			{
				number[k] = -(sq.oprt[++i] - '0');
			}
			
			else if(sq.oprt[i] == ',')//识别逗号‘，’，且将逗号转成0 
			{
				number[k] = 0;
			}
	
			else//‘0’--‘9’之间的字符转换成0--9的整型数 
			{
				number[k] = sq.oprt[i] - '0';
			}
		}
	
	//以下for循环为对转成的一维整型数组进行求和 
	 	for(k = 0;k < l;k++)
		{
			sum = sum + number[k];
		}
		printf("the sum is: %d\n",sum);
		}
		
	return 0;
}

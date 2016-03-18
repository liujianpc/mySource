/*
 * =====================================================================================
 *       Filename:  substrcation.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/11/14 12:41:39
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: substrcation.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/11/14 12:41:39
 ************************************************************************/

#include<stdio.h>
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
		printf("please input (less than 100) integers:\n");//提示输入少于100位的数字 
		scanf("%s",sq.oprt);
		//puts(sq.oprt);
		//l = strlen(sq.oprt);
		//printf("%d",l);
		l = strlen(sq.oprt);
		//将输入的字符串转换成一维整型数组 
		for(i = 0,k = 0;i < l;i++,k++)
		{
			if(sq.oprt[i] == '-')//识别负号‘-’ 
			{
				number[k] = -(sq.oprt[++i] - '0');
			}
			
			else if(sq.oprt[i] == ',')//把组之间的逗号转换成0 
			{
				number[k] = 0;
			}
	
			else
			{
				number[k] = sq.oprt[i] - '0';//'0'-'9'之间的字符转换成0-9之间的整型数 
			}
		}

		int sum = number[0];
//对一维整型数组进行减法运算	
	 	for(k = 1;k < l;k++)
		{
			sum = sum - number[k];
		}
		printf("the sum is: %d\n",sum);
		}
		
	return 0;
}



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
//�������Ա� �����ýṹ�壬Ҳ����ֱ�Ӳ���һά���� 
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
		printf("please input (less than 100) integers:\n");//��ʾ��������100λ������ 
		scanf("%s",sq.oprt);
		//puts(sq.oprt);
		//l = strlen(sq.oprt);
		//printf("%d",l);
		l = strlen(sq.oprt);
		//��������ַ���ת����һά�������� 
		for(i = 0,k = 0;i < l;i++,k++)
		{
			if(sq.oprt[i] == '-')//ʶ�𸺺š�-�� 
			{
				number[k] = -(sq.oprt[++i] - '0');
			}
			
			else if(sq.oprt[i] == ',')//����֮��Ķ���ת����0 
			{
				number[k] = 0;
			}
	
			else
			{
				number[k] = sq.oprt[i] - '0';//'0'-'9'֮����ַ�ת����0-9֮��������� 
			}
		}

		int sum = number[0];
//��һά����������м�������	
	 	for(k = 1;k < l;k++)
		{
			sum = sum - number[k];
		}
		printf("the sum is: %d\n",sum);
		}
		
	return 0;
}



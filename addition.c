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
		int sum = 0;
		printf("please input (less than 100) integers:\n");//��ʾ��������100λ���� 
		scanf("%s",sq.oprt);
		//puts(sq.oprt);
		//l = strlen(sq.oprt);
		//printf("%d",l);
		l = strlen(sq.oprt);
		
		//һ��forѭ���ǽ�������ַ���ת��һά�������� 
		for(i = 0,k = 0;i < l;i++,k++)
		{
			if(sq.oprt[i] == '-')//ʶ�𸺺�'-' 
			{
				number[k] = -(sq.oprt[++i] - '0');
			}
			
			else if(sq.oprt[i] == ',')//ʶ�𶺺š��������ҽ�����ת��0 
			{
				number[k] = 0;
			}
	
			else//��0��--��9��֮����ַ�ת����0--9�������� 
			{
				number[k] = sq.oprt[i] - '0';
			}
		}
	
	//����forѭ��Ϊ��ת�ɵ�һά�������������� 
	 	for(k = 0;k < l;k++)
		{
			sum = sum + number[k];
		}
		printf("the sum is: %d\n",sum);
		}
		
	return 0;
}

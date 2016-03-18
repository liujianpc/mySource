/*
 * =====================================================================================
 *       Filename:  jisuanqi.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2015/3/29 21:58:54
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: jisuanqi.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2015/3/29 21:58:54
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct DATA{
	float op;
	struct DATA *next;
};
//float calcul(char a);
float calcul(char a,struct DATA *lptr)
{

	float result;
	struct DATA *p = lptr;
	switch(a)
	{

		case '+':
			{
				float sum = 0;
				while(p != NULL)
				{
					sum = sum + p->op;
					p = p->next;

				}
				result = sum;
				break;
			}

		case '-':
			{
				result = p->op;
				p = p->next;
				while(p != NULL)
				{
					result = result - p->op;
					p = p ->next;
				}
				break;
			}

		case '*':
			{
				result = 1.0;
				while(p != NULL)
				{
					result = result * p->op;
					p = p->next;
				}
				break;
			}

		case '/':
			{
				result = p->op;
				while(p != NULL)
				{
					result = result / p->op;
					p = p->next;
				}
				break;
			}
	}


	return result;

}


int main()
{

//	while(1)
//	{

		char opt = getchar();
		char a[10] = {0};

		switch(opt)
		{
			case '+':
				printf("operation +\tplease input numbers\n");
				break;
			case '-':
				printf("operation -\tplease input numbers\n");
				break;
			case '*':
				printf("operation *\tplease input numbers\n");
				break;
			case '/':
				printf("operation /\tplease input numbers\n");
				break;
			default:
				printf("incorrect input\n");
				break;

		}

		struct DATA *p = NULL;
		struct DATA *L = (struct DATA *)malloc(sizeof(struct DATA));
		p = L;
		p->next = NULL;
		//输入操作数以等号结束
		while(getchar() != '=')
		{

			p->next = (struct DATA *)malloc(sizeof(struct DATA));
			gets(a);
			p->op = atof(a);
			p = p->next;
			p->next = NULL;
		}
		float answer;
		answer = calcul(opt,L);
		printf("the answer is %f",answer);
//	}

	return 0;
}



/*
 * =====================================================================================
 *       Filename:  cacculate.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/11/14 13:20:26
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: cacculate.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/11/14 13:20:26
 ************************************************************************/
/*�ӷ��������Ϊһ������*/ 
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101
//���ýṹ�幹�����Ա�Ҳ����ֱ�Ӳ���һά���� 
typedef struct Sqlist{
	char oprt[MAX];
};

int main()
{
	int number[MAX] = {0};
	int i = 0,l = 0,k = 0;
	char a;
	struct Sqlist sq;//�������Ա� 
	while(1)
	{
		printf("please input '+'or'-':");//��ʾ���롮+����-�� 
	 
		
			switch(getchar())//����Ӽ������ѡ����� 
			{
				case '+':
					{
						printf("you have chosen '+' Additon\n*********************************************\n");
						int sum = 0;
						printf("please input (less than 100) integers:\n");
						scanf("%s",sq.oprt);
						//puts(sq.oprt);
						//l = strlen(sq.oprt);
						//printf("%d",l);
						l = strlen(sq.oprt);
						
						//����forѭ����������ַ���ת���һά�������� 
						for(i = 0,k = 0;i < l;i++,k++)
						{
							if(sq.oprt[i] == '-')//ʶ�����'-'���� 
							{
								number[k] = -(sq.oprt[++i] - '0');
							}

							else if(sq.oprt[i] == ',')//��λһ�飬����ö��Ÿ�����ת��ʱ������ת��Ϊ0 
							{
								number[k] = 0;
							}

							else//�����������ַ�ת������������ 
							{
								number[k] = sq.oprt[i] - '0';
							}
						}
						
						//����forѭ���ǽ�ת���ɵ�һά������������������ 
						for(k = 0;k < l;k++)
						{
							sum = sum + number[k];
						}
						printf("the sum is: %d\n*******************************************************\n",sum);
					}
					break;
					
					//����Ϊ�������㣬ͬ��ֻ��ע�⽫sum��ʼֵ��ֵΪnumber[0] 

				case '-':
					{
						{
							printf("you have chosen substraction\n************************************************\n");
							printf("please input (less than 100) integers:\n");
							scanf("%s",sq.oprt);
							//puts(sq.oprt);
							//l = strlen(sq.oprt);
							//printf("%d",l);
							l = strlen(sq.oprt);
							for(i = 0,k = 0;i < l;i++,k++)
							{
								if(sq.oprt[i] == '-')
								{
									number[k] = -(sq.oprt[++i] - '0');
								}

								else if(sq.oprt[i] == ',')
								{
									number[k] = 0;
								}

								else
								{
									number[k] = sq.oprt[i] - '0';
								}
							}

							int sum = number[0];

							for(k = 1;k < l;k++)
							{
								sum = sum - number[k];
							}
							printf("the result is: %d\n***************************************************\n",sum);
						}
						break;
					}
					
					//������ѡ���������ʾ������� 
				//default:printf("incorrect input��please input again\n"); 

			}

		

	}

	return 0;
}




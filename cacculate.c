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
/*加法与减法合为一个程序*/ 
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101
//采用结构体构造线性表，也可以直接采用一维数组 
typedef struct Sqlist{
	char oprt[MAX];
};

int main()
{
	int number[MAX] = {0};
	int i = 0,l = 0,k = 0;
	char a;
	struct Sqlist sq;//声明线性表 
	while(1)
	{
		printf("please input '+'or'-':");//提示输入‘+’‘-’ 
	 
		
			switch(getchar())//进入加减运算的选择程序 
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
						
						//以下for循环将输入的字符串转变成一维整型数组 
						for(i = 0,k = 0;i < l;i++,k++)
						{
							if(sq.oprt[i] == '-')//识别符号'-'负号 
							{
								number[k] = -(sq.oprt[++i] - '0');
							}

							else if(sq.oprt[i] == ',')//四位一组，组间用逗号隔开，转换时将逗号转换为0 
							{
								number[k] = 0;
							}

							else//正常的数字字符转换成整型数字 
							{
								number[k] = sq.oprt[i] - '0';
							}
						}
						
						//以下for循环是将转换成的一维整型数组进行求和运算 
						for(k = 0;k < l;k++)
						{
							sum = sum + number[k];
						}
						printf("the sum is: %d\n*******************************************************\n",sum);
					}
					break;
					
					//以下为减法运算，同理。只需注意将sum初始值赋值为number[0] 

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
					
					//当输入选择符错误，提示输入错误 
				//default:printf("incorrect input，please input again\n"); 

			}

		

	}

	return 0;
}




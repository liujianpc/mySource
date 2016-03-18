/*
 * =====================================================================================
 *       Filename:  hannuota.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 16:00:59
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: hannuota.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/20 16:00:59
 ************************************************************************/

#include<stdio.h>
int hnt(int n,char one,char two,char three);
int yd(char one,char two);
int main()
{
	int hnt(int n,char one,char two,char three);
	int n;
	char a,b,c;
	while(1)
	{
		printf("输入圆盘数\n");
		scanf("%d",&n);
		hnt(n,'a','b','c');
	}

	return 0;
}
int hnt(int n,char one,char two,char three)
{
	int yd(char one,char two);
	if(n==1)
		yd(one,three);
	else{   
		hnt(n-1,one,three,two);
		yd(one,three);           
		hnt(n-1,two,one,three);
	}
}
int yd(char one,char two)
{
	printf("把%c搬到%c\n",one,two);

}

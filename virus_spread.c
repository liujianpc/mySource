/*
 * =====================================================================================
 *       Filename:  virus_spread.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2015/5/22 23:14:41
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: virus_spread.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2015/5/22 23:14:41
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int p = 5; 

struct PC{
	char sys[10];
	int infect;
};

int creat_rand(){
	srand((unsigned)time(NULL));
	return (rand()%10);
}

void contact(int m, int k,struct PC *ptr){
	if(m == 1 && k != 1)
	{
		if(creat_rand() >= p)
		{
			(ptr+k)->infect = 1;
		}

	}

	else if(k == 1 && m != 1)
	{
		if(creat_rand() >= p)
			(ptr+m)->infect = 1;
	}
	else;
}

struct PC computer[10]={
		{"windows",1},
		{"windows",1},
		{"windows",0},
		{"windows",1},
		{"windows",1},
		{"windows",1},
		{"windows",1},
		{"windows",1},
		{"windows",0},
		{"windows",0}
	};

int main()
{
	

	int h;
	for(h = 0;h < 10;h++)
	{

		while(computer[h].infect != 1)
		{
			int i = creat_rand();

			contact(h,i,computer);
		}
		printf("through\n");

	}
int g;
	for(g = 0;  g< 10 ;g++)
		printf("{%s,%d}\n",computer[g].sys,computer[g].infect);

	return 0;
}
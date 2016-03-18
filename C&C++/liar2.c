/*
 * =====================================================================================
 *       Filename:  liar2.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/5/22 22:18:49
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: liar2.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/5/22 22:18:49
 ************************************************************************/

#include<stdio.h>
int main()
{
	int a,b,c,d;
	for(a=0;a<=1;a++)
	{
		for(b=0;b<=1;b++)
		{
			for(c=0;c<=1;c++)
			{
				for(d=0;d<=1;d++)
				{
					if((a+b+c+d==1)&&((!b&&d)+(b&&!d)==1)&&((!b&&c)+(b&&!c)==1)&&((!a&&b)+(a&&!b)==1)&&(!d+d==1))
					{
						if(1==a) printf("liar is A\n");
						else if(1==b) printf("liar is B\n");
						else if(1==c) printf("liar is C\n");
						else printf("liar is D\n");
					}
				}
			}
		}
	}
	return 0;
}

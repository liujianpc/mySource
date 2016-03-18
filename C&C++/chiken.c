/*
 * =====================================================================================
 *       Filename:  chiken.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/5/24 8:46:48
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: chiken.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/5/24 8:46:48
 ************************************************************************/

#include<stdio.h>
int main()
{
	int male,female,chicken;
	for(male=0;male<20;male++)
		for(female=0;female<=33;female++)
			for(chicken=0;chicken<=100;chicken++)
			{
				if(5*male+3*female+chicken/3==100 && male+female+chicken==100 && chicken%3==0)
					printf("male:%d\tfemale:%d\tchicken:%d\n",male,female,chicken);
			}
	return 0;
}

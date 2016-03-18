/*
 * =====================================================================================
 *       Filename:  pointerOffunc.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/25 16:38:22
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: pointerOffunc.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/25 16:38:22
 ************************************************************************/
#include<stdio.h>
int *calc(int x,int y){
	int result=0;
	result=x|y+x+y;
	return &result;
}
int main(){
	int *result;
	printf("%d\n",calc(10,5));
	result=calc(10,5);
	printf("%d\n",*result);
	return 0;
}







/*
 * =====================================================================================
 *       Filename:  defien.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 15:45:17
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: defien.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/20 15:45:17
 ************************************************************************/
#include<stdio.h>
#define DX(c) c>='A'&&c<='Z'
#define XX(c) c>='a'&&c<='z'
#define NU(c) c>='0'&&c<='9'
#define ADD(a) a++
#define COUT(c,x,y,z) if(DX(c)) ADD(x);if(XX(c)) ADD(y);if(NU(c)) ADD(z);
int main()
{
  int count_xx=0,count_dx=0,count_nu=0;
  char ch;
  while(1)
  {

  printf("input a string(with an end_sign '*'): \n");
  ch=getchar();
  while(ch!='*')
  {
    COUT(ch,count_dx,count_xx,count_nu);
    ch=getchar();
  }
  printf("count_xx=%d\n",count_xx);
  printf("count_dx=%d\n",count_dx);
  printf("count_nu=%d\n",count_nu);

  }
  return 0;

}

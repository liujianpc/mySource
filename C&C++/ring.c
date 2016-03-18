/*
 * =====================================================================================
 *       Filename:  ring.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/25 22:35:52
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: ring.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/25 22:35:52
 ************************************************************************/

#include <stdio.h>
#include <windows.h>
int main()  
{
	while (1)
	{
		char a,b,c;   
		a='A';
		b='B';
		c=007;
		putchar(a); 
		putchar(b); 
		putchar('\n');
		
		putchar(c) ;  
		Sleep(5);     
		putchar(c);
		putchar('A');
		putchar('B');
		putchar('\n');
		putchar(007);  
		Sleep(3);  
		putchar(007); 
	
	}
		return 0;

}

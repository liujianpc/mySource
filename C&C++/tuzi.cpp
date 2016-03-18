/*
 * =====================================================================================
 *       Filename:  tuzi.cpp
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 16:14:23
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: tuzi.cpp
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/20 16:14:23
 ************************************************************************/

#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
int Fibonacci(int n)
{
 int t1,t2;
 if(n>0)
 {
  if(n==1||n==2)
  {
   return 1;
  }
  else
  {
   t1=Fibonacci(n-1);  
   t2=Fibonacci(n-2);    
   return t1+t2;
  } 
 }
 else
 {
  return 0;
 }
}
int main()
{
 int n,num;
 cout<<"请输入时间："<<endl;
 cin>>n;
 num=Fibonacci(n);
 cout<<"经过"<<n<<"个月之后"<<endl;
 cout<<"兔子的数量为："<<num<<"对"<<endl;
 return 0; 
}

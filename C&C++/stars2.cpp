/*
 * =====================================================================================
 *       Filename:  stars2.cpp
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/5/22 12:13:23
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: stars2.cpp
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/5/22 12:13:23
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	cout<<"input a number(n):"<<endl;
	cin>>n;
	cout<<"\n";
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			cout<<"  ";
		}
		for(j=n-i+1;(j>n-i)&&(j<n+i);j++)
		{
			cout<<"* ";
		}
		cout<<"\n";
	}
	for(i=1;i<=2*n-1;i++)
	{
		cout<<"* ";
	}
	cout<<"\n";
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<"  ";
		}
		for(j=i+1;(j>i)&&(j<2*n-i);j++)
		{
			cout<<"* ";
		}
		for(j=2*n-i;j<=2*n-1;j++)
		{
			cout<<"  ";
		}
		cout<<"\n";
	}

	return 0;
}

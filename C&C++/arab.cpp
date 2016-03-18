/*
 * =====================================================================================
 *       Filename:  arab.cpp
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 16:15:38
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: arab.cpp
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/20 16:15:38
 ************************************************************************/

#include<iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;
int arr1[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
string arr2[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
string covert2Roman(int n)
{
 string s;
 int i=0;
 while(n){
 if(n>=arr1[i]){
 n-=arr1[i];
 s+=arr2[i];
 }
 else {
 i++;
 }
 }
 return s;
}
int main()
{
 int n;
 cout<<"输入一个数："<<endl; 
 while(cin>>n){
 cout<<covert2Roman(n)<<endl;
 }
}

/*
 * =====================================================================================
 *       Filename:  xuanmei.cpp
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 16:18:44
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: xuanmei.cpp
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/20 16:18:44
 ************************************************************************/

#include<iostream>
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct student
{
int number;
int result;
int mingci;
};
int main(void)
{
student box[7]=
{
{1,5,1},
{2,3,1},
{3,4,1},
{4,7,1},
{5,3,1},
{6,5,1},
{7,6,1}
};
for (int i=0;i<7;i++)
{
for (int j=i+1;j<7;j++)
{
if (box[i].result<box[j].result)
{
student temp;
temp=box[i];
box[i]=box[j];
box[j]=temp;
}
else if (box[i].result==box[j].result)
{
student temp;
temp=box[i+1];
box[i+1]=box[j];
box[j]=temp;
}       
}
}
for (int i=0;i<6;i++)
{
if (box[i].result==box[i+1].result)
{
box[i+1].mingci=box[i].mingci;
}
else
{
box[i+1].mingci=box[i].mingci+1;
}
}
for (int i=0;i<7;i++)
{
for (int j=i+1;j<7;j++)
{
if (box[i].number>box[j].number)
{
student temp;
temp=box[i];
box[i]=box[j];
box[j]=temp;
}
}
 
         
    }
 
for (int i=0;i<7;i++)
{
cout<<"选手号:"<<box[i].number<<" 得分:"<<box[i].result<<" 名次:"
<<box[i].mingci<<endl;
}
return 0;
}

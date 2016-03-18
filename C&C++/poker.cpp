/*
 * =====================================================================================
 *       Filename:  poker.cpp
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/20 16:07:39
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: poker.cpp
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/6/20 16:07:39
 ************************************************************************/

#include<iostream>
using namespace std;
#include "stdio.h"   
#include "stdlib.h"   
#include "time.h"      
/*一副牌，去除大小王，四个玩家，每人13张牌*/      
int suitName[4] = { 3,4,5,6 };   
//const char suitName[][5] = {"黑桃", "红桃", "草花", "方片" };   
const char faceName[][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};      
int flag[4][13]={0};   //每张牌是否已发出标志      
int main()   
{   
    int i,j,k,l;             
    printf("\n");   
    printf("—开始发牌……");   
    printf("\n");         
    srand((unsigned)time(NULL));         
    for(i=0;i<13;i++)   
    {             
       printf("—第%d轮:\t", i+1);             
       for(j=0;j<4;j++)   
       {      
          do   
          {      
              k = (int)(rand()%4);   //产生0 ~ 3的随机数   
              l = (int)(rand()%13);  //产生0 ~ 12的随机数      
          }   
          while( flag[k][l] == 1 );  //如果该牌已发出，重新产生随机数      
          printf( "%c", suitName[k] );   
          printf( "%s\t", faceName[l] );     
          for(long p=0;p<50000000;p++ ){}   //延时，显示发牌过程     
          flag[k][l]=1;     //已发牌的标志                    
       }   
            printf("\n");   
    }      
           printf("—发牌结束—");       
           printf("\n"); 
		   return 0;          
}  

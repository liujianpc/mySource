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
/*һ���ƣ�ȥ����С�����ĸ���ң�ÿ��13����*/      
int suitName[4] = { 3,4,5,6 };   
//const char suitName[][5] = {"����", "����", "�ݻ�", "��Ƭ" };   
const char faceName[][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};      
int flag[4][13]={0};   //ÿ�����Ƿ��ѷ�����־      
int main()   
{   
    int i,j,k,l;             
    printf("\n");   
    printf("����ʼ���ơ���");   
    printf("\n");         
    srand((unsigned)time(NULL));         
    for(i=0;i<13;i++)   
    {             
       printf("����%d��:\t", i+1);             
       for(j=0;j<4;j++)   
       {      
          do   
          {      
              k = (int)(rand()%4);   //����0 ~ 3�������   
              l = (int)(rand()%13);  //����0 ~ 12�������      
          }   
          while( flag[k][l] == 1 );  //��������ѷ��������²��������      
          printf( "%c", suitName[k] );   
          printf( "%s\t", faceName[l] );     
          for(long p=0;p<50000000;p++ ){}   //��ʱ����ʾ���ƹ���     
          flag[k][l]=1;     //�ѷ��Ƶı�־                    
       }   
            printf("\n");   
    }      
           printf("�����ƽ�����");       
           printf("\n"); 
		   return 0;          
}  

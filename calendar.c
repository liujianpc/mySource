/*
 * =====================================================================================
 *       Filename:  calendar.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2015/3/19 20:32:09
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: calendar.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2015/3/19 20:32:09
 ************************************************************************/

#include<stdio.h>
//int leapYear(int year);
//int yearDay(int year);
//int monthDay(int month);
//int dateDay(int date);

int main()
{

	while(1)
	{
		int year,month,date;
		int tmp_monthDay;
		int i,j,k;
		int total_yearDay = 0,total_monthDay = 0,totalDay,month_day;
		printf("*****************************************************************\n");
		printf("\t\t\tWelcome to calendar(by LiuJian)\n");
		printf("*****************************************************************\n");
		printf("\t\t\tplease input date:");
		scanf("%d%d%d",&year,&month,&date);
		printf("\n");
		
		printf("   Mon   Tue   Wed   Thu   Fri   Sat   Sun\n");
		
		for(i = 1900;i < year;i++)
		 {
		 	if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) 
				total_yearDay = total_yearDay + 366;
			else total_yearDay = total_yearDay + 365;
	
		 }
		 
		for(j = 1;j < month;j++)
		{
			switch(j)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					month_day = 31;
					break;
				case 2:
					{
						if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) month_day = 29;
						else month_day = 28;
						break;
					}
				case 4:
				case 6:
				case 9:
				case 11:
					month_day = 30;
					break;
			}
			total_monthDay = total_monthDay + month_day;
		}
	
		totalDay = total_yearDay + total_monthDay;
		
		
		int t = 0,index;
		index = (totalDay % 7) + 1;
		t = index;
		
		switch(month)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					tmp_monthDay = 31;
					break;
				case 2:
					{
						if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) tmp_monthDay = 29;
						else tmp_monthDay = 28;
						break;
					}
				case 4:
				case 6:
				case 9:
				case 11:
					{
						tmp_monthDay = 30;
						break;
					}
			}
		
			
		for(k = 1;k <= tmp_monthDay;k++)
		{
			
			if(k == 1)
			{
				if(index % 7 == 0) 
				{	printf("%*d\n",6*index,k);
					t++;
				}
				else
				{	printf("%*d",index*6,k);
						t++;
				}
			}
			
			
			else
			{
				if(t % 7 == 0) 
				{
					printf("%*d\n",6,k);
					t++;
				}
				else 
				{
					printf("%*d",6,k);
					t++;
				}
			}
			
			
			
			
			
	
		}
		printf("\n");
		printf("\n");
		}
	

	return 0;
}

/*int leapYear(int year)
{
	int leap;
	leap = ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))?1:0; 
	return leap;
}
*/
//每一年的天数
/*int yearDay(int year)
{
	
	if (leapYear(year) == 1) year_Day = 366;
	else year_Day = 365;
	return year_Day;
}*/

//每一个月的天数
/*int monthDay(int month)
{
	int month_day;
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			month_day = 31;
			break;
		case 2:
			{
				if(leapYear(year) == 1) month_day = 29;
				else month_day = 28;
				break;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			month_day = 30;
			break;
	}
	return month_day;
}

*/
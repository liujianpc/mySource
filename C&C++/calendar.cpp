#include<stdio.h>
int main()
{
	int i,year,month,date,yearDay,monthDay,dateDay,month_day,days,firstDay,flag;

	while(1)
	{
		printf("input a year:");
		scanf("%d",&year);
		printf("input a month:");
		scanf("%d",&month);
		printf("input a date:");
		scanf("%d",&date);

		yearDay=0;
		monthDay=0;
		/*��������ɵ�������*/
		for(i=1900;i<year;i++)
		{
			if((i%4==0)&&(i%100!=0)||(i%400==0) )
			{
				yearDay+=366;
			}
			else yearDay+=365;

		}

		/*��������ɵ�������*/
		for(i=1;i<month;i++)
		{
			switch(i)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:monthDay+=31;
						break;

				case 4:
				case 6:
				case 9:
				case 11:monthDay+=30;
						break;

				case 2:
						if(((year%4==0)&&(year%100!=0))||(year%400==0))
						{
							monthDay+=29;
						}
						else monthDay+=28;
			}

		}
		/*���������ղ�������������*/
		days=yearDay+monthDay+date-1;

		/*ѡ����Ҫ������·�*/
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: month_day=31;
					 break;

			case 4:
			case 6:
			case 9:
			case 11: month_day=30;
					 break;

			case 2: if((year%4==0)&&(year%100!=0)||(year%400==0))
					{
						month_day=29;
					}

					else month_day=28;
		}

		/*input the calendar*/
		printf("*****************************************************************\n");
		printf("\t\t    %d��\n",month);
		printf("     һ    ��    ��    ��    ��    ��    ��\n");
		if(date==1)
			firstDay=1+days%7;//very important!!!
		else firstDay=1+(yearDay+monthDay)%7;//��date����1ʱѡ�����������䣬��˲��ܷ�ֹÿ���µĵ�һ�����ڴ�λ
		flag=6*firstDay;
		if(date==1)
		printf("%*c%d%c",flag-2,91,1,93);
		else printf("%*d",flag,1);
		if(firstDay==7)
			printf("\n");

		for(i=2;i<=month_day;i++)
		{

			if(i==date)
			{
				printf("   [%d]",i);
			}
			else printf("%6d",i);

			if((firstDay+i-1)%7==0)
				printf("\n"); 



		}
		

		printf("\n*****************************************************************");
		printf("\npowered by jianguo & All Rights Reserved");

printf("\n*****************************************************************");
		printf("\n");

	}
	return 0;
}

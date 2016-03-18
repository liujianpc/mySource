/*
 * =====================================================================================
 *       Filename:  grade.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/6/14 0:29:39
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: grade.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/6/14 0:29:39
 ************************************************************************/

#include<stdio.h>
#include<string.h>

struct grade
{
	int lesson[5];
	float average; //= (lesson[0]+lesson[1]+lesson[2]+lesson[3]+lesson[4])/5;
};

struct student
{
	char name[20];
	char number[20];
	struct grade mark;
};

void aver(int x,struct student *p);
void notjg(struct student *p);
void good(struct student *p);

int main()
{
	struct student stu[4];
	struct student *p_stu;
	int a,j,n;
	p_stu=stu;
	for(a=1;p_stu<stu+4;p_stu++,a++)
	{
		int total=0;
		printf("**************************************************************\n");
		printf("输入第%d位学生的信息:\n",a);
		printf("姓名:\t");
		scanf("%s",&p_stu->name);
		printf("学号:\t");
		scanf("%s",&p_stu->number);
		printf("各门成绩:\t");
	
		for(j=0;j<5;j++)
		{
			scanf("%d",&p_stu->mark.lesson[j]);
			
		}
		
		for(j=0;j<5;j++)
		{
			total += p_stu->mark.lesson[j];
		}
			p_stu->mark.average = total/5.0;


	}
	printf("\n");
	printf("**************************************************************\n");
	printf("输入需要计算平均分的课程(0,1,2,3,4):");
	scanf("%d",&n);
	printf("\n");
	aver(n,stu);
	notjg(stu);
	good(stu);

	return 0;
}

void aver(int x,struct student *p)
{
	float pj;
	int sum=0;
	struct student *i;

	switch(x)
	{
		case 0:
			for(i=p;i<p+4;i++)
			{
				sum += i->mark.lesson[0];
			}
			pj=sum/4.0;
			break;
		case 1:
			for(i=p;i<p+4;i++)
			{
				sum += i->mark.lesson[1];
			}
			pj=sum/4.0;
			break;
		case 2:
			for(i=p;i<p+4;i++)
			{
				sum += i->mark.lesson[2];
			}
			pj=sum/4.0;
			break;
		case 3:
			for(i=p;i<p+4;i++)
			{
				sum += i->mark.lesson[3];
			}
			pj=sum/4.0;
			break;
		case 4:
			for(i=p;i<p+4;i++)
			{
				sum += i->mark.lesson[4];
			}
			pj=sum/4.0;
			break;

	}

	printf("lesson[%d]平均分:%f\n",x,pj);
	printf("**************************************************************\n");

}

void notjg(struct student *p)
{
	int j,k,cout=0;
	struct student *i;
	printf("两门以上不及格学生：\n");
	for(i=p;i<p+4;i++)
	{
		for(j=0;j<=4;j++)
		{
			if(i->mark.lesson[j]<60) cout++;
		}
		if(cout>=2)
		{
			printf("不及格学号:%s\t",i->number);
			printf("总平均分:%f\t",i->mark.average);
			printf("各科成绩:");
			for(k=0;k<5;k++) printf("%d  ",i->mark.lesson[k]);
			printf("\n");
		}
		else printf("%s同学合格\n",i->name);

	}

}

void good(struct student *p)
{
	int m;
	struct student *i;
	printf("**************************************************************\n");
	for(i=p;i<p+4;i++)
	{
		//d=int(i->mark.average);
if(((i->mark.lesson[0]>=85)&&(i->mark.lesson[1]>=85)&&(i->mark.lesson[2]>=85)&&(i->mark.lesson[3]>=85)&&(i->mark.lesson[4]>=85))||((int)(i->mark.average)>=90))
	{ printf("\t优秀学生: %s",i->name);
	}
	}
	printf("\n");

}

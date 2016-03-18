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
		printf("�����%dλѧ������Ϣ:\n",a);
		printf("����:\t");
		scanf("%s",&p_stu->name);
		printf("ѧ��:\t");
		scanf("%s",&p_stu->number);
		printf("���ųɼ�:\t");
	
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
	printf("������Ҫ����ƽ���ֵĿγ�(0,1,2,3,4):");
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

	printf("lesson[%d]ƽ����:%f\n",x,pj);
	printf("**************************************************************\n");

}

void notjg(struct student *p)
{
	int j,k,cout=0;
	struct student *i;
	printf("�������ϲ�����ѧ����\n");
	for(i=p;i<p+4;i++)
	{
		for(j=0;j<=4;j++)
		{
			if(i->mark.lesson[j]<60) cout++;
		}
		if(cout>=2)
		{
			printf("������ѧ��:%s\t",i->number);
			printf("��ƽ����:%f\t",i->mark.average);
			printf("���Ƴɼ�:");
			for(k=0;k<5;k++) printf("%d  ",i->mark.lesson[k]);
			printf("\n");
		}
		else printf("%sͬѧ�ϸ�\n",i->name);

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
	{ printf("\t����ѧ��: %s",i->name);
	}
	}
	printf("\n");

}

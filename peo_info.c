/*
 * =====================================================================================
 *       Filename:  peo_info.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/11/14 16:21:50
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: peo_info.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/11/14 16:21:50
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//构造单链表结点 
struct peo_info
{
	char name[10];
	char tel[20];
	char mail[20];
	char adr[20];
	char pos[20];
	struct peo_info * next;//结点的指针域 
};
struct list//h是头指针，不储存数据
{
	struct peo_info * h;
	int l;
};
void input_p(struct peo_info * a)
{
	printf("请输入姓名：\n");
	scanf("%s",a->name);
	printf("请输入电话：\n");
	scanf("%s",a->tel);
	printf("请输入邮箱：\n");
	scanf("%s",a->mail);
	printf("请输入地址：\n");
	scanf("%s",a->adr);
	printf("请输入邮编：\n");
	scanf("%s",a->pos);
}
void insert(struct peo_info * b,struct peo_info * c)//把c插入到b的后面
{
	c->next=b->next;
	b->next=c;
}
void get(struct peo_info * a)//取出的是a->next
{
	a->next=a->next->next;
}
void n_list(struct list * a)//这个函数调用完h已经有了内存
{
	a->l=0;
	a->h=(struct peo_info *)malloc(sizeof(struct peo_info));
	a->h->next=NULL;
}
void n_p(struct list * a)//往链表尾添加一个新成员
{
	struct peo_info * p;
	p=a->h;
	while(p->next!=NULL)
		p=p->next;
	p->next=(struct peo_info *)malloc(sizeof(struct peo_info));
	input_p(p->next);
	p->next->next=NULL;
	a->l++;
}
void shuchu_p(struct peo_info * a)
{
	printf("welcome to peo_info app Powered by Liujian"); 
	printf("*****************************************\n");
	printf("姓名：\n%s\n",a->name);
	printf("电话：\n%s\n",a->tel);
	printf("邮箱：\n%s\n",a->mail);
	printf("地址：\n%s\n",a->adr);
	printf("邮编：\n%s\n",a->pos);
	printf("*****************************************\n");
}
void shuchu_l(struct list * a)
{
	struct peo_info * p;
	p=a->h;
	while(p->next!=NULL)
	{
		shuchu_p(p->next);
		p=p->next;
	}
	system("pause");
}
void search_n(struct list * a)
{
	struct peo_info * p;
	p=a->h;
	char Name[10];
	printf("请输入要查找的人的姓名：\n");
	scanf("%s",Name);
	while(p->next!=NULL)
	{
		if(!strcmp(p->next->name,Name))
		{
			shuchu_p(p->next);
			break;
		}
		p=p->next;
	}
}
void search_a(struct list * a)
{
	struct peo_info * p;
	p=a->h;
	char Adr[20];
	printf("请输入要查找的人的地址：\n");
	scanf("%s",Adr);
	while(p->next!=NULL)
	{
		if(!strcmp(p->next->name,Adr))
		{
			shuchu_p(p->next);
			break;
		}
		p=p->next;
	}
}
void search_t(struct list * a)
{
	struct peo_info * p;
	p=a->h;
	char Tel[20];
	printf("请输入要查找的人的电话：\n");
	scanf("%s",Tel);
	while(p->next!=NULL)
	{
		if(!strcmp(p->next->name,Tel))
		{
			shuchu_p(p->next);
			break;
		}
		p=p->next;
	}
}
void search(struct list * a)
{
	int x;
	printf("1、按姓名查找\n");
	printf("2、按地址查找\n");
	printf("3、按电话查找\n");
	scanf("%d",&x);
	if(x==1)
		search_n(a);
	if(x==2)
		search_a(a);
	if(x==3)
		search_t(a);
	system("pause");
}
void paixu_n(struct list *a)
{
	struct list * b;
	b=(struct list *)malloc(sizeof(struct list));
	n_list(b);
	struct peo_info * p,* q,* r,*s;
	p=a->h;
	s=a->h->next;
	get(p);
	insert(b->h,s);
	while(p->next!=NULL)
	{
		q=p->next;
		get(p);
		r=b->h;
		while(strcmp(q->name,r->next->name)>=0)
		{
			r=r->next;
		}
		insert(r,q);
	}
	a->h=b->h;
}
void paixu_a(struct list *a)
{
	struct list * b;
	b=(struct list *)malloc(sizeof(struct list));
	n_list(b);
	struct peo_info * p,* q,* r,*s;
	p=a->h;
	s=a->h->next;
	get(p);
	insert(b->h,s);
	while(p->next!=NULL)
	{
		q=p->next;
		get(p);
		r=b->h;
		while(strcmp(q->adr,r->next->adr)>=0)
		{
			r=r->next;
		}
		insert(r,q);
	}
	a->h=b->h;
}
void paixu(struct list * a)
{
	int x;
	printf("1、按姓名排序\n");
	printf("2、按地址排序\n");
	printf("请输入您的选择：\n");
	scanf("%d",&x);
	if(x==1)
		paixu_n(a);
	if(x==2)
		paixu_a(a);
}
void del(struct list * a)
{
	struct peo_info * p;
	p=a->h;
	char Name[10];
	char Tel[20];
	printf("请输入要删除的人的姓名：\n");
	scanf("%s",Name);
	printf("请输入要删除的人的电话：\n");
	scanf("%s",Tel);
	while(p->next!=NULL)
	{
		if(strcmp(p->next->name,Name)==0&&strcmp(p->next->tel,Tel)==0)
		{
			get(p);
			a->l--;
			printf("删除成功\n");
			break;
		}
		p=p->next;
	}
	system("pause");
}
int menu()
{
	int n;
	printf("welcome to peo_info app Powered by Liujian\n");
	printf("*****************************************\n");
	printf("1、添加联系人\n");
	printf("2、显示所有联系人\n");
	printf("3、对所有联系人排序并显示\n");
	printf("4、查找指定联系人\n");
	printf("5、删除指定联系人\n");
	printf("6、退出通信录\n");
	printf("请输入您的选择：\n");
	printf("*****************************************\n");
	scanf("%d",&n);
	return n;
}
void app()
{
	struct list * a;
	int x;
	a=(struct list *)malloc(sizeof(struct list));
	n_list(a);
	x=menu();
	while(x<6)
	{
		system("cls");
		if(x==1)
			n_p(a);
		if(x==2)
			shuchu_l(a);
		if(x==3)
		{
			paixu(a);
			shuchu_l(a);
		}
		if(x==4)
			search(a);
		if(x==5)
			del(a);
		system("cls");
		x=menu();
	}
}
int main()
{
	app();
	return 0;
}

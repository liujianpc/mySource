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
//���쵥������ 
struct peo_info
{
	char name[10];
	char tel[20];
	char mail[20];
	char adr[20];
	char pos[20];
	struct peo_info * next;//����ָ���� 
};
struct list//h��ͷָ�룬����������
{
	struct peo_info * h;
	int l;
};
void input_p(struct peo_info * a)
{
	printf("������������\n");
	scanf("%s",a->name);
	printf("������绰��\n");
	scanf("%s",a->tel);
	printf("���������䣺\n");
	scanf("%s",a->mail);
	printf("�������ַ��\n");
	scanf("%s",a->adr);
	printf("�������ʱࣺ\n");
	scanf("%s",a->pos);
}
void insert(struct peo_info * b,struct peo_info * c)//��c���뵽b�ĺ���
{
	c->next=b->next;
	b->next=c;
}
void get(struct peo_info * a)//ȡ������a->next
{
	a->next=a->next->next;
}
void n_list(struct list * a)//�������������h�Ѿ������ڴ�
{
	a->l=0;
	a->h=(struct peo_info *)malloc(sizeof(struct peo_info));
	a->h->next=NULL;
}
void n_p(struct list * a)//������β���һ���³�Ա
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
	printf("������\n%s\n",a->name);
	printf("�绰��\n%s\n",a->tel);
	printf("���䣺\n%s\n",a->mail);
	printf("��ַ��\n%s\n",a->adr);
	printf("�ʱࣺ\n%s\n",a->pos);
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
	printf("������Ҫ���ҵ��˵�������\n");
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
	printf("������Ҫ���ҵ��˵ĵ�ַ��\n");
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
	printf("������Ҫ���ҵ��˵ĵ绰��\n");
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
	printf("1������������\n");
	printf("2������ַ����\n");
	printf("3�����绰����\n");
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
	printf("1������������\n");
	printf("2������ַ����\n");
	printf("����������ѡ��\n");
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
	printf("������Ҫɾ�����˵�������\n");
	scanf("%s",Name);
	printf("������Ҫɾ�����˵ĵ绰��\n");
	scanf("%s",Tel);
	while(p->next!=NULL)
	{
		if(strcmp(p->next->name,Name)==0&&strcmp(p->next->tel,Tel)==0)
		{
			get(p);
			a->l--;
			printf("ɾ���ɹ�\n");
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
	printf("1�������ϵ��\n");
	printf("2����ʾ������ϵ��\n");
	printf("3����������ϵ��������ʾ\n");
	printf("4������ָ����ϵ��\n");
	printf("5��ɾ��ָ����ϵ��\n");
	printf("6���˳�ͨ��¼\n");
	printf("����������ѡ��\n");
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

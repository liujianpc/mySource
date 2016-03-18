/*
 * =====================================================================================
 *       Filename:  a.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/11/13 22:02:26
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: a.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/11/13 22:02:26
 ************************************************************************/

#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()��
#include<limits.h> // INT_MAX��
#include<stdio.h> // EOF(=^Z��F6),NULL
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h> // floor(),ceil(),abs()
#include<process.h> // exit()
#include<iostream.h> // cout,cin
//#include"ABlist.h"
// �������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
// #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
struct AddressBook *start;
struct AddressBook *last;
Status load(ABList &L);//װ�غ�����
int menu();//�˵���ʾ����
void CreatABList(ABList &L);//����ͨѶ¼
void Increase(ABList &L);//��ͨѶ¼�����ӳ�Ա
Status del(ABList &L);//ɾ��ͨѶ¼�е�һ����Ա
Status Modify(ABList &L);//�޸�ͨѶ¼��ָ����Ա����Ϣ
Status search(ABList &L);//����ͨѶ¼��ָ����ŵ�Ԫ����Ϣ
Status display(ABList &L);//��ʾͨѶ¼�и���Ա����Ϣ
Status save(ABList &L);//�����������Ϣ
void inputs(char *s,int count);//�˺���ר���ڽ��������õ��������
void destroy(ABList &L);
AddressBook creat_e();
void main()
{
 ABList L;
 printf("nnttWelcom to the information management system!nttt Copyright. Huang Wenbo,2010.n");
 InitList_AB(L);
    load(L);
    system("color 18");
 int flag=1;
 while(flag)
 {
  
  switch(menu())
  {
  case 1:CreatABList(L);break;
  case 2:Increase(L);break;
  case 3:del(L);break;
  case 4:Modify(L);break;
  case 5:search(L);break;
  case 6:save(L);break;
  case 7:destroy(L);break;
  case 8:system("cls");break;
  case 9:flag = 0;printf("ttt��ӭ�´�ʹ��! nttCopyright.Huang Wenbo,2010.n");
  }
 }
 
}
Status load(ABList &L)
{
 FILE *fp,*fq;
 int i,j;
 if( ((fq = fopen("amout.txt","rb")) == NULL)||((fp= fopen("info.txt","rb"))== NULL) )
 {
  printf("file read error,maybe you have not creat a file to save the information!n");
  return ERROR;
 }
 fread(&i,sizeof(int),1,fq);
 for (j=0;j<i;j++)
 {
  fread(&L.elem[j],sizeof(struct AddressBook),1,fp); 
  L.length++;
 }
 printf("nfile read succeed!!n");
 fclose(fp);
 return OK;
}
int menu()
{
 int a;
    printf("tt����������������������Ŀ¼����������������n");
    printf("tt��                                      ��n");
    printf("tt��    1. ����ͨѶ¼  2.����    3.ɾ��   ��n");
    printf("tt��                                      ��n");
    printf("tt��    4.�޸�      5.��ѯ       6.����   ��n");
    printf("tt��                                      ��n");
    printf("tt��    7.����      8.����       9.�˳�   ��n");
    printf("tt������������������������������������������n");
 printf("nnttt   ��ѡ�����:");
 scanf("%d",&a);
 getchar();
 printf("n");
    return a;   
 
}
void CreatABList(ABList &L)
{
 char c[2];
 int j = 0;
 if(InitList_AB(L) == 1)
 {
  printf("����ͨѶ¼����ռ�ɹ������������Կ�ʼ�������ݽ���������100���˵���Ϣ��n");
  
  printf("���Ƿ�������ڿ�ʼ������Y/N.n");
  gets(c);
  while((((c[0]=='y')||(c[0]=='Y')))&&(j<100))
  {
   printf("�������%dλͬѧ�ı�ţ�",j+1);
   scanf("%d",&L.elem[j].ID);
   getchar();
   printf("��%dλͬѧ������: ",j+1);
   inputs(L.elem[j].name,10);
   printf("��%dλͬѧ���Ա�: ",j+1);
   inputs(&L.elem[j].ch,1);
   printf("��%dλͬѧ�ĵ绰: ",j+1);
   inputs(L.elem[j].phone,13);
   printf("��%dλͬѧ�ĵ�ַ: ",j+1);
   inputs(L.elem[j].addr,31);
   L.length = j+1;
   j++;
   printf("�Ƿ��������Y/N.n");
   gets(c);
  }
 }
 else{
  printf("�Բ��𣡽���ͨѶ¼����ռ�ʧ�ܡ�n");exit(1);
 } 
}
void Increase(ABList &L)
{ 
 
 ListInsert_AB(L,L.length+1,creat_e());
 printf("���ӳɹ�������n");
}
Status del(ABList &L)
{
 if(display(L) == 0)
  return ERROR;
 printf("���������Ļ��ѡ������׼��ɾ��ͬѧ�ı��:  ");
 int a;
 scanf("%d",&a);
 getchar();
 ListDelete_AB(L,a);
 return OK;
}
Status Modify(ABList &L)
{
 int a;
 if(display(L) == 0)
  return ERROR;
 printf("n������Ҫ�޸�ͬѧ�ı�ţ� n");
 scanf("%d",&a);
 fflush(stdin);
 if (L.length == 0) {
  printf("�Բ��𣬴�ͨѶ¼Ŀǰ��û�н�����Ϣ��û�п�ɾ���Ķ���n");
  return ERROR;
 }
  AddressBook *p, *q;
  int j = 0;
  p = L.elem;
  q = &L.elem[L.length-1];// ��βԪ�ص�λ��
  for (p; p<=q;p++)
   if(p->ID == a)
   {
    printf("������ҵ������ڿ�ʼ�޸Ĵ˱������Ӧͬѧ����Ϣ.n");
   *p = creat_e();
   j = 1;
   break;
   }
  
   if (j == 0)
   {
    printf("�Բ���û�о��д˱�ŵ�Ԫ�أ�n");
    return ERROR;
   }
 printf("�޸ĳɹ���n");
 return OK;
}
Status search(ABList &L)
{
 if(display(L) == 0)
  return ERROR;
 printf("������Ҫ��ѯͬѧ�ľ����ţ��������ѯ����Ԫ�أ������� -1 �Ա��˳���:  ");
 int a;
 scanf("%d",&a);
 fflush(stdin);
 if(a == -1)
  return ERROR;
 if (LocateABook(L,a) == 0)
  printf("n�Բ�������ѡ��ı�Ų��ڴ�ͨѶ¼�С�nn");
 return OK;
}
Status display(ABList &L)
{
 AddressBook *p;
 if (L.length == 0) {
  printf("��ͨѶ¼��û�н��������Ƚ���������nnn");
  return ERROR;
 }
 int i=1;
 printf("��ͨѶ¼��������%dλͬѧ����Ϣ��nn",L.length);
 for(p = L.elem;p<=&L.elem[L.length-1];p++,i++)
 {
  printf("��%dλͬѧ����Ϣ����: n",i);
  printf("t��ţ� %dtt",p->ID);
  printf("������ %sn",p->name);
 }
 return OK; 
}
Status save(ABList &L)
{
 FILE *fp,*fq;
 int i;
 if((fq = fopen("amout.txt","wb"))== NULL)
 {
  printf("file write errorn");
  fclose(fq);
  return ERROR;
 }
 if ((fp = fopen("info.txt","wb")) ==  NULL)
 {
  printf("file write errorn");
  fclose(fp);
  fclose(fq);
  return ERROR;
 }
 for (i=0;i<L.length;i++)
 {
  fwrite(&L.elem[i],sizeof(struct AddressBook),1,fp);
 }
 fwrite(&i,sizeof(int),1,fq);
 printf("����ɹ���n");
 fclose(fp);
 fclose(fq);
 return OK;
}
void inputs(char *s,int count)
{
    char p[200];      
    do
 {
  gets(p);   
  if (strlen(p)>count)    
   printf("n�ַ�̫��������������n");
 }
    while (strlen(p)>count);      
    strcpy(s,p);
}
AddressBook creat_e()
{
 AddressBook e;
 printf("�������ţ�");
 scanf("%d",&e.ID);
 getchar();
 printf("����: ");
 inputs(e.name,11);
 printf("�Ա�: ");
 inputs(&e.ch,2);
 printf("�绰: ");
 inputs(e.phone,14);
 printf("��ַ: ");
 inputs(e.addr,32);
 return e;
}
void destroy(ABList &L)
{
 free(L.elem);
 save(L);
 printf("���ٳɹ�������n");
 L.length = 0;
}
 
 
////ABlist.h
 
 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 #include<stdio.h> // EOF(=^Z��F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream.h> // cout,cin
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 #define LIST_INIT_SIZE 100  //���Ա�洢�ռ�ĳ�ʼ������
 #define LISTINCREMENT  10   //���Ա�洢�ռ�ķ�������
struct AddressBook
{
  int ID;        //���
        char name[10];  //����
     char ch;    //�Ա�
  char phone[13];  //�绰
  char addr[31];  //��ַ
};
typedef struct
{
   AddressBook *elem;
   int length;
   int listsize;
}ABList;
Status InitList_AB(ABList &L)
{ 
  // ����һ���յ����Ա�L��
  L.elem = (AddressBook *)malloc(LIST_INIT_SIZE*sizeof(AddressBook));
  if (!L.elem) return ERROR;        // �洢����ʧ��
  L.length = 0;                  // �ձ���Ϊ0
  L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
  return OK;
} // InitList_ABList
Status ListInsert_AB(ABList &L,int i,AddressBook e) { 
  // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
 AddressBook *p;
   if (i < 1 || i > L.length+1) return ERROR;  // iֵ���Ϸ�
   if (L.length >= L.listsize) {   // ��ǰ�洢�ռ���������������
    AddressBook *newbase = (AddressBook *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (AddressBook));
    if (!newbase) return ERROR;   // �洢����ʧ��
    L.elem = newbase;             // �»�ַ
    L.listsize += LISTINCREMENT;  // ���Ӵ洢����
  }
  AddressBook *q = &(L.elem[i-1]);   // qΪ����λ��
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // ����λ�ü�֮���Ԫ������
  *q = e;       // ����e
  ++L.length;   // ����1
  return OK;
} // ListInsert_ABList
Status ListDelete_AB(ABList &L, int i) {  // iΪ���
 if (L.length == 0) {
  printf("�Բ��𣬴�ͨѶ¼Ŀǰ��û�н�����Ϣ��û�п�ɾ���Ķ���n");
  return ERROR;
 }
  AddressBook *p, *q;
  int j = 0;
  p = L.elem;
  q = &L.elem[L.length-1];// ��βԪ�ص�λ��
  for (p; p<=q;p++)
   if(p->ID == i)
   {
    for (p++;p<=q;p++) {
     *(p-1) = *p;// ��ɾ��Ԫ��֮���Ԫ������
    }
    --L.length; // ����1
   printf("ɾ���ɹ�����n");
   j = 1;
   break;
   }
  
   if (j == 0) { printf("�Բ���û�о��д˱�ŵ�Ԫ�أ�n");
   }
      
  return OK;
} // ListDelete_ABList
Status LocateABook(ABList &L, int a)
{ 
  AddressBook *p;
 printf("n");
   p = L.elem;
   int f = 0;//״̬�ж�������ʱʹ�ã�
  for (int i=1;i<=L.length;i++)
  {
    if (p->ID== a)
    {
  printf("������ҵ����˱�ŵĸ�����Ϣ���£� n");
  printf("t������ %sn",p->name);
  printf("t��ţ� %dn",p->ID);
  printf("t�Ա� %cn",p->ch);
  printf("t��ַ�� %sn",p->addr);
  printf("t�绰���룺 %sn",p->phone);
  f = 1;
  break;
    }
    p++;
  }
  
  if( f == 0) {return ERROR;} 
 else return OK;
} // LocateElem_Sq

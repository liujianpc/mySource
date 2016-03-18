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
#include<malloc.h> // malloc()等
#include<limits.h> // INT_MAX等
#include<stdio.h> // EOF(=^Z或F6),NULL
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h> // floor(),ceil(),abs()
#include<process.h> // exit()
#include<iostream.h> // cout,cin
//#include"ABlist.h"
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
// #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
struct AddressBook *start;
struct AddressBook *last;
Status load(ABList &L);//装载函数，
int menu();//菜单显示函数
void CreatABList(ABList &L);//创建通讯录
void Increase(ABList &L);//在通讯录中增加成员
Status del(ABList &L);//删除通讯录中的一个成员
Status Modify(ABList &L);//修改通讯录中指定成员的信息
Status search(ABList &L);//查找通讯录中指定编号的元素信息
Status display(ABList &L);//显示通讯录中各成员的信息
Status save(ABList &L);//保存输入的信息
void inputs(char *s,int count);//此函数专用于建立函数用的输入操作
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
  case 9:flag = 0;printf("ttt欢迎下次使用! nttCopyright.Huang Wenbo,2010.n");
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
    printf("tt┏━━━━━━━━操作目录━━━━━━━┑n");
    printf("tt┃                                      ┃n");
    printf("tt┃    1. 建立通讯录  2.增加    3.删除   ┃n");
    printf("tt┃                                      ┃n");
    printf("tt┃    4.修改      5.查询       6.保存   ┃n");
    printf("tt┃                                      ┃n");
    printf("tt┃    7.销毁      8.清屏       9.退出   ┃n");
    printf("tt┗━━━━━━━━━━━━━━━━━━━┛n");
 printf("nnttt   请选择操作:");
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
  printf("建立通讯录分配空间成功，现在您可以开始输入数据建立不超过100个人的信息！n");
  
  printf("您是否想从现在开始建立？Y/N.n");
  gets(c);
  while((((c[0]=='y')||(c[0]=='Y')))&&(j<100))
  {
   printf("请输入第%d位同学的编号：",j+1);
   scanf("%d",&L.elem[j].ID);
   getchar();
   printf("第%d位同学的姓名: ",j+1);
   inputs(L.elem[j].name,10);
   printf("第%d位同学的性别: ",j+1);
   inputs(&L.elem[j].ch,1);
   printf("第%d位同学的电话: ",j+1);
   inputs(L.elem[j].phone,13);
   printf("第%d位同学的地址: ",j+1);
   inputs(L.elem[j].addr,31);
   L.length = j+1;
   j++;
   printf("是否继续？？Y/N.n");
   gets(c);
  }
 }
 else{
  printf("对不起！建立通讯录分配空间失败。n");exit(1);
 } 
}
void Increase(ABList &L)
{ 
 
 ListInsert_AB(L,L.length+1,creat_e());
 printf("增加成功！！！n");
}
Status del(ABList &L)
{
 if(display(L) == 0)
  return ERROR;
 printf("请从上面屏幕上选择输入准备删除同学的编号:  ");
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
 printf("n请输入要修改同学的编号： n");
 scanf("%d",&a);
 fflush(stdin);
 if (L.length == 0) {
  printf("对不起，此通讯录目前还没有建立信息。没有可删除的对象！n");
  return ERROR;
 }
  AddressBook *p, *q;
  int j = 0;
  p = L.elem;
  q = &L.elem[L.length-1];// 表尾元素的位置
  for (p; p<=q;p++)
   if(p->ID == a)
   {
    printf("编号已找到，现在开始修改此编号所对应同学的信息.n");
   *p = creat_e();
   j = 1;
   break;
   }
  
   if (j == 0)
   {
    printf("对不起，没有具有此编号的元素！n");
    return ERROR;
   }
 printf("修改成功！n");
 return OK;
}
Status search(ABList &L)
{
 if(display(L) == 0)
  return ERROR;
 printf("请输入要查询同学的具体编号（若不想查询具体元素，请输入 -1 以便退出）:  ");
 int a;
 scanf("%d",&a);
 fflush(stdin);
 if(a == -1)
  return ERROR;
 if (LocateABook(L,a) == 0)
  printf("n对不起！您所选择的编号不在此通讯录中。nn");
 return OK;
}
Status display(ABList &L)
{
 AddressBook *p;
 if (L.length == 0) {
  printf("此通讯录还没有建立，请先建立！！！nnn");
  return ERROR;
 }
 int i=1;
 printf("此通讯录共建立了%d位同学的信息！nn",L.length);
 for(p = L.elem;p<=&L.elem[L.length-1];p++,i++)
 {
  printf("第%d位同学的信息如下: n",i);
  printf("t编号： %dtt",p->ID);
  printf("姓名： %sn",p->name);
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
 printf("保存成功！n");
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
   printf("n字符太长、请重新输入n");
 }
    while (strlen(p)>count);      
    strcpy(s,p);
}
AddressBook creat_e()
{
 AddressBook e;
 printf("请输入编号：");
 scanf("%d",&e.ID);
 getchar();
 printf("姓名: ");
 inputs(e.name,11);
 printf("性别: ");
 inputs(&e.ch,2);
 printf("电话: ");
 inputs(e.phone,14);
 printf("地址: ");
 inputs(e.addr,32);
 return e;
}
void destroy(ABList &L)
{
 free(L.elem);
 save(L);
 printf("销毁成功！！！n");
 L.length = 0;
}
 
 
////ABlist.h
 
 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 #include<stdio.h> // EOF(=^Z或F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream.h> // cout,cin
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
 #define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
 #define LISTINCREMENT  10   //线性表存储空间的分配增量
struct AddressBook
{
  int ID;        //编号
        char name[10];  //姓名
     char ch;    //性别
  char phone[13];  //电话
  char addr[31];  //地址
};
typedef struct
{
   AddressBook *elem;
   int length;
   int listsize;
}ABList;
Status InitList_AB(ABList &L)
{ 
  // 构造一个空的线性表L。
  L.elem = (AddressBook *)malloc(LIST_INIT_SIZE*sizeof(AddressBook));
  if (!L.elem) return ERROR;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_ABList
Status ListInsert_AB(ABList &L,int i,AddressBook e) { 
  // 在顺序线性表L的第i个元素之前插入新的元素e，
 AddressBook *p;
   if (i < 1 || i > L.length+1) return ERROR;  // i值不合法
   if (L.length >= L.listsize) {   // 当前存储空间已满，增加容量
    AddressBook *newbase = (AddressBook *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (AddressBook));
    if (!newbase) return ERROR;   // 存储分配失败
    L.elem = newbase;             // 新基址
    L.listsize += LISTINCREMENT;  // 增加存储容量
  }
  AddressBook *q = &(L.elem[i-1]);   // q为插入位置
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // 插入位置及之后的元素右移
  *q = e;       // 插入e
  ++L.length;   // 表长增1
  return OK;
} // ListInsert_ABList
Status ListDelete_AB(ABList &L, int i) {  // i为编号
 if (L.length == 0) {
  printf("对不起，此通讯录目前还没有建立信息。没有可删除的对象！n");
  return ERROR;
 }
  AddressBook *p, *q;
  int j = 0;
  p = L.elem;
  q = &L.elem[L.length-1];// 表尾元素的位置
  for (p; p<=q;p++)
   if(p->ID == i)
   {
    for (p++;p<=q;p++) {
     *(p-1) = *p;// 被删除元素之后的元素左移
    }
    --L.length; // 表长减1
   printf("删除成功！！n");
   j = 1;
   break;
   }
  
   if (j == 0) { printf("对不起，没有具有此编号的元素！n");
   }
      
  return OK;
} // ListDelete_ABList
Status LocateABook(ABList &L, int a)
{ 
  AddressBook *p;
 printf("n");
   p = L.elem;
   int f = 0;//状态判断量（临时使用）
  for (int i=1;i<=L.length;i++)
  {
    if (p->ID== a)
    {
  printf("编号已找到，此编号的个人信息如下： n");
  printf("t姓名： %sn",p->name);
  printf("t编号： %dn",p->ID);
  printf("t性别： %cn",p->ch);
  printf("t地址： %sn",p->addr);
  printf("t电话号码： %sn",p->phone);
  f = 1;
  break;
    }
    p++;
  }
  
  if( f == 0) {return ERROR;} 
 else return OK;
} // LocateElem_Sq

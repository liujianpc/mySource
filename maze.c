/*
 * =====================================================================================
 *       Filename:  maze.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/12/26 11:07:19
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: maze.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/12/26 11:07:19
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef enum{RIGHT,DOWN,LEFT,UP}Direction;
typedef enum{YES,NO}MarkTag;
typedef struct position   //�Թ���λ�õ�����
{  int x;
   int y;
}Position;
typedef struct
{  int order;          //��ǰλ����·���е����
  Position seat;       //��ǰλ�����Թ��е�����
  Direction di;       //�ӵ�ǰλ���ߵ���һλ�õķ���
}SElemType;              //ջԪ�ص�����
typedef struct
{ 
SElemType *elem;
  int top;
}Stack;
char maze[MAX_SIZE][MAX_SIZE]={
 {'1','1','1','1','1','1','1','1','1','1','1'},
 {'1','0','1','0','0','1','1','1','0','0','1'},
 {'1','0','0','0','0','0','1','0','0','1','1'},
 {'1','0','1','1','1','0','0','0','1','1','1'},
 {'1','0','0','0','1','0','1','1','0','1','1'},
 {'1','1','0','0','1','0','1','1','0','0','1'},
 {'1','1','1','0','0','0','0','0','0','0','1'},
 {'1','1','1','1','1','1','1','1','1','1','1'}
 };    //�ö�ά�ַ������ʾ�Թ�
int InitStack(Stack *S)             //����һ����ջ
{
S->elem=(SElemType*)malloc(MAX_SIZE*MAX_SIZE*sizeof(SElemType));
 if(!S->elem)  return -1;
 S->top=0;    return 1;
}  
int Push(Stack *S,SElemType e)     //Ԫ��e��ջ
{   if(S->top>=MAX_SIZE*MAX_SIZE)   return -1;
S->elem[S->top++]=e;
return 1;
} 
int Pop(Stack *S,SElemType *e) //ջ��Ԫ�س�ջ����e����ջ��Ԫ��
{   if(S->top<=0)     return -1;
  *e=S->elem[--S->top];   return 1;
}
 int Empty(Stack S)    //�ж�ջ�Ƿ�Ϊ��
{  if(S.top==0)    return 1;
   else   return 0;
} 
int createMaze(Position *startpos,Position *endpos)
{ Position start,end;
 printf("�������Թ���ڣ�");
 scanf("%d%d",&start.x,&start.y);
printf("�������Թ����ڣ�");
 scanf("%d%d",&end.x,&end.y);
     *startpos=start; *endpos=end;
 return 1;
}  //createMaze
int canPass(Position curpos)
{    if(maze[curpos.x][curpos.y]=='0')   return 1;
     return 0;
}   //canPass
void markPos(Position curpos,MarkTag tag)     //Ϊ�Ѿ�̽������λ�üӱ��
{  switch(tag)
 {  case YES: maze[curpos.x][curpos.y]='.'; break;   //·�����
  case NO:  maze[curpos.x][curpos.y]='x'; break;   //����ͬ���
 }
}  
//���ݵ�ǰ��λ���������һ��Ҫ̽���ķ���dir����һ��Ҫ�ߵ�λ������
Position nextPos(Position curpos,Direction dir)
{    Position nextpos;
switch(dir)
  {  case RIGHT:nextpos.x=curpos.x ;nextpos.y =curpos.y +1; break;
case DOWN :nextpos.x=curpos.x+1 ;nextpos.y =curpos.y; break;
case LEFT :nextpos.x=curpos.x ;nextpos.y =curpos.y -1; break;
case UP :nextpos.x=curpos.x-1 ;nextpos.y =curpos.y;  break;
}
return nextpos;
}
Direction nextDir(Direction dir)
{  switch(dir)
{   case RIGHT: return DOWN;
      case DOWN : return LEFT;
      case LEFT: return UP;
}
}
int Solve(Stack *S,Position start,Position end)
{//���Թ��д��ڴ����start������end��ͨ���������һ�������ջS�У�������1,���Թ��в����ڴ����start������end��ͨ����������0
	Position curpos;
	SElemType e;
	int curstep=1;   //���õĲ���
	if(InitStack(S)==-1)  return 0;
	curpos=start;
	do{
		if(canPass(curpos)){      //��ǰλ�ÿ���ͨ��
			markPos(curpos,YES);   //�����㼣
			e.order=curstep;e.seat=curpos;e.di=RIGHT;
			Push(S,e);             //��ǰλ�ü���·��
			if(curpos.x==end.x&&curpos.y==end.y)   //��ǰλ���ǳ���
				return 1;
			curpos=nextPos(curpos,RIGHT);
			curstep++;
		}
		else{              //��ǰλ�ò���ͨ��
			if(!Empty(*S)){
				if(Pop(S,&e)==-1)   return 0;
				while(e.di==UP&&!Empty(*S)){
					//�ĸ�������̽����û���ҵ�ͨ·Ҳ���ܼ���̽���������
					curpos=e.seat;markPos(curpos,NO);
					if(Pop(S,&e)==-1)  return 0;
				}
				if(e.di!=UP){   //�ĸ�����û����̽��
					e.di=nextDir(e.di);
					Push(S,e);  //����һ������̽��
					curpos=nextPos(e.seat,e.di);
				}
			}
		}
	}while(!Empty(*S));
	return 0;
}
void main()
{  

Position startPos,endPos;
Stack path;
int i,j;
SElemType e;
while(1)
{
	printf("======================================================================\n");
	printf("\n");
	printf("***************************���ݽṹ.ջ.�Թ�����***********************\n");
	printf("\n");
	printf("======================================================================\n");
	if(createMaze(&startPos,&endPos)==-1) return ;
	
	
	Solve(&path,startPos,endPos);
	while(!Empty(path)){    //������ڵ���ڵ�·��
		Pop(&path,&e);
		printf("(%d,%d)",e.seat.x,e.seat.y);
	}
	//����Թ���ͼ��
	printf("\n");
	for(i=0;i<8;i++)
	{for(j=0;j<11;j++)
	printf("%c ",maze[i][j]);
	printf("\n");
}
}
printf("======================================================================\n");
printf("\n");
printf("***************************���ݽṹ.ջ.�Թ�����***********************\n");
printf("\n");
printf("======================================================================\n");
if(createMaze(&startPos,&endPos)==-1) return ;


Solve(&path,startPos,endPos);
while(!Empty(path)){    //������ڵ���ڵ�·��
	Pop(&path,&e);
	printf("(%d,%d)",e.seat.x,e.seat.y);
}
//����Թ���ͼ��
printf("\n");
for(i=0;i<8;i++)
{for(j=0;j<11;j++)
printf("%c ",maze[i][j]);
printf("\n");
}
}


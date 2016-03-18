#include<stdio.h> 
#include<conio.h> 
int migong[10][10]= //设置迷宫，最外围1为墙 里边0为可走路径 1为障碍
{ 
	{1,1,1,1,1,1,1,1,1,1}, 
	{1,0,0,0,0,0,0,1,1,1}, 
	{1,0,1,1,1,1,1,0,0,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,1,1,1}, 
	{1,1,1,1,0,0,1,1,1,1}, 
	{1,0,0,0,0,1,1,1,1,1}, 
	{1,0,1,1,0,0,1,1,1,1}, 
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1} 
}; 
int num; 
struct lj{ int x,y,d;}lj[100];//x,y分别为垂直和水平方向,全局变量
void start() 
{ 
	int top=0,x,y,d,find;//d为设置方向，上下左右。find为设置找不找得到路,top设置为当前所在位置
	lj[top].x=1; //可行位置
	lj[top].y=1; 
	migong[1][1]=-1; //人最初所在位置入口
	find=0;d=-1; 
	while(top>-1)
	{ if(lj[top].x==8&&lj[top].y==8) 
		{ printf("迷宫路径如下：\n"); 
			printf("start->");
			for(x=0;x<=top;x++)
			{ printf("(%d,%d)->",lj[x].x,lj[x].y);//把找到的路径输出
				num++;
				if(num%8==0) 
					printf("\n");
			} 
			printf("->end!\n");
		} 
		while(d<4&&find==0)
		{ d++; 
			switch(d)
			{ 
				case 0:x=lj[top].x-1; y=lj[top].y; break;//方向为上
				case 1:x=lj[top].x; y=lj[top].y+1;break;//方向为右
				case 2:x=lj[top].x+1; y=lj[top].y; break;//方向为下
				case 3:x=lj[top].x; y=lj[top].y-1;//方向为左
			}
					   if(migong[x][y]==0) 
						   find=1; 

		} 
		if(find==1)
		{ //判断是否找得到
			lj[top].d=d; 
			top++; 
			lj[top].x=x;
			lj[top].y=y; 
			d=-1; 
			find=0; //重新调整方向
			migong[x][y]=-1;
		} 
		else{ 
			migong[lj[top].x][lj[top].y]=0; 
			top--;
			d=lj[top].d; //找不到的话退栈
		}
	}
}
int main()
{
	start(); 
	getch();
	return 0;
}

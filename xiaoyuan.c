/*
 * =====================================================================================
 *       Filename:  xiaoyuan.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/12/26 1:26:21
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: xiaoyuan.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/12/26 1:26:21
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define INFINITE 5000000   
#define MAX_POINT 30         
//以顺序存储的方式存储校园主要结点
typedef struct UESTC_Graph{
	char* NODE[MAX_POINT]; //以一维字符串数组代表各个结点
	int arcs[MAX_POINT][MAX_POINT];//二维整型数组存储各个结点间的距离，构建路线模型
	int NODE_NUM,arcnum;//当前接点数和路线数目
}; 
int POINT[30];
//构建UESTC校园地图的函数
void CreateUESTC(UESTC_Graph &G)
{
	int i = 0,j=0;
	G.NODE_NUM = 17;              
	G.arcnum = 10;

	//校园结点的构建
	G.NODE[0] = "科A";          G.NODE[1] = "科B";                 G.NODE[2] = "科C";
	G.NODE[3] = "布雷德西点屋"; G.NODE[4] = "学子餐厅";            G.NODE[5] = "后勤中心";
	G.NODE[6] = "银桦餐厅";     G.NODE[7] = "商业街";              G.NODE[8] = "建行";
	G.NODE[9] = "图书馆";       G.NODE[10] = "大学生活动中心";     G.NODE[11] ="校医院";
	G.NODE[12] = "工程训练中心";G.NODE[13] = "经管楼";             G.NODE[14] = "体育馆";
	G.NODE[15] = "主楼";        G.NODE[16] = "操场";
	//路线构建
	for(i=0;i<G.NODE_NUM;i++)
		for(j=0;j<G.NODE_NUM;j++)
		{
			if(i==j)G.arcs[i][j]=0;else G.arcs[i][j]=INFINITE;
		}
	G.arcs[0][3] = G.arcs[3][0] = G.arcs[0][2] = G.arcs[2][0] = 50 ; 
	G.arcs[2][5] = G.arcs[5][2] = G.arcs[3][5] = G.arcs[5][3] = 150;
	G.arcs[2][8] = G.arcs[8][2] = G.arcs[3][8] = G.arcs[8][3] = 150;
	G.arcs[1][2] = G.arcs[2][1] = G.arcs[1][3] = G.arcs[3][1] = 100;
	G.arcs[1][4] = G.arcs[4][1] = 50;        G.arcs[1][12] = G.arcs[12][1] = 300;
	G.arcs[2][3] = G.arcs[3][2] = 20;        G.arcs[0][4] = G.arcs[4][0] = 90; 
	G.arcs[5][6] = G.arcs[6][5] = 40;        G.arcs[5][10] = G.arcs[10][5] = 50;
	G.arcs[5][16] = G.arcs[16][5] = 100;     G.arcs[6][7] = G.arcs[7][6] = 40;      
	G.arcs[6][8] = G.arcs[8][6] = 50;
	G.arcs[7][8] = G.arcs[8][7] = 25;        G.arcs[7][9] = G.arcs[9][7] = 200;
	G.arcs[7][13] = G.arcs[13][7] = 150;     G.arcs[7][16] = G.arcs[16][7] = 100;
	G.arcs[8][9] = G.arcs[9][8] = 50;       G.arcs[9][11] = G.arcs[11][9] = 50;
	G.arcs[10][12] = G.arcs[12][10] = 300;   G.arcs[12][15] = G.arcs[15][12] = 100;
	G.arcs[13][14] = G.arcs[14][13] = 50;    G.arcs[14][15] = G.arcs[15][14] = 150;

}
//寻找最短路径的函数
void Find_PATH(UESTC_Graph &G,int start,int p[30][30],int d[]){   
	int v,w,i,j,min;int final[MAX_POINT];int k=1;
	for(v=0;v<G.NODE_NUM;++v){
		final[v]=0;
		d[v]=G.arcs[start-1][v];
		for(w=0;w<G.NODE_NUM;++w) p[v][w]=0;
		if(d[v]<INFINITE)
		{p[v][start-1]=1;p[v][v]=1;}
	}
	d[start-1]=0;final[start-1]=1;POINT[0]=start-1;
	for(i=1;i<G.NODE_NUM;++i){
		min=INFINITE;
		for(w=0;w<G.NODE_NUM;++w)
			if(!final[w])
				if(d[w]<min)
				{v=w;min=d[w];}
		final[v]=1;POINT[k]=v;k++;
		for(w=0;w<G.NODE_NUM;++w)
			if(!final[w]&&(min+G.arcs[v][w]<d[w]))
			{
				d[w]=min+G.arcs[v][w];
				for(j=0;j<G.NODE_NUM;j++)
				{p[w][j]=p[v][j];}
				p[w][w]=1;
			}
	}
}

//主函数
int main()
{

	UESTC_Graph G;
	int start,i,end;
	int P[MAX_POINT][MAX_POINT];
	int D[MAX_POINT];
	char *NODE[20];
	int control = 1;
	printf("=====================================================================\n");
	printf("********************UESTC.电子科大清水校区***************************\n"); 
	printf("********************发现成电之美，旅途愉快***************************\n");                  

	printf("选择出发地与目标地\t\t");  
	printf("powered by LiuJian!\n");
	printf("======================================================================\n");
	while(control == 1){  
		printf("(1) 科A            (2) 科B                  (3) 科C\n"); 
		printf("(4) 布雷德西点屋   (5) 学子餐厅             (6) 后勤中心 \n");  
		printf("(7) 银桦餐厅       (8) 商业街               (9) 建行 \n");  
		printf("(10) 图书馆        (11) 大学生活动中心      (12) 校医院\n");  
		printf("(13) 工程训练中心  (14) 经管楼              (15) 体育馆\n");  
		printf("(16) 主楼          (17) 操场\n");

		NODE[0] = "科A";   NODE[1] = "科B";      NODE[2] = "科C";
		NODE[3] = "布雷德西点屋";   NODE[4] = "学子餐厅";      NODE[5] = "后勤中心";
		NODE[6] = "银桦餐厅";   NODE[7] = "商业街";      NODE[8] = "建行";
		NODE[9] = "图书馆";     NODE[10] = "大学生活动中心"; NODE[11] ="校医院";
		NODE[12] = "工程训练中心";    NODE[13] = "经管楼";      NODE[14] = "体育馆";
		NODE[15] = "主楼";    NODE[16] = "操场";
		CreateUESTC(G);
		printf("分别输入起点和终点代号以空格分开\n");  
		scanf("%d %d",&start,&end);
		Find_PATH(G,start,P,D);
		printf("最短路径: ");
		for(i=0;i<G.NODE_NUM;i++)
		{   if(P[end-1][POINT[i]]==1)printf("%s-->",NODE[POINT[i]]);
		}
		printf("\n路径长度:%d",D[end-1]);
		printf("\n继续请按1，退出请按0；\n");
		scanf("%d",&control);


	}
	return 0;
}





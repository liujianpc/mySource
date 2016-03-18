#include <stdio.h>
#include <stdlib.h>
#define INFINITY 5000000   
#define MAX_V 30         
typedef struct MGraph{
	char* NODE[MAX_V];       
	int arcs[MAX_V][MAX_V];
	int vexnum,arcnum;
}; 
int have[30];
int CreateUDN(MGraph &G)
{
	int i = 0,j=0;
	G.vexnum = 17;              G.arcnum = 10;
	G.NODE[0] = "B1";           G.NODE[1] = "科B";                 G.NODE[2] = "科C";
	G.NODE[3] = "布雷德西点屋";           G.NODE[4] = "学子餐厅";                 G.NODE[5] = "后勤中心";
	G.NODE[6] = "银桦餐厅";           G.NODE[7] = "商业街";                 G.NODE[8] = "食堂";
	G.NODE[9] = "图书馆";       G.NODE[10] = "大学生活动中心";    G.NODE[11] ="校医院";
	G.NODE[12] = "工程训练中心";         G.NODE[13] = "经管楼";               G.NODE[14] = "体育馆";
	G.NODE[15] = "主楼";         G.NODE[16] = "操场";

	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++){if(i==j)G.arcs[i][j]=0;else G.arcs[i][j]=INFINITY;}
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


	return 1;
}
void ShortPath(MGraph &G,int v0,int p[30][30],int d[]){   
	int v,w,i,j,min;int final[MAX_V];int k=1;
	for(v=0;v<G.vexnum;++v){
		final[v]=0;
		d[v]=G.arcs[v0-1][v];
		for(w=0;w<G.vexnum;++w) p[v][w]=0;
		if(d[v]<INFINITY)
		{p[v][v0-1]=1;p[v][v]=1;}
	}
	d[v0-1]=0;final[v0-1]=1;have[0]=v0-1;
	for(i=1;i<G.vexnum;++i){
		min=INFINITY;
		for(w=0;w<G.vexnum;++w)
			if(!final[w])
				if(d[w]<min)
				{v=w;min=d[w];}
		final[v]=1;have[k]=v;k++;
		for(w=0;w<G.vexnum;++w)
			if(!final[w]&&(min+G.arcs[v][w]<d[w]))
			{
				d[w]=min+G.arcs[v][w];
				for(j=0;j<G.vexnum;j++)
				{p[w][j]=p[v][j];}
				p[w][w]=1;
			}
	}
}
int main()
{

	MGraph G;int v0,i,end;int P[MAX_V][MAX_V];int D[MAX_V];char *NODE[20];int ctr;
	printf("==================================================================================\n");
	printf("********************UESTC.电子科大清水校区***************************\n");                  
	printf("选择出发地与目标地\n");  
	printf("===================================================================================\n");  
	printf("(1) 科A            (2) 科B                  (3) 科C\n"); 
	printf("(4) 布雷德西点屋   (5) 学子餐厅             (6) 后勤中心 \n");  
	printf("(7) 银桦餐厅       (8) 商业街               (9) 食堂 \n");  
	printf("(10) 图书馆        (11) 大学生活动中心      (12) 校医院\n");  
	printf("(13) 工程训练中心  (14) 经管楼              (15) 体育馆\n");  
	printf("(16) 主楼          (17) 操场\n");

	NODE[0] = "B1";   NODE[1] = "科B";      NODE[2] = "科C";
	NODE[3] = "布雷德西点屋";   NODE[4] = "学子餐厅";      NODE[5] = "后勤中心";
	NODE[6] = "银桦餐厅";   NODE[7] = "商业街";      NODE[8] = "食堂";
	NODE[9] = "图书馆";     NODE[10] = "大学生活动中心"; NODE[11] ="校医院";
	NODE[12] = "工程训练中心";    NODE[13] = "经管楼";      NODE[14] = "体育馆";
	NODE[15] = "主楼";    NODE[16] = "操场";
	CreateUDN(G);
	printf("分别输入起点和终点代号以空格分开\n");  
	scanf("%d",&v0);
	ShortPath(G,v0,P,D);
	printf("最短路径: ");
	for(i=0;i<G.vexnum;i++)
	{   if(P[end-1][have[i]]==1)printf("%s-->",NODE[have[i]]);
	}
	printf("\n路径长度:%d",D[end-1]);
	printf("继续请按1，结束请按0；\n");
	scanf("%d",&ctr);

	return 0;
}


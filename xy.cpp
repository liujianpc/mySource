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
	G.NODE[0] = "B1";           G.NODE[1] = "��B";                 G.NODE[2] = "��C";
	G.NODE[3] = "���׵�������";           G.NODE[4] = "ѧ�Ӳ���";                 G.NODE[5] = "��������";
	G.NODE[6] = "�������";           G.NODE[7] = "��ҵ��";                 G.NODE[8] = "ʳ��";
	G.NODE[9] = "ͼ���";       G.NODE[10] = "��ѧ�������";    G.NODE[11] ="УҽԺ";
	G.NODE[12] = "����ѵ������";         G.NODE[13] = "����¥";               G.NODE[14] = "������";
	G.NODE[15] = "��¥";         G.NODE[16] = "�ٳ�";

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
	printf("********************UESTC.���ӿƴ���ˮУ��***************************\n");                  
	printf("ѡ���������Ŀ���\n");  
	printf("===================================================================================\n");  
	printf("(1) ��A            (2) ��B                  (3) ��C\n"); 
	printf("(4) ���׵�������   (5) ѧ�Ӳ���             (6) �������� \n");  
	printf("(7) �������       (8) ��ҵ��               (9) ʳ�� \n");  
	printf("(10) ͼ���        (11) ��ѧ�������      (12) УҽԺ\n");  
	printf("(13) ����ѵ������  (14) ����¥              (15) ������\n");  
	printf("(16) ��¥          (17) �ٳ�\n");

	NODE[0] = "B1";   NODE[1] = "��B";      NODE[2] = "��C";
	NODE[3] = "���׵�������";   NODE[4] = "ѧ�Ӳ���";      NODE[5] = "��������";
	NODE[6] = "�������";   NODE[7] = "��ҵ��";      NODE[8] = "ʳ��";
	NODE[9] = "ͼ���";     NODE[10] = "��ѧ�������"; NODE[11] ="УҽԺ";
	NODE[12] = "����ѵ������";    NODE[13] = "����¥";      NODE[14] = "������";
	NODE[15] = "��¥";    NODE[16] = "�ٳ�";
	CreateUDN(G);
	printf("�ֱ����������յ�����Կո�ֿ�\n");  
	scanf("%d",&v0);
	ShortPath(G,v0,P,D);
	printf("���·��: ");
	for(i=0;i<G.vexnum;i++)
	{   if(P[end-1][have[i]]==1)printf("%s-->",NODE[have[i]]);
	}
	printf("\n·������:%d",D[end-1]);
	printf("�����밴1�������밴0��\n");
	scanf("%d",&ctr);

	return 0;
}


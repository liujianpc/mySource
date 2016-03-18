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
//��˳��洢�ķ�ʽ�洢У԰��Ҫ���
typedef struct UESTC_Graph{
	char* NODE[MAX_POINT]; //��һά�ַ����������������
	int arcs[MAX_POINT][MAX_POINT];//��ά��������洢��������ľ��룬����·��ģ��
	int NODE_NUM,arcnum;//��ǰ�ӵ�����·����Ŀ
}; 
int POINT[30];
//����UESTCУ԰��ͼ�ĺ���
void CreateUESTC(UESTC_Graph &G)
{
	int i = 0,j=0;
	G.NODE_NUM = 17;              
	G.arcnum = 10;

	//У԰���Ĺ���
	G.NODE[0] = "��A";          G.NODE[1] = "��B";                 G.NODE[2] = "��C";
	G.NODE[3] = "���׵�������"; G.NODE[4] = "ѧ�Ӳ���";            G.NODE[5] = "��������";
	G.NODE[6] = "�������";     G.NODE[7] = "��ҵ��";              G.NODE[8] = "����";
	G.NODE[9] = "ͼ���";       G.NODE[10] = "��ѧ�������";     G.NODE[11] ="УҽԺ";
	G.NODE[12] = "����ѵ������";G.NODE[13] = "����¥";             G.NODE[14] = "������";
	G.NODE[15] = "��¥";        G.NODE[16] = "�ٳ�";
	//·�߹���
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
//Ѱ�����·���ĺ���
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

//������
int main()
{

	UESTC_Graph G;
	int start,i,end;
	int P[MAX_POINT][MAX_POINT];
	int D[MAX_POINT];
	char *NODE[20];
	int control = 1;
	printf("=====================================================================\n");
	printf("********************UESTC.���ӿƴ���ˮУ��***************************\n"); 
	printf("********************���ֳɵ�֮������;���***************************\n");                  

	printf("ѡ���������Ŀ���\t\t");  
	printf("powered by LiuJian!\n");
	printf("======================================================================\n");
	while(control == 1){  
		printf("(1) ��A            (2) ��B                  (3) ��C\n"); 
		printf("(4) ���׵�������   (5) ѧ�Ӳ���             (6) �������� \n");  
		printf("(7) �������       (8) ��ҵ��               (9) ���� \n");  
		printf("(10) ͼ���        (11) ��ѧ�������      (12) УҽԺ\n");  
		printf("(13) ����ѵ������  (14) ����¥              (15) ������\n");  
		printf("(16) ��¥          (17) �ٳ�\n");

		NODE[0] = "��A";   NODE[1] = "��B";      NODE[2] = "��C";
		NODE[3] = "���׵�������";   NODE[4] = "ѧ�Ӳ���";      NODE[5] = "��������";
		NODE[6] = "�������";   NODE[7] = "��ҵ��";      NODE[8] = "����";
		NODE[9] = "ͼ���";     NODE[10] = "��ѧ�������"; NODE[11] ="УҽԺ";
		NODE[12] = "����ѵ������";    NODE[13] = "����¥";      NODE[14] = "������";
		NODE[15] = "��¥";    NODE[16] = "�ٳ�";
		CreateUESTC(G);
		printf("�ֱ����������յ�����Կո�ֿ�\n");  
		scanf("%d %d",&start,&end);
		Find_PATH(G,start,P,D);
		printf("���·��: ");
		for(i=0;i<G.NODE_NUM;i++)
		{   if(P[end-1][POINT[i]]==1)printf("%s-->",NODE[POINT[i]]);
		}
		printf("\n·������:%d",D[end-1]);
		printf("\n�����밴1���˳��밴0��\n");
		scanf("%d",&control);


	}
	return 0;
}





#include<stdio.h> 
#include<conio.h> 
int migong[10][10]= //�����Թ�������Χ1Ϊǽ ���0Ϊ����·�� 1Ϊ�ϰ�
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
struct lj{ int x,y,d;}lj[100];//x,y�ֱ�Ϊ��ֱ��ˮƽ����,ȫ�ֱ���
void start() 
{ 
	int top=0,x,y,d,find;//dΪ���÷����������ҡ�findΪ�����Ҳ��ҵõ�·,top����Ϊ��ǰ����λ��
	lj[top].x=1; //����λ��
	lj[top].y=1; 
	migong[1][1]=-1; //���������λ�����
	find=0;d=-1; 
	while(top>-1)
	{ if(lj[top].x==8&&lj[top].y==8) 
		{ printf("�Թ�·�����£�\n"); 
			printf("start->");
			for(x=0;x<=top;x++)
			{ printf("(%d,%d)->",lj[x].x,lj[x].y);//���ҵ���·�����
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
				case 0:x=lj[top].x-1; y=lj[top].y; break;//����Ϊ��
				case 1:x=lj[top].x; y=lj[top].y+1;break;//����Ϊ��
				case 2:x=lj[top].x+1; y=lj[top].y; break;//����Ϊ��
				case 3:x=lj[top].x; y=lj[top].y-1;//����Ϊ��
			}
					   if(migong[x][y]==0) 
						   find=1; 

		} 
		if(find==1)
		{ //�ж��Ƿ��ҵõ�
			lj[top].d=d; 
			top++; 
			lj[top].x=x;
			lj[top].y=y; 
			d=-1; 
			find=0; //���µ�������
			migong[x][y]=-1;
		} 
		else{ 
			migong[lj[top].x][lj[top].y]=0; 
			top--;
			d=lj[top].d; //�Ҳ����Ļ���ջ
		}
	}
}
int main()
{
	start(); 
	getch();
	return 0;
}

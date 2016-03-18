/*
 * =====================================================================================
 *       Filename:  huffman.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/12/25 20:33:25
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
  > File Name: huffman.c
  >    Author: liujianpc
  >     Email: zhouhu8899@163.com 
  >   Created: 2014/12/25 20:33:25
 ************************************************************************/
#include<stdio.h>     /*I/O����*/
#include<stdlib.h> 
#include<string.h>
#include<conio.h>    /*�����⺯������*/
int num;/*��¼�����*/
int codenum=0;/*�Ѿ���õı������*/
char filename[20]=""; /*�洢�ļ���*/
typedef struct        /*���������洢�ṹ*/
{
	char ch;             /*����ַ�*/
	int w;              /*���Ȩֵ*/
	int lchild,rchild; /*���Һ��ӵ������±�*/
}HuffmNode,*HuffmTree;
HuffmTree ht;/*����һ��ָ������㵽ָ��*/
typedef struct
{
	char ch;     /*Ҷ�ӽ���ַ�*/
	char codestr[20]; /*�ַ�����*/
}HuffmCode;
HuffmCode code[27];/*���ڴ�Ŷ�Ӧ�ַ�������������*/
void InitHuffmArry()
{ /*�����ļ�����Ȩֵ������ֻ����Ҷ�ӽ���HuffmNode����*/
	int j,i,k;
	HuffmNode tmpht;
	FILE *fp; /*����һָ����ļ���ָ��*/
	char ch;/*���ڴ洢һ����ĸ*/
	char location[30]="D:\\";
	ht=(HuffmTree)malloc(53*sizeof(HuffmNode));    /*Ϊ�������������ڴ�ռ�*/
	if(ht==NULL) return ;
	for(i=0;i<53;i++) /*��ʼ�����Ե����ݵ�Ԫ��ÿ����Ԫ�Գ�һ����*/
	{
		ht[i].w=0; /*Ȩֵ��ʼ��Ϊ0*/
		ht[i].lchild=ht[i].rchild=-1;   /*������Ϊ��*/
	}
	num=0;
	printf("File name(�ļ��������׺��):");
	scanf("%s",filename);
	strcat(location,filename);
	fp = NULL;
	fp=fopen(location,"r");
	if(!fp) /*����1ʱ�������ļ�*/
	{
		printf("Open Error");
		return;
	}
	while(!feof(fp))/*û����βʱ����0*/
	{
		ch=fgetc(fp);
		if(ch==' '||ch<='z'&&ch>='a'||ch<='Z'&&ch>='A')
		{
			printf("%c",ch);
			if(ch==' ') ch='#';
			for(j=0;j<num;j++)
			{
				if(ht[j].ch==ch)
				{
					break;
				}
			}
			if(j==num) /*�ҵ����ַ�*/
			{
				ht[num].ch=ch; /*�����ַ����벢��Ȩֵ��1*/
				ht[num].w++;
				num++;

			}
			else
			{
				ht[j].w++;    /*�������ַ�Ȩֵ��1*/
			}
		}
	}fclose(fp);
	printf("\n");
	for(i=0;i<num;i++)  /*��Ҷ�ӽ�㰴Ȩֵ������������*/
	{
		k=i;
		for(j=i+1;j<num;j++)
		{
			if(ht[j].w<ht[k].w)/*������淢��Ȩֵ��iС�������±��¼������ѭ����֮���ҵ���С��*/
				k=j;
		}
		if(k!=i) /*���Ȩֵ��С�Ĳ��ǵ�i��Ԫ���򽻻�λ�ã���С�ķŵ�ǰ��*/
		{
			tmpht=ht[i];
			ht[i]=ht[k];
			ht[k]=tmpht;
		}
	}
}

int CreateHuffmman(HuffmTree ht)
{ /*������ht�����ɹ������������ظ��ڵ��±�*/
	int i,k,j,root;
	HuffmNode hfnode;
	codenum=0;
	for(i=0;i<num-1;i++)
	{ /*������num-1�����*/
		k=2*i+1; /*ÿ��ȡ��ǰ��������㣬��Ȩֵ�ض���С*/
		hfnode.w=ht[k].w+ht[k-1].w;
		hfnode.lchild=k-1;
		hfnode.rchild=k;
		for(j=num+i;j>k;j--)  /*���½���������������*/
		{
			if(ht[j].w>hfnode.w)
			{
				ht[j+1]=ht[j];
			}
			else break;
		}
		ht[j]=hfnode;
		root=j;/*һֱ���������ɵĽ�㣬��������ɵĽ��Ϊ�����*/
	}
	return root;
}

void GetHuffmCode(HuffmTree ht,int root,char *codestr)
{ /*ht�ǹ���������root�Ǹ�����±꣬codestr������ʱ���Ҷ�ӽ�����ģ�һ��ʼΪ��*/
	FILE *out;
	int len,i;
	FILE *fp; /*����һָ����ļ���ָ��*/
	char ch;/*���ڴ洢һ����ĸ*/
	char location[30]="C:\\";
	if(ht[root].lchild==-1)
	{/*�����ݹ��յ���Ҷ�ӽ���¼Ҷ�ӽ��Ĺ���������*/
		code[codenum].ch=ht[root].ch;
		strcpy(code[codenum].codestr,codestr);
		codenum++;
	}
	else /*�����յ�������ݹ�*/
	{
		len=strlen(codestr);
		codestr[len]='0';  /*���֧������0*/
		codestr[len+1]=0;  /*�����ӵݹ�֮ǰ������������ĩβ��0,�൱�ڼ��˸���\0����null����ʮ����ֵ��0���Ա��´�ѭ��ʱ����ַ�������ᱻ���ǵ�*/
		GetHuffmCode(ht,ht[root].lchild,codestr); /*����ݹ�*/
		len=strlen(codestr);
		codestr[len-1]='1';/*�ҷ�֧����Ϊ1�����ҵݹ�֮ǰĩβ����0��Ϊ1*/
		GetHuffmCode(ht,ht[root].rchild,codestr); /*���ҵݹ�*/
		len=strlen(codestr);
		codestr[len-1]=0;  /*���Һ��ӵݹ鷵�غ�ɾ��������ĩβ*/
	}
	strcat(location,filename);
	fp = NULL;
	fp=fopen(location,"r");
	if(!fp) /*����1ʱ�������ļ�*/
	{
		printf("Open Error");
		return;
	}
	out=fopen("D:\\code.txt","w+")        ;
	if(!out)
	{
		/*printf("Write Error");  */
		return;
	}
	while(!feof(fp))/*û����βʱ����0*/
	{
		ch=fgetc(fp); /*�ٴ�Դ�ļ������չ�����������ɱ���*/
		if(ch==' '||ch<='z'&&ch>='a'||ch<='Z'&&ch>='A')
		{  if(ch==' ') ch='#'; /*����ǿո����#�Ŵ���*/
			for(i=0;i<codenum;i++)
			{ /*�ҵ��ַ�����Ӧ������������*/
				if(ch==code[i].ch)
				{ /*�����ù���������������ļ���*/
					fputs(code[i].codestr,out);
				}
			}
		}
	}
	fclose(fp); /*�رմ򿪵������ļ�*/
	fclose(out);
}

void decodeHuffmCode(HuffmTree ht,int root) /*�����������뷭��Ϊ����*/
{
	FILE *fp2; /*����һָ����ļ���ָ��*/
	char ch;/*���ڴ洢һ����ĸ*/
	int curr=root;/*��ǰ��㵽�±�*/
	char filename2[20]="";/*����ļ���*/
	char location[30]="D:\\";
	printf("File name���ļ��������׺����:");
	scanf("%s",filename);
	strcat(location,filename);
	fp2 = NULL;
	fp2=fopen(location,"r");
	if(!fp2) /*����1ʱ�������ļ�*/
	{
		printf("Open Error2");
		return;
	}
	printf("Code:");
	while(!feof(fp2))/*û����βʱ����0*/
	{
		ch=fgetc(fp2);
		if(ch>='0'&&ch<='1')/*��������˳���*/
		{
			printf("%c",ch); /*�����������ʾ*/
		}
	}
	printf("\n");
	rewind(fp2); /*���ļ�ָ��λ�ö�λ�ڿ�ͷ*/
	while(!feof(fp2))/*û����βʱ����0*/
	{
		ch=fgetc(fp2);
		if(ch>='0'&&ch<='1')/*��������˳���*/
		{
			if(ch=='0') /*���Ϊ0��ǰ���������*/
			{
				if(ht[curr].lchild!=-1)
				{
					curr=ht[curr].lchild;/*����������ȥ����*/
				}
				else
				{
					curr=root; /*û���򷵻ظ����*/
				}

			}
			if(ch=='1') /*���Ϊ1��ǰ���������*/
			{
				if(ht[curr].rchild!=-1)
				{
					curr=ht[curr].rchild;/*����������ȥ����*/
				}
				else
				{
					curr=root; /*û���򷵻ظ����*/
				}
			}
			if(ht[curr].lchild==-1&&ht[curr].rchild==-1)/*��ΪҶ�ӽ�����ӡ���*/
			{
				printf("%c",ht[curr].ch=='#'?' ':ht[curr].ch);
				curr=root; /*�ص�������������*/
			}
		}
	}
	fclose(fp2);
	printf("\n");
}

int main()
{ 
	int root;
	int i;
	char codestr[20]="";
	int choose_ID;
	while(1)
	{
		/*��ʾ�˵���ѡ����롢���뻹���˳�*/
		printf("***===============**��**��**==============***\n");
		printf("ѡ��1: ����\n");
		printf("ѡ��2: ����\n");
		printf("ѡ��3: �˳�\n");
		printf("\t\t\t\tpowered by LiuJian\n");
		printf("***===============**��**ӭ**==============***\n");

		scanf("%d",&choose_ID);
		while(choose_ID!=3) /*ֻ��û��ѡ���˳���һֱѭ��*/
		{
			if(choose_ID==1) /*ѡ�����ѡ��*/
			{
				FILE *output;
				char ch;
				InitHuffmArry(); /*��ʼ�����*/
				root=CreateHuffmman(ht); /*��һ�ù�������*/
				GetHuffmCode(ht,root,codestr);/*���ݹ��������������������*/
				printf("Code:");
				output = NULL;
				output=fopen("D:\\CODE.TXT","r");
				if(!output) /*����1ʱ�������ļ�*/
				{
					printf("Open Error3");
					continue;
				}
				while(!feof(output))/*û����βʱ����0*/
				{
					ch=fgetc(output);
					if(ch>='0'&&ch<='1')/*��������˳���*/
					{
						printf("%c",ch); /*�����������ʾ*/
					}
				}
				printf("\n");
				fclose(output);/*�����ļ��ر�*/
			}
			if(choose_ID==2)  /*���ѡ�����룬��������뺯��*/
			{
				decodeHuffmCode(ht,root);
			}
			if(choose_ID==3)  /*���ѡ��3���˳�����*/
			{
				exit(0);
			}
			/*��û���˳��������ӡ�˵���ʾ��ѡ��*/
			printf("***===============**��**��**==============***\n");
			printf("ѡ��1: ����\n");
			printf("ѡ��2: ����\n");
			printf("ѡ��3: �˳�\n");
			printf("\t\t\t\tpowered by LiuJian\n");
			printf("***===============**�ָ���**==============***\n");
			getch();
			scanf("%d",&choose_ID);
		}

		return 0;
	}
}


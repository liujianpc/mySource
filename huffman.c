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
#include<stdio.h>     /*I/O函数*/
#include<stdlib.h> 
#include<string.h>
#include<conio.h>    /*其他库函数声明*/
int num;/*记录结点数*/
int codenum=0;/*已经获得的编码个数*/
char filename[20]=""; /*存储文件名*/
typedef struct        /*哈夫曼结点存储结构*/
{
	char ch;             /*结点字符*/
	int w;              /*结点权值*/
	int lchild,rchild; /*左右孩子的数组下标*/
}HuffmNode,*HuffmTree;
HuffmTree ht;/*声明一个指向树结点到指针*/
typedef struct
{
	char ch;     /*叶子结点字符*/
	char codestr[20]; /*字符编码*/
}HuffmCode;
HuffmCode code[27];/*用于存放对应字符到哈夫曼编码*/
void InitHuffmArry()
{ /*导入文件计算权值，生成只含有叶子结点的HuffmNode数组*/
	int j,i,k;
	HuffmNode tmpht;
	FILE *fp; /*定义一指向打开文件的指针*/
	char ch;/*用于存储一个字母*/
	char location[30]="D:\\";
	ht=(HuffmTree)malloc(53*sizeof(HuffmNode));    /*为哈夫曼数分配内存空间*/
	if(ht==NULL) return ;
	for(i=0;i<53;i++) /*初始化所以的数据单元，每个单元自成一棵树*/
	{
		ht[i].w=0; /*权值初始化为0*/
		ht[i].lchild=ht[i].rchild=-1;   /*左右子为空*/
	}
	num=0;
	printf("File name(文件名须带后缀名):");
	scanf("%s",filename);
	strcat(location,filename);
	fp = NULL;
	fp=fopen(location,"r");
	if(!fp) /*返回1时即存在文件*/
	{
		printf("Open Error");
		return;
	}
	while(!feof(fp))/*没到结尾时返回0*/
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
			if(j==num) /*找到新字符*/
			{
				ht[num].ch=ch; /*将新字符存入并将权值加1*/
				ht[num].w++;
				num++;

			}
			else
			{
				ht[j].w++;    /*将已有字符权值加1*/
			}
		}
	}fclose(fp);
	printf("\n");
	for(i=0;i<num;i++)  /*对叶子结点按权值进行升序排序*/
	{
		k=i;
		for(j=i+1;j<num;j++)
		{
			if(ht[j].w<ht[k].w)/*如果后面发现权值比i小的则将其下标记录下来，循环完之后找到最小的*/
				k=j;
		}
		if(k!=i) /*如果权值最小的不是第i个元素则交换位置，将小的放到前面*/
		{
			tmpht=ht[i];
			ht[i]=ht[k];
			ht[k]=tmpht;
		}
	}
}

int CreateHuffmman(HuffmTree ht)
{ /*在数组ht中生成哈夫曼数，返回根节点下标*/
	int i,k,j,root;
	HuffmNode hfnode;
	codenum=0;
	for(i=0;i<num-1;i++)
	{ /*需生成num-1个结点*/
		k=2*i+1; /*每次取最前面两个结点，其权值必定最小*/
		hfnode.w=ht[k].w+ht[k-1].w;
		hfnode.lchild=k-1;
		hfnode.rchild=k;
		for(j=num+i;j>k;j--)  /*将新结点插入有序数组中*/
		{
			if(ht[j].w>hfnode.w)
			{
				ht[j+1]=ht[j];
			}
			else break;
		}
		ht[j]=hfnode;
		root=j;/*一直跟随新生成的结点，最后新生成的结点为根结点*/
	}
	return root;
}

void GetHuffmCode(HuffmTree ht,int root,char *codestr)
{ /*ht是哈夫曼树，root是根结点下标，codestr是来暂时存放叶子结点编码的，一开始为空*/
	FILE *out;
	int len,i;
	FILE *fp; /*定义一指向打开文件的指针*/
	char ch;/*用于存储一个字母*/
	char location[30]="C:\\";
	if(ht[root].lchild==-1)
	{/*遇到递归终点是叶子结点记录叶子结点的哈夫曼编码*/
		code[codenum].ch=ht[root].ch;
		strcpy(code[codenum].codestr,codestr);
		codenum++;
	}
	else /*不是终点则继续递归*/
	{
		len=strlen(codestr);
		codestr[len]='0';  /*左分支编码是0*/
		codestr[len+1]=0;  /*向左孩子递归之前调整编码序列末尾加0,相当于加了个‘\0’（null）其十进制值是0，以便下次循环时添加字符，否则会被覆盖掉*/
		GetHuffmCode(ht,ht[root].lchild,codestr); /*向左递归*/
		len=strlen(codestr);
		codestr[len-1]='1';/*右分支编码为1，想右递归之前末尾编码0改为1*/
		GetHuffmCode(ht,ht[root].rchild,codestr); /*向右递归*/
		len=strlen(codestr);
		codestr[len-1]=0;  /*左右孩子递归返回后，删除编码标记末尾*/
	}
	strcat(location,filename);
	fp = NULL;
	fp=fopen(location,"r");
	if(!fp) /*返回1时即存在文件*/
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
	while(!feof(fp))/*没到结尾时返回0*/
	{
		ch=fgetc(fp); /*再打开源文件，对照哈夫曼编码译成编码*/
		if(ch==' '||ch<='z'&&ch>='a'||ch<='Z'&&ch>='A')
		{  if(ch==' ') ch='#'; /*如果是空格就用#号代替*/
			for(i=0;i<codenum;i++)
			{ /*找到字符所对应到哈夫曼编码*/
				if(ch==code[i].ch)
				{ /*将所得哈夫曼编码输出到文件中*/
					fputs(code[i].codestr,out);
				}
			}
		}
	}
	fclose(fp); /*关闭打开到两个文件*/
	fclose(out);
}

void decodeHuffmCode(HuffmTree ht,int root) /*将哈夫曼编码翻译为明文*/
{
	FILE *fp2; /*定义一指向打开文件的指针*/
	char ch;/*用于存储一个字母*/
	int curr=root;/*当前结点到下标*/
	char filename2[20]="";/*获得文件名*/
	char location[30]="D:\\";
	printf("File name（文件名须带后缀名）:");
	scanf("%s",filename);
	strcat(location,filename);
	fp2 = NULL;
	fp2=fopen(location,"r");
	if(!fp2) /*返回1时即存在文件*/
	{
		printf("Open Error2");
		return;
	}
	printf("Code:");
	while(!feof(fp2))/*没到结尾时返回0*/
	{
		ch=fgetc(fp2);
		if(ch>='0'&&ch<='1')/*将编码过滤出来*/
		{
			printf("%c",ch); /*将密文输出显示*/
		}
	}
	printf("\n");
	rewind(fp2); /*将文件指针位置定位在开头*/
	while(!feof(fp2))/*没到结尾时返回0*/
	{
		ch=fgetc(fp2);
		if(ch>='0'&&ch<='1')/*将编码过滤出来*/
		{
			if(ch=='0') /*如果为0则当前结点向左走*/
			{
				if(ht[curr].lchild!=-1)
				{
					curr=ht[curr].lchild;/*若有左子则去左子*/
				}
				else
				{
					curr=root; /*没有则返回根结点*/
				}

			}
			if(ch=='1') /*如果为1则当前结点向右走*/
			{
				if(ht[curr].rchild!=-1)
				{
					curr=ht[curr].rchild;/*若有右子则去右子*/
				}
				else
				{
					curr=root; /*没有则返回根结点*/
				}
			}
			if(ht[curr].lchild==-1&&ht[curr].rchild==-1)/*若为叶子结点则打印输出*/
			{
				printf("%c",ht[curr].ch=='#'?' ':ht[curr].ch);
				curr=root; /*回到根结点继续索引*/
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
		/*显示菜单可选择编码、译码还是退出*/
		printf("***===============**菜**单**==============***\n");
		printf("选项1: 编码\n");
		printf("选项2: 解码\n");
		printf("选项3: 退出\n");
		printf("\t\t\t\tpowered by LiuJian\n");
		printf("***===============**欢**迎**==============***\n");

		scanf("%d",&choose_ID);
		while(choose_ID!=3) /*只有没有选择退出就一直循环*/
		{
			if(choose_ID==1) /*选择编码选项*/
			{
				FILE *output;
				char ch;
				InitHuffmArry(); /*初始化结点*/
				root=CreateHuffmman(ht); /*造一棵哈夫曼树*/
				GetHuffmCode(ht,root,codestr);/*根据哈夫曼树将明文译成密码*/
				printf("Code:");
				output = NULL;
				output=fopen("D:\\CODE.TXT","r");
				if(!output) /*返回1时即存在文件*/
				{
					printf("Open Error3");
					continue;
				}
				while(!feof(output))/*没到结尾时返回0*/
				{
					ch=fgetc(output);
					if(ch>='0'&&ch<='1')/*将编码过滤出来*/
					{
						printf("%c",ch); /*将密文输出显示*/
					}
				}
				printf("\n");
				fclose(output);/*将打开文件关闭*/
			}
			if(choose_ID==2)  /*如果选择译码，则调用译码函数*/
			{
				decodeHuffmCode(ht,root);
			}
			if(choose_ID==3)  /*如果选择3则退出程序*/
			{
				exit(0);
			}
			/*若没有退出则继续打印菜单提示供选择*/
			printf("***===============**菜**单**==============***\n");
			printf("选项1: 编码\n");
			printf("选项2: 解码\n");
			printf("选项3: 退出\n");
			printf("\t\t\t\tpowered by LiuJian\n");
			printf("***===============**分割线**==============***\n");
			getch();
			scanf("%d",&choose_ID);
		}

		return 0;
	}
}


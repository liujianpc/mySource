/*
 * =====================================================================================
 *       Filename:  huffuman.c
 *    Description:  All Rights Reserved
 *        Version:  1.0
 *        Created:  2014/12/25 15:26:28
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  liujianpc
 *          Email:  ljlovelife@foxmail.com
 *   Organization:  SCUT&UESTC
 * =====================================================================================
 */
/*************************************************************************
	> File Name: huffuman.c
	>    Author: liujianpc
	>     Email: zhouhu8899@163.com 
	>   Created: 2014/12/25 15:26:28
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAXNUM 32762
typedef struct HTnode{
	int weight;
	int value;
	int parent;
	int lchild;
	int rchild;
};

typedef struct HTcode{
	char *hfm_code;
	char value;
};

//选择最小权重的两个树
void select(struct HTnode *ht,int n,int *s1,int *s2)    
{
    /*ht,为树所在数组的头指针,n为允许查找的最大序号,s1,s2,返回最小的两个序号*/
    int p1=MAXNUM; 
    int p2=MAXNUM;         /*p1, p2用来记录最小的两个权, 要求p1<p2*/
    int pn1=0; 
    int pn2=0;        /*pn1, pn2 用来记录这两个权的序号*/
    int i;
    for(i=1;i<=n;i++)
    {
        if(ht[i].weight<p1 && ht[i].parent==0)    //ht[i].parent=0的作用是去掉已经选过的节点
        {
            pn2=pn1;
            p2=p1;
            pn1=i;
            p1=ht[i].weight;
        }
        else if(ht[i].weight<p2 && ht[i].parent==0)
        {
            pn2=i;
            p2=ht[i].weight;
        }
    }
    *s1=pn1;    //赋值返回
    *s2=pn2;    
}

//创建霍夫曼树
void Creat_Huffuman(struct HTnode *ht,int *w,char *str,int n)
{
    int m=2*n-1;
    ht=(struct HTnode *)malloc( (m+1)*sizeof(struct HTnode) );        //0号单元不用
    struct HTnode *p;
    int i;
    w=w+1;    //因为w[]的0号单元没有用
    str=str+1;
    for(p=ht+1,i=1; i<=n; i++,p++,w++,str++ )        //1-n号放叶子结点，初始化
    {
        (*p).weight=*w;
        (*p).value=*str;
        (*p).parent=0;
        (*p).lchild=0;
        (*p).rchild=0;
    }
    for(; i<=m; i++,p++)        //非叶子结点初始化
    {
        (*p).weight=0;
        (*p).parent=0;
        (*p).lchild=0;
        (*p).rchild=0;
    }

    int s1,s2;    //在select函数中使用,用来存储最小权的结点的序号
    for(i=n+1;i<=m;++i)        //创建非叶子结点,建哈夫曼树
    {
        //在ht[1]~ht[i-1]的范围内选择两个parent为0且weight最小的结点，其序号分别赋值给s1、s2返回
        select(ht,i-1,&s1,&s2); 
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight + ht[s2].weight;
    }
}//哈夫曼树建立完毕

void outputHuffman(struct HTnode *ht, int m) 
{ 
    int i;
    for(i=1;i<=m;i++)
        printf("%d  ",ht[i].weight);
} 

//从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
void Creat_HuffmanCode(struct HTnode *ht,struct HTcode *hc,int n)
{
    char *cd;
    int start;
    int c;    //c指向当前节点
    int p;    //p指向当前节点的双亲结点
    int i;

    hc=(struct HTcode *)malloc( (n+1)*sizeof(struct HTcode) );    //分配n个编码的头指针
    cd=(char * )malloc(n * sizeof(char ));    //分配求当前编码的工作空间
    cd[n-1]='\0';    //从右向左逐位存放编码，首先存放编码结束符
    for(i=1;i<=n;i++)    //求n个叶子结点对应的哈夫曼编码
    {
        hc[i].value=ht[i].value;
        start=n-1;        //初始化编码起始指针
        for(c=i,p=ht[i].parent; p!=0; c=p,p=ht[p].parent)    //从叶子到根结点求编码
        {
            if(ht[p].lchild == c)
                cd[--start]='0';
            else
                cd[--start]='1';
        }
        hc[i].hfm_code = (char *)malloc(n*sizeof(char));    //为第i个编码分配空间
        strcpy(hc[i].hfm_code,&cd[start]);
    }
    free(cd);
}

//解码
void Decoding_HuffmanTree(struct HTnode *ht,char code[],char result[])
{
    int i , k=0 ;
    int p=0, root;   
    for (root=1 ; ht[root].parent!=0 ; root=ht[root].parent)
        ;  //root是霍夫曼树的根 
    for (i=0 , p=root ; code[i]!='\0'; i++)   
    {   
        if (code[i] == '0')   
            p = ht[p].lchild;   
        else  
            p = ht[p].rchild;   
        if (ht[p].lchild==NULL && ht[p].rchild==NULL)   
        {   
            result[k++] = ht[p].value;   
            p = root;   
      }   
    }   
     result[k] = '\0';   
}
int main()
{
	struct HTnode *HT;
	struct HTcode *HC;
	char *str;
	int i=0;int j = 0; int count = 0;int m = 0;
	printf("请输入字符串：");
	gets(str);
	printf("字符串种类：  ");
	scanf("%d",&n);

	//n = strlen(str);
	Creat_Huffuman(HT,w,str,n);
	 m=2*n-1;
    outputHuffman(HT,m);    /*显示H树*/
    printf("\n");

    Creat_HuffmanCode(HT,HC,n); /*根据H树,求每个字符的编码,放在HC中*/
    for(i=1;i<=n;i++)        /*输出编码*/ 
       printf("%d   %s\n",HC[i].value,HC[i].hfm_code);// 
    //解码
    char *code="01101110101010001110110110011100";
    char *result;
    result=(char *)malloc(100*sizeof(char));
    Decoding_HuffmanTree(HT,code,result);    //result[]存放解码结果
    for(i=0;result[i];i++) 
    printf("%c  ");//
	return 0;
}

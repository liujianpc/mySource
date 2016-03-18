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

//ѡ����СȨ�ص�������
void select(struct HTnode *ht,int n,int *s1,int *s2)    
{
    /*ht,Ϊ�����������ͷָ��,nΪ������ҵ�������,s1,s2,������С���������*/
    int p1=MAXNUM; 
    int p2=MAXNUM;         /*p1, p2������¼��С������Ȩ, Ҫ��p1<p2*/
    int pn1=0; 
    int pn2=0;        /*pn1, pn2 ������¼������Ȩ�����*/
    int i;
    for(i=1;i<=n;i++)
    {
        if(ht[i].weight<p1 && ht[i].parent==0)    //ht[i].parent=0��������ȥ���Ѿ�ѡ���Ľڵ�
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
    *s1=pn1;    //��ֵ����
    *s2=pn2;    
}

//������������
void Creat_Huffuman(struct HTnode *ht,int *w,char *str,int n)
{
    int m=2*n-1;
    ht=(struct HTnode *)malloc( (m+1)*sizeof(struct HTnode) );        //0�ŵ�Ԫ����
    struct HTnode *p;
    int i;
    w=w+1;    //��Ϊw[]��0�ŵ�Ԫû����
    str=str+1;
    for(p=ht+1,i=1; i<=n; i++,p++,w++,str++ )        //1-n�ŷ�Ҷ�ӽ�㣬��ʼ��
    {
        (*p).weight=*w;
        (*p).value=*str;
        (*p).parent=0;
        (*p).lchild=0;
        (*p).rchild=0;
    }
    for(; i<=m; i++,p++)        //��Ҷ�ӽ���ʼ��
    {
        (*p).weight=0;
        (*p).parent=0;
        (*p).lchild=0;
        (*p).rchild=0;
    }

    int s1,s2;    //��select������ʹ��,�����洢��СȨ�Ľ������
    for(i=n+1;i<=m;++i)        //������Ҷ�ӽ��,����������
    {
        //��ht[1]~ht[i-1]�ķ�Χ��ѡ������parentΪ0��weight��С�Ľ�㣬����ŷֱ�ֵ��s1��s2����
        select(ht,i-1,&s1,&s2); 
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight + ht[s2].weight;
    }
}//���������������

void outputHuffman(struct HTnode *ht, int m) 
{ 
    int i;
    for(i=1;i<=m;i++)
        printf("%d  ",ht[i].weight);
} 

//��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
void Creat_HuffmanCode(struct HTnode *ht,struct HTcode *hc,int n)
{
    char *cd;
    int start;
    int c;    //cָ��ǰ�ڵ�
    int p;    //pָ��ǰ�ڵ��˫�׽��
    int i;

    hc=(struct HTcode *)malloc( (n+1)*sizeof(struct HTcode) );    //����n�������ͷָ��
    cd=(char * )malloc(n * sizeof(char ));    //������ǰ����Ĺ����ռ�
    cd[n-1]='\0';    //����������λ��ű��룬���ȴ�ű��������
    for(i=1;i<=n;i++)    //��n��Ҷ�ӽ���Ӧ�Ĺ���������
    {
        hc[i].value=ht[i].value;
        start=n-1;        //��ʼ��������ʼָ��
        for(c=i,p=ht[i].parent; p!=0; c=p,p=ht[p].parent)    //��Ҷ�ӵ�����������
        {
            if(ht[p].lchild == c)
                cd[--start]='0';
            else
                cd[--start]='1';
        }
        hc[i].hfm_code = (char *)malloc(n*sizeof(char));    //Ϊ��i���������ռ�
        strcpy(hc[i].hfm_code,&cd[start]);
    }
    free(cd);
}

//����
void Decoding_HuffmanTree(struct HTnode *ht,char code[],char result[])
{
    int i , k=0 ;
    int p=0, root;   
    for (root=1 ; ht[root].parent!=0 ; root=ht[root].parent)
        ;  //root�ǻ��������ĸ� 
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
	printf("�������ַ�����");
	gets(str);
	printf("�ַ������ࣺ  ");
	scanf("%d",&n);

	//n = strlen(str);
	Creat_Huffuman(HT,w,str,n);
	 m=2*n-1;
    outputHuffman(HT,m);    /*��ʾH��*/
    printf("\n");

    Creat_HuffmanCode(HT,HC,n); /*����H��,��ÿ���ַ��ı���,����HC��*/
    for(i=1;i<=n;i++)        /*�������*/ 
       printf("%d   %s\n",HC[i].value,HC[i].hfm_code);// 
    //����
    char *code="01101110101010001110110110011100";
    char *result;
    result=(char *)malloc(100*sizeof(char));
    Decoding_HuffmanTree(HT,code,result);    //result[]��Ž�����
    for(i=0;result[i];i++) 
    printf("%c  ");//
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXNUM 60

typedef struct
{
	char ch;
	int weight; //权值，这个字符出现的频率
	int parent;
	int left;
	int right;
}HuffNode;

typedef struct
{
	char code[MAXNUM];
	int start;
}HuffCode;

HuffNode ht[MAXNUM*2]; //存放哈夫曼树

HuffCode hcd[MAXNUM];  //存放ht数组中对应的字符的编码

int n;                 //字符的个数

//初始化哈夫曼树ht
void initHt()
{
	FILE * fp;
	char ch;
	int i=0;
	//从文件document/character.txt中读出要编码的字符和权值
	if((fp=fopen("C:\\huffmancode.txt","r"))==NULL){
		printf("can not open the file character.txt");
		exit(0);
	}
	ht[i].left=ht[i].right=ht[i].parent=-1;
	while((ch=fgetc(fp))!=EOF){
		if(ch=='\n'){
			i++;
			ht[i].left=ht[i].right=ht[i].parent=-1;		
		}
		else if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
			ht[i].ch=ch;
		else if(ch>='0'&&ch<='9')
			ht[i].weight=ht[i].weight*10+ch-'0';
	}
	n=i+1;
	if(fclose(fp)){
		printf("can not close the file character.txt");
		exit(0);
	}
}

//构造哈夫曼树,看成有n棵树，选择权值最小的两棵树合并
void createHuffTree()
{

	int i=0,k;
	int minI,minJ;
	int f=0;
	minI=minJ=-1; //minI<minJ
	for(k=n;k<2*n-1;k++){
		//寻找ht中权值最小且无父结点的两个结点
		i=0;
		f=0;
    	while(ht[i].ch!='\0'){
    		if(ht[i].parent==-1){
	    		if(f==0){
            		minI=i;
		          	f++;
				}else if(f==1){
					if(ht[i].weight<ht[minI].weight){
						minJ=minI;
						minI=i;
					}else
			    		minJ=i;
					f++;
				}else{
			    	if(ht[i].weight<ht[minI].weight){
			    		minJ=minI;
			    		minI=i;
					}else if(ht[i].weight<ht[minJ].weight)
						minJ=i;
				}
			}
    		i++;
		}
		//合并两个结点
		ht[k].ch='#';
		ht[k].left=minI;
		ht[k].right=minJ;
		ht[k].weight=ht[minI].weight+ht[minJ].weight;
		ht[k].parent=-1;
		ht[minI].parent=ht[minJ].parent=k;
	}
}

//将一个字符串反转
void reverse(char *str)
{
	int i,j;
	char ch;
	for(i=0,j=strlen(str)-1;i<j;i++,j--){
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
	}
}

//哈夫曼编码，通过父节点从下往上找
void createHuffCode()
{
    int i,j,length;
	FILE * fp;
	for(i=0;i<n;i++){
		length=0;
		j=i;
		//给每个字符进行编码
		while(ht[j].parent!=-1){
    		if(ht[ht[j].parent].left==j){
		    	hcd[i].code[length++]=0+'0';
			}else
		    	hcd[i].code[length++]=1+'0';
			j=ht[j].parent;
		}

		hcd[i].start=hcd[i].code[length-1]-'0';
		hcd[i].code[length]='\0';
		reverse(hcd[i].code);
	}
	//把hcd字符编码写入文件document/code.txt中
	if((fp=fopen("document/code.txt","w"))==NULL){
		printf("can not open the file character.txt");
		exit(0);
	}
    for(i=0;i<n;i++){
		fputc(ht[i].ch,fp);
		fputs("    ",fp);
		fputs(hcd[i].code,fp);
		fputc('\n',fp);
	}
	if(fclose(fp)){
		printf("can not close the file character.txt");
		exit(0);
	}
}

//哈夫曼解码，每次都从根节点开始搜索
int releaseHuffCode(char *str,char* code)
{
	int root=2*n-2;
	int length=0,i=0;
	while(code[i]){
		if(code[i]=='0'+0)
			root=ht[root].left;
		else if(code[i]=='0'+1)
			root=ht[root].right;
		else
			return 0;
		if(ht[root].left==-1 && ht[root].right==-1){
	    	str[length++]=ht[root].ch;
			root=2*n-2;
		}
		i++;
	}
	str[length]='\0';
	if(root==2*n-2)
		return 1;
	return 0;
}

//用户输入编码字符
void encode()
{
	int i=0,j,f=1;
	char str[50];
	char code[500]={'\0'};
	printf("\n请输入要编码的字符串(length<50)\n");
	scanf("%s",str);
	while(str[i]){
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
    		for(j=0;j<n;j++)
	    		if(str[i]==ht[j].ch){
		    		strcat(code,hcd[j].code);
			    	break;
			}
	    	i++;
		}else{
			f=0;
			break;
		}
	}
	if(f)
    	puts(code);
	else
		printf("你输入的字符串错误！\n");
	printf("按任意键后重新选择！\n");
	getch();
}

//用户输入解码字串
void  decode()
{
	char str[50];
	char code[500];
	printf("\n请输入要解码的字串(用0和1表示)\n");
	scanf("%s",code);
	if(releaseHuffCode(str,code))
		puts(str);
	else
		printf("你输入的字串错误！\n");
	
	printf("按任意键后重新选择！\n");
	getch();
}

//主函数
int main()
{
	int choice=1;
    initHt();
    createHuffTree();
    createHuffCode();
    while(choice){
  	   system("cls"); 
       printf("/****************哈夫曼编码与解码*********************/\n");
	   printf(" 在document/character.txt 文件中存放着各个字母的权值\n");
	   printf(" 程序从中读出各个字母的权值构造哈夫曼树并进行编码\n");
	   printf(" 各个字符的编码存在document/code.txt文件中\n");
	   printf("/*****************************************************/\n");
	   printf("\n请输入你的选择：1 ---- 编码  2 ---- 解码  0 ---- 退出\n");
       scanf("%d",&choice);
	   switch(choice){
	   case 1: 
		   encode();
		   break;
	   case 2: 
		   decode();
		   break;
	   case 0: 
		   printf("谢谢使用！\n");
		   break;
	   default:
		   choice=1;
		   printf("你的输入错误！按任意键后重新输入！\n");
		   getch();
		   break;
	   }
   }
   return 0;
}
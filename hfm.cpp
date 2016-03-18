#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXNUM 60

typedef struct
{
	char ch;
	int weight; //Ȩֵ������ַ����ֵ�Ƶ��
	int parent;
	int left;
	int right;
}HuffNode;

typedef struct
{
	char code[MAXNUM];
	int start;
}HuffCode;

HuffNode ht[MAXNUM*2]; //��Ź�������

HuffCode hcd[MAXNUM];  //���ht�����ж�Ӧ���ַ��ı���

int n;                 //�ַ��ĸ���

//��ʼ����������ht
void initHt()
{
	FILE * fp;
	char ch;
	int i=0;
	//���ļ�document/character.txt�ж���Ҫ������ַ���Ȩֵ
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

//�����������,������n������ѡ��Ȩֵ��С���������ϲ�
void createHuffTree()
{

	int i=0,k;
	int minI,minJ;
	int f=0;
	minI=minJ=-1; //minI<minJ
	for(k=n;k<2*n-1;k++){
		//Ѱ��ht��Ȩֵ��С���޸������������
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
		//�ϲ��������
		ht[k].ch='#';
		ht[k].left=minI;
		ht[k].right=minJ;
		ht[k].weight=ht[minI].weight+ht[minJ].weight;
		ht[k].parent=-1;
		ht[minI].parent=ht[minJ].parent=k;
	}
}

//��һ���ַ�����ת
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

//���������룬ͨ�����ڵ����������
void createHuffCode()
{
    int i,j,length;
	FILE * fp;
	for(i=0;i<n;i++){
		length=0;
		j=i;
		//��ÿ���ַ����б���
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
	//��hcd�ַ�����д���ļ�document/code.txt��
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

//���������룬ÿ�ζ��Ӹ��ڵ㿪ʼ����
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

//�û���������ַ�
void encode()
{
	int i=0,j,f=1;
	char str[50];
	char code[500]={'\0'};
	printf("\n������Ҫ������ַ���(length<50)\n");
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
		printf("��������ַ�������\n");
	printf("�������������ѡ��\n");
	getch();
}

//�û���������ִ�
void  decode()
{
	char str[50];
	char code[500];
	printf("\n������Ҫ������ִ�(��0��1��ʾ)\n");
	scanf("%s",code);
	if(releaseHuffCode(str,code))
		puts(str);
	else
		printf("��������ִ�����\n");
	
	printf("�������������ѡ��\n");
	getch();
}

//������
int main()
{
	int choice=1;
    initHt();
    createHuffTree();
    createHuffCode();
    while(choice){
  	   system("cls"); 
       printf("/****************���������������*********************/\n");
	   printf(" ��document/character.txt �ļ��д���Ÿ�����ĸ��Ȩֵ\n");
	   printf(" ������ж���������ĸ��Ȩֵ����������������б���\n");
	   printf(" �����ַ��ı������document/code.txt�ļ���\n");
	   printf("/*****************************************************/\n");
	   printf("\n���������ѡ��1 ---- ����  2 ---- ����  0 ---- �˳�\n");
       scanf("%d",&choice);
	   switch(choice){
	   case 1: 
		   encode();
		   break;
	   case 2: 
		   decode();
		   break;
	   case 0: 
		   printf("ллʹ�ã�\n");
		   break;
	   default:
		   choice=1;
		   printf("���������󣡰���������������룡\n");
		   getch();
		   break;
	   }
   }
   return 0;
}
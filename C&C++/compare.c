#include<stdio.h>
/*����ȽϺ���*/
void strcmp(char*t,char*s)
{
	int i=0;
	while(t[i]==s[i]&&i<=100)i++;
	//if(s[i]=='\0'&&t[i]=='\0')
	if(i==100)
		printf("һ����\n"); 
	else if(t[i]>s[i])printf("ǰ�ߴ�\n");
	else printf("���ߴ�\n");//����
}

int main()
{
	
	char s1[100],s2[100];
	while(1){
	printf("please input two strings:\n");
	gets(s1);
	gets(s2);
	//���ñȽϺ���
	strcmp(s1,s2);
		}
return 0;
}

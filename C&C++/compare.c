#include<stdio.h>
/*定义比较函数*/
void strcmp(char*t,char*s)
{
	int i=0;
	while(t[i]==s[i]&&i<=100)i++;
	//if(s[i]=='\0'&&t[i]=='\0')
	if(i==100)
		printf("一样大\n"); 
	else if(t[i]>s[i])printf("前者大\n");
	else printf("后者大\n");//返回
}

int main()
{
	
	char s1[100],s2[100];
	while(1){
	printf("please input two strings:\n");
	gets(s1);
	gets(s2);
	//调用比较函数
	strcmp(s1,s2);
		}
return 0;
}

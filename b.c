#include <stdio.h>
#include <stdlib.h> //Ϊ��ʹ��exit()
int main()
{
char ch;
FILE* fp;
char fname[50]; //�����ļ���������
printf("�����ļ���");
scanf("%s",fname);
fp=fopen(fname,"w"); //���ļ�
if(fp==NULL) //�жϷ���ֵ
{
printf("����");
exit(1); //��ֹ����
}
//getc()�����ڴ򿪵��ļ��л�ȡ����
while((ch=getc(fp))!=EOF)
putchar(ch);
fclose(fp); //�ر��ļ�
return 0;
}
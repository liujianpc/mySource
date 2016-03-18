#include <stdio.h>
#include <stdlib.h> //为了使用exit()
int main()
{
char ch;
FILE* fp;
char fname[50]; //创建文件名的数组
printf("输入文件名");
scanf("%s",fname);
fp=fopen(fname,"w"); //打开文件
if(fp==NULL) //判断返回值
{
printf("错误");
exit(1); //终止程序
}
//getc()用于在打开的文件中获取文字
while((ch=getc(fp))!=EOF)
putchar(ch);
fclose(fp); //关闭文件
return 0;
}
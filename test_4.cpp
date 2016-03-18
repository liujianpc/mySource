#include <stdio.h>
/*void copy_string(char *from, char *to)
{
char *f = from;
char *t = to;
for(;*f!='\0';f++,t++)
*t=*f;
*t='\0';
}*/
int main()
{
char *a="I am a teacher";
char *b="You are a student.";
printf("\nstring a=%s\nstring b=%s\n",a,b);
//copy_string(a,b);
//printf("\nstring a=%s\nstring b=%s\n",a,b);
//a++;
//a++;
//printf("%c\n",++a);
printf(a);
return 0;
}
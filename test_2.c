#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	float opt;
	char a[10] = {0};
	gets(a);
	opt = atof(a);
	printf("%f",opt);
	return 0;
}
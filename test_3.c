#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Data{
	float data;
	struct Data *next;
}data_;

int main()
{
	char a[10] = {0};
	char opt = getchar();
	switch(opt)
	{
		case '+':
			printf("加法运算");
			break;
		case '-':
			printf("减法运算");
			break;
	}
	    
		struct Data *L = (struct Data *)malloc(sizeof(struct Data));
		struct Data *p = L;
		       p->next = NULL;
		//输入操作数以等号结束
		while(getchar() != '=')
		{

			p->next    = (struct Data *)malloc(sizeof(struct Data));
			gets(a);
			p->data    = atof(a);
			p          = p->next;
			p->next    = NULL;
		}
		printf("%f",L->next->data);
	//	printf("%d",'\n');
	return 0;	
}
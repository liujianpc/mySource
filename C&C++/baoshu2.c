#include <stdio.h>
 int main()
{
  int i,k,m,n,num[50],*p;
  printf("input number of person: n= ");
  scanf("%d",&n);
  p=num;
  for (i=0;i<n;i++)
	  *(p+i)=i+1;          //以1至n为序给每人编号
  i=0;
  k=0;
  m=0;
  
  while (m<n-1)              //当退出人数比n-1少时，执行循环体
  {
	  if (*(p+i)!=0) { k++;}
	if (k==3)
	{
	  *(p+i)=0;
	  k=0;
	  m++;
	}
	i++;
	if(i==n) i=0;         //报数到尾后，i恢复为0
  }

    while (*p==0) p++;
	printf("The last one is N0.%d\n",*p);
	return 0;
}

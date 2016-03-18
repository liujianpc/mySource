#include<stdio.h>
#include<string.h>
int main()
{
	//struct HTnode *HT;
	//struct HTcode *HC;
	char *str;
	int i=0;int j = 0; int count = 0;int m = 0;
	printf("ÇëÊäÈë×Ö·û´®£º");
	gets(str);
	int w[strlen(str)];
	int n = strlen(str);
	for(i = 0;i < strlen(str);i++)
	{
		w[i] = 1;
		j = i+1;
		while(str[i] != '!' && str[j] != '!' && j < strlen(str))
		{
			if(str[i] == str[j])
			{
				count++;
				str[j] = '!';
				w[i]++;
				n--;
			}
			
			//n = n - count;
			j++;
		}
		if(str[i] == '!') w[i] = 0;
		//w[i] = count + 1;
		
	}
	puts(str);
	i = 0;
	j = 0;
	while(i < strlen(str))
	{
		if(str[i] != '!')
		{
			str[j] = str[i];
			w[j] = w[i];
			i++;
			j++;
		}
		else{
			int k = i;
			while(str[k] == '!' && k < strlen(str)) k++;
			str[j] = str[k+1];
			w[j] = w[k+1];
			j++;
			i++;
		}
	}
	
	i = 0;
	j = 0;
	while(w[i] != 0)
	{
		str[j] = str[i];
		w[j] = w[j];
		i++;
		j++;
	}
	n = strlen(str);
	puts(str);
	printf("%d",n);
	return 0;
}
/*	int w[strlen(str)];
	int n = strlen(str);
	for(i = 0;i < strlen(str);i++)
	{
		w[i] = 1;
		j = i+1;
		while(str[i] != '!' && str[j] != '!' && j < strlen(str))
		{
			if(str[i] == str[j])
			{
				count++;
				str[j] = '!';
				w[i]++;
			}
			
			n = n - count;
			j++;
		}
		if(str[i] == '!') w[i] = 0;
		//w[i] = count + 1;
		
	}
//	i = 0;
	while(i < strlen(str))
	{
		if(str[i] != '!')
		{
			str[j] = str[i];
			w[j] = w[i];
			i++;
			j++;
		}
		else{
			int k = i;
			while(str[k] == '!' && k < strlen(str)) k++;
			str[j] = str[k];
			w[j] = w[k];
			j++;
			i++;
		}
	}
	
//	i = 0;
	j = 0;
	while(w[i] != 0)
	{
		str[j] = str[i];
		w[j] = w[j];
		i++;
		j++;
	}*/
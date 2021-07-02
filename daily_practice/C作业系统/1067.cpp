#include <stdio.h>
#include <string.h> 
int main()
{
	char str[5];
	char *p;
	gets(str);
	p=str;
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		str[i]+=4;
	}
	printf("password is %s",str);		
}

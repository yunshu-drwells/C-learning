#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[100];
	char a;
	gets(str);
	scanf("%c",&a);
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		if(str[i]!=a) printf("%c",str[i]);
	 } 	
}

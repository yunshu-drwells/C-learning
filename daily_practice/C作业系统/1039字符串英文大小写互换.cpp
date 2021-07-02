#include <stdio.h>
#include <string.h>
int main()
{
	char b[80];
	int i,n;
	gets(b);
	n=strlen(b);
	for(i=0;i<n;i++){
		if(b[i]>='a'&&b[i]<='z') 
		printf("%c",b[i]-32);
		else if(b[i]>='A'&&b[i]<='Z') 
		printf("%c",b[i]+32);
		else
		printf("%c",b[i]);
	}
	printf("\n");
	return 0;
}

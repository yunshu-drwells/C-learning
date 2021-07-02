#include <stdio.h>
#include <string.h>
int main()
{

	char a[19];
	char b[19];
	int c,d,e,i,j;

	gets(a);
	gets(b);
		
	c=strlen(a);
	d=strlen(b);
	for(i=0;i<c;i++)
		for(j=0;j<d;j++){
		if(a[i]==b[j])
		printf("%c",a[i]);
	}
	return 0;
}

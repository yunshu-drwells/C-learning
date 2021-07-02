#include <stdio.h>
int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	for(int i=0;a[i]!='\0';i++){
		for(int j=0;b[j]!='\0';j++){
			if(a[i]==b[j])
			printf("%c",a[j]);
		}
	}
}

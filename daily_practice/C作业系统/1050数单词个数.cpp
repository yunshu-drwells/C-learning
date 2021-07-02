#include <stdio.h>
#include <string.h>
int main()
{
	int i,j=1;
 	char a[100];
 	gets(a);
 	int n=strlen(a);

 	for(i=0;i<n;i++)
 	{
 		if(a[i]==' '&&a[i+1]!=' ') j++;
	 }
	 printf("%d",j);
}

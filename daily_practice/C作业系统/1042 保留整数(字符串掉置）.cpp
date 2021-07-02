#include <stdio.h>
#include <string.h>
int main()
{
	char a[81],b[81];
	int i,n,c=-1,t=-1;
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			if(i==c+1)
			{
				b[++t]='*';
				b[++t]=a[i];	
			 } 
			else if(i!=c+1) {
				b[++t]='*';
				b[++t]=a[i];		
			} 
			c=i;
			}
		else
		{
			if(i=n-1)
			b[++t]='*';
		 } 	
	}
	b[++t]='\0';
	for(i=0;i<n;i++)
	   printf("%c",b[i]);
	printf("\n");
	return 0;		
}

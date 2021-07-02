#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100],b;
	int i,len;
	gets(str1);
	len=strlen(str1);
	b=1;
	for(i=0;i<len;i++){
		if('0'<=str1[i]&&str1[i]<='9'){
			printf("%c",str1[i]);
			b=1;
		}
		else if(b){
			printf("*");
			b=0;
		}	
	}
	printf("\n");
	return 0;
} 

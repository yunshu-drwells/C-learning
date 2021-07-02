#include<stdio.h>
int main()
{
	char a;
	for(int i=0;i<81;++i){
		a=getchar();
		if(a>='A'&&a<='z')
		putchar(a);
		if(a=='\n')
		break;
	}
	return 0;	
} 

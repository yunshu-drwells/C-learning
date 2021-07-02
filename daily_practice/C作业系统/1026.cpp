#include <stdio.h>
int main (void)
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a>b){	
		printf("max=%d\n",a);
		}
		
		else{	
		printf("max=%d\n",b);
		}
	}
} 

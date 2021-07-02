#include <stdio.h>
int main ()
{
	int a,b,c;
	while(scanf("%d,%d,%d",&a,&b,&c)!=EOF)
	{
			if(a>b && a>c){		
			printf("max=%d\n",a);
		}
	
			else if(b>c && b>a){
			printf("max=%d\n",b);
		}
		
			else(c>a && c>b){
			printf("max=%d\n",c);
		}
	}	
} 



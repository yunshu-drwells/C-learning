#include <stdio.h> 
int main()
{
	int a,b,c;
	while(scanf("%d,%d,%d",&a,&b,&c) != EOF)
	if(a>b) {
		if(a>c)
		    printf("max=%d\n",a);
		else
		    printf("max=%d\n",c);   
	}
	else {
		if(b>c)
		    printf("max=%d\n",b);
		else
		    printf("max=%d\n",c);
	}
	return 0; 
}

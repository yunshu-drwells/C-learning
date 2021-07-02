#include<stdio.h>
int main()
{
	int max,a,b;
	scanf("%d%d",&a,&b);
    max=a;
	if(b>a) max=b;
	printf("max=%d",max);
	return 0;
}

#include <stdio.h>
int main (void)
{
	int a,b,c;
	double d;
	scanf("%d%d%d",&a,&b,&c,&d);
	d=(a+b+c)/3.0;
	printf("%d %d %.2lf",a+b+c,a*b*c,d);
}

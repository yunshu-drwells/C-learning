#include <stdio.h>
int main (void)
{
	int a,b,c,d,e;
	float f;
	scanf("%d%d%d",&a,&b,&c);
	d=a+b+c;
	e=a*b*c;
	f=(a+b+c)/3.0;
	printf("%d %d %.2lf",d,e,f);
}

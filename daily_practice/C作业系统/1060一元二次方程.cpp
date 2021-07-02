#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,m;
	float d,n;
	scanf("%f %f %f",&a,&b,&c);
	if(b*b>4*a*c) d=b*b-4*a*c;
	else d=4*a*c-b*b;	
	m=(-b)/2*a;
	n =sqrt(d) / 2*a;
    printf("%.2f+%.2fi %.2f-%.2fi",m,n,m,n);
    return 0;
}

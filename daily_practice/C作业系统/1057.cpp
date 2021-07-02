#include <stdio.h>
int main()
{
 	int n,a,b,c,d,x;
 	scanf("%d",&n);
 	c=n%10;
 	b=(n%100-c)/10;
 	d=n%100;
 	a=(n-d)/100;
 	x=100*c+10*b+a;
 	printf("%d",x);
} 

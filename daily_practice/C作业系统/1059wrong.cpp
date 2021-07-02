#include <stdio.h>
int main()
{
 	long long n;
 	int c,i=0,d,j,u=1;
 	scanf("%lld",&n);
	while(n!=0)
	{
		n/=10;
		i++;
	}
	printf("%d\n",i);
	d=i;
	int a[d];
	for(j=0;j<d;j++)
	{
		for(d-1;d>0;d--) u*=10;
		c=n/u;
		a[j]=c;
	}
		for(j=0;j<d;j++)
		printf("%d",a[j]) ;


}

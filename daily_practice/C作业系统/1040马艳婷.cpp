#include <stdio.h> 
int  main(void)
{
	int n,i;
	double sum,a,b,e;
	a=2.0;
	b=1.0;
	sum=0.0; 
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		sum += a/b;	
		e=a;
		a+=b;
		b=e;
	}
	printf("%.6f\n",sum);  
}

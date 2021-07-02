#include<stdio.h>
int main()
{
	int n,i,a,b;
	float e=0,d,t1=2,t2=1,c1=1,c2=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	
	d=t1/c1;
	
	e+=d;
	printf("%.7f",e);
	a=t1+t2;
	t2=t1;
	t1=a;
	
	b=c1+c2;
	c2=c1;
	c1=b;	
			
	}
	
} 

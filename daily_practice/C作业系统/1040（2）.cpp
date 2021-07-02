#include<stdio.h>
int main(void)
{
	int n,i,a,b;
	double d=0.0,e=0.0,t1=2.0,t2=1.0,c1=1.0,c2=1.0;//对比1040（1）“.0”有无都可以 
	scanf("%d",&n);
	if(n>=1&&n<=10){
	
	for(i=1;i<=n;i++){
	d=t1/c1;
	e+=d;
	
	a=t1+t2;
	t2=t1;
	t1=a;
	
	b=c1+c2;
	c2=c1;
	c1=b;
}
}
printf("%.6f\n",e);
}

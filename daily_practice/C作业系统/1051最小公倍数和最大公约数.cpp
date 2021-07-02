#include <stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d %d",&a,&b);
	if(a>b) c=a;
	else c=b;
	for(int i=2;i<c;i++)
	{
		if(a%i==0&&b%i==0) d=i;
	}
	e=(a/d)*(b/d)*d; 
	printf("%d %d",e,d);
 	return 0;
}

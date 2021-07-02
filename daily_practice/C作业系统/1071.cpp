#include <stdio.h>
int main()
{
	int n,x=1;
	scanf("%d",&n);
	while(n>=10)
	{
		n/=10;
		x++;
	 }	
	 printf	("%d",x);
}

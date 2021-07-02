#include <stdio.h>
int main(void)
{
	static int a,b,c=0;
	scanf("%d%d",&a,&b);
	c=a+b;
	printf("%d\n",c);
	return 0;
}

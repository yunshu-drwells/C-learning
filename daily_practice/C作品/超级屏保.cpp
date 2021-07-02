#include <stdio.h>
int main(void)
{
	int	n,i,j;
	n=999;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)printf("01010");
		for(j=1;j<=2*i-1;j++)printf("10");
		putchar('\n');
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=i;j++)printf("010");
		for(j=1;j<=2*n-1-2*i;j++)//j<=2*(n-l)-1
			printf("1010");
			printf("\n");
	}
}

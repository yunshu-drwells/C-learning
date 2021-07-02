#include <stdio.h>
int main(void)
{
	int	n,i,j,k,l;
	if(n>=1&&n<=10)
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)printf(" ");
		for(j=1;j<=2*i-1;j++)printf("*");
		putchar('\n');
	}
	for(l=1;l<=n-1;l++){
		for(k=1;k<=l;k++)printf(" ");
		for(k=1;k<=9-2*l;k++)
			printf("*");
			printf("\n");
	}

}

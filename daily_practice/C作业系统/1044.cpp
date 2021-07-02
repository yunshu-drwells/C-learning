#include <stdio.h>
int main()
{
	int n,i,j,k;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)printf(" ");
		for(j=1;j<=2*i-1;j++)	
		{
			printf("*");
			printf("\n");
		}
	}
	for(i=4;i>=1;i--){
		for(k=1;k<=n-i;k++)printf(" ");
		for(k=1;k<=2*i-1;k++){
			printf("*");
			printf("\n");
		}
	}
}

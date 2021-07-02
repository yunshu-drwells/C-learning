#include<stdio.h>
int main(void)
{
	int i,n=3,a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d %d\n",&a[i],&b[i]);
		
	if(scanf("%d %d\n",&a[i],&b[i])==EOF)
	{
		for(i=0;i<=n;i++)
		printf("%d\n",a[i]+b[i]);		
	}	
}


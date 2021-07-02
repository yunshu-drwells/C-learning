#include <stdio.h>
int main()
{
	int n,i,j,k,s=0;
	scanf("%d\n",&n);
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
		scanf("%d",&a[i][j]);	
		}
	 }
	  
		for(i=0;i<n;i++)
			for(k=0;k<=i;k++){
				s+=a[i][k];
		}		
	printf("%d",s);
	return 0;
}

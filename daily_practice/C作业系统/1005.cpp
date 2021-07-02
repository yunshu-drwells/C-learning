#include <stdio.h>
int main()
{
	int m,n,i,j,a[n],sum=0;
	scanf("%d\n",&m);
	for(j=0;j<m;j++){
		scanf("%d ",&n);
		for(i=0;i<n;i++){
			scanf("%d ",&a[i]);
			sum+=a[i];	
		}
		printf("%d\n",sum);	
	}
}

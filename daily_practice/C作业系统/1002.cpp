#include <stdio.h>
int main()
{
	int n,a[n],b[n],i;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		printf("%d\n",a[i]+a[i]);
	}
	return 0;		
}

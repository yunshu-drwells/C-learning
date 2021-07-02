#include <stdio.h>
int main()
{
	int n,sum,i;
	while(scanf("%d",&n)&&n!=0){
		int a[n];
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		printf("%d\n",sum);
	}

} 

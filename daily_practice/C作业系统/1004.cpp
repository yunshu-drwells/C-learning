#include <stdio.h>
int main()
{
	int i,sum=0,n=999,a[n];
	while (a[n]!='\n'){
	for	(i=0;i<=n;i++){
		scanf("%d ",&a[i]);
		if(a[i]!=0)
		sum+=a[i];
		if(a[i]=='\n')
		break ;
	}
	}
	printf("%d",sum);
 } 

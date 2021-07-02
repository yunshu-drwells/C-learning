#include <stdio.h>
int main()
{
	int n,i=1,t=0;
	scanf("%d",&n);
	while(i<=n){
		t+=i;
		++i;
	}
	printf("%d",t);
}

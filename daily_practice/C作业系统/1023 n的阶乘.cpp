#include <stdio.h>
int main()
{
	int i,t,n;
	t=1,i=2;
	scanf("%d",&n); 
	while(i<=n){
		t=t*i;
		i++;
	}
	printf("%d",t);
}

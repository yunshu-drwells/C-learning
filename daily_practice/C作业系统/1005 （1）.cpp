#include <stdio.h>
int main()
{
	int n,i,j,a,s,N;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&n);
		s=0;
		for(j=1;j<=n;j++){
			scanf("%d",&n);
			s+=j;
		}
		printf("%d\n",s); 
	}
 } 

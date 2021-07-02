#include <stdio.h>
int main(void)
{
	int n,i;
	scanf("%d",&n);
	for(i=2;i<=n/2;++i){
		if(n%i==0){
			printf("This is not a prime.");
		}
		else{
			printf("This is a prime.");
		}
		} 
		
}

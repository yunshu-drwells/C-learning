#include<stdio.h>
int main()
{
	int n=99,i,j,count=100;
	if(n<=200)
		n++;
	for(j=2;j<=n/2;j++){

		if(n%j==0){
			count--;
		}
		else
		printf("%d ",n);		
	}
	printf("%d",count);
}

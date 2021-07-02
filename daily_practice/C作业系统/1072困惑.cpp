#include <stdio.h> 
int main()
{
	long n,x,t=0;
	long s=0;
	scanf("%ld",&n);
	x=n*n*n;
	while(x!=t){
		t=x%10;
		x=(x-t)/10;
		s+=t*t*t; 
	}
	printf("%ld\n",s);
}

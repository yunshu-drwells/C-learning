#include<stdio.h>
int main()
{
	int x,n=0;
	scanf("%d",&x);
	while(x > 0){
        n++;
        x /= 10;
    }
    printf("%d",n);
	
}

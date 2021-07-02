#include <stdio.h>
#define SIZE 3
int main(void)
{
	int b,c,d;
	scanf("%d %d %d",&b,&c,&d);
	int a[SIZE] = {b,c,d};
	for (size_t i=0;i < SIZE; ++i) {
		if(a[i]>a[i+1]){
			int hold = a[i];
			a[i] = a[i+1];
			a[i+1] = hold;
		}	
	}
	for (size_t i=0;i < SIZE; ++i) {
		printf("%d %d %d",a[0],a[1],a[2]);
	}
}

#include <stdio.h>
int main(void)
{
	int b,i,a[8];
	b=0;
	for(i=0;i<8;++i)
	scanf("%d",&a[i]);
	for(i=0;i<8;++i){
		if(a[i]%2==0)
		b+=a[i];
	}
	printf("%d",b);
}

#include <stdio.h>
int main(void)
{
	int n,i;
	float b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		b+=1.0/(i*(i+1.0));
		}
printf("%.2f",b);
}

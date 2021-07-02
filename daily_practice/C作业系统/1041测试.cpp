#include<stdio.h>
int main(void)
{
	int i,max,min,n,a[n]={};
	scanf("%d\n",&n);
	
	for(i=0;i<n;i++)
	scanf("%d ",&a[i]);
	
	for(i=0;i<n;i++){
	if(a[i]>max)
	max=a[i];
	if(a[i]<min)
	min=a[i];
	}
	printf("%d %d",max,min);
	
}

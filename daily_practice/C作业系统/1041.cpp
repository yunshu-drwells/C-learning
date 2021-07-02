#include<stdio.h>
int main(void)
{
	int i,c,d,max,min,n,a[n]={};
	scanf("%d\n",&n);
	
	for(i=0;i<n;i++){
		scanf("%d ",&a[i]);
	}

	for(i=0;i<n;i++){
	if(a[i]>max)
	max=a[i];
	if(a[i]<min)
	min=a[i];
	}
	
	c=a[4];
	a[4]=max;
	max=c;

	d=a[0];
	a[0]=min;
	min=d;

	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}

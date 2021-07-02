#include <stdio.h> 
int main()
{
	int a[3],i,j;
	for(i=0;i<3;i++)
	scanf("%d,",&a[i]);
	for(i=0;i<3;i++){
	if(a[i]>a[i+1]){
		j=a[i];
	a[i]=a[i+1];
	a[i+1]=j;
	}	
	else
	break;
	}
	for(i=0;i<3;i++)
	printf("%d ",a[i]);
}

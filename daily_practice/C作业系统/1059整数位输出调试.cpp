#include <stdio.h>
int main()
{
	int j,n=123;
	int a[10]={1,10,100,1000,10000,100000};
	int x=3;
	int b[10]={1,1,1,1,1};
 	for(j=0;j<x;j++)
	 {
	 	if(j<x-1)
	 	{
	 		b[j]=((n/a[j])%10);	
				
		 }	
	 	else b[j]=n/a[x-1];
	 	printf("%d ",b[j]);
	  } 
}

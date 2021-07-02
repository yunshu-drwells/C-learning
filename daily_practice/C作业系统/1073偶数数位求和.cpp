#include <stdio.h>
int main()
{
 	int i,j,k,u;
 	int n,z=0;
 	int x=1;
 	int a[10]={1};
 	int b[10];
 	scanf("%d",&n);
 	
 	u=n; 
	
	while(n>=10)
	{
		n/=10;
		x++;
	 } 
	 for(i=0;i<10;i++)
	 	a[i+1]=a[i]*10;

	 for(j=0;j<x;j++)
	 {
	 	if(j<x-1) b[j]=((u/a[j])%10);	
	 	else b[j]=u/a[x-1];
	  } 
	  for(k=0;k<x;k++)
	  {
	  	if(b[k]%2==0) z+=b[k];
	   } 
	   printf("%d",z);
} 

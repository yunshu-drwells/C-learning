#include <stdio.h>
int main()
{
	int n,i,b;		
	while(scanf("%d",&n)!=EOF&&n!=0){
		{
		int a[n];
 		for(i=0;i<n;i++) scanf("%d",&a[i]);
 		for(i=0;i<n-1;i++)
 		{
 			if(a[i]>a[i+1])
 			{
 				b=a[i];
 				a[i]=a[i+1];
 				a[i+1]=b;
			 }	
			 
		 } 
		 for(i=0;i<n;i++)  printf("%d ",a[i]);
		 puts("");	
		}	
	}
}

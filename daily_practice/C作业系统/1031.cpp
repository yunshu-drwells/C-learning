#include <stdio.h>
int main()
{
	int n,i,a[n],b[n];
	scanf("%d\n",&n);
	
	for(i=0;i<n;i++)
	scanf("%d %d",&a[i],&b[i]);
		
	for(i=0;i<n;i++){
		if(a[i]<b[i])	
	    printf("%d\n",b[i]);
	    else
	    printf("%d\n",a[i]); 
	}
}


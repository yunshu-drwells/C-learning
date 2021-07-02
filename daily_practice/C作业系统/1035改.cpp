#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
 int main() 
 { 
 	int i,j,k,l; 
	int a[5]; 
		for(i=1;i<=4;i++) {
         scanf("%d",&a[i]); 
	 	} 
	 	for(i=4;i>=1;i--)
	  		{ 
	  	for(j=1;j<=4;j++) { 
		if(j!=i) { 
	 	for(k=1;k<=4;k++) { 
	 	if(k!=i&&k!=j) { 
	 	printf("%d %d %d\n",a[j],a[k],a[10-i-j-k]); 
	  	   } 
	 	  } 
	 	 } 
	    } 
	    } 
	return 0; 
}

#include <stdio.h>
int main()
{
	int i,j,x=0;
	for (i=0;i<2;i++){
		x++;
		for(j=0;j<=3;j++){
			if(j%2) continue;//j%2的意思是j%2!=0 
			x++;
		}
		x++;
	}
	printf("%d",x);
 } 

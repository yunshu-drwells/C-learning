#include <stdio.h> 
int main()
{
	int x,y,z,i,j;
	scanf("%d,%d,%d",&x,&y,&z);
	if(x>y){
		i=z;
		z=y;
		y=i;
	}
	if(y>z){
		j=y;
		y=z;
		z=j;	
	}
	printf("%d %d %d\n",x,y,z);
}


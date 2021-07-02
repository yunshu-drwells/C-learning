#include <stdio.h>
int main()
{
 	int i,j,k,u;
 	scanf("%d %d %d",&i,&j,&k);
 	if(i<j&&i>k||i>j&&i<k) u=i;
 	else if(j<i&&j>k||j>i&&j<k) u=j;
 	else u=k;
 	printf("%d",u);
}

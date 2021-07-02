#include <stdio.h>
main()
{
	int i=0,j=0,x=0;
	int a[][4]={{0,1},{0,2,5,0},{2,3,4,5},{9,3,0,7}};
	while(i<4&&j<4)
	{
		x+=a[3-i][j];
		i++;
		j++;
	}
	printf("\n%d",x);
}

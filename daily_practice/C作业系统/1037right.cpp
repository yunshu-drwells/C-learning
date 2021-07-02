#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,count=21;
	printf("%d\n",count);
	for(m=101;m<=200;m=m+2)
	{
		for(n=2;n<m;++n)
		if(m%n==0) break;
	    if(n>=m-1)
		{
			printf("%d ",m);
		}
	}
}

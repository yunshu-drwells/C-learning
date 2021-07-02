#include <stdio.h>
int main()
{
	int N=10,a[N],i,temp;
	for(i=0;i<N;i++) scanf("%d",&a[i]);
		for(i=0;i<N;i++)
		{
			if(i<N-1)
			{
				temp=a[i];
				a[i]=a[N-1];
				a[N-1]=temp;	
			}
			N--;	
		}
		for(i=0;i<10;i++)
			printf("%d ",a[i]);
}


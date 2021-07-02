#include<stdio.h>
int main()
{
	int n,i,a[10],b,c,x=0,y=0,max,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];min=a[0];
	for(i=1;i<n;i++)
	{
		if(max<a[i])
		{
		max=a[i];
		x=i;
		}
		if(min>a[i])
		{
		min=a[i];
		y=i;
		}
	}
	b=a[0];
	c=a[n-1];
	a[0]=min;a[n-1]=max;
	a[x]=c;
	a[y]=b;
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		printf("%d\n",a[i]);
		else
		printf("%d ",a[i]);
	}
	return 0;
}


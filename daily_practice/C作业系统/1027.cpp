#include<stdio.h>
int main()
{
int n,i;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
int m,j,max=0;
scanf("%d",&m);
for(j=1;j<=m;j++)
{
int k;
scanf("%d",&k);
if(k>max) max=k;
}
printf("%d\n",max);
}
return 0;
}

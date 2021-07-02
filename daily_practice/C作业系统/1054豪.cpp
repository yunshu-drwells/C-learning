#include<stdio.h>
 
int main()
 
{
 
int t,n,i,j;
 
double h,f[10000];
 
scanf("%d",&t);
 
for(i=0;i<t;i++)
 
{
 
scanf("%lf%d",&h,&n);
 
f[0]=h;
 
for(j=1;j<n;j++)
 
{
 
h=h/2;
 
f[j]=f[j-1]+2*h;
 
}
 
h=h/2;
 
printf("%.2lf %.2lf\n",f[n-1],h);
 
}
 
return 0;
 
}
 

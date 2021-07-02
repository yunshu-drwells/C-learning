#include<stdio.h>
#define PI 3.1415926
int main()
{
float r,h,v,c,s,S;
scanf("%f%f",&r,&h);;
c=2*PI*r;
s=PI*r*r;
S=2*PI*r*h;
v=PI*r*r*h;
printf("%.2f %.2f %.2f %.2f\n",c,s,S,v);
return 0;
}


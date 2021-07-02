#include <stdio.h>
#define pai 3.14159
int main()
{
	float r,h,s,vz;
	scanf("%f %f",&r,&h);
	s=2*pai*r;
	vz=pai*r*r*h;
	printf("s=%.2f vz=%.2f",s,vz);
} 

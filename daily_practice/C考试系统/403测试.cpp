#include<stdio.h>
#include<math.h>
int main()
{
	double x,y,z,u,i,o;
	scanf("%lf,%lf",&x,&y);
	u=(sqrt(x+y));     //printf("u=%.2lf",u);

	i=(sin(x)+cos(y)); //printf("i=%.2lf",i);
	
	z=u/i;
	printf("z=%.2lf",z);
	return 0;
}

#include <stdio.h>
int main()
{
	float a,b,c=0;
	float i;
	scanf("%f",&i);
	for(int j;j<i+1;j++)
	{
		a=1.0/(4*j-3);
		b=1.0/(4*j-1);
		c+=4*(a-b);
	}
	printf("%.5f",c);		
}
/*
输入n值，并利用下列格里高里公式计算并输出圆周率：
*/

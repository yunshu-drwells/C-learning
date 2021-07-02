#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n",a<(b<c?b:c)?a:(b<c?b:c));
	return 0;
} 
/*b<c?b:c的意思就是if(b<c)则b,  else 则c整句话的意思是b,c中最小的数
 同理b<c?b:c的意思也是找出吧b,c 中最小的数
 合起来这a<(b<c?b:c)?a:(b<c?b:c)句话的意思是找出a和（b,c中最小数 ）的最小数，
 简言之就是先找出b,c中最小数。再找出a和第一次找出的最小数的最小数 也就是、找出了a,b,c三个数中的最小数 */ 

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	
#if 0
//打印100~200之间的素数 (一)

	int count = 0;
	for (int i = 100; i < 200; i++)
	{
		int j;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d   ", i);
			count++;
		}	
	}
	printf("\n Primenumber's number = %d\n\n", count);

#endif


#if 0
//打印100~200之间的素数 (二)

	int count = 0;
	for (int i = 100; i < 200; i++)
	{
		int j;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d   ", i);
			count++;
		}
	}
	printf("\n Primenumber's number = %d\n\n", count);

#endif

#if 1
//打印100~200之间的素数 (三)

;	int count = 0;
	for (int i = 101; i < 200; i+=2)
	{
		int j;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d   ", i);
			count++;
		}
	}
	printf("\n Primenumber's number = %d\n\n", count);

#endif

	



//1*1=1
//2*1=2  2*2=4
//3*1=3  3*2=6  3*3=9
// ...

#if 1
//输出乘法口诀表
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", i, j, i * j);
		}
		printf("\n");
	}
	printf("\n\n");
#endif

#if 0
//判断1000年---2000年之间的闰年
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				printf("%d ", year);
			}
		}
		if (year % 400 == 0)
		{
			printf("%d ", year);
		}
	}

#endif

#if 1
	//判断1000年---2000年之间的闰年(Self)
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				printf("%d ", year);
	}
#endif
	system("pause");
	return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
typedef struct SuperInt  //创造一个进制为1e9+7,最大支持(1e9+7)*2^64的计数器
{
	long long real;
	int tail;
}SuperInt;

SuperInt fib(long long n)
{
	SuperInt a = { 0, 1 };
	SuperInt b = { 0, 1 };
	SuperInt c = { 0, 2 };
	if (n == 1 || n == 2)
		return a;
	else if(n == 3)
		return c;
	else
	{
		while (n > 3)
		{
			a.real = b.real;
			a.tail = b.tail;

			b.real = c.real;
			b.tail = c.tail;

			c.real = a.real + b.real;
			c.real += (a.tail + b.tail)/ ((int)1e9 + 7);
			c.tail = (a.tail + b.tail) % ((int)1e9 + 7);
			n--;
		}
		return c;
	}
}

int main()
{
	long long n = 0;
	(void)scanf("%d", &n);
	SuperInt ret = fib(n);
	printf("%d", ret.tail%((int)1e9+7));
}
*/






/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

typedef struct SuperInt  //创造一个进制为1e9+7,最大支持(1e9+7)*2^64的计数器
{
	long long real;
	int tail;
}SuperInt;

SuperInt fib(long long n)
{
	SuperInt a = { 0, 1 };
	SuperInt b = { 0, 1 };
	SuperInt c = { 0, 2 };
	if (n == 1 || n == 2)
		return a;
	else if (n == 3)
		return c;
	else
	{
		while (n > 3)
		{
			if (b.tail < ((int)1e9 + 7))
			{
				//a.real = b.real;
				a.tail = b.tail;
			}
			else
			{
				//a.real = b.real;
				//a.real += (b.tail / ((int)1e9 + 7));
				a.tail = b.tail % ((int)1e9 + 7);
			}
			

			if (c.tail < ((int)1e9 + 7))
			{
				//b.real = c.real;
				b.tail = c.tail;
			}
			else
			{
				//b.real = c.real;
				//b.real += c.tail / ((int)1e9 + 7);
				b.tail = c.tail % ((int)1e9 + 7);
			}
			

			//c.real = a.real + b.real;cc
			if (b.tail >= 5e8)
			{
				//c.real += (a.tail + b.tail) / ((int)1e9 + 7);
				c.tail = (a.tail + b.tail) % ((int)1e9 + 7);
			}
			else
			{
				c.tail = a.tail + b.tail;
			}

			n--;
		}
		return c;
	}
}

int main()
{
	long long n = 0;
	(void)scanf("%lld", &n);
	SuperInt ret = fib(n);
	printf("%d", ret.tail % ((int)1e9 + 7));
}
//4593 6135 8325 5041
//4593613583255041
*/









#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
//创造一个进制为1e9+7,最大支持(1e9+7)*2^64的计数器

typedef struct SuperInt
{
	long long real;
	int tail;
}SuperInt;

SuperInt fib(long long n)
{
	SuperInt a = { 0, 1 };
	SuperInt b = { 0, 1 };
	SuperInt c = { 0, 2 };
	if (n == 1 || n == 2)
		return a;
	else if (n == 3)
		return c;
	else
	{
		while (n > 3)
		{
			if (b.tail < ((int)1e9 + 7))
			{
				a.tail = b.tail;
			}
			else
			{
				a.tail = b.tail % ((int)1e9 + 7);
			}


			if (c.tail < ((int)1e9 + 7))
			{
				b.tail = c.tail;
			}
			else
			{
				b.tail = c.tail % ((int)1e9 + 7);
			}


			if (b.tail >= 5e8)
			{
				c.tail = (a.tail + b.tail) % ((int)1e9 + 7);
			}
			else
			{
				c.tail = a.tail + b.tail;
			}

			n--;
		}
		return c;
	}
}

int main()
{
	long long n = 0;
	(void)scanf("%lld", &n);
	SuperInt ret = fib(n);
	printf("%d", ret.tail);
}
//4593 6135 8325 5041
//4593613583255041



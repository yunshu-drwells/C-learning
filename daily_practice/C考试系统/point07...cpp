/*程序的功能是：统计子串sub在母串中出现的次数，请填空。
例如输入：abcabsdefabc
          abc
输出：2
*/ 
#include <stdio.h>
int count(char *p,char *q);
int main()//DeV编译器main必须要有返回值 int,visual C里 可以没有 
{
	char s[80],sub[80];
	gets(s);
	gets(sub);
	printf("%d\n",count(s,sub));
}

int count(char *p,char *q)
{
	int m,n,k,num=0;
	for(m=0;p[m];m++)
	for(n=m,k=0;q[k]==p[n];k++,n++)
	
	if(q[k+1]=='\0')
	{
		num++;
		break;
	}
	return num;	
}
//填空题中没有函数原型声明，语法上是允许这样的,但是实际编码中,强烈建议使用函数原型

/*1、void main的返回值为空值（即没有返回值），int main的返回值为整数类型值。

2、void main 可以用 int main代替，但是 int main 不能用 void main代替。

3、有的编译器main必须要有返回值 int ， 那就写成int main 。*/

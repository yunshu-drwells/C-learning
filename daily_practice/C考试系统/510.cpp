/*----------------------------------------------------
统计从键盘输入的字符串中大写字母的个数。输入的字符串可能包含空格。
输入： abGshXf
输出： num=2
----------------------------------------------------*/
#include <stdio.h> 
#include <string.h>

int main()
{
	char a[99];
	int i,t,num=0;
	gets(a);
	t=strlen(a);
	for(i=0;i<t;i++) 
		if(a[i]>='A'&&a[i]<='Z') num++;
		printf("num=%d",num);	 
	
}

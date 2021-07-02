/*程序的功能是：删除字符串s中的素有空白符（包括tab符、回车符），请填空。
例如输入：abcde abcd efg
输出：abcdeabcdefg
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
delspace(char *t)
{ int m,n;
  char c[80];
  for(m=0,n=0;__(1)__;m++)
	if(!isspace(__(2)__))    /*C语言提供的库函数，用以判断字符是否为空白符*/
	{ c[n]=t[m]; n++; }
	c[n]='\0';
	strcpy(t,c);
}
void main()
{ char s[80];
  gets(s);
  delspace(s);
  puts(s);
}


/*程序的功能是：比较两个字符串是否相等，若相等则返回1，否则返回0，请填空并将程序补充完整。
例如输入：abcdef
          abcdef
输出：两个字符串相等
输入：abcdefefg
      abcdef
输出：两个字符串不相等
*/
#include<stdio.h>
#include<string.h>
int fun(char *s,char *t)
{ int m=0;
  while(*(s+m)==*(t+m)&& s[m]!='\0')
     m++;
  return(*(s+m)==*(t+m));
}
int main()
{
/******************************/
char a[10],b[10],*s,*t;
char j;
gets(a);
gets(b);
j=fun(a,b);
if(j==1) printf("两个字符串相等");
else
printf("两个字符串不相等");
/******************************/
}

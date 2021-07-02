/*程序的功能是：在字符串s中找出最大的字符放在第一个位置上，并将该字符前原字符往后顺序移动，请填空。
例如输入：boy&girl
输出：ybo&girl
*/
#include<stdio.h>
#include<string.h>
int main()
{ char s[80],*t,max,*w;
  t=s;
  gets(t);
  max=*(t++);
  while(*t!='\0')
  { if(max<*t)
 	{ max=*t;w=t; }
    t++;
  }
  t=w;
  while(t>s)
  { *t=*(t-1); t--; }
    *t=max;
  puts(t);
}


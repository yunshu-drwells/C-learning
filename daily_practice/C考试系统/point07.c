/*程序的功能是：统计子串sub在母串中出现的次数，请填空。
例如输入：abcabsdefabc
          abc
输出：2
*/
#include<stdio.h>
#include<string.h>
int count(char *p,char *q)
{ int m,n,k,num=0;
  for(m=0;p[m];m++)
	for(n=m,k=0;q[k]==p[n];k++,n++)
	   if(q[k+1]=='\0')
	   { num++;break; }
   return num;
}
void main()
{ char s[80],sub[80];
  gets(s);
  gets(sub);
  printf("%d\n",count(s,sub));
}
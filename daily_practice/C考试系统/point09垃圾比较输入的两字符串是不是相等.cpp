#include<stdio.h>
#include<string.h>
int fun(char *s,char *t)
{ int m=0;
  while(*(s+m)==*(t+m)&&*(t+m)!='\0')
     m++;
  return(*(s+m)-*(t+m));
}
int main() 
{
/******************************/
	{char a[10],b[10];
	int j;
	scanf("%s",a);
	scanf("%s",b);
	j=fun(a,b);
	if(j==0)
	printf("两个字符串相等");
	else
	printf("两个字符串不相等");
	}
/******************************/
}

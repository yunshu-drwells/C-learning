#include <stdio.h>
#include <string.h> 
int main()
{
	char s[3][20]={"BASIC","JAVA","C++"}; //在这个例子红发现[20]表示每一个字符都不能超过的长度（所能允许的最长字符串长度） 
	int i,k=0;
	for(i=1;i<3;i++)
	if(strcmp(s[k],s[i])<0)
	k=i;
	puts(s[k]);
}

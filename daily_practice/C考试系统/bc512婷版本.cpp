/*任意输入两个字符串（使用数组存储，串长度不超过19个字符，允许出现空格字符，并且一个串内字符不重复），
求两串中相同的字符（按相同字符在第一个串的先后顺序输出）。*/
#include <stdio.h>
#include <string.h>
int main()
{
	char a[100],b[100],c[100];
	int i,d,e,j,t=0;
	gets(a);
	gets(b);
	d=strlen(a);
	e=strlen(b);
	for(i=0;i<d;i++){
		for(j=0;j<e;j++){
			if(a[i]==b[j]){
				c[t]=a[i];
				t++;
			}
		}
	}
	c[t]='\0'; //字符数组以'\0'结尾 
	puts(c);  
} 

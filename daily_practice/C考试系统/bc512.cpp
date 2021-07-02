/*任意输入两个字符串（使用数组存储，串长度不超过19个字符，允许出现空格字符，并且一个串内字符不重复），
求两串中相同的字符（按相同字符在第一个串的先后顺序输出）。*/
#include <stdio.h>
#include <string.h>
int main()
{
	char a[19],b[19];
	int  c,d,e,k;
	gets(a);
	gets(b);
	c=strlen(a);
	d=strlen(b);
	if(c>d) e=c;
	else e=d;
	for(k=0;k<e;k++){
	if(a[k]==b[k])
		printf("%c",a[k]);}//错误的原因存在于 只有下标相同的比较 ，具体看以上花括号前的for 语句 
}

/*-------------------------------------------------------------------
从键盘上输入一个字符串，放在数组中，要求将字符串中的大写字母转换成小写字母，
小写字母转换成大写字母，非字母字符不变，并输出。
输入： ABC123def
输出： abc123DEF
-------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
int main()
{
	char b[80];
	int i,n;
	gets(b);
	n=strlen(b);
	for(i=0;i<n;i++){
		if(b[i]>='a'&&b[i]<='z') 
		printf("%c",b[i]-32);
		else if(b[i]>='A'&&b[i]<='Z') 
		printf("%c",b[i]+32);
		else
		printf("%c",b[i]);
	}
	printf("\n");
	return 0;
}

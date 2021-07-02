#include <stdio.h>
int main()
{
	char password[2][2];//第一个[]代表字符串个数，第二个[] 表示每一个字符都不能超过的长度
	gets(password[1]);
	printf("%s\n",password[1]);
	gets(password[2]);
	printf("%s\n",password[2]);
}

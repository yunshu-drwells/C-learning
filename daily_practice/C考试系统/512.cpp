#include <stdio.h>
#include <string.h>
int main()
{

	char a[19],b[19];
	int c,d,e,k;
	gets(a);
	gets(b);
	c=strlen(a);
	d=strlen(b);
	if(c>d) e=c;
	else e=d;
	for(k=0;k<e;k++){
	if(a[k]==b[k])//错误的原因存在于 只有下标相同的比较 
	printf("%s",a[k]);
	return 0;
	}
}

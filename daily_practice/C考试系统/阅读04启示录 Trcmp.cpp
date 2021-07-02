#include <stdio.h>
#include <string.h> 
int main()
{
	char s[3][20]={"BASIC","JAVA","C++"};
	int i,k=0;
	for(i=1;i<3;i++){
	printf("%s %s\n",s[k],s[i]);
	printf("%d\n",strcmp(s[k],s[i]));
	if(strcmp(s[k],s[i])<0)k=i;
	}
	puts(s[k]);
}

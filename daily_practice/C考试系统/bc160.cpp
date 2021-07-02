#include  <stdio.h>
#include  <string.h>
#define N 80

int fun(char str[N])
{ 
/**********Program**********/
int n;
n=strlen(str);
for(int i=0;i<n;i++){
	if(str[i]=='*') return i;
	else
		return -1;
}
/**********  End  **********/
}


void  main( )
{char  s[N];
 
 scanf("%s",s);

 printf("%d",fun(s)); 
}


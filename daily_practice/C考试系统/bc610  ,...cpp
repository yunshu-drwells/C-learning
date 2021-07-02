#include  <stdio.h>
#include  <string.h>
#define N 80

int fun(char str[N])
{ 
/**********Program**********/
int n,j=-1;
n=strlen(str);
for(int i=0;i<n;i++){
	if(str[i]=='*'){
		j=1;
		break;
		}
}
return j;
/**********  End  **********/
}


int  main( )
{char  s[N];
 
 scanf("%s",s);

 printf("%d",fun(s)); 
}

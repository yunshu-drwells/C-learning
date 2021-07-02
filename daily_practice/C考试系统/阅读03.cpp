#include<stdio.h>
#include<string.h>
main()
{char a[20];
int i,t,l=0,d=0;
gets(a);
t=strlen(a);
for(i=0;a[i]!='\0';i++)
if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
    l++;
    else if(a[i]>='0'&&a[i]<='9')  d++;
    printf("%d,%d,%d",t,l,d);
 } 

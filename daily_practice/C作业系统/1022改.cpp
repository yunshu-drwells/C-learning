#include <stdio.h>
int main()
{
long a,n;
while (scanf("%ld",&n)!=EOF)
{
a=2;
while(a<n)
{
if(n%a==0)
break;
a++;
}
if(a==n)
{
    printf("This is a prime.");
}else
printf("This is not a prime.");
}
return 0;
}

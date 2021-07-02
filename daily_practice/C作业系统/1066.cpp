#include<stdio.h>
#include<math.h>
int main()
{
    int n,a,b;
    scanf("%d",&n);
    n = n * 10;
    a = n / 3;
    b = n % 3;
    printf("%d %d",a,b);
}

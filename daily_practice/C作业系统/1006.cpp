#include<stdio.h>
int main(void)
{
    int N=0,a=0,sum=0,i=0;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&a);
            sum=sum+a;
        }
        printf("%d\n",sum);
        sum=0;
    }
}

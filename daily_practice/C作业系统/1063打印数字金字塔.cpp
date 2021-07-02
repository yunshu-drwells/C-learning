#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;
    int n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=i; j<n; j++)
            printf("  ");
        for(j=1; j<=i; j++)
        {
            printf("%d",j);
            if(i!=1)
                printf(" ");
        }
        for(j=i-1; j>0; j--)
        {
            printf("%d",j);
            if(j!=1)
                printf(" ");
        }
        printf("\n");
    }
} 

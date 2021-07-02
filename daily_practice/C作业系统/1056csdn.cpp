#include<stdio.h>
int main()
{
    int sum[10];
    int n;
    int i,j;
    int temp;
    int a[10];
    while(~scanf("%d",&n)&&n)
    {
        for(i = 0; i < n; i++)
        {
            sum[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            temp = a[i];
            for(j = 0; ; j++)
            {
                sum[i] += temp%10;
                temp = temp / 10;
                if(temp == 0)
                    break;
            }
        }
        for(i = 0; i < n - 1; i++)
        { 
            for(j = i + 1; j < n; j++)
            {
                if(sum[i] > sum[j])
                {
                    temp = sum[i];
                    sum[i] = sum[j];
                    sum[j] = temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            if(i == n-1)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}

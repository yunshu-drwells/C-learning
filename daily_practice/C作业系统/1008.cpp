#include<stdio.h>
int main()
{
    int m;
    scanf("%d",&m);	
    while(m--)      
    {
        int n;
        scanf("%d",&n);        
        int sum = 0;
        while(n--)             
        {
            int a;
            scanf("%d",&a);
            sum += a;
        }
        if(m != 0) 
        printf("%d\n\n",sum);
        else
        printf("%d\n",sum);
    }
}

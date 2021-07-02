#include <stdio.h>
#include <stdlib.h>
int work(int a[])
{
int i,j,k;
for(j=0;j<3;j++)
            for(i=0;i<3;i++)
                for(k=0;k<3;k++)
                if(i!=j&&i!=k&&k!=j)
    printf("%d %d %d\n",a[j],a[i],a[k]);
}
int main()
{
    int a[4],b[4];
    int i,j,k;
    for(i=0;i<4;i++)
        scanf("%d",&a[i]);
    b[0]=a[0],b[1]=a[1],b[2]=a[2];
    work(b);
    b[0]=a[0],b[1]=a[1],b[2]=a[3];
    work(b);
    b[0]=a[0],b[1]=a[2],b[2]=a[3];
    work(b);
    b[0]=a[1],b[1]=a[2],b[2]=a[3];
    work(b);
    return 0;
}

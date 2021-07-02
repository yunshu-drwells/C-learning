#include <stdio.h>
int main()
{
 	int i,j,k,u;
 	int n;
 	int x=1;
 	int a[10]={1};
 	int b[10];
 	scanf("%d",&n); //输入一个多位数   	for(i=0;i<80;i++) a[i]=1;
 	
 	u=n; // 保留原始数据 printf("%d  %d",u,n);
	
	while(n>=10)
	{
		n/=10;
		x++;
	 } //得出输入数字的个数
	 printf("%d\n",x);
	 for(i=0;i<10;i++)  //i<x
	 	a[i+1]=a[i]*10; //a  :  1,10,100,1000......1000000000	printf("%lld ",a[i]);

	 for(j=0;j<x;j++)
	 {
	 	if(j<x-1) b[j]=((u/a[j])%10);	
	 	else b[j]=u/a[x-1]; //j=x-1时 ，u/a[x-1]为最高位数 
	  } 
	  for(k=x-1;k>=0;k--)
	  printf("%d ",b[k]);
	  puts("");
	  
	  for(k=0;k<x;k++)
	  printf("%d ",b[k]);  
}
/*  for(i=0;i<18;i++)
	  {
	  	if(n/a[i]<10&&n/a[i]>0) x=i+1;
	  }
	  printf("%d\n",x);

*/

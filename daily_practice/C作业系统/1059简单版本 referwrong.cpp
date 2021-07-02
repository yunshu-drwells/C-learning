#include <stdio.h>
int main()
{
 	int n;
 	int q,w,e,r,a;
 	int x;
 	scanf("%d",&n);
 	if(n<10) x=1;
 	else if(n>10&&n<100) x=2;
 	else if(n>100&&n<1000) x=3;
 	else if(n>1000&&n<10000) x=4;
 	else x=5;
 	printf("%d\n",x);
 	a=n%10;
 	r=n/10%10;
 	e=n/100%10;
 	w=n/1000%10;
 	q=n/10000;
 	switch(x)
 	{
 		case 5: printf("%d ",q,w,e,r,a);  break;
 		case 4: printf("%d %d",w,e,r,a); break;
		case 3: printf("%d %d %d",e,r,a);  break;
		case 2: printf("%d %d %d %d",r,a);  break;
		case 1: printf("%d %d %d %d %d",a);   break;
	 }
	 puts("");
	 switch(x)
 	{
 		case 1: printf("%d ",a); break;
 		case 2: printf("%d %d",a,r); break;
		case 3: printf("%d %d %d",a,r,e);  break;
		case 4: printf("%d %d %d %d",a,r,e,w); break; 
		case 5: printf("%d %d %d %d %d",a,r,e,w,q);   break;
	 } 	
}

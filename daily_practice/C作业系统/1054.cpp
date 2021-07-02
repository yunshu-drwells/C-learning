#include <stdio.h>
int main()
{
 	int t,u=0.00,x;
 	scanf("%d",&t);
 	float h[t],n[t],m[t];
 	for(int i=0;i<t;i++) scanf("%f %f",&h[i],&n[i]);

 	for(int i=0;i<t;i++)
 	{
 		m[i]=h[i];
 		
 		for(n[i];n[i]>1;n[i]--)
		 {	
			h[i]*=0.5;
			m[i]+=h[i]*2;
		  } 
		 printf("%.2f %.2f",m[i],h[i]/2);
		 puts("");	
	 }	
}
/*
2
100 1
100.0 2
*/ 

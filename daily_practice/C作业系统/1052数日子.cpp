#include <stdio.h>
int main()
{
	int n ;
	scanf("%d",&n);
	int u;
	int a[n],b[n],c[n];
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	for(int i=0;i<n;i++)
	{
		if(a[i]%4==0&&a[i]%100==0)
		{
			switch(b[i])
			{
				case 1:
					u=c[i] ;break;
				case 2:
					u=c[i]+31 ;break;
				case 3:
					u=c[i]+60;break;  //31 60 91 121 152 182 213 244 274 305 335 
				case 4:
					u=c[i]+91 ;break;
				case 5:
					u=c[i]+121;break;
				case 6:
					u=c[i]+152;break;
				case 7:
					u=c[i]+182;break;
				case 8:
					u=c[i]+213;break;
				case 9:
					u=c[i]+244;break;
				case 10:
					u=c[i]+274;break;
				case 11:
					u=c[i]+305;break;
				case 12:
					u=c[i]+335;break;	
			}
		 } 
		 else 
		 {
		 	switch(b[i])
			{
				case 1:
					u=c[i] ;break;
				case 2:
					u=c[i]+31 ;break;
				case 3:
					u=c[i]+59;break;  //31 60 91 121 152 182 213 244 274 305 335 
				case 4:
					u=c[i]+90 ;break;
				case 5:
					u=c[i]+120;break;
				case 6:
					u=c[i]+151;break;
				case 7:
					u=c[i]+181;break;
				case 8:
					u=c[i]+212;break;
				case 9:
					u=c[i]+243;break;
				case 10:
					u=c[i]+273;break;
				case 11:
					u=c[i]+304;break;
				case 12:
					u=c[i]+334;break;	
			}
		 }
		 
	}
	printf("%d\n",u);
}
} 

#include<stdio.h>
int main()
{
	int N,i,j,t;
	int a[N][N]={};
	scanf("%d\n",&N);
	
	for(i=0;i<N;i++){	
	for(j=0;j<N;j++)
	scanf("%d",&a[i][j]);
	}
	
	for(i=0;i<N;i++){	
	for(j=0;j<N;j++)
		t=a[i][j];
		a[i][j]=a[j][i];
		a[j][i]=t;
	}
	
	for(i=0;i<N;i++){	
	for(j=0;j<N;j++)
	printf("%d ",a[i][j]);
		if(j==N)
		printf("\n");
	} 	
}

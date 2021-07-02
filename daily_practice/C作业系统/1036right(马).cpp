#include<stdio.h>
int main()
{
	int N,i,j;
	scanf("%d\n",&N);
	int a[N][N];
	for(i=0;i<N;i++){	
	for(j=0;j<N;j++)
	scanf("%d",&a[i][j]);
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
		printf("%d ",a[j][i]);
		if(j==1)
		printf("\n");
	}
 	}
}

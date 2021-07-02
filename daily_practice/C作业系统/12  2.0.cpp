#include<stdio.h>
int main()
{
	int N,i=0,j=0;
	scanf("%d\n",&N);
	int a[N][N];
	for(i=0;i<N;i++){	
	for(j=0;j<N;j++)
	scanf("%d",&a[i][j]);
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
		if(j==1) printf("\n");	
		printf("%d ",a[i][j]);

	}
 	}
}
/*特别奇怪的换行 */ 
/*
3
1 2 3
4 5 6
7 8 9
1
4 7 2
5 8 3
6 9

---
*/

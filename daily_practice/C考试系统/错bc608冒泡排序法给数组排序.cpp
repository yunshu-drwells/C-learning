#include <stdio.h>
void sort(int a[],int n)
{
	int s;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				s=a[j];
				a[j]=a[j=1];
				a[j+1]=s; 
			}
		}
	}
}
int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	sort(a,10);
	for(i=0;i<10;i++) 
	printf("%d",a[i]);
}

/*  10 2 4 5 6 7 8 9 3 1  */

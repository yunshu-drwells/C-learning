#include <stdio.h>
int search(int a[],int n,int x)  //int search(int arr[],int len,int num)//arr为序列，len为序列长度，num为要查找的数
{
	for(int i=0;i<n;i++){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
} 
int main()
{
	int a[10],x,i,k;
	for(i=0;i<10;i++){
		scanf("%d",a+i);
	}
	scanf("%d",&x);
	k=search(a,10,x);
	printf("%d\n",k);
}

/*----------------------------------------------------
编写程序：输入一个3x4的矩阵,求出其中值为最大的元素的值
以及它在矩阵中的下标. max=…, row=…, colum=… (输出符号用英文符号，中间无空格)
输入：
2 5 8 7
9 8 7 5
5 74 1 0 
输出：
max=74,row=2,colum=1
-----------------------------------------------------*/
#include <stdio.h>
int main()
{
int a[3][4];
int i,j,c,d;
int max;
for(i=0;i<3;i++)
for(j=0;j<4;j++)
{
	scanf("%d",&a[i][j]);
}
max=a[0][0];
for(i=0;i<3;i++)
for(j=0;j<4;j++)
{	
	if(max<a[i][j])
	{max=a[i][j];c=i,d=j;}
}
printf("max=%d,row=%d,colum=%d",max,c,d);
}


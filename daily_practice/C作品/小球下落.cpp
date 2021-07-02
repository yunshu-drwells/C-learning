#include <stdlib.h>
#include <stdio.h>
int main()
{
	int i,j;
	int x=1,y=10;
	for(x=1;x<10;x++)
	{
		system("cls");   //ÇåÆÁº¯Êý 
		
		for(i=0;i<x;i++)
		printf("\n");
		for(j=0;j<y;j++)    		
		printf(" "); 
		
		printf("o");
		printf("\n");
	}
	return 0;
}

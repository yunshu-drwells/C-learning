//#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int i,j;
	int x=5,y=10;
	
	int height=20;
	int velocity=1.0;  //velocity速率，速度 (float velocity=1.0;)
	
	while(1)
	{
		x+=velocity;
		system("cls");
		
		for(i=0;i<x;i++)
		printf("\n");
		for(j=0;j<y;j++)    		
		printf(" "); 
		
		printf("o");
		printf("\n");
		
		//Sleep(100);
		
		if(x==height) velocity=-velocity;
		if(x==0)      velocity=-velocity;
	}
	return 0;
 } 

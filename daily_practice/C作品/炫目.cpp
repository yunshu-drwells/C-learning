#include <stdlib.h>
#include <windows.h> //包含sleep函数与清屏函数连用可增强程序可读性
#include <stdio.h>
int main()
{
	int i,j;
	int x=0,y=5;
	
	int velocity_x=1;
	int velocity_y=1;
	int left=0,right=6;
	int top=0,bottom=6;
	while(1)
	{
		x+=velocity_x;
		y+=velocity_y;
			
		for(i=0;i<x;i++)
		printf("\n");
		for(j=0;j<y;j++)    		
		printf(" "); 
		
		printf("o"); 
		
		Sleep(100);
		
		if(x==top||x==bottom) velocity_x=-velocity_x;
		if(y==left||y==right) velocity_y=-velocity_y;
	}
	return 0;
 } 

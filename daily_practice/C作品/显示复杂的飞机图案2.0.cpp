#include<stdlib.h>
#include<stdio.h>
#include<conio.h> 
int main()
{
	int i,j;
	int x = 5,y = 10;
	char input;
	
	while(1)
	{
		system("cls");

		for(i=0;i<x;i++)
		printf("\n");
		
		for(j=0;j<y;j++)
	      printf(" ");
	      printf("    /\\ \n");
		for(j=0;j<y;j++)
		  printf(" ");
		  printf("   *--* \n");
		for(j=0;j<y;j++)
		  printf(" ");
		  printf(" ***__*** \n");
		for(j=0;j<y;j++)
		  printf(" ");
		  printf("   **** \n");
	    for(j=0;j<y;j++)
	      printf(" ");
		  printf("    ** \n");
		for(j=0;j<y;j++)
		  printf(" ");
		  printf("   **** \n");
		
		if(kbhit())
		{
			input=getch();
			if(input == 'w') x--;
			if(input == 'a') y--;
			if(input == 's') x++;
			if(input == 'd') y++;
		}	
	}
return 0; 
}

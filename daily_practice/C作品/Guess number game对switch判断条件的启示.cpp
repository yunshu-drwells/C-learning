#include <stdio.h>
int main()
{
	int number,guessnumber,j;//
	while(scanf("%d %d",&number,&guessnumber)!=EOF)
	{
		j=(guessnumber-number)/10;  //机器没有理解负数的自觉 
		printf("%d\n",j);
	}
	
}

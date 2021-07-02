#include<stdio.h>
int main(void)
{
	int a,b;
	char c;
	scanf("%d%c%d",&a,&c,&b);
	
	if(a%400==0 && b==2)
	printf("29");

	if(a%400!=0 && b==2)
	printf("28");

	switch(b)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30");
			break;	
		}
}


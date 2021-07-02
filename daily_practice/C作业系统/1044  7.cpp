#include <stdio.h>
int main(void)
{
	int	k,l;
	for(l=1;l<=4;l++){
		for(k=1;k<=l;k++)printf(" ");
		for(k=1;k<=9-2*l;k++)
			printf("*");
			printf("\n");
	}
}

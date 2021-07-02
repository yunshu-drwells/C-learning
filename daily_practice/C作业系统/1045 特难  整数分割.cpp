# include <stdio.h>
# include <math.h>
int main ()
{

long long  i,ss,l=1;
long long  temp=0;
while (scanf ("%lld",&i) !=EOF)
	{
		l=i;
 		ss=i;
		temp=0;
	while(ss){
		ss=ss/10;
		temp++ ;
		}
	for(long long j=temp-1;j>0;j--)
	{
	ss=i/(long long ) pow(10,j);
	i=i-ss* (long long )pow(10,j);
	printf("%lld ",ss);
		}
	printf("%lld \n" ,l%10);
	}
return 0;
}

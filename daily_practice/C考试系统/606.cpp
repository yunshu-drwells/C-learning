/*------------------------------------------------


功能：求两个整数的最大公约数。

------------------------------------------------*/

#include<stdio.h>


int gcd(int n,int m)
{
  /**********Program**********/
  
  int b,c;
  if(m>n) b=m;
  else b=n;

  for(int i=2;i<b;i++){
	  if(m%i==0 && n%i==0) c=i;
  }
  return c;
  /**********  End  **********/
}

main()
{
  int n,m,result;
  scanf("%d%d",&n,&m);
  result=gcd(n,m);
  printf("the gcd is %d\n",result);

}


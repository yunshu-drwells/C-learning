/*------------------------------------------------
【程序设计】
--------------------------------------------------

功能：编写main程序调用函数fact求解从m个元素选n个元
      素的组合数的个数。计算公式是：
      组合数＝m!/(n!*(m-n)!)。注意:m>n。
说明：函数fact(x)的功能是求x!。

------------------------------------------------*/

#include <stdio.h>

long fact(int x)
{
  long y;
  int i;
  y=1;
  for(i=1;i<=x;i++)
    y=y*i;
  return y;
}

main()
{
  int m,n;
  long zhsgs;
  scanf("%d%d",&m,&n);
  /**********Program**********/
  zhsgs=fact(m)/(fact(n)*fact(m-n));
  
  
  
  
  
  /**********  End  **********/
  printf("%d\n",zhsgs);

}


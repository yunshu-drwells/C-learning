/*程序的功能是：在a数组中查找与x相同的元素的所在位置，请填空。
例如输入：11 23 45 31 65 78 82 14 55 91
          31
输出：position of 31 is 3
输入：11 23 45 31 65 78 82 14 55 91
      71
输出：71 not been found!
*/
#include<stdio.h>
int main()
{ int a[11],x,m,*p;
  p=a;
  printf("please input ten numers:\n");
  for(m=1;m<11;m++)
	  scanf("%d",p+m);
  printf("please input x:");
  scanf("%d",&x);
  m=10;
  while(x!=*(p+m))
	m--;
  if(m>0) printf("position of %3d is:%4d\n",x,m);
  else  printf("%d not been found!\n",x);
}


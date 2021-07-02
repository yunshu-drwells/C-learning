/*程序的功能是：把从键盘输入的一行字符作为字符串放在字符数组中，然后输出，请填空*/
#include<stdio.h>
#include<string.h>
int main()
{ int m;
  char s[80],*t;
  for(m=0;m<79;m++)
  { s[m]=getchar();
    if(s[m]=='\n') break;
  }
  s[m]='\0';			    /*和上面for语句中break前面的s[m]=='\n'有联系，由于前面if(s[m]=='\n'部分的存在所以这条语句
  可以省略，意思就是将字符串的结尾作为指针结束的标志 */ 
  t=s;                      //把字符串地址传递给指针 
  while(*t) putchar(*t++);  // *t的意思是(*t!='\0')	，就是直到没有*t指针进入为止才停止输出字符串 
}

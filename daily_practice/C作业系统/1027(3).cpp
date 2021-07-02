#include <stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h; 
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){	
	if(a>=b && a>=c);{
	d=a,e=b,f=c;}
	if(b>=c && b>=a);{
	d=b,e=a,f=c;}
	if(c>=b && c>=a);{
	d=c,e=a,f=b;}
	
	if(e>f){
		g=e,h=f;
	}
	else{
		g=f,h=e;
	}
	printf("max=%d",d);		
}
return 0;
}

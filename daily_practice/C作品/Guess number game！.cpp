#include <stdio.h>
#include <string.h> 
main()
{
	int number,guessnumber;
	char password[1];
	int n;
	int i=-1;
	int j,k;
	char friendbirthday[]="0727";
	do{
		printf("*******************************************************\n");
		printf("Welcome to number guess game***************************\n");
		printf("Please key in your password(Hint:Try your birthday ): *\n");
		printf("*******************************************************\n");
		i++;
		if(i>0)printf("The password is wrong!\n Please input the right password:");
		gets(password);
	} while(strcmp(friendbirthday,password)!=0); /**/
	
	 printf("恭喜你来到这一步，生活总是有惊喜的，只要你努力\n");
	 printf("挺感谢你的好朋友，希望我们的友谊可以持续下去 .\n");
	 printf("这个猜数字游戏我有独家版权喔，等我优化一下就可以实现任意大的数的比较\n");
	 printf("Please your other friend input an number(要求1<=number<100):\n");
	 scanf("%d",&number);
	 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Please input your guess number:");
	 scanf("%d",&guessnumber);
	 
	
	 while(guessnumber!=number)
	 {
	 	if(guessnumber>number){
	 		
		j=((guessnumber-number)/10);
		
	 	switch(j){
	 		case 0:
		 		printf("Much close to the right number!\n");break;
		 	case 1:
		 	printf("A little  bigger!\n");break;
			case 2:
		 	printf("Bigger than the answer!\n");break;
			 default:
		 	printf("Munch bigger than the answer!\n");break;
		 }
		 
		}
		else
		{
			k=(number-guessnumber)/10;
			
			switch(k)
			{
				case 0:
		 	printf("Much close  to the right number!\n");break;
		 	case 1:
		 	printf("A little less  !\n");break;
			case 2:
		 	printf("Little than  the answer!\n");break;//Far apart the answer!
			 default:
		 	printf("Munch less than the answer!\n");break;
			}
				
		}
		
		printf("\f Please input your other guess number:");
		scanf("%d",&guessnumber);	
	}
	if(guessnumber==number) printf("Congratulations ! You have guessed the right number!!");
	
}


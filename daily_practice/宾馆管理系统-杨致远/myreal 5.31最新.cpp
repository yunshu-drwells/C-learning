#include <windows.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int system_time_year()
{
	int year;
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);

    year = 1900+p->tm_year ; /*获取当前年份,从1900开始，所以要加1900*/
    return year;
}
 int system_time_month()
{
	int month;
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);


    month = 1+p->tm_mon;      /*获取当前月份,范围是0-11,所以要加1*/
	return month;
    
}
 int system_time_day()
{
	int day;
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);

    day = p->tm_mday;        /*获取当前月份日数,范围是1-31*/
	return day;  
}
	int system_time_hour()
{
	int h=0;
	time_t t=time(NULL);
    time_t t1;
    time(&t1); 
	h=(t%(3600*24)/3600+8);//时  
    return h;

} 
int system_time_mintue()
	{
	 int m=0;
	 time_t t=time(NULL);
     time_t t1;
     time(&t1); 
	 m=t%3600/60;           //分 
	 return m;

	} 
	int system_time_second()
	{
	 int s=0;
	 time_t t=time(NULL);
     time_t t1;
     time(&t1);
     s=t%60;                //秒 
	 return s;
	} 

//读入最原始的房间数据 
int save_Room()
{
	const char* filename = "room.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}

	char grad[22] = "ACEDBCAEBECADCEBADCEC"; 
//	acedbcaebecadcebadcec

	int  nu[21]={105,121,145,132,116,125,103,144,
	112,143,124,102,133,123,141,111,101,136,122,142,126};   
	    
	char stat[22] = "NYYNYNYNYNYNYNNYNYNYY";

	for(int i = 0;i<21;i++)
	{	
		fprintf(fp,"类型：Grade = %c 房间号：Num = %d 当前状态：State = %c\n",grad[i] , nu[i] , stat[i]);
	}
	fclose(fp);
	return 0;
}


int load_Room()
{
	
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	cout<<"当前所有房间的状态等级，房间号，房间当前状态分别为："<<endl; 
	char buf[512];
	int n = 0;
	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		if(line)
		{
			printf(" %s",line);
			n++;
		}
	}
	cout<<"\n共有"<<n<<"条房间记录"<<endl;
	cout<<"\n"<<endl;
	cout<<"房间类型分ABCDE五个等级，房间当前状态N代表没有客人Y代表有客人"<<endl;
	fclose(fp);
	return 0;
}

//读入最原始的客人入住记录数据 
int save_guest()
{
	const char* filename = "guest.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}

	char name[12][12] = {"Ashley","Amanda","Jessica","Sarah","Brittany",
	"Megan","Jennifer","Nicole","Stephanie","Katherine","Allon"};

	char id[12][18] = {"410145121015218","101451451200110","210181150404566",
		"220551511550484","235124031013024","312545147845440","320025154413883",
		"930154540188383","871212415458538","827545811458575","132134314211422"};

	char gender[12] = "MWMMMWMWMWM";

	char grad[12] = "CEBABCDBDEC"; 
 
	char  nu[12][4]   ={"121","145","116","103",
	"112","124","133","111","136","142","126"}; 
	char year[12][5]  = {"2019","2018","2019","2019","2018","2019","2019","2019","2018","2019","2019"};
	char month[12][3] = {"11","12","3","5","8","9","6","7","5","4"};
	char day[12][3]   = {"31","27","23","19","15","11","9","8","2","1","5"};
	char hour[12][3]  = {"12","23","0","10","21","13","14","15","16","18","12"};
	char minute[12][3] = {"56","42","58","42","35","28","16","9","7","10","12"};
	char second[12][3] = {"00","01","55","13","53","54","53","12","21","41","33"};


	for(int j = 0;j<11;j++)
	{	
		fprintf(fp,"姓名：name = %9s ID：id = %18s 性别：gender = %c 居住的房间类别及房间号: %c %s入住的时间为: %4s/%2s/%2s  %2s:%2s:%2s\n"			
			,name[j] , id[j] , gender[j],grad[j],nu[j],year[j],month[j],day[j],hour[j],minute[j],second[j]);  												
}
	fclose(fp);
	return 0;
}

int load_guest()
{
	const char* filename = "guest.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}

	char buf[512];
	int n = 0;
	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		if(line)
		{
			printf(" %s",line);
			n++;
		}
	}
	cout<<"\n现在共有"<<n<<"条客人记录"<<endl;
	cout<<"\n\n"<<endl;
	fclose(fp);
	return 0;
}

int new_save_guest(char name[32],char id[18],char gender,char grad,char  nu[4],int year,int month,int day,int hour,int mintue,int second ) //year month,day,hour,minute,second    
{
	const char* filename = "guest.txt";
	FILE* fp = fopen(filename ,"ab");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	fprintf(fp,"姓名：name = %9s ID：id = %18s 性别：gender = %c 居住的房间类别及房间号: %c %s入住的时间为: %4d/%2d/%2d  %2d:%2d:%2d\n",name , id , gender,grad,nu,year,month,day,hour,mintue,second);   //      

	fclose(fp);
	return 0;
}

//写入有新客人入住房间的信息
int save_new_Room(char grad,char nu[4])
{
	const char* filename = "room.txt";
	FILE* fp = fopen(filename,"ab");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}
	fprintf(fp,"类型：Grade = %c 房间号：Num = %s 当前状态：State = %c",grad , nu ,'Y');

	fclose(fp);
	return 0;
}


//获取输入新房间信息的字符串到字符串acc[]
//找出获取的字符串acc[]在原文件多少行（n）


 int gets_str_new_Room___load_getline_old_Room(char grad,char nu[4])
{
	
	char *p;
	char acc[5];
	acc[0] = grad;
	for(int i = 1;i<4;i++)
	{
		//cout<<"i = "<<i<<endl;
		acc[i] = nu[i-1];
	}
	acc[4] = 'N';
	p = (char *)malloc(10);
	

	int n = 0;
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}

	char buf[512];

	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		n++;
		if(acc[0] == *(line+14) && acc[1] ==  *(line+30) && acc[2] == *(line+31) && acc[3] == *(line+32) && acc[4] == *(line+52))
		break;
	}

	fclose(fp);
	return n;

}


//删除Room记录中的指定行第n行,对房间的记录刷新
int newly_delete_n_Room(int n)
{
	int m = -1;

	const char* filename = "room.txt";
	FILE* fp_ = fopen(filename ,"rb");
	
	char buf[512];
	while(! feof(fp_))
	{
		char* line = fgets(buf,512,fp_);
		m++;
	}
	fclose(fp_);
	
	
	FILE* fp = fopen(filename ,"rb");
	
	const char* filename_s = "temp.txt"; 
	FILE* fps = fopen(filename_s ,"wb");
	
	char buf_[512];
	for(int i = 1;i <= m;i++)
	{
		char* line = fgets(buf_,512,fp);
		if(i != n && i)
		{
			fprintf(fps,"%s", line);
			n++;
		}	
	}

	fclose(fp);
	fclose(fps);
	
	

	FILE* fp2 = fopen(filename ,"wb");
	
	FILE* fps2 = fopen(filename_s ,"rb");
	
	for(int i = 1;i < m;i++)
	{
		char* line = fgets(buf_,512,fps2);
		fprintf(fp2,"%s", line);
	}
	fclose(fp2);
	fclose(fps2);
	return 0;
}


/**
删除指定文件filepath中第n行内容
思路:
1.依次读取源文件内容(除了第n行),并且写入到新的tmp.txt文件。
2.然后清空源文件，将tmp.txt文件重新读取写入到源文件
3.删除tmp.txt文件
**/



//打印当前空闲房间记录
int print_empty_Room()
{
	int m = -1;
	const char* filename_ = "room.txt";
	FILE* fp_ = fopen(filename_ ,"rb");
	if(fp_ == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf[512];
	while(! feof(fp_))
	{
		char* line = fgets(buf,512,fp_);
		m++;
	}
	fclose(fp_);
		
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf_[512];
	int n = 0;
	for(int i = 0;i < m;i++)
	{
		char* line = fgets(buf_,512,fp);
		if(*(line+52) == 'N')
		{
			printf("%s",line);
			n++;
		}
	}
	cout<<"\n共有"<<n<<"个空客房\n\n\n"<<endl;
	fclose(fp);
	return 0;
}

//打印当前时刻有客人的房间记录
int print_full_Room()
{
	int m = -1;
	const char* filename_ = "room.txt";
	FILE* fp_ = fopen(filename_ ,"rb");
	if(fp_ == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf[512];
	while(! feof(fp_))
	{
		char* line = fgets(buf,512,fp_);
		m++;
	}
	fclose(fp_);
		
	const char* filename = "room.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
	char buf_[512];
	int n = 0;
	for(int i = 0;i < m;i++)
	{
		char* line = fgets(buf_,512,fp);
		if(*(line+52) == 'Y')
		{
			printf("%s",line);
			n++;
		}
	}
	cout<<"\n共有"<<n<<"个有客人的房间\n\n\n"<<endl;
	fclose(fp);
	return 0;
}

int main()
{

	char name[32];char id[18];char gender;char grad;char  nu[4];

	int m;

	cout<<"Welcome to hotel management system"<<endl;
//	save_Room();  //写入入最原始的房间数据 
//	save_guest(); //写入最原始的客人入住记录数据 

	while(1)
{
	cout<<  "请您按要求键入所需的操作:								  "<<endl;	
	cout<<  "键入数字1，将执行打印当前时刻房间记录					  "<<endl;
	cout<<  "键入数字2，将执行打印当前时刻的客人记录				  "<<endl;
	cout<<  "键入数字3，将执行打印当前时刻空房间记录				  "<<endl;
	cout<<  "键入数字4，打印当前时刻有客人的房间记录				  "<<endl;
	cout<<  "键入数字5，将执行写入新入住的客人记录并对房间的记录刷新  "<<endl;
	
	cout<<"请输入数字："<<endl;

	int sel;
	cin>>sel;

	getchar();

	switch(sel)
	{
	case 1:
		load_Room(); //读入最原始的房间数据，打印原始房间记录
		break;
	case 2:
		load_guest();//读入最原始的客人入住记录数据 ，打印原始客人记录
		break;

	case 3:
		cout<<"打印当前时刻空闲房间记录 "<<endl;
		cout<<"N代表没人，为空房间；Y代表有人，不是空房间。"<<endl;
		print_empty_Room();

		break;
	case 4:	
		cout<<"打印当前时刻有客人的房间记录 "<<endl;
		cout<<"N代表没人，为空房间；Y代表有人，不是空房间。"<<endl;
		print_full_Room();

		break;
	case 5:	
		cout<<"当前空房间有如下列表，新入住客人只能入住当前时刻的空房间，请录入新入住客人信息务必选择如下空房间"<<endl;
		
		cout<<"房间有ABCDE五个类型，每个类型6个房间，总共5*6 = 30个房间，房间号都是三个数字,如下："<<endl;
		cout<<"B,C,D,E类型房间号分别是11，12，13，14开头的，房间号尾号依次为1，2，3，4，5，6"<<endl;
		cout<<"A房间号（101，102，103，104，105，106）"<<endl;
		cout<<"B房间号（111，112，113，114，115，116）"<<endl;
		cout<<"C房间号（121，122，123，124，125，126）"<<endl;
		cout<<"D房间号（131，132，133，134，135，136）"<<endl;
		cout<<"E房间号（141，142，143，144，145，146）\n\n"<<endl; //B,C,D,E类型房间号分别是11，12，13，14开头的，房间号尾号依次为1，2，3，4，5，6

		//打印当前时刻空闲房间记录
		cout<<"打印当前时刻空闲房间记录 "<<endl;
		cout<<"N代表没人，为空房间；Y代表有人，不是空房间。\n"<<endl;
		print_empty_Room();

		cout<<"\n请键入姓名              （姓名最多32个字符）：                                 "<<endl;
		cin>> name;
		cout<<"\n请分别键入身份ID        （ID为18位数字）：                                         "<<endl;
		cin>> id;
		cout<<"\n请分别键入性别：gender  （性别用大写字母M和W表示，M代表man男性,W代表woman女性）"<<endl;
		cin>> gender;
		cout<<"\n请分别键入居住的房间类别（房间有ABCDE五个类型，请务必输入上面打印的空房间所对应的大写字母，否则会产生BUG）：				"<<endl;
		cin>> grad;
		cout<<"\n请分别键入房间号        （房间号为上面打印的空房间的数字）:				    "<<endl;
		cin>> nu;

	 
		new_save_guest(name,id,gender,grad,nu,system_time_year(),system_time_month(),system_time_day(),system_time_hour(),system_time_mintue(),system_time_second() );//name,id,gender,grad,nu,year month,day,hour,minute,second
																		
		//写新客人入住房间的信息
		save_new_Room(grad,nu);
		
		//获取输入新房间信息的字符串到字符串acc[]
		

		cout<<"新的客人记录录入成功，结果如下："<<endl;
	
		load_guest();   //*******************************************************************//

		//找出获取的字符串acc[]在原文件多少行（n）
		//删除Room记录中的指定行第n行,对房间的记录刷新
		printf("\n");
		Sleep(1982);
	    //gets_str_new_Room(grad,nu,add);

		m = gets_str_new_Room___load_getline_old_Room(grad,nu);
		
		newly_delete_n_Room(m);
		save_new_Room(grad,nu);

		cout<<"新刷新的房间记录，如下："<<endl;
		load_Room();

		break;

	default:
		cout<<"无效输入"<<endl;
		break;
	}
}	
	
	return 0;
}


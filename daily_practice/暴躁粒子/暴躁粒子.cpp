#include<iostream>
#include<windows.h>
#include<conio.h>
#include <graphics.h> 
#include<string>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_COUNT 10
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);




#define WIDTH      1024    //屏幕的宽 
#define HEIGHT     768     //屏幕的高 
#define NUM_MOVERS  800	   //小球数量 
#define FRICTION   0.96f   //摩擦力，阻尼系数 

//定义小球结构
struct Mover
{
	COLORREF  color;   //颜色 
	float     x,y;     //坐标 
	float     vX,vY;   //速度 
	float     radius;  //半径 
 } ;
 
 //定于全局变量
 Mover movers[NUM_MOVERS] ;    //
 int mouseX,mouseY;          //
 int prevMouseX ,prevMouseY; //
 int mouseVX,mouseVY;		 //
 int isMouseDown;			 //
 
 void startup()
 {
 	//设置随机种子 
 	srand((unsigned int)time(NULL));
 	
 	//初始化小球数组
	for(int i = 0;i<NUM_MOVERS;i++) 
	{
		movers[i].color = RGB(rand() % 256 ,rand() &256,rand() % 256);
		movers[i].x = rand()% WIDTH;
		movers[i].y = rand()% HEIGHT;
		movers[i].vX = float(cos(float(i))) * (rand() % 34);
		movers[i].vY = float(sin(float(i))) * (rand() % 34);
		movers[i].radius = (rand() % 34)/15.0;		
	}
 	
 	//初始化鼠标变量，当前鼠标坐标，上次鼠标都在画布中心
	 mouseX = prevMouseX = WIDTH / 2;
	 mouseY = prevMouseY = HEIGHT / 2;
	 
	 isMouseDown = 0;
	 
	 initgraph(WIDTH,HEIGHT) ;
	 BeginBatchDraw();
 }
 
 void show()
 {
 	clearrectangle(0,0,WIDTH - 1,HEIGHT - 1);
 	
 	for(int i = 0;i<NUM_MOVERS;i++)
	{
		//画小球 
		setcolor(movers[i].color);
		setfillstyle(movers[i].color);
		fillcircle(int (movers[i].x + 0.5),int (movers[i].y  + 0.5),int (movers[i].radius + 0.5));
	 } 
 	FlushBatchDraw() ;
 	Sleep(5);	
 }
 
 void updateWithoutInput()
 {
 	float toDist = WIDTH * 0.86;
 	float blowDist = WIDTH * 0.5;
 	float striDist = WIDTH * 0.125;
 	
 	mouseVX = mouseX - prevMouseX;
 	mouseVY = mouseY - prevMouseY;
 	
 	prevMouseX = mouseX;
 	prevMouseY = mouseY;
 	
 	for(int i = 0;i<NUM_MOVERS;i++)   //对所有小球进行遍历 
 	{
 		float x = movers[i].x;
 		float y = movers[i].y;
 		float vX = movers[i].vX;
 		float vY = movers[i].vY;
 		
 		float dX = x - mouseX;
 		float dY = y - mouseY;
 		float d = sqrt(dX * dX + dY * dY);
 		
 		if(d!=0)
 		{
 			dX = dX/d;
 			dY = dY/d;
		 }
 		else
 		{
 			dX = 0;
 			dY = 0;
		 }
 		
 		//若小球距离鼠标< toDist ,在此范围内小球就会受到鼠标的指引
		 if(d < toDist)
		 {
		 	//
		 	//
		 	float toACC = (1 - (d/toDist)) * WIDTH * 0.0014f;
		 	//
		 	vX = vX - dX * toACC;
		 	vY = vY - dY * toACC;
		 }
		 
		 //当鼠标左键按下，并且小球距离鼠标<blowDist（在打击范围内） 时会受到向外的力
		 if(isMouseDown && d < blowDist) 
		 {
		 	float blowACC = (1 - (d/ blowDist))  * 10;
		 	
		 	vX = vX + dX * blowACC + 0.5f - float(rand()) / RAND_MAX;
		 	vY = vY + dY * blowACC + 0.5f - float(rand()) / RAND_MAX;	
		 }
		 
		 if(d < striDist)
		 {
		 	float mACC = (1 - (d/striDist))	 * WIDTH * 0.00026f;
		 	vX = vX * FRICTION;
		 	vY = vY * FRICTION;
		 	
		 	float avgVX = abs(vX);
		 	float avgVY = abs(vY);
		 	
		 	float avgV = (avgVX + avgVY) * 0.5f;
		 	
		 	if(avgVX<0.1)
		 		vX = vX * float(rand())/ RAND_MAX * 3;
		 	if(avgVY < 0.1) 
		 		vY = vY * float(rand())/ RAND_MAX * 3;
		 		
		 	float sc = avgV * 0.45f;
		 	sc = max(min(sc, 3.5f),0.4f);
		 	movers[i].radius = sc;
		 	
		 	float nextX = x + vX;
		 	float nextY = y + vY;
		 	
		 	if(nextX > WIDTH)
		 	{
		 		nextX = WIDTH;
		 		vX    = -1*vX;
			 }
		 	else if(nextX<0)
		 	{
		 		nextX = 0;
		 		vX=-1*vX;
			 }
		 	if(nextY > HEIGHT)
		 	{
		 		nextY = HEIGHT;
		 		vY = -1 * vY;
			 }
			 else if(nextY < 0)
			 {
			 	nextY = 0;
			 	vY = -1*vY;
			 }
			 
			 movers[i].vX = vY;
			 movers[i].vY = vY;
			 movers[i].x  = nextX;
			 movers[i].y  = nextY;	 
		 }	
	 }
	}
 	void updateWithInput() 
 	{
 		MOUSEMSG m;
 		while(MouseHit())
 		{
 			m = GetMouseMsg() ;
 			if(m.uMsg == WM_MOUSEMOVE)
 			{
 				mouseX = m.x;
 				mouseY = m.y;
			 }
 			else if (m.uMsg == WM_LBUTTONDOWN)
 				isMouseDown = 1;
 			else if(m.uMsg == WM_LBUTTONUP)	
 				isMouseDown = 0;
		 }
	 }
 	
 	void gameover()
 	{
 		EndBatchDraw();
 		closegraph();
	 }
 	
	using namespace std;
/*=============== all the structures ===============*/
typedef struct Frame
{
	COORD position[2];
	int flag;
}Frame;
  /*=============== all the functions ===============*/
void SetPos(COORD a)// set cursor 
{

	HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}
void SetPos(int i, int j)// set cursor
{

	COORD pos={i, j};
	SetPos(pos);
}
 void HideCursor()

{

	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}

 

//把第y行，[x1, x2) 之间的坐标填充为 ch

void drawRow(int y, int x1, int x2, char ch)

{

	SetPos(x1,y);

	for(int i = 0; i <= (x2-x1); i++)

		cout<<ch;

}

 

//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch

void drawRow(COORD a, COORD b, char ch)

{

	if(a.Y == b.Y)

		drawRow(a.Y, a.X, b.X, ch);

	else

	{

		SetPos(0, 25);

		cout<<"error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等";

		system("pause");

	}

}

 

//把第x列，[y1, y2] 之间的坐标填充为 ch

void drawCol(int x, int y1, int y2, char ch)

{

	int y=y1;

	while(y!=y2+1)

	{

		SetPos(x, y);

		cout<<ch;

		y++;

	}

}

 

//在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch

void drawCol(COORD a, COORD b, char ch)

{

	if(a.X == b.X)

		drawCol(a.X, a.Y, b.Y, ch);

	else

	{

		SetPos(0, 25);

		cout<<"error code 02：无法填充列，因为两个坐标的横坐标(y)不相等";

		system("pause");

	}

}

 

//左上角坐标、右下角坐标、用row填充行、用col填充列

void drawFrame(COORD a, COORD  b, char row, char col)

{

	drawRow(a.Y, a.X+1, b.X-1, row);

	drawRow(b.Y, a.X+1, b.X-1, row);

	drawCol(a.X, a.Y+1, b.Y-1, col);

	drawCol(b.X, a.Y+1, b.Y-1, col);

}

 

void drawFrame(int x1, int y1, int x2, int y2, char row, char col)

{

	COORD a={x1, y1};

	COORD b={x2, y2};

	drawFrame(a, b, row, col);

}

 

void drawFrame(Frame frame, char row, char col)

{

	COORD a = frame.position[0];

	COORD b = frame.position[1];

	drawFrame(a, b, row, col);

}

 

void drawPlaying()

{

	drawFrame(0, 0, 48, 24, '=', '|');//	draw map frame;

	drawFrame(49, 0, 79, 4, '-', '|');//		draw output frame

	drawFrame(49, 4, 79, 9, '-', '|');//		draw score frame

	drawFrame(49, 9, 79, 20, '-', '|');//	draw operate frame

	drawFrame(49, 20, 79, 24, '-', '|');//	draw other message frame

	SetPos(52, 6);

	cout<<"得分：";

	SetPos(52, 7);

	cout<<"称号：";

	SetPos(52,10);

	cout<<"操作方式：";

	SetPos(52,12);

	cout<<"  a,s,d,w 控制战机移动。";

	SetPos(52,14);

	cout<<"  p 暂停游戏。";

	SetPos(52,16);

	cout<<"  e 退出游戏。";

}

 

//在[a, b)之间产生一个随机整数

int random(int a, int b)

{

	int c=(rand() % (a-b))+ a;

	return c;

}

 

//在两个坐标包括的矩形框内随机产生一个坐标

COORD random(COORD a, COORD b)

{

	int x=random(a.X, b.X);

	int y=random(a.Y, b.Y);

	COORD c={x, y};

	return c;

}

 

bool  judgeCoordInFrame(Frame frame, COORD spot)

{

	if(spot.X>=frame.position[0].X)

		if(spot.X<=frame.position[1].X)

			if(spot.Y>=frame.position[0].Y)

				if(spot.Y<=frame.position[0].Y)

					return true;

	return false;

}

 

void printCoord(COORD a)

{

	cout	<<"( "<<a.X<<" , "<<a.Y<<" )";

}

 

void printFrameCoord(Frame a)

{

	printCoord(a.position[0]);

	cout	<<" - ";

	printCoord(a.position[1]);

}

 

int drawMenu()

{

	SetPos(30, 1);

	cout<<"P l a n e  W a r";

	drawRow(3, 0, 79, '-');

	drawRow(5, 0, 79, '-');

	SetPos(28, 4);

	cout<<"w 和 s 选择， k 确定";

	SetPos(15, 11);

	cout<<"1. 简单的敌人";

	SetPos(15, 13);

	cout<<"2. 冷酷的敌人";

	drawRow(20, 0, 79, '-');

	drawRow(22, 0, 79, '-');

	SetPos(47, 11);

	cout<<"简单的敌人：";

	SetPos(51, 13);

	cout<<"简单敌人有着较慢的移动速度。";

	SetPos(24, 21);

	cout<<"制作：LJF神犇";

	int j=11;

	SetPos(12, j);

	cout<<">>";

 

	//drawFrame(45, 9, 79, 17, '=', '|');

 

	while(1)

	{	if( _kbhit() )

		{	

			char x=_getch();

			switch (x)

			{

			case 'w' :

					{	

						if( j == 13)

						{

							SetPos(12, j);

							cout<<"　";

							j = 11;

							SetPos(12, j);

							cout<<">>";

							SetPos(51, 13);

							cout<<"　　　　　　　　　　　　";

							SetPos(47, 11);

							cout<<"简单的敌人：";

							SetPos(51, 13);

							cout<<"简单敌人有着较慢的移动速度，比较容易对付";

						}

						break;

					}

			case 's' :

					{	

						if( j == 11 )

						{

							SetPos(12, j);

							cout<<"　";		

							j = 13;

							SetPos(12, j);

							cout<<">>";

							SetPos(51, 13);

							cout<<"　　　　　　　　　　　　　　";

							SetPos(47, 11);

							cout<<"冷酷的敌人：";

							SetPos(51, 13);

							cout<<"冷酷的敌人移动速度较快，难对付哟。";

						}

						break;

					}

			case 'k' :

					{	

						if (j == 8)	return 1;

						else return 2;

					}

			}

		}

	}

}

 

/* 

DWORD WINAPI MusicFun(LPVOID lpParamte)

{

	//DWORD OBJ;

	sndPlaySound(TEXT("bgm.wav"), SND_FILENAME|SND_ASYNC);

	return 0;

}

*/

 

 

/*================== the Game Class ==================*/

 

class Game

{

public:

	COORD position[10];

	COORD bullet[10];

	Frame enemy[8];

	int score;

	int rank;

	int rankf;

	string title;

	int flag_rank;

 

	Game ();

	

	//初始化所有

	void initPlane();

	void initBullet();

	void initEnemy();

 

	//初始化其中一个

	//void initThisBullet( COORD );

	//void initThisEnemy( Frame );

 

	void planeMove(char);

	void bulletMove();

	void enemyMove();

	

	//填充所有

	void drawPlane();

	void drawPlaneToNull();

	void drawBullet();

	void drawBulletToNull();

	void drawEnemy();

	void drawEnemyToNull();

 

	//填充其中一个

	void drawThisBulletToNull( COORD );

	void drawThisEnemyToNull( Frame );

 

	void Pause();

	void Playing();

	void judgePlane();

	void judgeEnemy();

 

	void Shoot();

 

	void GameOver();

	void printScore();

};

 

Game::Game()

{

	initPlane();

	initBullet();

	initEnemy();

	score = 0;

	rank = 25;

	rankf = 0;

	flag_rank = 0;

}

 

void Game::initPlane()

{

	COORD centren={39, 22};

	position[0].X=position[5].X=position[7].X=position[9].X=centren.X;

	position[1].X=centren.X-2;	

	position[2].X=position[6].X=centren.X-1;

	position[3].X=position[8].X=centren.X+1;

	position[4].X=centren.X+2;

	for(int i=0; i<=4; i++)

		position[i].Y=centren.Y;

	for(int i=6; i<=8; i++)

		position[i].Y=centren.Y+1;

	position[5].Y=centren.Y-1;

	position[9].Y=centren.Y-2;

}

 

void Game::drawPlane()

{

	for(int i=0; i<9; i++)

	{

		SetPos(position[i]);

		if(i!=5)

			cout<<"O";

		else if(i==5)

			cout<<"|";		

	}

}

 

void Game::drawPlaneToNull()

{

	for(int i=0; i<9; i++)

	{

		SetPos(position[i]);

		cout<<" ";

	}	

}

 

void Game::initBullet()

{

	for(int i=0; i<10; i++)

		bullet[i].Y = 30;

}

 

void Game::drawBullet()

{

	for(int i=0; i<10; i++)

	{

		if( bullet[i].Y != 30)

		{

			SetPos(bullet[i]);

			cout<<"^";	

		}

	}

}

 

void Game::drawBulletToNull()

{

	for(int i=0; i<10; i++)

		if( bullet[i].Y != 30 )

			{

				COORD pos={bullet[i].X, bullet[i].Y+1};

				SetPos(pos);

				cout<<" ";

			}	

}

 

void Game::initEnemy()

{

	COORD a={1, 1};

	COORD b={45, 15};

	for(int i=0; i<8; i++)

	{

		enemy[i].position[0] = random(a, b);

		enemy[i].position[1].X = enemy[i].position[0].X + 3;

		enemy[i].position[1].Y = enemy[i].position[0].Y + 2;

	}

}

 

void Game::drawEnemy()

{

	for(int i=0; i<8; i++)

		drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');

}

 

void Game::drawEnemyToNull()

{

	for(int i=0; i<8; i++)

	{

		drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');

	}		

}

 

void Game::Pause()

{

	SetPos(61,2);

	cout<<"               ";

	SetPos(61,2);

	cout<<"暂停中...";

	char c=_getch();

	while(c!='p')

		c=_getch();

	SetPos(61,2);

	cout<<"         ";

}

 

void Game::planeMove(char x)

{

	if(x == 'a')

		if(position[1].X != 1)

			for(int i=0; i<=9; i++)

				position[i].X -= 2;

				

	if(x == 's')

		if(position[7].Y != 23)

			for(int i=0; i<=9; i++)

				position[i].Y += 1;

 

	if(x == 'd')

		if(position[4].X != 47)

			for(int i=0; i<=9; i++)

				position[i].X += 2;

 

	if(x == 'w')

		if(position[5].Y != 3)

			for(int i=0; i<=9; i++)

				position[i].Y -= 1;

}

 

void Game::bulletMove()

{

	for(int i=0; i<10; i++)

	{

		if( bullet[i].Y != 30)

		{

			bullet[i].Y -= 1;

			if( bullet[i].Y == 1 )

			{

				COORD pos={bullet[i].X, bullet[i].Y+1};

				drawThisBulletToNull( pos );

				bullet[i].Y=30;

			}

				

		}

	}

}

 

void Game::enemyMove()

{

	for(int i=0; i<8; i++)

	{

		for(int j=0; j<2; j++)

			enemy[i].position[j].Y++;

 

		if(24 == enemy[i].position[1].Y)

		{

			COORD a={1, 1};

			COORD b={45, 3};

			enemy[i].position[0] = random(a, b);

			enemy[i].position[1].X = enemy[i].position[0].X + 3;

			enemy[i].position[1].Y = enemy[i].position[0].Y + 2;

		}

	}

}

 

void Game::judgePlane()

{

	for(int i = 0; i < 8; i++)

		for(int j=0; j<9; j++)

			if(judgeCoordInFrame(enemy[i], position[j]))

			{

				SetPos(62, 1);

				cout<<"坠毁";

				drawFrame(enemy[i], '+', '+');

				Sleep(1000);

				GameOver();

				break;

			}

}

 

void Game::drawThisBulletToNull( COORD c)

{

	SetPos(c);

	cout<<" ";

}

 

void Game::drawThisEnemyToNull( Frame f )

{

	drawFrame(f, ' ', ' ');

}

 

void Game::judgeEnemy()

{

	for(int i = 0; i < 8; i++)

		for(int j = 0; j < 10; j++)

			if( judgeCoordInFrame(enemy[i], bullet[j]) )

			{

				score += 5;

				drawThisEnemyToNull( enemy[i] );

				COORD a={1, 1};

				COORD b={45, 3};

				enemy[i].position[0] = random(a, b);

				enemy[i].position[1].X = enemy[i].position[0].X + 3;

				enemy[i].position[1].Y = enemy[i].position[0].Y + 2;					

				drawThisBulletToNull( bullet[j] );

				bullet[j].Y = 30;

			}

}

 

void Game::Shoot()

{

	for(int i=0; i<10; i++)

		if(bullet[i].Y == 30)

		{

			bullet[i].X = position[5].X;

			bullet[i].Y = position[5].Y-1;

			break;

		}

}

 

void Game::printScore()

{

	if(score == 120 && flag_rank == 0)

	{

		rank -= 3;

		flag_rank = 1;

	}

 

	else if( score == 360 && flag_rank == 1)

	{

		rank -= 5;

		flag_rank = 2;

	}

	else if( score == 480 && flag_rank == 2)

	{

		rank -= 5;

		flag_rank = 3;

	}

	int x=rank/5;

	SetPos(60, 6);

	cout<<score;

 

	if( rank!=rankf )

	{

		SetPos(60, 7);

		if( x == 5)

			title="初级飞行员";

		else if( x == 4)

			title="中级飞行员";

		else if( x == 3)

			title="高级飞行员";

		else if( x == 2 )

			title="王牌飞行员";

		cout<<title;

	}

	rankf = rank;

}

 

void Game::Playing()

{

	//HANDLE MFUN;

	//MFUN= CreateThread(NULL, 0, MusicFun, NULL, 0, NULL); 

 

	drawEnemy();

	drawPlane();

 

	int flag_bullet = 0;

	int flag_enemy = 0;

 

	while(1)

	{

		Sleep(8);

		if(_kbhit())

		{

			char x = _getch();

			if ('a' == x || 's' == x || 'd' == x || 'w' == x)

			{

				drawPlaneToNull();

				planeMove(x);

				drawPlane();

				judgePlane();

			}			

			else if ('p' == x)

				Pause();

			else if( 'k' == x)

				Shoot();

			else if( 'e' == x)

			{

				//CloseHandle(MFUN);

				GameOver();

				break;

			}

				

		}

		/* 处理子弹 */

		if( 0 == flag_bullet )

		{

			bulletMove();

			drawBulletToNull();

			drawBullet();

			judgeEnemy();

		}			

		flag_bullet++;

		if( 5 == flag_bullet )

			flag_bullet = 0;

 

		/* 处理敌人 */

		if( 0 == flag_enemy )

		{

			drawEnemyToNull();

			enemyMove();			

			drawEnemy();

			judgePlane();

		}

		flag_enemy++;

		if( flag_enemy >= rank )

			flag_enemy = 0;

 

		/* 输出得分 */

		printScore();

	}

}

 

void Game::GameOver()

{

	system("cls");				

	COORD p1={28,9};

	COORD p2={53,15};

	drawFrame(p1, p2, '=', '|');

	SetPos(36,12);

	string str="Game Over!";

	for(int i=0; i < str.size(); i++)

	{

		Sleep(80);

		cout<<str[i];

	}

	Sleep(1000);

	system("cls");

	drawFrame(p1, p2, '=', '|');

	SetPos(31, 11);

	cout<<"击落敌机："<<score/5<<" 架";

	SetPos(31, 12);

	cout<<"得　　分："<<score;

	SetPos(31, 13);

	cout<<"获得称号："<<title;

	SetPos(30, 16);

	Sleep(1000);

	cout<<"继续？ 是（y）| 否（n）制作：DPF";

as:

	char x=_getch();

	if (x == 'n')

		exit(0);

	else if (x == 'y')

	{

		system("cls");

		Game game;

		int a = drawMenu();

		if(a == 2)

			game.rank = 20;

		system("cls");

		drawPlaying();

		game.Playing();

	}

	else goto as;

}


void menu()
{
	printf("************************\n");
	printf("****    1. play     ****\n");
	printf("****    0. exit     ****\n");
	printf("************************\n");
}

void game()
{
	//甯冪疆濂介浄鐨勪俊鎭?
	char mine[ROWS][COLS] = { 0 };//'0'
	//鎺掓煡鍑洪浄鐨勪俊鎭?
	char show[ROWS][COLS] = { 0 };//'*'

	//鍒濆鍖栨鐩?
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//鎵撳嵃妫嬬洏
	DisplayBoard(show, ROW, COL);
	//甯冪疆闆?
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//鎵浄
	FindMine(mine, show, ROW, COL);
}
//娴嬭瘯鎵浄浠ｇ爜
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//鎵撳嵃鑿滃崟
		menu();
		printf("璇烽�夋嫨:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("閫�鍑烘父鎴廫n");
			break;
		default:
			printf("閫夋嫨閿欒锛岃閲嶆柊閫夋嫨!\n");
			break;
		}
	} while (input);
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------------------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

	/*int i = 0;
	int j = 0;
	for(i=-1; i<=1; i++)
	{
	for(j=-1; j<=1; j++)
	{
	mine[x+i][y+j];
	}
	}*/
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("璇疯緭鍏ヨ鎺掓煡鍧愭爣锛?\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("寰堥仐鎲撅紝鎮ㄨ鐐告浜哱n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//1+48=49-'1'
				//1+'0'=49-'1'
				//4+'0'='4'
				//count+'0'
				//
				//缁熻x,y鍧愭爣鍛ㄥ洿鏈夊嚑涓浄
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("杈撳叆鍧愭爣闈炴硶\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("鎭枩浣犳帓闆锋垚鍔焅n");
		DisplayBoard(mine, row, col);
	}
}




 	int main()
 	{
		int a;
		int n;
		Game game;

		printf("欢迎来到游戏小屋 1扫雷 2暴躁粒子 3扫雷游戏\n");
		printf("请输入数字选择您需要进入的游戏\n");
		scanf("%d",&n);


		switch(n)
		{
		case 1:
			printf("欢迎来到打飞机游戏：\n");
					srand((int)time(0));	//随机种子
			HideCursor();	//隐藏光标
			
			a = drawMenu();
			if(a == 2)
				game.rank = 20;
			system("cls");
			drawPlaying();
			game.Playing();
			break;

		case 2:

			printf("欢迎来到暴躁粒子：\n");
				startup();
 			while(1)
 			{
 				show();
 				updateWithInput();
 				updateWithoutInput();
			 }
 			gameover();
			break;
			
		case 3:
			printf("欢迎来到扫雷游戏：\n");
			test();
			system("pause");

			break;

		default:
		cout<<"无效输入"<<endl;
		break;


		}

 		
 		return 0;
	 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

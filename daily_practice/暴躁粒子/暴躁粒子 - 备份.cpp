#include <graphics.h> 
#include <math.h>
#include <time.h>

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
 	
 	int main()
 	{
 		startup();
 		while(1)
 		{
 			show();
 			updateWithInput();
 			updateWithoutInput();
		 }
 		gameover();
 		return 0;
	 }

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

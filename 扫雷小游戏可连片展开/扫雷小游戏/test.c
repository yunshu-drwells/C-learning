#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

static void menu()
{
	printf("*****************\n");
	printf("**** 1.Play  ****\n");
	printf("****  0.Exit ****\n");
	printf("*****************\n");
	printf("请输入对应数字的选择:>\n");
}

static Initshow(char show[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			show[i][j] = set;
		}
	}
}

static void game(char show[ROWS][COLS], char board[ROWS][COLS], int rows, int cols)
{
	InitBoard(board, ROWS, COLS, '0');
	SetMine(board, ROWS, COLS, '1');//随机放置好雷
	//DisplayBoard(board, ROWS, COLS);

	int x = 0;
	int y = 0;
	int flag = 1;
	DisplayBoard(show, ROWS, COLS);

	do
	{
		printf("请输入要扫雷的坐标 :>\n");
		(void)scanf("%d%d", &x, &y);

		flag = FindMine(board, show, x, y);
		DisplayBoard(show, rows, cols);

	} while (flag);
	//游戏失败时
	//打印雷
	if (flag == 0)
		DisplayBoard(board, ROWS, COLS);

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	char board[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	Initshow(show, ROWS, COLS, '*');
	//DisplayShow(show, ROWS, COLS);

	do
	{
		menu();
		(void)scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			game(show, board, ROWS, COLS);
			break;
		default:
			break;
		}

	} while (input);
	return 0;
}
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

static Initshow(char show[ROW][COL], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			show[i][j] = set;
		}
	}
}

static void DisplayShow(char show[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n");
	for (i = 0; i <= col; i++)
		printf("%2d", i);
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%2d ", i + 1);
		for (j = 0; j < col; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}

static void game(char show[ROW][COL], char board[ROWS][COLS], int row, int col)
{
	InitBoard(board, ROWS, COLS, '0');
	SetMine(board, ROWS, COLS, '1');//随机放置好雷
	//DisplayBoard(board, ROWS, COLS);

	int x = 0;
	int y = 0;
	int flag = 1;
	DisplayShow(show, ROW, COL);

	do
	{
		printf("请输入要扫雷的坐标 :>\n");
		(void)scanf("%d%d", &x, &y);

		flag = FindMine(board, show, x, y);
		DisplayShow(show, row, col);

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
	char show[ROW][COL] = { 0 };

	Initshow(show, ROW, COL, '*');
	//DisplayShow(show, ROW, COL);

	do
	{
		menu();
		(void)scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			game(show, board, ROW, COL);
			break;
		default:
			break;
		}

	} while (input);
	return 0;
}
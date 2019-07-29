#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 12
#define COL 12

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 30

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col, char set);
int FindMine(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y);



# three-son-chess
function the three-son chess
void menu()
{
	printf("#################################\n");
	printf("###1.single play  2.duo player###\n");
	printf("#########    0.exit   ###########\n");
	printf("#################################\n");
}
#include "game.h"
void game1()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	int ret;
	while (1)
	{
		Player1(board, ROW, COL);
		ret=Winner(board, ROW, COL);
		if (ret == 0)//玩家赢
		{
			printf("玩家赢\n");
			break;
		}
		else if (ret == 2)//平局
		{
			printf("平局\n");
			break;
		}
		printf("\n");
		Computer(board, ROW, COL);
		ret = Winner(board, ROW, COL);
		if (ret == 1)//电脑赢
		{
			printf("电脑赢\n");
			break;
		}
		else if (ret == 2)//平局
		{
			printf("平局\n");
			break;
		}
	}
}

void game2()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	int ret;
	while (1)
	{
		Player1(board, ROW, COL);
		ret = Winner(board, ROW, COL);
		if (ret == 0)//玩家1赢
		{
			printf("玩家1赢\n");
			break;
		}
		else if (ret == 2)//平局
		{
			printf("平局\n");
			break;
		}
		printf("\n");//玩家1判定

		Player2(board, ROW, COL);
		ret = Winner(board, ROW, COL);
		if (ret == 4)//玩家2赢
		{
			printf("玩家2赢\n");
			break;
		}
		else if (ret == 2)//平局
		{
			printf("平局\n");
			break;
		}
		printf("\n");//玩家2判定
	}
}

void testbug()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	int ret;
	while (1)
	{
		int ret;
		Player1(board, ROW, COL);
		ret = Winner(board, ROW, COL);
		if (ret == 0)
		{
			printf("玩家1赢\n");
			break;
		}
		else if (ret == 2)
		{
			printf("平局\n");
			break;
		}
		printf("\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		printf("\n");
		menu();
		printf("请选择>：");
		scanf("%d", &input);
		if (input == 6)
			testbug();
		switch (input)
		{
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}
	} while (input);
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col)//boar[][]括号内部必须写常量表达式
{
	int i;
	int j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{	
			printf(" %c ", board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if (i<row-1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Player1(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x;
		int y;
		printf("请输入坐标>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
				printf("该区已被占用，请重新输入\n");
		}
		else
		{
			printf("输入坐标不合法，请重新输入\n");
		}
	}
	DisplayBoard(board, ROW, COL);
}

void Player2(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x;
		int y;
		printf("请输入坐标>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '+';
				break;
			}
			else
				printf("该区已被占用，请重新输入\n");
		}
		else
		{
			printf("输入坐标不合法，请重新输入\n");
		}
	}
	DisplayBoard(board, ROW, COL);
}

void Computer(char board[ROW][COL],int row, int col)
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	DisplayBoard(board, ROW, COL);
}

int Winner(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	//判断玩家1赢

	{
		for (i = 0;i < row; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == '*')
				return 0;
		}
		for (j = 0;j < col;j++)
		{
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == '*')
				return 0;
		}
		for (i = 0;i < row; i++)
		{
			for (j = 0;j < col;j++)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i - 1][j - 1] && board[i][j] == '*')
					return 0;
			}
		}
		for (i = 0;i < row; i++)
		{
			for (j = 0;j < col;j++)
			{
				if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i + 1][j - 1] && board[i][j] == '*')
					return 0;
			}
		}
	}
	//判定玩家2赢

	{
		for (i = 0;i < row; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == '+')
				return 4;
		}
		for (j = 0;j < col;j++)
		{
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == '+')
				return 4;
		}
		for (i = 0;i < row; i++)
		{
			for (j = 0;j < col;j++)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i - 1][j - 1] && board[i][j] == '+')
					return 4;
			}
		}

		for (i = 0;i < row; i++)
		{
			for (j = 0;j < col;j++)
			{
				if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i + 1][j - 1] && board[i][j] == '+')
					return 0;
			}
		}
	}
	//判断电脑赢

	{
		for (i = 0;i < row; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == '#')
				return 1;
		}
		for (j = 0;j < col;j++)
		{
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == '#')
				return 1;
		}
		for (i = 0;i < row;i++)
		{
			for (j = 0;j < col;j++)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i - 1][j - 1] && board[i][j] == '#')
					return 1;
			}
		}
		for (i = 0;i < row;i++)
		{
			for (j = 0;j < col;j++)
			{
				if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i + 1][j - 1] && board[i][j] == '#')
					return 0;
			}
		}
	}
	//判断继续
		for (i = 0;i < row; i++)
		{
			for (j = 0;j < col;j++)
			{
				if (board[i][j] == ' ')
					return 3;
			}
		}
	return 2;//平局
}

#define ROW 3
#define COL 3
void DisplayBoard(char board[ROW][COL],int row,int col);
void InitBoard(char board[ROW][COL],int row,int col);
void Player1(char board[ROW][COL], int row, int col);
void Player2(char board[ROW][COL], int row, int col);
void Computer(char board[ROW][COL], int row, int col);
int Winner(char board[ROW][COL],int row, int col);

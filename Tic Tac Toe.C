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

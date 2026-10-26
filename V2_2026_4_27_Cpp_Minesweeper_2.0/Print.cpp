
#include"Print.h"

void PrintBoard(char board[EASY][EASY])
{
	int dif = EASY;
	printf("   ");
	for (int i = 1; i <= dif; i++)
		printf("%-2d ", i);
	printf("\n");
	for (int i = 0; i < dif; i++)
	{
		setColor(7);
		printf("%-3d", i + 1);
		for (int j = 0; j < dif; j++)
		{
			if (board[i][j] == '*')
			{
				setColor(7);//设置为默认的颜色
				printf("%-3c", board[i][j]);
			}
			else if (board[i][j] == '#')
			{
				setColor(12);
				printf("%-3c", board[i][j]);
			}
			else
			{
				setColor((int)(board[i][j] - '0' + 1));
				printf("%-3c", board[i][j]);
			}


		}
		printf("\n");
	}
	setColor(7);
}

void PrintBoard(char board[MID][MID])
{
	int dif = MID;
	printf("   ");
	for (int i = 1; i <= dif; i++)
		printf("%-2d ", i);
	printf("\n");
	for (int i = 0; i < dif; i++)
	{
		setColor(7);
		printf("%-3d", i + 1);
		for (int j = 0; j < dif; j++)
		{
			if (board[i][j] == '*')
			{
				setColor(7);//设置为默认的颜色
				printf("%-3c", board[i][j]);
			}
			else if (board[i][j] == '#')
			{
				setColor(12);
				printf("%-3c", board[i][j]);
			}
			else
			{
				setColor((int)(board[i][j] - '0' + 1));
				printf("%-3c", board[i][j]);
			}


		}
		printf("\n");
	}
	setColor(7);
}
void PrintBoard(char board[HARD][HARD])
{
	int dif = HARD;
	printf("   ");
	for (int i = 1; i <= dif; i++)
		printf("%-2d ", i);
	printf("\n");
	for (int i = 0; i < dif; i++)
	{
		setColor(7);
		printf("%-3d", i + 1);
		for (int j = 0; j < dif; j++)
		{
			if (board[i][j] == '*')
			{
				setColor(7);//设置为默认的颜色
				printf("%-3c", board[i][j]);
			}
			else if (board[i][j] == '#')
			{
				setColor(12);
				printf("%-3c", board[i][j]);
			}
			else
			{
				setColor((int)(board[i][j] - '0' + 1));
				printf("%-3c", board[i][j]);
			}


		}
		printf("\n");
	}
	setColor(7);
}
void PrintMINE(char MINE[EASY + 2][EASY + 2])
{
	int dif = EASY;
	printf("  ");
	for (int i = 1; i <= dif; i++)
		printf("%-2d ", i);
	printf("\n");
	for (int i = 1; i <= dif; i++)
	{
		printf("%-2d", i);
		for (int j = 1; j <= dif; j++)
		{
			printf("%-3c", MINE[i][j]);
		}
		printf("\n");
	}
}
void PrintMINE(char MINE[MID + 2][MID + 2])
{
	int dif = MID;
	printf("  ");
	for (int i = 1; i <= dif; i++)
		printf("%-2d ", i);
	printf("\n");
	for (int i = 1; i <= dif; i++)
	{
		printf("%-2d", i);
		for (int j = 1; j <= dif; j++)
		{
			printf("%-3c", MINE[i][j]);
		}
		printf("\n");
	}
}
void PrintMINE(char MINE[HARD + 2][HARD + 2])
{
	int dif = HARD;
	printf("  ");
	for (int i = 1; i <= dif; i++)
		printf("%-2d ", i);
	printf("\n");
	for (int i = 1; i <= dif; i++)
	{
		printf("%-2d", i);
		for (int j = 1; j <= dif; j++)
		{
			printf("%-3c", MINE[i][j]);
		}
		printf("\n");
	}
}

void setColor(int color)//设置颜色的函数
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}


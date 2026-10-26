#pragma once
#include"Print.h"

void PrintScore(int dif)
{

}

void PrintBoard(
	char* board,
	int dif
)
{
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
			if (*(board+i*dif+j) == '*')
			{
				setColor(7);//设置为默认的颜色
				printf("%-3c", *(board + i * dif + j));
			}
			else if (*(board + i * dif + j) == '#')
			{
				setColor(12);
				printf("%-3c", *(board + i * dif + j));
			}
			else
			{
				setColor(
					(int)
					(*(board + i * dif + j) - '0' + 1)
				);
				printf(
					"%-3c",
					*(board + i * dif + j)
				);
			}


		}
		printf("\n");
	}
	setColor(7);
}


void PrintMine
(
	char* MINE,
	int dif
)
{

	for (int i = 0; i < (dif + 2) * (dif + 2); i++)
		printf("%d %c\n", i, *(MINE + i));

}

void setColor(int color)//设置颜色的函数
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}


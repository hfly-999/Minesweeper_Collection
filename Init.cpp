#include"Init.h"



void InitBoard(char board[EASY][EASY])
{
	int dif = EASY;
	printf("初始化棋盘...\n");
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
		{
			board[i][j] = '*';
		}
	printf("初始化棋盘成功!\n");
}

void InitBoard(char board[MID][MID])
{
	int dif = MID;
	printf("初始化棋盘...\n");
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
		{
			board[i][j] = '*';
		}
	printf("初始化棋盘成功!\n");
}
void InitBoard(char board[HARD][HARD])
{
	int dif = HARD;
	printf("初始化棋盘...\n");
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
		{
			board[i][j] = '*';
		}
	printf("初始化棋盘成功!\n");
}

void InitMINE(char MINE[EASY + 2][EASY + 2])
{
	printf("正在埋雷...\n");
	int dif = EASY;
	
	for (int i = 0; i < dif + 2; i++)
		for (int j = 0; j < dif + 2; j++)
			MINE[i][j] = '0';
	while (true)
	{
		srand((unsigned int)time(NULL));
		int x = rand() % dif;
		int y = rand() % dif;//生成0~dif-1的随机数
		if (MINE[x][y] == '#')
			continue;
		else MINE[x + 1][y + 1] = '#';//1~dif产生雷
		dif--;
		if (dif == 0)return;
	}
	printf("埋雷成功\n");
}
void InitMINE(char MINE[MID + 2][MID + 2])
{
	printf("正在埋雷...\n");
	int dif = MID;

	for (int i = 0; i < dif + 2; i++)
		for (int j = 0; j < dif + 2; j++)
			MINE[i][j] = '0';
	while (true)
	{
		srand((unsigned int)time(NULL));
		int x = rand() % dif;
		int y = rand() % dif;//生成0~dif-1的随机数
		if (MINE[x][y] == '#')
			continue;
		else MINE[x + 1][y + 1] = '#';//1~dif产生雷
		dif--;
		if (dif == 0)return;
	}
	printf("埋雷成功\n");
}
void InitMINE(char MINE[HARD + 2][HARD + 2])
{
	printf("正在埋雷...\n");
	int dif = HARD;

	for (int i = 0; i < dif + 2; i++)
		for (int j = 0; j < dif + 2; j++)
			MINE[i][j] = '0';
	while (true)
	{
		srand((unsigned int)time(NULL));
		int x = rand() % dif;
		int y = rand() % dif;//生成0~dif-1的随机数
		if (MINE[x][y] == '#')
			continue;
		else MINE[x + 1][y + 1] = '#';//1~dif产生雷
		dif--;
		if (dif == 0)return;
	}
	printf("埋雷成功\n");
}



void InitIsClick(bool IsClick[EASY][EASY])
{
	int dif = EASY;
	printf("正在初始化用户输入...\n");
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
			IsClick[i][j] = false;
	printf("初始化用户输入成功\n");
}

void InitIsClick(bool IsClick[MID][MID])
{
	int dif = MID;
	printf("正在初始化用户输入...\n");
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
			IsClick[i][j] = false;
	printf("初始化用户输入成功\n");
}

void InitIsClick(bool IsClick[HARD][HARD])
{
	int dif = HARD;
	printf("正在初始化用户输入...\n");
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
			IsClick[i][j] = false;
	printf("初始化用户输入成功\n");
}
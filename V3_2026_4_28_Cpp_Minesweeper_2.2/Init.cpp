#pragma once
#include"Init.h"

void InitBoard(
	char* board,
	int dif
)
{
	printf("初始化棋盘...\n");
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
		{
			*(board+i*dif+j) = '*';
		}
	printf("初始化棋盘成功!\n");
	Sleep(100);
}

void InitMINE(
	char* MINE,
	int dif
){

	printf("正在埋雷...\n");
	Sleep(200);

	for (int i = 0; i < dif + 2; i++)
		for (int j = 0; j < dif + 2; j++)
			*(MINE + i * (dif+2) + j) = '\0';
			//MINE[i][j] = '0';
	int count;
	if (dif == EASY)
		count = EASY_MINE_COUNT;
	else if (dif == MID)
		count = MID_MINE_COUNT;
	else count = HARD_MINE_COUNT;

	while (true)
	{

		int x = rand() % dif;
		int y = rand() % dif;//生成0~dif-1的随机数
		if (*(MINE + (x + 1) * (dif + 2) + (y + 1 )) == '#')
			continue;
		else
			*(MINE + (x + 1) * (dif + 2) + (y + 1 )) = '#';//1~dif产生雷
		count--;
		if (count == 0)return;
	}
	printf("埋雷成功\n");
	Sleep(200);
}

void InitIsClick(
	bool* IsClick,
	int dif
)
{
	printf("正在初始化用户输入...\n");
	Sleep(200);
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
			*(IsClick + i * dif + j) = false;
	printf("初始化用户输入成功\n");
	Sleep(200);
}

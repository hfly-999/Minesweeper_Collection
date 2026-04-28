#pragma once
#include"Game.h"

void Game()
{
	int input = 0;
	do
	{
		printf("请输入1/0:(1表示开始游戏,0表示退出游戏)\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			system("cls");
			printf("退出成功!!");
			break;
		case 1:
			Menu();//进入游戏菜单
			break;
		default:
			input = 1;
			printf("输入非法,请重新输入!!\n");
			break;
		}

	} while (input);

}

void Menu()
{
	system("cls");
	while (true)
	{
		printf("请选择难度(1/2/3,输入0以退出到主菜单):\n");
		int dif = 0;
		scanf("%d", &dif);
		system("cls");
		char* board;
		char* MINE;
		bool* IsClick;
		if (dif == 0)
		{
			system("cls");
			printf("退出到主菜单");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			printf("\n");
			return;
		}
		else if (dif == 1)
		{
			dif = EASY;//第一档难度改成EASY
			board=(char*)malloc(dif * dif *sizeof(char));
			MINE = (char*)malloc((dif + 2) * (dif + 2) * sizeof(char));
			IsClick=(bool*)malloc(dif * dif * sizeof(bool));
			
		}
		else if (dif == 2)
		{
			dif = MID;//第二档难度改成MID
			board = (char*)malloc(dif * dif * sizeof(char));
			MINE = (char*)malloc((dif + 2) * (dif + 2) * sizeof(char));
			IsClick = (bool*)malloc(dif * dif * sizeof(bool));
			
		}
		else if (dif == 3)
		{
			dif = HARD;//第二档难度改成MID
			board = (char*)malloc(dif * dif * sizeof(char));
			MINE = (char*)malloc((dif + 2) * (dif + 2) * sizeof(char));
			IsClick = (bool*)malloc(dif * dif * sizeof(bool));
		}
		else
		{
			printf("难度错误,请重新选择难度!\n");
			break;
		}
		if (board && MINE && IsClick == NULL)
		{
			system("cls");
			printf("内存分配失败,即将回到主菜单\n");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			Sleep(100);
			printf(".");
			Sleep(400);
		}
		InitBoard(board, dif);
		InitMINE(MINE, dif);
		InitIsClick(IsClick, dif);
		
		//游戏逻辑
		printf("初始化成功!!正在进入游戏...");
		Sleep(750);
		system("cls");
		game(board, MINE, IsClick, dif);

	}
	
}

void game(
	char* board,
	char* MINE,
	bool* IsClick,
	int dif
)
{
	while (true)
	{
		PrintScore(dif);

		PrintBoard(board,dif);//打印棋盘
		printf("请输入行和列:\n");//提示用户输入
		int x;
		int y;
		bool IsDefeat = false;
		scanf("%d%d", &x, &y);
		system("cls");
		printf("用户点击的位置为(%d,%d)\n", x, y);
		bool IsOperateSuccess = Click(x, y, board, MINE, IsClick, IsDefeat,dif);


		if (IsDefeat == true)//如果被打败了
		{
			EndingBoard(board, MINE,dif);
			PrintBoard(board,dif);
			printf("很遗憾,你输了!\n");
			

			return;
		}
		if (IsWin(board, MINE, IsClick,dif))//如果赢了
		{
			EndingBoard(board, MINE,dif);
			PrintBoard(board,dif);
			printf("*****恭喜你,胜利!*****\n");
			return;
		}
		if (IsOperateSuccess == false)
		{
			printf("输入非法地址,请重新输入!\n");
		}

	}

}

bool Click(
	int x,
	int y,
	char* board,
	char* MINE,
	bool* IsClick,
	bool& IsDefeat,
	int dif
){//泛型
	//输入非法的情况
	if (x<1 || x>dif)return false;
	if (y<1 || y>dif)return false;
	if (
		*(IsClick + (x - 1) * dif + (y - 1))//IsClick[x-1][y-1]
		==
		true
		)return false;
	*(IsClick + (x - 1) * dif + (y - 1)) = true;//IsClick[x-1][y-1]=true
	if (
		*(MINE + x * (dif+2) + y)
		==
		'#'
	){
		return IsDefeat = true;
	}
	*(board + (x - 1) * dif + (y - 1)) = '0';//borad[x-1][y-1]='\0'
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (
				*(MINE + i * (dif + 2) + j)//MINE[i][j]=='#'
				==
				'#'
				)
				*(board + (x - 1) * dif + (y - 1)) += 1;//borad[x-1][y-1]++
	if (
		*(board + (x - 1) * dif + (y - 1))//borad[x - 1][y - 1]=='\0'
		==
		'0'
		)
	{
		Click(x - 1, y, board, MINE, IsClick, IsDefeat, dif);
		Click(x + 1, y, board, MINE, IsClick, IsDefeat, dif);
		Click(x, y - 1, board, MINE, IsClick, IsDefeat, dif);
		Click(x, y + 1, board, MINE, IsClick, IsDefeat, dif);
	}


	return true;
}

void EndingBoard(
	char* board,
	char* MINE,
	int dif
)
{
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
		{
			if (*(MINE + (i + 1) * (dif+2) + j + 1) == '#')
				*(board+i*dif+j) = '#';
			else
			{
				*(board + i * dif + j) = '0';
				for (int m = i; m <= i + 2; m++)
					for (int n = j; n <= j + 2; n++)
						if (*(MINE + m * (dif + 2) + n) == '#')
							*(board + i * dif + j) += 1;
			}
		}
}

bool IsWin(
	char* board,
	char* MINE,
	bool* IsClick,
	int dif
)
{

	int count = 0;
	for (int i = 0; i < dif * dif; i++)
		if (IsClick[i] == true)count++;
	switch (dif)
	{
	case EASY:
		if (EASY * EASY - EASY_MINE_COUNT == count)
		{
			//score++;
			return true;
		}

		break;
	case MID:
		if (MID * MID - MID_MINE_COUNT == count)
		{
			//score++;
			return true;
		}
		break;
	case HARD:
		if (HARD * HARD - HARD_MINE_COUNT == count)
		{
			//score++;
			return true;
		}
		break;
	}
	
	return false;
}




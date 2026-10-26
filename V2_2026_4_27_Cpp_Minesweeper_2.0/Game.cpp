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
	while (true)
	{
		system("cls");
		printf("请选择难度(1/2/3):\n");
		int dif = 0;
		scanf("%d", &dif);
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
			char board[EASY][EASY];
			InitBoard(board);

			char MINE[EASY + 2][EASY + 2];
			InitMINE(MINE);

			bool IsClick[EASY][EASY];
			InitIsClick(IsClick);
			//游戏逻辑
			game(board, MINE, IsClick);
			break;

		}
		else if (dif == 2)
		{
			char board[MID][MID];
			InitBoard(board);
			char MINE[MID + 2][MID + 2];
			InitMINE(MINE);
			bool IsClick[MID][MID];
			InitIsClick(IsClick);
			game(board, MINE, IsClick);
			break;
		}
		else if (dif == 3)
		{
			char board[HARD][HARD];
			InitBoard(board);
			char MINE[HARD + 2][HARD + 2];
			InitMINE(MINE);
			bool IsClick[HARD][HARD];
			InitIsClick(IsClick);
			game(board, MINE, IsClick);
			break;
		}
		else
		{
			printf("难度错误,请重新选择难度!\n");
		}
	}
	
}



void game(
	char board[EASY][EASY],
	char MINE[EASY + 2][EASY + 2],
	bool IsClick[EASY][EASY]
)
{
	while (true)
	{
		system("cls");
		PrintBoard(board);
		printf("请输入行和列:\n");
		int x;
		int y;
		bool IsDefeat=false;
		scanf("%d%d", &x, &y);
		system("cls");
		printf("用户点击的位置为(%d,%d)\n", x, y);
		bool IsOperateSuccess=Click(x, y, board, MINE, IsClick,IsDefeat);
		if(IsOperateSuccess==false)
		{
			printf("输入非法地址,请重新输入!\n");
		}
		if (IsDefeat == true)//如果被打败了
		{
			EndingBoard(board, MINE);
			PrintBoard(board);
			printf("很遗憾,你输了!\n");
			return;
		}
		if (IsWin(board, MINE, IsClick))//如果赢了
		{
			EndingBoard(board, MINE);
			PrintBoard(board);
			printf("*****恭喜你,胜利!*****\n");
			return;
		}
		
	}
	
}
void game(
	char board[MID][MID],
	char MINE[MID + 2][MID + 2],
	bool IsClick[MID][MID]
)
{
	while (true)
	{
		system("cls");
		PrintBoard(board);
		printf("请输入行和列:\n");
		int x;
		int y;
		bool IsDefeat = false;
		scanf("%d%d", &x, &y);
		system("cls");
		printf("用户点击的位置为(%d,%d)\n", x, y);
		bool IsOperateSuccess = Click(x, y, board, MINE, IsClick, IsDefeat);
		if (IsOperateSuccess == false)
		{
			printf("输入非法地址,请重新输入!\n");
		}
		if (IsDefeat == true)//如果被打败了
		{
			EndingBoard(board, MINE);
			PrintBoard(board);
			printf("很遗憾,你输了!\n");
			return;
		}
		if (IsWin(board, MINE, IsClick))//如果赢了
		{
			EndingBoard(board, MINE);
			PrintBoard(board);
			printf("*****恭喜你,胜利!*****\n");
			return;
		}
	}
}
void game(
	char board[HARD][HARD],
	char MINE[HARD + 2][HARD + 2],
	bool IsClick[HARD][HARD]
)
{
	while (true)
	{
		system("cls");
		PrintBoard(board);
		printf("请输入行和列:\n");
		int x;
		int y;
		bool IsDefeat = false;
		scanf("%d%d", &x, &y);
		system("cls");
		printf("用户点击的位置为(%d,%d)\n", x, y);
		bool IsOperateSuccess = Click(x, y, board, MINE, IsClick, IsDefeat);
		if (IsOperateSuccess == false)
		{
			printf("输入非法地址,请重新输入!\n");
		}
		if (IsDefeat == true)//如果被打败了
		{
			EndingBoard(board, MINE);
			PrintBoard(board);
			printf("很遗憾,你输了!\n");
			return;
		}
		if (IsWin(board, MINE, IsClick))//如果赢了
		{
			EndingBoard(board, MINE);
			PrintBoard(board);
			printf("*****恭喜你,胜利!*****\n");
			return;
		}
	}
}
bool Click(
	int x,//1~dif
	int y,//1~dif
	char board[EASY][EASY],
	char MINE[EASY + 2][EASY + 2],
	bool IsClick[EASY][EASY],
	bool &IsDefeat
)
{
	int dif = EASY;
	//输入非法的情况
	if (x<1 || x>dif)return false;
	if (y<1 || y>dif)return false;
	if (IsClick[x - 1][y - 1] == true)return false;
	IsClick[x - 1][y - 1] = true;
	if (MINE[x][y] == '#')
	{
		return IsDefeat = true;
	}
	board[x - 1][y - 1] = '0';
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (MINE[i][j] == '#')
				board[x - 1][y - 1]++;
	if (board[x - 1][y - 1] == '0')
	{
		Click(x - 1, y, board, MINE, IsClick, IsDefeat);
		Click(x + 1, y, board, MINE, IsClick, IsDefeat);
		Click(x, y - 1, board, MINE, IsClick, IsDefeat);
		Click(x, y + 1, board, MINE, IsClick, IsDefeat);
	}
		

	return true;
	
}

bool Click(
	int x,
	int y,
	char board[MID][MID],
	char MINE[MID + 2][MID + 2],
	bool IsClick[MID][MID],
	bool& IsDefeat
)
{
	int dif = MID;
	//输入非法的情况
	if (x<1 || x>dif)return false;
	if (y<1 || y>dif)return false;
	if (IsClick[x - 1][y - 1] == true)return false;
	IsClick[x - 1][y - 1] = true;
	if (MINE[x][y] == '#')
	{
		return IsDefeat = true;
	}
	board[x - 1][y - 1] = '0';
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (MINE[i][j] == '#')
				board[x - 1][y - 1]++;
	if (board[x - 1][y - 1] == '0')
	{
		Click(x - 1, y, board, MINE, IsClick, IsDefeat);
		Click(x + 1, y, board, MINE, IsClick, IsDefeat);
		Click(x, y - 1, board, MINE, IsClick, IsDefeat);
		Click(x, y + 1, board, MINE, IsClick, IsDefeat);
	}


	return true;

}
bool Click(
	int x,
	int y,
	char board[HARD][HARD],
	char MINE[HARD + 2][HARD + 2],
	bool IsClick[HARD][HARD],
	bool& IsDefeat
) {
	int dif = HARD;
	//输入非法的情况
	if (x<1 || x>dif)return false;
	if (y<1 || y>dif)return false;
	if (IsClick[x - 1][y - 1] == true)return false;
	IsClick[x - 1][y - 1] = true;
	if (MINE[x][y] == '#')
	{
		return IsDefeat = true;
	}
	board[x - 1][y - 1] = '0';
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (MINE[i][j] == '#')
				board[x - 1][y - 1]++;
	if (board[x - 1][y - 1] == '0')
	{
		Click(x - 1, y, board, MINE, IsClick, IsDefeat);
		Click(x + 1, y, board, MINE, IsClick, IsDefeat);
		Click(x, y - 1, board, MINE, IsClick, IsDefeat);
		Click(x, y + 1, board, MINE, IsClick, IsDefeat);
	}


	return true;
}


void EndingBoard(
	char board[EASY][EASY],
	char MINE[EASY + 2][EASY + 2]
){
	int dif = EASY;
	for(int i=0;i<dif;i++)
		for (int j = 0; j < dif; j++)
		{
			if (MINE[i + 1][j + 1] == '#')
				board[i][j] = '#';
			else
			{
				board[i][j] = '0';
				for (int m = i; m <= i + 2; m++)
					for (int n = j; n <= j + 2; n++)
						if (MINE[m][n] == '#')
							board[i][j]++;
			}
		}

}
void EndingBoard
(
	char board[MID][MID],
	char MINE[MID + 2][MID + 2]
){
	int dif = MID;
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
		{
			if (MINE[i + 1][j + 1] == '#')
				board[i][j] = '#';
			else
			{
				board[i][j] = '0';
				for (int m = i; m <= i + 2; m++)
					for (int n = j; n <= j + 2; n++)
						if (MINE[m][n] == '#')
							board[i][j]++;
			}
		}
}
void EndingBoard
(
	char board[HARD][HARD],
	char MINE[HARD + 2][HARD + 2]
) {
	int dif = HARD;
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
		{
			if (MINE[i + 1][j + 1] == '#')
				board[i][j] = '#';
			else
			{
				board[i][j] = '0';
				for (int m = i; m <= i + 2; m++)
					for (int n = j; n <= j + 2; n++)
						if (MINE[m][n] == '#')
							board[i][j]++;
			}
		}
}

bool IsWin(
	char board[EASY][EASY],
	char MINE[EASY + 2][EASY + 2],
	bool IsClick[EASY][EASY]
){
	int dif = EASY;
	int count = 0;
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
			if (IsClick[i][j] == true && MINE[i + 1][j + 1] != '#')
				count++;
	if (count == dif * dif - dif)return true;
	return false;
}
bool IsWin(
	char board[MID][MID],
	char MINE[MID + 2][MID + 2],
	bool IsClick[MID][MID]
) {
	int dif = MID;
	int count = 0;
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
			if (IsClick[i][j] == true && MINE[i + 1][j + 1] != '#')
				count++;
	if (count == dif * dif - dif)return true;
	return false;
}
bool IsWin(
	char board[HARD][HARD],
	char MINE[HARD + 2][HARD + 2],
	bool IsClick[HARD][HARD]
){
	int dif = HARD;
	int count = 0;
	for (int i = 0; i < dif; i++)
		for (int j = 0; j < dif; j++)
			if (IsClick[i][j] == true && MINE[i + 1][j + 1] != '#')
				count++;
	if (count == dif * dif - dif)return true;
	return false;
}
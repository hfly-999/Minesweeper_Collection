#include"Define.h"
#include"Init.h"//初始化用的头文件
#include"Print.h"//棋盘打印用的头文件
//游戏主体逻辑
void Game();//游戏

void Menu();//难度选择菜单

//======================================//game
void game(
	char board[EASY][EASY],
	char MINE[EASY + 2][EASY + 2],
	bool IsClick[EASY][EASY]
);//正式进入游戏-简单难度
void game(
	char board[MID][MID],
	char MINE[MID + 2][MID + 2],
	bool IsClick[MID][MID]
);//正式进入游戏-中等难度
void game(
	char board[HARD][HARD],
	char MINE[HARD + 2][HARD + 2],
	bool IsClick[HARD][HARD]
);//正式进入游戏-困难难度


//======================================//click
bool Click(
	int x,
	int y,
	char board[EASY][EASY],
	char MINE[EASY + 2][EASY + 2],
	bool IsClick[EASY][EASY],
	bool &IsDefeat
);//EASY

bool Click(
	int x,
	int y,
	char board[MID][MID],
	char MINE[MID + 2][MID + 2],
	bool IsClick[MID][MID],
	bool& IsDefeat
);//MID

bool Click(
	int x,
	int y,
	char board[HARD][HARD],
	char MINE[HARD + 2][HARD + 2],
	bool IsClick[HARD][HARD],
	bool& IsDefeat
);//HARD



//======================================//iswin



bool IsWin(
	char board[EASY][EASY],
	char MINE[EASY + 2][EASY + 2],
	bool IsClick[EASY][EASY]
);//EASY

bool IsWin(
	char board[MID][MID],
	char MINE[MID + 2][MID + 2],
	bool IsClick[MID][MID]
);//MID
bool IsWin(
	char board[HARD][HARD],
	char MINE[HARD+ 2][HARD + 2],
	bool IsClick[HARD][HARD]
);//MID

//======================================//endingboard

void EndingBoard(
	char board[EASY][EASY], 
	char MINE[EASY + 2][EASY + 2]
);//终止时刻的游戏框-EASY
void EndingBoard
(
	char board[MID][MID],
	char MINE[MID + 2][MID + 2]
);//终止时刻的游戏框-MID
void EndingBoard
(
	char board[HARD][HARD],
	char MINE[HARD + 2][HARD + 2]
);//终止时刻的游戏框-HARD
//======================================//



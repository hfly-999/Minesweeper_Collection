#include"Define.h"
#include"Init.h"//初始化用的头文件
#include"Print.h"//棋盘打印用的头文件
//游戏主体逻辑
void Game();//游戏

void Menu();//难度选择菜单

//======================================//game

void game(
	char* board,
	char* MINE,
	bool* IsClick,
	int dif
);//泛型

//======================================//click

bool Click(
	int x,
	int y,
	char *board,
	char *MINE,
	bool *IsClick,
	bool& IsDefeat,
	int dif
);//泛型

//======================================//iswin

bool IsWin(
	char* board,
	char* MINE,
	bool* IsClick,
	int dif
);//泛型

//======================================//endingboard
void EndingBoard(
	char *board,
	char *MINE,
	int dif
);//终止时刻的游戏框-泛型

//======================================//



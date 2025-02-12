#include"Game.h"



void game()
{
	//扫雷

	char mine[ROWS][COLS];//地雷的字符数组11*11,埋雷的时候只在中间9*9的数组埋雷
	char show[ROWS][COLS];//展示给玩家雷信息的数组,要给玩家看的
	InitBoard(mine, ROWS, COLS,'0');//初始化
	InitBoard(show, ROWS, COLS, '*');
	Display(show,ROW,COL);
	
	//布置雷
	SetMine(mine,ROW,COL);
	
	//让玩家进行扫雷
	FindMine(mine,show,ROW,COL);
}//游戏具体逻辑



void menu()
{
	printf("********************************\n");
	printf("*******  1. 玩  0. 退出  *******\n");
	printf("********************************\n");
	printf("********************************\n");
}//菜单函数



void test()
{
	int input = 0;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		printf("请选择:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 0:printf("<退出游戏>"); break;
		case 1:game(); break;
		default:printf("<选择错误,请重新选择>"); break;
			
		}


	} while (input);
}//游戏是否继续进行的逻辑函数



int main()
{
	test();
	return 0;
}





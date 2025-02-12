#include"Game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for(int i = 0;i<rows;i++)
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
}//初始化函数

void Display(char board[ROWS][COLS], int row, int col)
{
	
	print("  ");
	for (int i = 1; i < row + 1; i++)print("%d ", i);
	print("\n"); 
	for (int i = 1; i < row + 1; i++)
	{
		print("%d ", i);
		for (int j = 1; j < col+1; j++)print("%c ",board[i][j]);
		print("\n");
	}
}//display函数
//展示show的函数

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand()%row +1;//产生一个1~行数的随机数 
		int y = rand()%col +1;//产生一个1~列数的随机数
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}//布置雷的函数
//放雷的函数

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (true)
	{
		print("请输入排查雷的坐标:\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{//合法坐标
			if (mine[x][y] == '1')//踩雷了
			{
				print("很遗憾,你踩到雷了!!\n");
				Display(mine,row,col);
				break;
			}
			else//没有踩雷
			{
				GetMineCount(mine, x, y);
				show[x][y] = GetMineCount(mine, x, y) + '0';
				Display(show,row,col);
				win++;
				if (win == ((ROW * COL) - EASY_COUNT))
				{
					print("你赢啦!!\n");
					Display(mine, ROW, COL);
					break;
				}
			}
			
		}
		else
		{
			print("输入坐标非法,请重新输入");
		}
	}
	
}

	//扫雷的函数
int GetMineCount(char mine[ROWS][COLS],int x,int y)//扫描函数
{
	return
		mine[x - 1][y - 1]/*左上*/
		+ mine[x - 1][y]/*上*/
		+ mine[x - 1][y + 1]/*右上*/
		+ mine[x][y - 1]/*左*/
		+ mine[x][y + 1]/*右*/
		+ mine[x + 1][y - 1]/*左下*/
		+ mine[x + 1][y]/*下*/
		+ mine[x + 1][y + 1]/*右下*/
		-8*'0';
}
#pragma once
#include"Define.h"
void InitBoard(char board[EASY][EASY]);//简单难度下的棋盘初始化
void InitBoard(char board[MID][MID]);//中等难度下的棋盘初始化
void InitBoard(char board[HARD][HARD]);//困难难度下的棋盘初始化

void InitMINE(char MINE[EASY + 2][EASY + 2]);//简单难度下雷盘的初始化
void InitMINE(char MINE[MID + 2][MID + 2]);//中等难度下雷盘的初始化
void InitMINE(char MINE[HARD + 2][HARD + 2]);//困难难度下雷盘的初始化


void InitIsClick(bool IsClick[EASY][EASY]);//简单难度下的IsClick数组的初始化
void InitIsClick(bool IsClick[MID][MID]);//中等难度下的IsClick数组的初始化
void InitIsClick(bool IsClick[HARD][HARD]);//困难难度下的IsClick数组的初始化

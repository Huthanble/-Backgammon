#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initboard(char board[ROW][COL],int row,int col);//函数声明
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
//能告诉我们四种游戏状态
//电脑赢  '#'
//玩家赢  '*'
//平局  'b'
//继续  'c'

char iswin(char board[ROW][COL],int row,int col);


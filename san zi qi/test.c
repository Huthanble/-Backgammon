#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void menu()//菜单书写
{
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
}
void game()//游戏逻辑
{
	char ret = 0;
	//数组存放走出的棋盘信息
	char board[ROW][COL]={0};//全部空格
	initboard(board, ROW, COL);//初始化棋盘
	//打印棋盘
	displayboard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		playermove(board,ROW,COL);
		displayboard(board, ROW, COL);
		//判断是否胜利
		ret=iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//电脑下棋
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断是否胜利
		ret=iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
	}
	switch (ret)
	{
	case '*':printf("玩家胜利\n"); break;
	case '#':printf("电脑胜利\n"); break;
	case 'b':printf("平局\n"); break;
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入 >");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("退出游戏"); break;
		default:printf("输入错误，请重新选择"); break;
		}
	} while (input); 
}
int main()
{
	test();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void menu()//�˵���д
{
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
}
void game()//��Ϸ�߼�
{
	char ret = 0;
	//�������߳���������Ϣ
	char board[ROW][COL]={0};//ȫ���ո�
	initboard(board, ROW, COL);//��ʼ������
	//��ӡ����
	displayboard(board,ROW,COL);
	//����
	while (1)
	{
		//�������
		playermove(board,ROW,COL);
		displayboard(board, ROW, COL);
		//�ж��Ƿ�ʤ��
		ret=iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//��������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�ж��Ƿ�ʤ��
		ret=iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
	}
	switch (ret)
	{
	case '*':printf("���ʤ��\n"); break;
	case '#':printf("����ʤ��\n"); break;
	case 'b':printf("ƽ��\n"); break;
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������ >");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("�˳���Ϸ"); break;
		default:printf("�������������ѡ��"); break;
		}
	} while (input); 
}
int main()
{
	test();
	return 0;
}
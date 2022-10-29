#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
//void displayboard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0],board[i][1], board[i][2]);//��ӡ��
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");//��ӡ�ݸ���
//		}
//	}
//}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//��ӡ��
			if (j < col - 1)
			{
				printf("|");
			}
			else
			{
				printf("\n");
			}
			
		}
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");//��ӡ�ݸ���
				if (j < col - 1)
				{
					printf("|");
				}
				else
				{
					printf("\n");
				}
			}
		}
	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����\n");
	while(1)
	{
		printf("����������>");
		scanf("%d%d", &x, &y);
		//�ж�xy�ĺ�����
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��λ���ѱ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("���겻���ڣ�����������\n");
		}
	} 
}
void computermove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//������
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)//������
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//б
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	for (i = 0;i < row; i++)//�ж�ƽ�ֻ����
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				continue;
			}
			else
			{
				return 'c';
			}
		}
	}
	return 'b';
}
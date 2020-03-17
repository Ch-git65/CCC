#define _CRT_SECURE_NO_WARNINGS	1

#include<stdio.h>
#include<windows.h>
#include<time.h>

#define ROW 3
#define COL 3

void Menu()//��Ϸ����
{
	printf("****************************\n");
	printf("******    1.play    ********\n");
	printf("******    0.exit    ********\n");
	printf("****************************\n");
}

void Init_board(char a[ROW][COL], int row, int col) //��ʼ������
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			a[i][j] = ' ';
		}
	}
}

void display_board(char a[ROW][COL], int row, int col)//��ӡ����
{
	int i, j;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf(" %c ", a[i][j]);
			if (j < col - 1){
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("___");
				if (j < col - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void go_player(char a[ROW][COL], int row, int col)//�������
{
	int m = 0, n = 0;
	printf("�������:\n");
	while (1)
	{
		printf("���������������:");
		scanf("%d %d", &m, &n);
		if ((m >= 0) && (m < row) && (n >= 0) && (n < col))
		{
			if (a[m][n] == ' ')
			{
				a[m][n] = '*';
				break;
			}
			else
				printf("�����걻ռ�ã�����������\n");
		}
		else
		{
			printf("��������,����������\n");
		}
	}
}

void go_computer(char a[ROW][COL], int row, int col)//��������
{
	printf("��������:\n");
	while (1)
	{
		int r1 = rand() % row;
		int r2 = rand() % col;
		if (a[r1][r2] == ' ')
		{
			a[r1][r2] = '#';
			break;
		}
	}
}

static int IsFull(char a[ROW][COL], int row, int col) //�����Ƿ���
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++){
			if (a[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char judge_win(char a[ROW][COL], int row, int col) //�ж���Ӯ
{
	int i;
	for (i = 0; i < row; i++) {
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ')
		{
			return a[i][0];
		}
	}
	//�ж������Խ����Ƿ����
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ')
	{
		return a[0][0];
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != ' ')
	{
		return a[0][2];
	}
	//�ж�ƽ�֣������Ƿ�����
	if (IsFull(a, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}

void game()  //��Ϸ
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	Init_board(board, ROW, COL);
	display_board(board, ROW, COL);

	while (1)								//��Ϸ���У�һ����һ���ж���Ӯ
	{
		go_player(board, ROW, COL);
		display_board(board, ROW, COL);
		ret = judge_win(board, ROW, COL);
		if (ret != 'C')
			break;

		go_computer(board, ROW, COL);
		display_board(board, ROW, COL);
		ret = judge_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}

	if (ret =='*')				//�������������ж�˭Ӯ
	{
		printf("��ϲ����ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ \n");
	}

}

int main()
{
	int select = 0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		Menu();
		printf("��ѡ��:");
		scanf("%d", &select);
		if (select == 1)
		{
			game();
			break;
		}
		else if (select == 0)
		{
			printf("�˳���Ϸ\n");
		}
		else
		{
			printf("�������\n");
		}
	}
	return 0;
}
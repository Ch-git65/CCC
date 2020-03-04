#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h> //����
#include<string.h>
#include<time.h> //ʱ���
#include<stdlib.h>

#define MAX_ROW 5
#define MAX_COL 5

void menu()    //��Ϸ����
{
	printf("******************************\n");
	printf("*********  1.play  ***********\n");
	printf("*********  0.exit  ***********\n");
	printf("******************************\n");
}

int ChoiceStart(int i)   //��Ϸѡ��
{
	while (1)
	{
		scanf("%d", &i);
		if (i == 1)     //����Ϸ
		{
			system("cls"); //����
			return 1;
		}
		else if (i == 0)  //����
		{
			system("cls");
			printf("exit game!\n");
		}
		else
		{
			printf("input is error,input again:\n");
			continue;
		}
	}
	return 0;
}

void menu_play() //ģʽѡ�����
{
	printf("*****************************************\n");
	printf("*********   1.player-player   ***********\n");
	printf("*********  2.player-computer  ***********\n");
	printf("*****************************************\n");
}

int choicemode(int i) //ģʽѡ��
{
	while (1)
	{
	scanf("%d", &i);
	if (i == 1) { return 1; }
	if (i == 2) { return 2; }
	else
	{
		printf("your choice is error,input again:\n");
		continue;
	}
	}
}

//���̳�ʼ��
void Init(char chessBoard[MAX_ROW][MAX_COL])
{
	srand((unsigned int)time(NULL));
	memset(chessBoard, ' ', MAX_ROW * MAX_COL * sizeof(char));
	//memset void* ָ��������ʹ�õĺ���
}

//��ӡ����
void Print(char chessBoard[MAX_ROW][MAX_COL])
{
	printf("----------------\n");
	for (int row = 0; row < MAX_ROW; row++)   // ��
	{
		for (int col = 0; col < MAX_COL; col++) //��
		{
			printf("|%c ", chessBoard[row][col]); //������̵ĸ�ʽ
		}
		printf("|\n");
		printf("----------------\n");
	}
}

//������ӣ�one+two��
void Playone(char chessBoard[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("��������Ҫ���ӵ�λ�ã����̹��Ϊ5x5���磨row col):");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
		{
			printf("��������\n");
			continue;
		}
		if (chessBoard[row][col] != ' ')
		{
			printf("��λ���Ѿ������ˣ�\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}
//��������
void Playcomputer(char chessBoard[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = rand() % MAX_ROW; //����0-4
		int col = rand() % MAX_COL; //
		if (chessBoard[row][col] != ' ')
		{
			continue;
		}
		chessBoard[row][col] = '0';
		break;
	}
}

//�ж������Ƿ�����������
int IsFull(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chessBoard[row][col] == ' ')
			{//�ҵ���λ�ˣ�����û��
				return 0;
			}
		}
	}
	return 1;
}

//���˭��˭Ӯ
char Check(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{//���е���
		if (chessBoard[row][0] != ' ' 
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]
			&& chessBoard[row][0] == chessBoard[row][3]
			&& chessBoard[row][0] == chessBoard[row][4])
			return chessBoard[row][0];
	}
	// 2. �ټ�����е���
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]
			&& chessBoard[0][col] == chessBoard[3][col]
			&& chessBoard[0][col] == chessBoard[4][col]) {
			return chessBoard[0][col];
		}
	}
	// 3. �ټ��Խ���
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]
		&& chessBoard[0][0] == chessBoard[3][3]
		&& chessBoard[0][0] == chessBoard[4][4]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][4] != ' '
		&& chessBoard[0][4] == chessBoard[1][3]
		&& chessBoard[0][4] == chessBoard[2][2]
		&& chessBoard[0][4] == chessBoard[3][1]
		&& chessBoard[0][4] == chessBoard[4][0]) {
		return chessBoard[0][4];
	}
	// 4. �ж��Ƿ����, �����������, �������
	if (IsFull(chessBoard)) {
		return 'Q';
	}
	return ' ';
}

void GamePlay()
{
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(chessBoard);//���ó�ʼ�����̺���
	printf("һ�����ִ�壡\n");
	char winner = ' '; //����Ӯ�ҵ�����
	while (1)
	{
		Playone(chessBoard);//һ���������
		Print(chessBoard); //���д�ӡ
		Check(chessBoard); //����Ƿ�Ӯ��
		winner = Check(chessBoard);
		if (winner != ' ')
		{
			break;
		}
		printf("�������ִ�壡\n");
		Playone(chessBoard);
		Print(chessBoard);
		Check(chessBoard);
		winner = Check(chessBoard);
		if (winner != ' ')
		{
			break;
		}
	}
	system("cls");
	Print(chessBoard);//����Ϸ������ʱ���ӡ��������
	if (winner == 'x')
	{
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (winner == 'o')
	{
		printf("�����!\n");
	}
	else
	{
		printf("������ˣ�\n");
	}
}

void GameComputer()
{
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(chessBoard);//���ó�ʼ�����̺���
	printf("һ�����ִ�壡\n");
	char winner = ' '; //����Ӯ�ҵ�����
	while (1)
	{
		Playone(chessBoard);//һ���������
		Print(chessBoard); //���д�ӡ
		Check(chessBoard); //����Ƿ�Ӯ��
		winner = Check(chessBoard);
		if (winner != ' ')
		{
			break;
		}
		printf("����ִ�壡\n");
		Playcomputer(chessBoard);
		Print(chessBoard);
		Check(chessBoard);
		winner = Check(chessBoard);
		if (winner != ' ')
		{
			break;
		}
	}
	system("cls");
	Print(chessBoard);//����Ϸ������ʱ���ӡ��������
	if (winner == 'x')
	{
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (winner == 'o')
	{
		printf("�����!\n");
	}
	else
	{
		printf("������ˣ�\n");
	}
}
int main()
{
	int i = 0, choice = 0;
	menu();  //��ӡ��Ϸ����
	printf("please input your choice:\n");
	choice = ChoiceStart(i);
	if (choice == 1)
	{
		menu_play();
	}
	printf("please choice model:\n");
	choice = choicemode(i);
	if (choice == 1)         //����
	{
		system("cls");
		GamePlay();
	}
	if (choice == 2)         //�˻�
	{
		system("cls");
		GameComputer();
	}
	return 0;
}
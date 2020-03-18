#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

#define MAX_ROW 8
#define MAX_COL 8

int Boxs; //ͳ��������ʣδ��ɵ����ӵĸ���
int x, y; //�ô���������λС�˵�λ��

//��ͼ
int map[MAX_ROW][MAX_COL] = {
	{ 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 4, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 1, 1, 1, 1 },
	{ 1, 1, 1, 3, 0, 3, 4, 1 },
	{ 1, 4, 0, 3, 2, 1, 1, 1 },
	{ 1, 1, 1, 1, 3, 1, 0, 0 },
	{ 0, 0, 0, 1, 4, 1, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0 }
};
//  0  ��ʾ��
//  1  ��ʾǽ
//  2  ��ʾ��
//  3  ��ʾ����
//  4  ��ʾĿ�ĵ�
//  5  ��ʾ����ɵ�����

void Menu()
{
	printf("*********************************\n");
	printf("**********  1.play  *************\n");
	printf("**********  0.exit  *************\n");
	printf("*********************************\n");
}

int ChoiceStart(int i)
{
	printf("����������ѡ��:");
	while (1)
	{
		scanf("%d", &i);
		if (i == 1)
		{
			system("cls");
			return 1;
		}
		if (i == 0)
		{
			system("cls");
			printf("�ټ���\n");
			break;
		}
		else
		{
			printf("������������:\n");
			continue;
		}
	}
	return 0;
}

//��ͼ���� ��¼�����ڵ�λ�ã����Ҽ����ͼ֮�е�������
void InitData()
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			if (map[i][j] == 2)
			{
				x = j;
				y = i;
			}
			if (map[i][j] == 3)
			{
				Boxs++;
			}
		}
	}
}

//��ӡ��ͼ����
void drawMap()
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf(" ");
				break;
			case 1:   //ǽ
				printf("��");
				break;
			case 2:   //��
				printf("��");
				break;
			case 3:   //����
				printf("��");
				break;
			case 4:   //Ŀ�ĵ�
				printf("��");
				break;
			case 5:   //�����
				printf("��");
				break;
			}
		}
		printf("\n");
	}
}

	
//�����ƶ�
void MoveUp()
{
	if (y == 0) {  //��x[0][j],��һ�У�ֱ�ӷ���
		return;
	}
	int Ux = x;
	int Uy = y - 1;
	if (map[Uy][Ux] == 1 || map[Uy][Ux] == 5) //�Ϸ���ǽ�������
	{
		return;
	}
	if (map[Uy][Ux] == 3) //����������
	{
		if (map[Uy - 1][Ux - 1] == 1)//������ǽ
		{
			return;
		}
		if (map[Uy - 1][Ux] == 4) {//�������յ�
			map[Uy - 1][Ux] = 5;//���������ƶ��������յ�
			Boxs--;
		}
		else
		{
			map[Uy - 1][Ux] = 3;//�����ǿ�
		}
	}
	map[y][x] = 0; //���˵�λ�û�Ϊ0
	map[Uy][Ux] = 2;//��ԭ���ӵ�λ�û�Ϊ��
	y = Uy; //���˵�λ�ý��иı�
}

//�����ƶ�
void MoveDown()
{
	int D = MAX_ROW - 1;
	if (y == D) { 
		return;
	}
	int Dx = x;
	int Dy = y + 1;
	if (map[Dy][Dx] == 1 || map[Dy][Dx] == 5) 
	{
		return;
	}
	if (map[Dy][Dx] == 3) 
	{
		if (map[Dy + 1][Dx] == 1)
		{
			return;
		}
		if (map[Dy + 1][Dx] == 4)
		{
			map[Dy + 1][Dx] = 5;
			Boxs--;
		}
		else
		{
			map[Dy + 1][Dx] = 3;
		}
	}
	map[y][x] = 0; 
	map[Dy][Dx] = 2;
	y = Dy; 
}

//�����ƶ�
void MoveLeft()
{
	if (x == 0) {  
		return;
	}
	int Lx = x-1;
	int Ly = y;
	if (map[Ly][Lx] == 1 || map[Ly][Lx] == 5) 
	{
		return;
	}
	if (map[Ly][Lx] == 3) 
	{
		if (map[Ly][Lx - 1] == 1)
		{
			return;
		}
		if (map[Ly][Lx - 1] == 4) {
			map[Ly][Lx - 1] = 5;
			Boxs--;
		}
		else
		{
			map[Ly][Lx - 1] = 3;
		}
	}
	map[y][x] = 0; 
	map[Ly][Lx] = 2;
	x = Lx; 
}

//�����ƶ�
void MoveRight()
{
	int R = MAX_COL - 1;
	if (x == R) {
		return;
	}
	int Rx = x + 1;
	int Ry = y;
	if (map[Ry][Rx] == 1 || map[Ry][Rx] == 5)
	{
		return;
	}
	if (map[Ry][Rx] == 3)
	{
		if (map[Ry][Rx + 1] == 1)
		{
			return;
		}
		if (map[Ry][Rx + 1] == 4) {
			map[Ry][Rx + 1] = 5;
			Boxs--;
		}
		else
		{
			map[Ry][Rx + 1] = 3;
		}
	}
	map[y][x] = 0;
	map[Ry][Rx] = 2;
	x = Rx;
}

int Game()
{
	char direction;  //�����
	InitData();
	while (1)
	{
		system("cls");
		drawMap();
		printf("��������Ҫ�ƶ��ķ���Сд��ĸ������wΪ�ϣ�sΪ�£�aΪ��dΪ�ң�\n");
		if (!Boxs)
		{
			break;
		}
		direction = getch();
		switch (direction)
		{
		case 'w':
			MoveUp();
			break;
		case 's':
			MoveDown();
			break;
		case 'a':
			MoveLeft();
			break;
		case 'd':
			MoveRight();
			break;
		}
	}
	printf("����ͨ����Ϸ��\n");
	return 0;
}

int main()
{
	int i = 0;
	int choice = 0;
	Menu();
	choice = ChoiceStart(i);
	if (choice == 1)
	{
		Game();
	}
	return 0;
}
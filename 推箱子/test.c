#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

#define MAX_ROW 8
#define MAX_COL 8

int Boxs; //统计其中所剩未完成的箱子的个数
int x, y; //用此坐标来定位小人的位置

//地图
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
//  0  表示空
//  1  表示墙
//  2  表示人
//  3  表示箱子
//  4  表示目的地
//  5  表示已完成的箱子

void Menu()
{
	printf("*********************************\n");
	printf("**********  1.play  *************\n");
	printf("**********  0.exit  *************\n");
	printf("*********************************\n");
}

int ChoiceStart(int i)
{
	printf("请输入您的选择:");
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
			printf("再见！\n");
			break;
		}
		else
		{
			printf("您的输入有误:\n");
			continue;
		}
	}
	return 0;
}

//搜图函数 记录人所在的位置，并且计算地图之中的箱子数
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

//打印地图函数
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
			case 1:   //墙
				printf("■");
				break;
			case 2:   //人
				printf("♀");
				break;
			case 3:   //箱子
				printf("◆");
				break;
			case 4:   //目的地
				printf("●");
				break;
			case 5:   //已完成
				printf("★");
				break;
			}
		}
		printf("\n");
	}
}

	
//向上移动
void MoveUp()
{
	if (y == 0) {  //即x[0][j],第一行，直接返回
		return;
	}
	int Ux = x;
	int Uy = y - 1;
	if (map[Uy][Ux] == 1 || map[Uy][Ux] == 5) //上方是墙或已完成
	{
		return;
	}
	if (map[Uy][Ux] == 3) //上面是箱子
	{
		if (map[Uy - 1][Ux - 1] == 1)//上面是墙
		{
			return;
		}
		if (map[Uy - 1][Ux] == 4) {//上面是终点
			map[Uy - 1][Ux] = 5;//箱子向上移动，到达终点
			Boxs--;
		}
		else
		{
			map[Uy - 1][Ux] = 3;//上面是空
		}
	}
	map[y][x] = 0; //将人的位置换为0
	map[Uy][Ux] = 2;//将原箱子的位置换为人
	y = Uy; //将人的位置进行改变
}

//向下移动
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

//向左移动
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

//向右移动
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
	char direction;  //方向键
	InitData();
	while (1)
	{
		system("cls");
		drawMap();
		printf("请输入你要移动的方向（小写字母）：（w为上，s为下，a为左，d为右）\n");
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
	printf("您已通关游戏！\n");
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
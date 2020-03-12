#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int feiji_x, feiji_y;//飞机位置
int zidan_x, zidan_y;//子弹位置
int diji_x, diji_y; //敌机位置
int h, w;
int score = 0;//得分
int c = 0;

void gotoxy(int x, int y) {  //定位光标位置到指定位置
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void startup() {
	h = 20;
	w = 60;

	feiji_x = h / 2;
	feiji_y = w / 2;

	zidan_x = -1;
	zidan_y = feiji_y;

	diji_x = 0;
	diji_y = w / 2;
}

void show() {
	int i, j;
	char dad;
	if (c == 0) {
		printf("======================================\n");
		printf("=           ---打飞机---             =\n");
		printf("=       w,a,s,d------控制飞机移动    =\n");
		printf("=           不要开中文输入法         =\n");
		printf("=       j------------发射子弹        =\n");
		printf("=                                    =\n");
		printf("=         闪屏纯属正常               =\n");
		printf("=                        ----倾白白  =\n");
		printf("======================================\n");
		c++;
		dad = _getch();
		system("cls");
	}
	gotoxy(0, 0);
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (i == feiji_x && j == feiji_y)
				printf("▲");
			else if (i == zidan_x && j == zidan_y)
				printf("↑");
			else if (i == diji_x && j == diji_y)
				printf("●");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("当前得分:%d", score);
	Sleep(50);
}

void wuguan()
{
	static int speed = 0;
	if (speed < 5)
		speed++;
	if (diji_x > h) {
		diji_x = 0;
		diji_y = rand() % w;
	}
	else
	{
		if (speed == 5) {
			diji_x++;
			speed = 0;
		}
	}
	zidan_x--;
	if (zidan_y == diji_y && zidan_x == diji_x) {
		diji_x = 0;
		zidan_x = -1;
		diji_y = rand() % w;
		score++;
	}
}

void youguan() {
	char input;
	if (_kbhit()) {
		input = _getch();
		if (input == 'w') feiji_x--;
		if (input == 'a')feiji_y--;
		if (input == 's')feiji_x++;
		if (input == 'd')feiji_y++;
		if (input == 'j') {
			zidan_y = feiji_y;
			zidan_x = feiji_x - 1;
		}
	}
}

int main()
{
	startup();// 数据
	while (1) {
		show();//显示界面
		wuguan();
		youguan();
		if (score == 5) {
			printf("通关了\n");
			break;
		}
	}
	return 0;
}
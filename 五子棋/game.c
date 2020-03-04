#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h> //清屏
#include<string.h>
#include<time.h> //时间戳
#include<stdlib.h>

#define MAX_ROW 5
#define MAX_COL 5

void menu()    //游戏界面
{
	printf("******************************\n");
	printf("*********  1.play  ***********\n");
	printf("*********  0.exit  ***********\n");
	printf("******************************\n");
}

int ChoiceStart(int i)   //游戏选择
{
	while (1)
	{
		scanf("%d", &i);
		if (i == 1)     //玩游戏
		{
			system("cls"); //清屏
			return 1;
		}
		else if (i == 0)  //不玩
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

void menu_play() //模式选择界面
{
	printf("*****************************************\n");
	printf("*********   1.player-player   ***********\n");
	printf("*********  2.player-computer  ***********\n");
	printf("*****************************************\n");
}

int choicemode(int i) //模式选择
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

//棋盘初始化
void Init(char chessBoard[MAX_ROW][MAX_COL])
{
	srand((unsigned int)time(NULL));
	memset(chessBoard, ' ', MAX_ROW * MAX_COL * sizeof(char));
	//memset void* 指针所可以使用的函数
}

//打印棋盘
void Print(char chessBoard[MAX_ROW][MAX_COL])
{
	printf("----------------\n");
	for (int row = 0; row < MAX_ROW; row++)   // 行
	{
		for (int col = 0; col < MAX_COL; col++) //列
		{
			printf("|%c ", chessBoard[row][col]); //输出棋盘的格式
		}
		printf("|\n");
		printf("----------------\n");
	}
}

//玩家落子（one+two）
void Playone(char chessBoard[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("请输入你要落子的位置，棋盘规格为5x5，如（row col):");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
		{
			printf("输入有误！\n");
			continue;
		}
		if (chessBoard[row][col] != ' ')
		{
			printf("该位置已经有子了！\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}
//电脑落子
void Playcomputer(char chessBoard[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = rand() % MAX_ROW; //生成0-4
		int col = rand() % MAX_COL; //
		if (chessBoard[row][col] != ' ')
		{
			continue;
		}
		chessBoard[row][col] = '0';
		break;
	}
}

//判断棋盘是否满，即和棋
int IsFull(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chessBoard[row][col] == ' ')
			{//找到空位了，棋盘没满
				return 0;
			}
		}
	}
	return 1;
}

//检查谁输谁赢
char Check(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{//所有的行
		if (chessBoard[row][0] != ' ' 
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]
			&& chessBoard[row][0] == chessBoard[row][3]
			&& chessBoard[row][0] == chessBoard[row][4])
			return chessBoard[row][0];
	}
	// 2. 再检查所有的列
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]
			&& chessBoard[0][col] == chessBoard[3][col]
			&& chessBoard[0][col] == chessBoard[4][col]) {
			return chessBoard[0][col];
		}
	}
	// 3. 再检查对角线
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
	// 4. 判定是否和棋, 棋盘如果满了, 就算和棋
	if (IsFull(chessBoard)) {
		return 'Q';
	}
	return ' ';
}

void GamePlay()
{
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(chessBoard);//调用初始化棋盘函数
	printf("一号玩家执棋！\n");
	char winner = ' '; //定义赢家的条件
	while (1)
	{
		Playone(chessBoard);//一号玩家落子
		Print(chessBoard); //进行打印
		Check(chessBoard); //检测是否赢了
		winner = Check(chessBoard);
		if (winner != ' ')
		{
			break;
		}
		printf("二号玩家执棋！\n");
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
	Print(chessBoard);//在游戏结束的时候打印最后的棋盘
	if (winner == 'x')
	{
		printf("恭喜你，你赢了！\n");
	}
	else if (winner == 'o')
	{
		printf("你真菜!\n");
	}
	else
	{
		printf("你俩真菜！\n");
	}
}

void GameComputer()
{
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(chessBoard);//调用初始化棋盘函数
	printf("一号玩家执棋！\n");
	char winner = ' '; //定义赢家的条件
	while (1)
	{
		Playone(chessBoard);//一号玩家落子
		Print(chessBoard); //进行打印
		Check(chessBoard); //检测是否赢了
		winner = Check(chessBoard);
		if (winner != ' ')
		{
			break;
		}
		printf("电脑执棋！\n");
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
	Print(chessBoard);//在游戏结束的时候打印最后的棋盘
	if (winner == 'x')
	{
		printf("恭喜你，你赢了！\n");
	}
	else if (winner == 'o')
	{
		printf("你真菜!\n");
	}
	else
	{
		printf("你俩真菜！\n");
	}
}
int main()
{
	int i = 0, choice = 0;
	menu();  //打印游戏界面
	printf("please input your choice:\n");
	choice = ChoiceStart(i);
	if (choice == 1)
	{
		menu_play();
	}
	printf("please choice model:\n");
	choice = choicemode(i);
	if (choice == 1)         //人人
	{
		system("cls");
		GamePlay();
	}
	if (choice == 2)         //人机
	{
		system("cls");
		GameComputer();
	}
	return 0;
}
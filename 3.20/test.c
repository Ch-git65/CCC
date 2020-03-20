#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
//int main()
//{
//	char password[20];
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			system("cls");
//			printf("密码错误，请重新登录\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("退出\n");
//	}
//	return 0;
//}
//void menu()
//{
//	printf("************************\n");
//	printf("********1.play**********\n");
//	printf("********0.exit**********\n");
//	printf("************************\n");
//}
//
//void game()
//{
//	int x, y;
//	y = rand() % 100 + 1;
//	while (1)
//	{
//		printf("请输入您要猜的数字:");
//		scanf("%d", &x);
//		if (x < y)
//		{
//			system("cls");
//			printf("猜小了\n");
//		}
//		else if (x > y)
//		{
//			system("cls");
//			printf("猜大了\n");
//		}
//		else
//		{
//			system("cls");
//			printf("恭喜您，猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	menu();
//	int choice;
//	scanf("%d", &choice);
//	if (choice == 1)
//	{
//		game();
//	}
//	else if (choice == 0)
//	{
//		printf("退出游戏\n");
//	}
//	else
//	{
//		printf("输入有误\n");
//	}
//	return 0;
//}


//int main()
//{
//	int f1 = 1, f2 = 1;
//	int i;
//	for (i = 1; i <= 20; i++)
//	{
//		printf("%12d%12d", f1, f2);
//		if (i % 2 == 0)
//			printf("\n");
//		f1 = f1 + f2;
//		f2 = f2 + f1;
//	}
//	return 0;
//}
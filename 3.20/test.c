#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
//int main()
//{
//	char password[20];
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			system("cls");
//			printf("������������µ�¼\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("�˳�\n");
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
//		printf("��������Ҫ�µ�����:");
//		scanf("%d", &x);
//		if (x < y)
//		{
//			system("cls");
//			printf("��С��\n");
//		}
//		else if (x > y)
//		{
//			system("cls");
//			printf("�´���\n");
//		}
//		else
//		{
//			system("cls");
//			printf("��ϲ�����¶���\n");
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
//		printf("�˳���Ϸ\n");
//	}
//	else
//	{
//		printf("��������\n");
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
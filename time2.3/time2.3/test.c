#define _CRT_SECURE_NO_WARNINGS 1
//#include<time.h>
//#include<stdio.h>
//#include<stdlib.h>
//
//void menu()
//{
//	printf("***************************\n");
//	printf("******   1.play   *********\n");
//	printf("******   0.exit   *********\n");
//	printf("***************************\n");
//}
//
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1)
//	{
//		printf("������µ�����:");
//		scanf("%d",&input);
//		if (input > random_num)
//		{
//			printf("�´���\n");
//		}
//		else if (input < random_num)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��:");
//		scanf("%d",&input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("ѡ���������������!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//#include<stdio.h>
//int get_max(int x, int y)
//{
//	return(x > y) ? (x) : (y);
//}
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int max = get_max(num1, num2);
//	printf("max=%d\n",max);
//	return 0;
//}
//#include<stdio.h>
//void Swap1(int x, int y)
//{
//	int m = 0;
//	m = x;
//	x = y;
//	y = m;
//}
//void Swap2(int *px, int *py)
//{
//	int m = 0;
//	m = *px;
//	*px = *py;
//	*py = m;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap1(a, b);
//	printf("Swap1  a = %d b=%d\n", a, b);
//	Swap2(&a, &b);
//	printf("Swap2  a = %d b=%d\n", a, b);
//	return 0;
//}
//������Ƕ�׵���
//#include<stdio.h>
//void new_line()
//{
//	printf("hehe\n");
//}
//void three_line()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		new_line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}
//����һ�����ͣ���˳���ӡ����ÿһλ��
//#include<stdio.h>
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n%10);
//}
//int main()
//{
//	int num = 5165;
//	print(num);
//	return 0;
//}

//�ַ�������
//#include<stdio.h>
//int strlen(const char *str)
//{
//	if (*str == '\0')
//		return 0;
//	else return 1 + strlen(str + 1);
//}
//int main()
//{
//	char *p = "abcdef";
//	int len = strlen(p);
//	printf("%d\n",len);
//	return 0;
//}

//n�Ľ׳�
//#include<stdio.h>
//int factorial(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n*factorial(n - 1);
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int m = factorial(n);
//	printf("%d\n",m);
//	return 0;
//}
//
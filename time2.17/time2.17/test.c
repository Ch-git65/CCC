#define _CRT_SECURE_NO_WARNINGS 1
// �´�С
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("*************************\n");
//	printf("******   1.play   *******\n");
//	printf("******   0.exit   *******\n");
//	printf("*************************\n");
//}
//void game()
//{
//	int x=0;
//	int y = rand() % 100 + 1;
//	while (1) {
//		printf("������µ���;");
//		scanf("%d", &x);
//		if (x > y) { printf("�´���\n"); }
//		else if (x < y) { printf("��С��\n"); }
//		else { printf("�¶���\n"); break; }
//	}
//}
//int main()
//{
//	int i;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��:");
//		scanf("%d", &i);
//		switch (i)
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
//	} while (i);
//	return 0;
//}
// 4*5����
//#include<stdio.h>
//int main()
//{
//	int i, j, n=0;
//	for (i = 1; i < 5; i++)
//	{
//		for (j = 1; j < 6; j++, n++)
//		{
//			if (n % 5 == 0) printf("\n");
//			printf("%d\t", i*j);
//		}
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 2;
//	int n, s=0,y;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int x = 10;; x *= 10)
//		{
//			if (i = 1)  y = a;
//			else   y = a + a*x;
//			s = s + y;
//		}
//	}
//	printf("%d\n", s);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int s,sum = 0;
//	for (int i = 1; i <= 20; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			s = (1 + j)*j;
//			sum += s;
//		}
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//ˮ�ɻ���
//#include<stdio.h>
//int main()
//{
//	for (int n = 100; n < 1000;n++)
//	{
//		int c = n / 100;//��λ
//		int b = (n - c * 100)/10;
//		int a = n % 10; //��λ��
//		if (n == a*a*a + b*b*b + c*c*c)
//			printf("%d ", n);
//	}
//	printf("\n");
//	return 0;
//}

//һ����������������֮��  6=1+2+3    28  496
//#include<stdio.h>
//int main()
//{
//	int i,j,sum;
//	for (i = 2; i < 1000; i++)
//	{
//		sum = 1;
//		for (j = 2; j <= i/2; j++)
//		{
//			if (i%j == 0) {	sum += j;	}
//		}
//		if (sum == i)
//		{
//			printf("%d its factors are 1,",i);
//			for (j = 2; j <= i/2; j++)
//			{
//				if (i%j == 0)
//					printf("%d,",j);
//				    //printf("\n");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	printf("   *   \n");
//	printf("  ***  \n");
//	printf(" ***** \n");
//	printf("*******\n");
//	printf(" ***** \n");
//	printf("  ***  \n");
//	printf("   *   \n");
//	return 0;
//}
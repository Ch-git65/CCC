#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	char c1, c2;
//	c1 = getchar();//�Ӽ��̶���һ����д��ĸ�������ַ�����c1
//	c2 = c1 + 32;//���ӦСд��ĸ��ASC����룬�����ַ�����c2�С�
//	putchar(c2);//���c2��ֵ����һ���ַ���
//	putchar('\n');
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int c1, c2;
//	c1 = 197;
//	c2 = 198;
//	printf("c1=%c,c2=%c\n", c1, c2);
//	printf("c1=%d,c2=%d\n", c1, c2);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	float x, y;
//	char c1, c2;
//	scanf("a=%db=%d", &a, &b);
//	scanf("%f%e", &a, &y);
//	scanf("%c%c", &c1, &c2);
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c, disc, x1, x2, p, q;
//	scanf("%1f%1f%1f", &a, &b, &c);
//	disc = b*b - 4 * a*c;
//	if (disc < 0)
//		printf("This equation hasn't ral root\n");
//	else
//	{
//		p = -b / (2.0*a);
//		q = sqrt(disc) / (2.0*a);
//		x1 = q + p;
//		x2 = q - p;
//		printf("real root:\n x1=%7.2f\n x2=%7.2f\n", x1, x2);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	float a, b, t;
//	scanf("%f,%f", &a, &b);
//	if (a > b)
//	{
//		t = a;
//		a = b;
//		b = t;
//		printf("%f,%f\n", a, b);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int x, y;
//	scanf("%d", &x);
//	if (x < 0)
//		y = -1;
//	else
//		if (x == 0) y = 0;
//		else y = 1;
//		printf("x=%d,y=%d\n", x, y);
//	return 0;
//}
#include<stdio.h>
//int main()
//{
//	float x, y;
//	scanf("%f", &x);
//	if (x < 1)
//		y = x;
//	else
//		if (x == 0) y = 2 * x - 1;
//		else y = 3 * x - 11;
//		printf("x=%f,y=%f", x, y);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int x, y;
//	printf("enter x:");
//	scanf("%d", &x);
//	if (x != 0)
//		if (x > 0)
//			y = 1;
//		else
//			y = -1;
//	else y = 0;
//	printf("x=%d,y=%d\n", x, y);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char grade;
//	scanf("%c", &grade);
//	switch (grade)
//	{
//	case 'A':printf("85-100\n"); break;
//	case 'B':printf("70-84\n"); break;
//	case 'C':printf("60-69\n"); break;
//	case 'D':printf("<60\n"); break;
//	default:printf("enter data error!\n");
//	}
//			
//
//	return 0;
//#include<stdio.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = str (arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//	return 0;
//}
//

//
//
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("************************\n");
//	printf("*******  1.play   ******\n");
//	printf("*******  2.exit   ******\n");
//	printf("************************\n");
//}
//void game()
//{
//     //��������Ϸ��ʵ��
//     //1.���������
//     //0-32767
//	 //ʱ���
//	int ret = 0;
//	int guess = 0;
//	ret = rand() % 100 + 1;
//	//printf("%d\n",ret);
//	//2.������
//	while (1)
//	{
//		printf("�������:");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();//�˵�
//		printf("��ѡ��:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int max(int x, int y);
//	int a, b, c;
//	scanf("%d%d", &a, &b);
//	c = max(a, b);
//	printf("max=%d\n", c);
//	return 0;
//}
//int max(int x,int y)
//{
//	int z;
//	if (x > y)
//		z = x;
//	else z = y;
//	return z;
//}
//#include<stdio.h>
//int main()
//{
//	int  b = 2, c = 1;
//	for (b = 2; b <= 5; b++)
//	{
//		c = b*c;
//	}
//    printf("c=%d\n", c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char c1, c2;
//	c1 = getchar();
//	c2 = c1 + 32;
//	putchar(c2);
//	putchar('\n');
//	return 0;
//
//
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	char password[20] = {0};
//	for (n = 0; n < 3; n++)
//	{
//		printf("����������:"); 
//		scanf("%s", password);
//		if (strcmp(password, "123456")==0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char c1='C',c2='H',c3='I',c4='N',c5='A';
//	c1 = c1 + 4;
//	c2 = c2 + 4;
//	c3 = c3 + 4;
//	c4 = c4 + 4;
//	c5 = c5 + 4;
//	//putchar(c1);
//	//putchar(c2);
//	//putchar(c3);
//	//putchar(c4);
//	//putchar(c5);
//	//putchar('\n');
//	printf("%c%c%c%c%c", c1, c2, c3, c4, c5);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int grade;
//	scanf("%d",&grade);
//	switch (grade)
//	{
//	case 90-100: printf("A\n"); break;
//	case 80-89 : printf("B\n"); break;
//	default:printf("enter data error!\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int grade;
//	scanf("%d", &grade);
//	switch (grade/10)
//	{
//	case 10:
//	case 9:printf("A\n"); break;
//	case 8:printf("B\n"); break;
//	case 7:printf("C\n"); break;
//	case 6:printf("D\n"); break;
//	default:printf("enter data error!\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{ 
//	int i = 1, s = 0;            //int i = 1,s=0;
//	do                           //while (i <= 100)
//	{                            //{
//		s = s + i;               //   s = i + s;
//		i++;                     //   i++;
//	} while (i <= 100);          //}
//    printf("s=%d\n", s);
//	return 0;
////}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int ch, line = 0, at_beginning = 1;
//	while ((ch = getchar()) != EOF)
//	{
//		if (at_beginning == 1)
//		{
//			at_beginning = 0;
//			line++;
//			printf("%d", line);
//		}
//		putchar(ch);
//		if (ch == '\n')
//			at_beginning = 1;
//	}
//	return EXIT_SUCCESS;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 1;
//	char password[20] = { 0 };
//	for (n = 1; n <= 3; n++)
//	{
//		printf("���������룺");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//			printf("��½ʧ��\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int key = 7;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			break;
//	}
//	if (left <= right)
//		printf("�ҵ��ˣ��±���%d\n", mid);
//	else
//		printf("�Ҳ���\n");
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
//	printf("max=%d\n", max);
//	return 0;
//}
//#include<stdio.h>
//void Swap1(int x, int y)
//{
//	int t = 0;
//	t = x;
//	x = y;
//	y = t;
//}
//void Swap2(int *px, int *py)
//{
//	int t = 0;
//	t = *px;
//	*px = *py;
//	*py = t;
//}
//int main()
//{
//	int num1;
//	int num2;
//	scanf("%d%d", &num1, &num2);
//	Swap1(num1, num2);
//	printf("Swap1::num1=%d num2=%d\n", num1, num2);
//	Swap2(&num1, &num2);
//	printf("Swap2::num1=%d num2=%d\n", num1, num2);
//	return 0;
//}
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
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[20] = "hello";
//	int ret = strlen(strcat(arr, "bit"));
//	printf("%d\n", ret);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		if ((i % 2) != 0)
//			printf("%d ", i);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int x = 10;
	int y = 10;
	x = y = ++y;
	printf("%d %d\n", x, y);
	return 0;
}
//#include<stdio.h>
//void sun(int x,int y)
//{
//	int i = 0;
//	for (i = 0;i<)
//
//}
//int main()
//{
//	char n[10] = {5,9,8,6,2,1,3,4,7,0};
//	char moon = sun[10];
//	printf("%s ", sun);
//	return 0;
//}
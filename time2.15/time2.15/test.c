#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void max(int x)
//{
//	if ((x % 4 == 0 && x & 10 != 0) || (x % 400 == 0))
//		printf("是闰年\n");
//	else
//		printf("不是闰年\n");
//}
//int main()
//{
//	int i;
//	printf("输入一个年份:");
//	scanf("%d", &i);
//	max(i);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double r=0.09, n=10.0;
//	double p=(1+r);
//	for (int i = 2; i <= 10; i++)
//	{
//		p = (1 + r)*p;
//	}
//	printf("%f ", p);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	float x, y;
//	char c1, c2;
//	scanf("%d %d", &a, &b);
//	scanf("%f %f", &x, &y);
//	scanf("%s %s", &c1, &c2);
//	printf("a=%d b=%d\n", a, b);
//	printf("x=%f y=%f\n", x, y);
//	printf("c1=%c c2=%c\n", c1, c2);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char arr[10] = { 'C','H','I','N','A' };
//	for (int i = 0; i < 5; i++)
//	{
//		arr[i] = arr[i] + 4;
//	}
//	printf("%s ", arr);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b, c,max;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b)
//		if (a > c) max = a;
//		else max = c;
//	else
//		if (b > c) max = b;
//		else max = c;
//		printf("max=%d\n", max);
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m, n;
//	while (1)
//	{
//		scanf("%d", &m);
//		if (m < 1000)
//		{
//			n = sqrt(m);
//			printf("%d\n", n);
//			break;
//		}
//		else
//		{
//			printf("again\n");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char password[10];
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("ok\n");
//			break;
//		}
//		else
//		{
//			printf("again\n");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	float x, y;
//	scanf("%f", &x);
//	if (x < 1) y = x;
//	if (1 <= x <= 10) y = 2 * x - 1;
//	if (x >= 10) y = 3 * x - 11;
//	printf("%f\n",y);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int score;
//	char w;
//	scanf("%d", &score);
//	switch (score/10)
//	{
//	case 10:
//	case 9: w = 'A'; break;
//	case 8: w = 'B'; break;
//	case 7: w = 'C'; break;
//	case 6: w = 'D'; break;
//	default:w = 'E'; break;
//	}
//	printf("%c\n", w);
//	return 0;
//}
//#include<stdio.h>}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int i = 0;
//	while (a != 0)
//	{
//		a /= 10;
//		i++;
//	}
//	printf("%d\n", i);
//	return 0;
//}

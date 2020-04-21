#define _CRT_SECURE_NO_WARNINGS 1

//1.冒泡法
//#include<stdio.h>
//int main()
//{
//	int arr[16] = { 1,3,5,7,8,9,4,32,12,33,21,12,14,13,16,15 };
//	int temp;
//	int i, m, n;
//	for (n = 0; n < 15; n++)
//	{
//		for (m = 0; m < 15 - n; m++)
//		{
//			if (arr[m] < arr[m + 1])
//			{
//				temp = arr[m];
//				arr[m] = arr[m + 1];
//				arr[m + 1] = temp;
//			}
//		}
//	}
//	for (i = 0; i < 16; i++)
//		printf("The order is:%d\n", arr[i]);
//	return 0;
//}

//2.数字遍历
//#include<stdio.h>
//int main()
//{
//	int n = 123456;
//	int i;
//	for (i = n; i; i /= 10)
//	{
//		printf("%d ", i%10);
//	}
//	return 0;
//}

//3.递归输出1234
//#include<stdio.h>
//void PrintNum(int num)
//{
//	if (num > 9)
//	{
//		PrintNum(num / 10);
//	}
//	printf("%d ", num%10);
//}
//int main()
//{
//	PrintNum(1234);
//	return 0;
//}

//4.计算一个数的位数 按位输出 逆序输出
//#include<stdio.h>
//#include<math.h>
//
//int factor(int x)
//{
//	int count = 1;
//	for (x; x / 10 != 0; x /= 10)
//	{
//		count += 1;
//	}
//	printf("%d",count);
//	return (count);
//}
//
//void Factor(int a)
//{
//	double n = factor(a);
//	double x = a;
//	int i, j;
//	for (n; n > 0; n--)
//	{
//		i = x / pow(10, n - 1);
//		j = i % 10;
//		printf("%d ", j);
//	}
//}
//
//void PrintNum(int num)
//{
//	int i;
//	for (i = num; i; i /= 10)
//	{
//		printf("%d ",i%10);
//	}
//}
//
//int main()
//{
//	int x;
//	printf("请输入一个不大于五位的正整数:\n");
//	scanf("%d", &x);
//	factor(x);
//	printf("\n");
//	Factor(x);
//	printf("\n");
//	printf("逆序输出:");
//	PrintNum(x);
//	printf("\n");
//	return 0;
//}

//5.完数
//#include<stdio.h>
//int Sum(int n)
//{
//	int i, sum = 0;
//	for (i = 1; i < n; i++)
//	{
//		if (n % i == 0)
//			sum += i;
//	}
//	return sum;
//}
//int main()
//{
//	for (int j = 2; j < 1000; j++)
//	{
//		if (Sum(j) == j)
//			printf("%d is 完数！\n", j);
//	}
//	return 0;
//}

//6.反向输出字符串
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i, j, k;
//	char c[200], c1;
//	printf("Enter a string:\n");
//	scanf("%s", c);
//	k = strlen(c);
//	for (i = 0, j = k - 1; i < j; i++, j--)
//	{
//		c1 = c[i];
//		c[i] = c[j];
//		c[j] = c1;
//	}
//	printf("%s", c);
//	return 0;
//}

//7.杨辉三角
//#include<stdio.h>
//int main()
//{
//	int i, j;
//	int a[7][7];
//	for (i = 0; i <= 6; i++)
//	{
//		a[i][i] = 1;
//		a[i][0] = 1;
//	}
//	for (i = 2; i <= 6; i++)
//	{
//		for (j = 1; j <= i - 1; j++)
//		{
//			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//		}
//	}
//	for (i = 0; i <= 6; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%4d",a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

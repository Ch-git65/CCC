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

//8.回文字符串
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s[100];
//	printf("Enter a string:\n");
//	gets(s);
//	int i, j, n;
//	n = strlen(s);
//	for (i = 0, j = n - 1; i < j; i++, j--)
//	{
//		if (s[i] != s[j]) {
//			break;
//		}
//	}
//	if (i >= j)
//	{
//		printf("This is a huiwen string.\n");
//	}
//	else {
//		printf("This is not a huiwen string.\n");
//	}
//	return 0;
//}

//9.从字符数组中删除d中的字符
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s[200];
//	char a;
//	printf("Enter a string.\n");
//	gets(s);
//	printf("Enter a charater.\n");
//	a = getchar();
//	int i, j;
//	for (i = 0, j = 0; s[i] != '\0'; i++)
//	{
//		if (s[i] != a)
//		{
//			s[j++] = s[i];
//		}
//	}
//	if (s[i] == '\0')
//	{
//		s[j] = s[i];
//	}
//	printf("%s\n", s);
//}

//10.从100米的地方落下的球，每一次弹起来是下落的一半，则第十次弹多高，共多高
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double sum = 0, sum_down = 0, sum_up = 0, h = 0;
//	double i;
//	for (i = 0.0; i <= 9.0; i++)
//	{
//		sum_down = sum_down + 100 * pow(1.0 / 2.0, i);
//	}
//	for (i = 1.0; i < 9.0; i++)
//	{
//		sum_up = sum_up + 100 * pow(1.0 / 2.0, i);
//	}
//	sum = sum_down + sum_up;
//	h = 100 * pow(1.0 / 2.0, 10);
//	printf("第十次高度:%1f米\n", h);
//	printf("共%1f米\n", sum);
//	return 0;
//}

//11.选择法，以小到大开始排列
//#include<stdio.h>
//void Sort(int arr[], int n)
//{
//	int i, j, temp;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (arr[j] < arr[i])
//			{
//				temp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int a[10];
//	printf("Enter a array:\n");
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	Sort(a, 10);
//	printf("The sorted array:\n");
//	for (i = 0; i < 10; i++) {
//		printf("%d", a[i]);
//	}
//	printf("\n");
//	return 0;
//}

//12.输入16进制，以10进制输出
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i, j = 0;
//	int x, y = 0;
//	printf("Enter a number:\n");
//	scanf("%d", &i);
//	while (i != 0) {
//		x = i % 10;
//		y += x * pow(16, j);
//		i /= 10;
//		j++;
//	}
//	printf("%d\n", y);
//	return 0;
//}

//13.猴子摘桃
//#include<stdio.h>
//int main()
//{
//	int i, N = 1;
//	for (i = 1; i < 10; i++)
//	{
//		N = (N + 1) * 2;
//	}
//	printf("%d\n", N);
//	return 0;
//}

//14.正整数分解质因数
//#include<stdio.h>
//int main()
//{
//	int i, n;
//	printf("请输入数字:\n");
//	scanf("%d", &n);
//	printf("%d=", n);
//	for (i = 2; i <= n; i++)
//	{
//		while (n > i) {
//			if (n % i == 0) {
//				printf("%d*", i);
//				n /= i;
//			}
//			else {
//				break;
//			}
//		}
//	}
//	printf("%d\n", n);
//	return 0;
//}

//15.迭代法求平方根
//#include<stdio.h>
//#include<math.h>
//#define Epsilon 1.0E-6
//int main()
//{
//	float a, x0, x1;
//	printf("请输入要求的数:\n");
//	scanf("%f", &a);
//	x0 = a / 2;
//	x1 = (x0 + a / x0) / 2;
//	while (fabs(x1 - x0) >= Epsilon) {
//		x0 = x1;
//		x1 = (x0 + a / x0) / 2;
//	}
//	printf("平方根为:%f\n", x1);
//	return 0;
//}

//16.输入字母，判断周几
//#include<stdio.h>
//int main() {
//	char letter;
//	printf("please input the first letter of someday\n");
//	while ((letter = getchar()) != 'Y') {
//		switch (letter) {
//		case 'S':printf("please input the second letter:\n");
//			if ((letter = getchar()) == 'a')
//				printf("Saturday\n");
//			else if ((letter = getchar()) == 'u')
//				printf("Sunday\n");
//			else
//				printf("data error.\n");
//			break;
//		case 'F':printf("Friday");
//			break;
//		case 'M':printf("Monday");
//			break;
//		case 'T':printf("please input the second letter:\n");
//			if ((letter = getchar()) == 'u')
//				printf("Tuesday\n");
//			else if ((letter = getchar()) == 'h')
//				printf("Thursday\n");
//			else
//				printf("data error.");
//			break;
//		case 'W':printf("Wednesday");
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}

//17.二进制按位取反
//#include<stdio.h>
//int main() {
//	int a = 12;
//	int b;
//	b = ~a;
//	printf("将a取反得到b:%d\n", b);
//	return 0;
//}

//18.用指针顺序输出a和b的最大最小值
//#include<stdio.h>
//int main() {
//	int* p1, * p2, * p, a, b;
//	printf("please enter two integer numbers:");
//	scanf("%d %d", &a, &b);
//	p1 = &a;
//	p2 = &b;
//	if (a < b) {
//		p = p1;
//		p1 = p2;
//		p2 = p;
//	}
//	printf("a=%d,b=%d\n", a, b);
//	printf("max=%d, min=%d\n", *p1, *p2);
//	return 0;
//}
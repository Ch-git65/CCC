#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int n,a,b,c,m=10;
//	for (n = 0; n < m; n++, putchar('\n'))
//		for (a = n, b = c = 1; a >= 0; c = c*a-- / b++)
//			printf("%*d", (b==1?m-n:2)*2,c);
//	return 0;
//}
//#include<stdio.h>
//#define N 10
//int main()
//{
//	int i, j;
//	int a[N][N] = {0};
//	for (i = 0; i < N; i++)
//	{
//		a[i][0] = 1;
//		printf("%3d",a[i][0]);
//		for (j = 1; j <= i; j++)
//		{
//			if (i == j) { a[i][j] = 1; }
//			else { a[i][j] = a[i - 1][j - 1] + a[i - 1][j]; }
//			printf("%3d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int age(int n);
//	printf("NO.5,age:%d\n", age(5));
//	return 0;
//}
//int age(int n)
//{
//	return n == 1 ? 10 : age(n - 1) + 2;
//}
//#include<stdio.h>
//int fac(int n)
//{
//	if (n < 0)  printf("n<0,data error!");
//	return (n == 0 || n == 1) ? 1 : fac(n - 1)*n;
//}
//int main()
//{
//	int n, y;
//	printf("input an number:");
//	scanf("%d", &n);
//	y = fac(n);
//	printf("%d!=%d\n", n, y);
//	return 0;
//}
//#include<stdio.h>
//int gy(int x, int y)
//{
//	int n = x > y ? y : x;
//	for (int i =n; i > 0; i--)
//	{
//		if (x%i == 0 && y%i == 0)
//			printf("%d\n", i);
//		break;
//	}
//	return 0;
//}
//int gb(int x, int y)
//{
//	int n = x > y ? y : x;
//	int m = x > y ? x : y;
//	for (int i = 1; i < n; i++)
//	{
//		if (i*m%n==0)
//			printf("%d\n", i*m);
//		break;
//	}
//	return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	gy(a, b);
//	gb(a, b);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i;
//	char password[10];
//	for ( i = 0; i < 3; i++)
//	{
//		printf("please input password:");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("succeed\n");
//			break;
//		}
//		else printf("again\n");
//	}
//	if (i == 3) printf("default\n");
//	return 0;
//}
//将输入的字符反向输出
//#include<stdio.h>
//int main()
//{
//	char c[200], c1;
//	int i, j, k;
//	printf("enter a string:");
//	scanf("%s", c);
//	k = strlen(c);
//	for (i = 0, j = k - 1; i < k / 2; i++, j--)
//	{
//		c1 = c[i]; c[i] = c[j]; c[j] = c1;
//	}
//	printf("%s\n", c);
//	return 0;
//}
//将s中删除的存放在c中
#include<stdio.h>
int main()
{
	char s[80	], c;
	int i, k;
	printf("enter a string:");
	gets(s);
	printf("enter a character:");
	c = getchar();
	for (i = k = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[k++] = s[i];
	s[k] = '\0';
	printf("%s\n", s);
	return 0;
}
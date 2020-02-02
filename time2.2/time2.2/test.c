#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int x, y, z;
//	scanf("%d %d", &x, &y);
//	z = x;
//	x = y;
//	y = z;
//	printf("x=%d y=%d\n",x,y);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(long double));
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	printf("c:\code\test.c\n");
//	printf("%d\n",strlen("c:\code\test.c\n"));
//	printf("%d\n",strlen("abcdef"));
//	printf("c:\test\32\test.c\n");
//	printf("%d\n",strlen("c:\test\32\test.c\n"));
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//typedef unsigned int unit_32;
//int main()
//{
//	unsigned int num1 = 0;
//	unit_32 num2 = 0;
//	return 0;
//}
//#include<stdio.h>
//void test()
//{
//	static int i = 0;
//	i++;
//	printf("%d ",i);
//}
//int main()
//{
//  int i=0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char*)); 
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(double*));
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 != 0)
//			printf("%d ",i);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;//break;
//		printf("%d ", i);
//		i = i + 1;
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//		putchar(ch);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int ch = 0;
//	while((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>  '9')
//			continue;
//		putchar(ch);
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)
//		k++;
//	printf("i=%d\n k=%d\n",i,k);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char password[20];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//			printf("重新登陆\n");
//	}
//	if (i == 3)
//		printf("退出登录\n");
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
//		printf("找到了，下标是%d\n", mid);
//	else
//		printf("找不到\n");
//
//	return 0;
//}
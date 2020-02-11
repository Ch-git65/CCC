#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char str[] = "ABCD", *p = str;
//	printf("%d\n", *(p+4));
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 100, b = 10;//定义整型变量a,b，并初始化
//	int *pointer_1, *pointer_2;//定义指向整数数据的指针变量
//	pointer_1 = &a;//把变量a的地址赋给指针变量
//	pointer_2 = &b;
//	printf("a=%d,b=%d\n", a, b);
//	printf("*pointer_1=%d,*pointer_2=%d\n", *pointer_1, *pointer_2);
//	return 0;
//}
//输入两个整数，按大小顺序输出
//#include<stdio.h>
//int main()
//{
//	int *p1, *p2, *p, a, b;
//	printf("请输入两个数:");
//	scanf("%d,%d", &a, &b);
//	p1 = &a;
//	p2 = &b;
//	if (a < b)
//	{
//		p = p1;
//		p1 = p2;
//		p2 = p;
//	}
//	printf("a=%d,b=%d\n", a, b);
//	printf("max=%d,min=%d\n", *p1, *p2);
//	return 0;
//}
//输入一个整型数组，输出其全部元素
//#include<stdio.h>
//int main() {
//	int a[10];
//	int i;
//	printf("请输入十个数:");
//	for (i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	for (i = 0; i < 10; i++)
//		scanf("%d", a[i]);
//	printf("%\n");
//	return 0;
//}
//
#include<stdio.h>
int main()
{
	int i = 0;
	char password[20];
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:");
		scanf("password", &password);
		if (strcmp(password, "123456") == 0)
			printf("登陆成功\n");
			break;
	}
	if (i == 3)
		printf("登陆失败\n");
	return 0;
}

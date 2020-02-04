#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[3][4] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			arr[i][j] = i * 4 + j;
//		}
//	}
//		for (i = 0; i < 3; i++)
//		{
//			int j = 0;
//			for (j = 0; j < 4;j++)
//			{
//				printf("%d ",arr[i][j]);
//		}
//	}
//	return 0;
//}

//打印二维数组的每个元素
//#include<stdio.h>
//int main()
//{
//	int arr[3][4];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d]=%p\n", i,  j, &arr[i][j]);
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int num1 = 1;  //001
//	int num2 = 2;  //010
//	int a, b, c;
//	a=num1&num2;   //000 有0为0              a=0
//	b=num1 | num2; //011 有1为1              b=3
//	c=num1^num2;   //011 相同为0，不同为1    c=3
//	printf("a=%d\n b=%d\n c=%d\n",a,b,c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 10; //  1010
//	int b = 20; // 10100
//	a = a^b;    // 11110=a=30
//	            // 10100
//	b = a^b;    // 01010=b=10
//	            // 11110
//	a = a^b;    // 10100=a=20
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}

//求一个整数储存在内存中的二进制中1的个数
//#include<stdio.h>
//int main()
//{
//	int num = 10;//1010
//	int count = 0;//计数
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num = num / 2;
//	}
//	printf("二进制中1的个数=%d\n",count);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int num = -1;//100000000000001
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((num >> i) & 1) == 1)
//			count++;
//	}
//	printf("count=%d\n", count);
//	return 0;
//}
//#include<stdio.h>
//int main() 
//{
//	int num = -1;
//	int i = 0;
//	int count = 0;
//	while (num)
//	{
//		count++;
//		num = num&(num - 1);
//	}
//	printf("二进制中1的个数=%d\n",count);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = -10;
//	int *p = NULL;
//	printf("%d\n", !2);
//	printf("%d\n", !0);
//	a = -a;
//	p = &a;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof a);
//	return 0;
//}
//#include<stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n",sizeof(arr));//4
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//4
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));//40
//	printf("%d\n", sizeof(ch)); //10
//	test1(arr);
//	test2(ch);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;//1 2 3 4
//	i = a++ || ++b || d++;//1 3 3 4
//	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	return 0;
//}
//#include<stdio.h>
//void test1()
//{
//	printf("hehe\n");
//}
//void test2(const char *str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	test1();
//	test2("hello bit.");
//	return 0;
//}
//#include<stdio.h>
//struct Stu
//{
//	char name[10];
//	int age;
//	char sex[5];
//	double score;
//};
//void set_agel(struct Stu stu)
//{
//	stu.age = 18;
//}
//void set_age2(struct Stu* pStu)
//{
//	pStu->age = 18;
//}
//int main()
//{
//	struct Stu stu;
//	struct Stu*  pStu = &stu;
//
//	stu.age = 20;
//	set_age1(stu);
//
//	pStu->age = 20;
//	set_age2(pStu);
//	return 0;
//}
//整型提升
//#include<stdio.h>
//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0x6000000;
//	if (a == 0xb6)
//		printf("a");
//	if (b = 0xb600)
//		printf("b");
//	if (c == 0x6000000)
//		printf("c");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c)); //1
//	printf("%u\n", sizeof(+c));//4
//	printf("%u\n", sizeof(!c));//1
//	return 0;
//}
//#include<stdio.h>
//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//	int answer;
//	answer = fun() - fun()*fun();
//	printf("%d\n",answer);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int ret = (++i) + (++i) + (++i);
//	printf("%d\n", i);
//	printf("%d\n", ret);
//	return 0;
//}
#include<stdio.h>
#include<string.h>
int main()
{
	char password[20];
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:");
		scanf("%s", &password);
		if (strcmp(password, "123456") == 0)
			break;
		else
			printf("请重新输入\n");
	}
	if (i == 3)
		printf("输入错误，退出\n");
	else
		printf("登陆成功\n");
}

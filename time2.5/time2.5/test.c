#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	int n = 10;
//	char *pc = (char*)&n;
//	int *pi = &n;
//	printf("%p\n", &n);   //012FFEAC
//	printf("%p\n", pc);   //012FFEAC
//	printf("%p\n", pc+1); //012FFEAD
//	printf("%p\n", pi);   //012FFEAC
//	printf("%p\n", pi+1); //012FFEBO
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0x11223344;
//	char *pc = (char *)&n;
//	char *pi = &n;
//	*pc = 0x55;
//	*pi = 0;
//	printf("%p\n", pc);
//	printf("%p\n", pi);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int *p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p <====> p+%d = %p\n", i, arr[i], i, p+i );
//	}
//	return 0;
//}
//用指针访问数组
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int *p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	return 0;
//}

//结构体成员的访问
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//};
//void print(struct Stu* ps)
//{
//	printf("name=%s age=%d\n", (*ps).name, (*ps).age);
//	//用结构体指针访问指向对象的成员
//	printf("name=%s age=%d\n", ps->name, ps->age);
//}
//int main()
//{
//	struct Stu s = {"haha", 20};
//	print(&s);//结构体地址传参
//	return 0;
//}

//结构体传参
//#include<stdio.h>
//struct S
//{
//	int data[1000];
//	int num;
//};
//
//struct S s = { {1,2,3,4}, 1000 };
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s); //传结构体
//	print2(&s);//传地址
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
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//			break;
//	}
//	if (i == 3)
//		printf("登陆失败\n");
//	else
//		printf("登陆成功\n");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("************************\n");
	printf("*******  1.play   ******\n");
	printf("*******  2.exit   ******\n");
	printf("************************\n");
}
void game()
{
     //猜数字游戏的实现
     //1.生成随机数
     //0-32767
	 //时间戳
	int ret = 0;
	int guess = 0;
	ret = rand() % 100 + 1;
	//printf("%d\n",ret);
	//2.猜数字
	while (1)
	{
		printf("请猜数字:");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//菜单
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
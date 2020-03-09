#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<windows.h>
#include<string.h>

#define N 10

enum Sex//枚举性别的两种可能
{
	male, female
};

struct Student {
	char name[20];
	int num;      //100-109
	char sex[10];
	int Math;
}stu[N] = { {"张三", 100, "male" , 100},
{"李四", 101, "male", 56},
{"王婆", 102, "female", 78}
};

void PrintUi()
{
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║                                                              ║\n");
	printf("\t║                                                              ║\n");
	printf("\t║                 ._______________________.                    ║\n");
	printf("\t║                 | _____________________ |                    ║\n");
	printf("\t║                 | I                   I |                    ║\n");
	printf("\t║                 | I    教学管理系统   I |                    ║\n");
	printf("\t║                 | I                   I |                    ║\n");
	printf("\t║                 | I___________________I |                    ║\n");
	printf("\t║                 !_______________________!                    ║\n");
	printf("\t║                     ._[__________]_.                         ║\n");
	printf("\t║                 .___|_______________|___.                    ║\n");
	printf("\t║                  |:::  ____            |                     ║\n");
	printf("\t║                  |     密码：          |                     ║\n");
	printf("\t║                  !_____________________!                     ║\n");
	printf("\t║                                                              ║\n");
	printf("\t║                                                              ║\n");
	printf("\t║                                                              ║\n");
	printf("\t║                                                              ║\n");
	printf("\t╚═══════════════════════════════╝\n");
}

int Land() //登陆函数
{
	printf("请输入您的登陆密码:");
	int password;
	int a = 123456;
	for (int n = 1; n <= 3; n++)
	{
		scanf("%d", &password);
		if (password == a) {
			system("cls");
			printf("您输入的密码正确!\n");
			printf("正在登陆，请稍等....\n");
			Sleep(4000);//登录延时，产生短暂的登陆状态
			system("cls");
			return 1;
		}
		else
		{
			printf("您输入的密码有误，请重新输入!\n");
		}
		if (n == 3) {
			printf("您的机会已用尽!\n");
			return -1;
		}
	}
	return 0;
}

void PrintMode() {//系统菜单页面
	printf("**************************************\n");
	printf("**************************************\n");
	printf("******                        ********\n");
	printf("******       教 学 系 统      ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("******     1. 录 入 信 息     ********\n");
	printf("******     2. 输 出 信 息     ********\n");
	printf("******     3. 查 询 信 息     ********\n");
	printf("******     4. 成 绩 排 名     ********\n");
	printf("******     0. 退 出 系 统     ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("**************************************\n");
	printf("**************************************\n");
}

int Welcome() //欢迎函数
{
	PrintUi(); //打印主界面函数
	int i = Land();
	if (i == 1) {
		PrintMode();
		return 0;
	}
	else
	{
		return -1;
	}
}

int Search(int i)//查询函数，为了后面输出特定的信息而进行学号的查找
{
	for (int n = 0; n < N; n++)
	{
		if (i == stu[n].num) {
			return n;
		}
	}
	return -1;
}

void InPut()
{
	int i;
	printf("提示：姓名 学号（100-109） 性别（male,female） 数学成绩（100分制）\n");
	printf("请输入全部的学生信息：\n");
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %s %d", &stu[i].name, &stu[i].num, &stu[i].sex, &stu[i].Math);
	}
}

void SpecialPut()
{
	int i, c;
	printf("请输入你要查找的学号（100-109）:");
	while (1)
	{
		scanf("%d", &i);
		c = Search(i);
		if (c == -1)
		{
			printf("您的输入有误!\n");
			continue;
		}
		printf("姓名：%s\n学号：%d\n性别：%s\n数学：%d\n", stu[c].name, stu[c].num, stu[c].sex, stu[c].Math);
		break;
	}
}

void OutPut() {
	int i;
	printf("----------------------------------------------\n");
	printf("|姓名：   |学号：    |性别：   |数学：   |\n");
	for (i = 0; i < N; i++) {
		printf("|%s       |%d        |%s       |%d       |\n", stu[i].name, stu[i].num, stu[i].sex, stu[i].Math);
	}
	printf("----------------------------------------------\n");
}

void Rand()
{
	int i, j, num, math;
	char name[20], sex[10];
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (stu[j].Math > stu[i].Math) {
				math = stu[j].Math;//将数学成绩进行调换
				stu[j].Math = stu[i].Math;
				stu[i].Math = math;

				strcpy(name, stu[j].name);//对于字符串不能够进行直接转换，因为指针所指向的只是字符串的首地址
				strcpy(stu[j].name, stu[i].name);//因此使用strcpy函数来进行字符串的复制
				strcpy(stu[i].name, name);

				num = stu[j].num;//和成绩类似
				stu[j].num = stu[i].num;
				stu[i].num = num;

				strcpy(sex, stu[j].sex);//性别和名字类似
				strcpy(stu[j].sex, stu[i].sex);
				strcpy(stu[i].sex, sex);
			}
		}
	}
	printf("成绩排名为:\n");
	OutPut();
}

int main()
{
	int c = Welcome();
	if (c == 0)
	{
		int choice;
		printf("请输入您要进行的操作序号:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:InPut();
			break;
		case 2:OutPut();
			break;
		case 3: SpecialPut();//按学号查找并输出此学生的信息
			break;
		case 4: Rand();//科目成绩排名
			break;
		case 0://退出系统
			system("cls");
			printf("您选择退出系统!");
			break;
		}
	}
	return 0;
}

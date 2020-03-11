#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//字符转数字
int Trans(char c)
{
	return (c - 48);
}

//基础格式检查
int CheckFormat(char* id)
{
	if (strlen(id) != 18)
	{
		printf("输入错误!\n");
		return 0;
	}
	for (int i = 0; i < 18; i++)
	{
		if (id[i] > '9' || id[i] < 0)
		{
			printf("输入错误，出现非数字！\n");
			return 0;
		}
	}
	if ((id[17] > '9' || id[17] < '0') && id[17] != 'X')
	{
		printf("输入错误，第18位不是数字或X，请检查后重试！\n");
		return 0;
	}
	return 1;
}

//出生日期检查
int CheckDate(int year, int month, int day)
{
	int sign = 1;
	if (month > 12 || month < 1) sign = 0;
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29 || day < 1)sign = 0;
		}
		else if (day > 28 || day < 1)sign = 0;
	}
	switch (month)//根据月份来判断月份天数是否合格
	{//此都归为大月
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31 || day < 1)sign = 0; break;
	case 4://此类归为小月
	case 6:
	case 9:
	case 11:
		if (day > 30 || day < 1)sign = 0; break;
	}
	if (sign == 0)
	{
		printf("该身份证号出生日期格式不正确，请检查后重试！\n");
		return 0;
	}
	return 1;
}

int CheckCode(char* id)
{//对于这一个子函数的定义，很多人可能会不懂，我们可以进行百度搜索关于身份证校验的规则就可以明白
	int r[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	int check;
	char code[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3','2' };
	int sum = 0;
	for (int i = 0; i < 17; i++)
	{
		sum += (Trans(id[i])) * r[i];
	}
	check = sum % 11;
	if (id[17] != code[check])
	{
		printf("该身份证号未通过ISO校验,请检查最后一位后重试\n");
		return 0;
	}

	return 1;
}

//常住户口所在地输出函数
void FindAddress(char* id)//根据身份证前六位输出所对应的地址
{
	int address;
	address = Trans(id[0]) * 100000 + Trans(id[1]) * 10000
		+ Trans(id[2]) * 1000 + Trans(id[3]) * 100
		+ Trans(id[4]) * 10 + Trans(id[5]);
	printf("常住户口所在地：");
	//DataBase(address);//调用基础数据检测前六位所对应的地址
	printf("\n");
}

//-- - 性别输出函数------ -
//身份证的第17位，奇数为男，偶数为女，通过除2得余数来判断
void FindSex(char* id)
{
	int sex = Trans(id[16]);
	printf("性别：");
	if (sex % 2 == 1)printf("男\n");
	if (sex % 2 == 0)printf("女\n");
}

//---- - 年龄和出生日期输出函数------ -
//void FindBirthday(int year, int month, int day)//用来计算身份证所对应的出生年月日来计算对应的年龄
//{
	//time_t timep;
	//struct tm* p;
	//time(&timep);
	//p = gmtime(&timep);//获取系统时间中的年份
	//printf("年龄：%d岁\n", (1900 + p->tm_year) - year);
	//printf("出生日期：%4d年%2d月%2d日\n", year, month, day);
//}

//顺序码输出函数------ -
void FindCode(char* id)//表示给同地同日出生的人进行编号第15-17位原样输出即可
{
	printf("当地同年同月同日出生的第%c%c%c个孩子\n", id[14], id[15], id[16]);
}

//行政区划代码数据库------ -
void DataBase(int address)
{
	switch (address)
	{
	case 110000:printf("北京市"); break;
	case 110100:printf("北京市市辖区"); break;
	case 110101:printf("北京市市辖区东城区"); break;
	case 110102:printf("北京市市辖区西城区"); break;
	case 710000:printf("台湾省"); break;
	case 810000:printf("香港特别行政区"); break;
	case 820000:printf("澳门特别行政区"); break;
	default:
		printf("数据库中无此行政代码"); break;
	}
}


int main()
{
	char id[20] = { 0 };
	char choose;
	int year, month, day;
	printf("身份证号校验or查询系统\n");
start:
	printf("————————————\n");
	printf("请输入需要查询的身份证号：\n");
	scanf("%18s", id);
	if (CheckFormat(id) == 0) goto start;  //检查是否18位
	year = Trans(id[6]) * 1000 + Trans(id[7]) * 100 + Trans(id[8]) * 10 + Trans(id[9]);
	month = Trans(id[10]) * 10 + Trans(id[11]);
	day = Trans(id[12]) * 10 + Trans(id[13]);
	if (CheckDate(year, month, day) == 0)goto start;
	if (CheckCode(id) == 0) goto start;
	printf("该身份证号是合法的!\n");
	printf("————————————\n");
	printf("信息如下:\n");
	FindAddress(id);
	FindSex(id);
	//FindBirthday(id);
	FindCode(id);
	printf("————————————\n");
	printf("是否要再次查询？按Y继续，按其他键退出。\n");
	scanf("%c", &choose);
	if (choose == 'Y' || choose == 'y')goto start;
	return 0;
}
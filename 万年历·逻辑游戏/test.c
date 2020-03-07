#define _CRT_SECURE_NO_WARNINGS 1
////万年历
//#include<stdio.h>
//
////闰年的判断
//int Leap(int year) {
//	if (year % 400 == 0) { return 1; }
//	if (year % 4 == 0 && year % 100 != 0) { return 1; }
//	return 0;
//}
//
////计算在所需要输出年份之前的总天数有多少天，
//int DayCount(int year) {
//	int count = 0;
//	count = 365 * (year - 1900);//计算从1900年到所输入年份之前的总天数
//	for (int i = 1900; i < year; i++) {
//		if (Leap(i) == 1) {
//			count++;
//		}
//	}
//	return count;
//}
//
//void LayOut(int year, int month) {
//	int i, n;
//	int M[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int daysum = 0;
//	daysum = DayCount(year);
//	if (month <= 2) {//若是二月，只需要增加一月的日子
//		daysum += 31;
//	}
//	if (month > 2) {//大于二月，先进行求闰年，若是则加1；
//		daysum += Leap(year);
//		for (i = 0; i < month; i++)
//		{
//			daysum += M[i];
//		}
//	}
//	n = (daysum % 7) + 1;//计算星期几
//	printf("日 一 二 三 四 五 六 \n");
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("   ");
//		count += 1;
//	}
//	for (i = 1; i < M[month]; i++) {
//		printf("%-2d ", i);
//		count += 1;
//		if (count % 7 == 0) {
//			printf("\n");
//		}
//	}
//}
//int main() {
//	int year = 0;
//	int month = 0;
//	printf("请输入你要查看的万年历年 月:");
//	scanf("%d %d", &year, &month);
//	LayOut(year, month);
//	return 0;
//}

//逻辑数字游戏
#include<stdio.h>
#include<time.h>
#include<windows.h>

//生成随机的四个不重复的数
void slashCard(int arr[]) {
	srand((unsigned int)time(NULL));//定义时间戳
	int s;
	int str[10] = {0,1,2,3,4,5,6,7,8,9};
	int i;
	for (i = 0; i < 4; i++) {
		s = rand() % 10;//取0-9的数
		while (str[s] == -1) {//如果这个数取过，则取下一位
			s++;
			if (s == 10)
			{
				s = 0;
			}
		}
		arr[i] = str[s];//将取出来的值放入
		str[s] = -1;//将所去走的的值置换为-1
	}
}

//打印函数
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

//判断函数
int judgeAns(int ans[], int arr[])
{
	int i, j;
	int countA = 0;//代表存在数目数值和数都对
	int countB = 0;//代表存在这个数
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			if (ans[i] == arr[j]) {
				countB++;
				break;
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (ans[i] == arr[i])
		{
			countA++;
		}
	}
	countB = countB - countA;
	printf("%dA%dB\n", countA, countB);
	if (countA == 4)
	{
		return 1;
	}
	return 0;
}

int main() {
	int i, j;
	int arr[4];
	slashCard(arr);//采用时间戳随机生成四个数字
	int ans[4];
	for (i = 1; i < 9; i++) {//回答次数
		printf("第%d次输入:\n", i);
		for (j = 0; j < 4; j++) {
			scanf("%d", &ans[j]);//输入自己猜的四个数
		}
		if (judgeAns(ans, arr))//判断
		{
			break;
		}
	}
	if (i == 9) {
		printf("您的次数已用尽!\n");
		printf("正确答案为:\n");
		printArray(arr, 4);
	}
	else
	{
		printf("恭喜你，挑战成功！\n");
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

//为了实现左旋，分两个步骤
//先实现一个函数，一次左旋一个字符
//再实现一个函数，一次左旋N个字符

void LeftRotateOne(char str[], int size)
{
	//如果长度为1，就没必要
	if (size == 1) {
		return;
	}
	//如果长度超过1
	//1.先把0号下标的元素备份下
	char tmp = str[0];
	//2.再把1号下标开始的元素依次往左移动
	for (int i = 1; i < size; i++)
	{
		str[i - 1] = str[i];
	}
	//3.把刚才备份的字符放到最后一个元素的位置上区
	str[size - 1] = tmp;
}

void LeftRotateN(char str[], int n, int size)
{
	for (int i = 0; i < n % size; i++)
	{
		LeftRotateOne(str, size);
	}
}

int RotateCmp(char str1[], char str2[])
{
	//可以把str1进行左旋若干次，每次左旋后都和str2比较
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
	{
		return 0;
	}
	for (int i = 0; i < len1; ++i)
	{
		if (strcmp(str1, str2) == 0) {
			return 1;
		}
		LeftRotateOne(str1, len1);
	}
	return 0;
}

#define ROW 3
#define COL 3
int FindNum(int arr[ROW][COL], int to_find)
{
	int row = 0;
	int col = COL - 1;
	int cur = arr[row][col];
	while (row >= 0 && row < ROW && col >= 0 && col < COL)
	{
		if (to_find < cur)
		{
			cur = arr[row][--col];
		}
		else if (to_find > cur) {
			cur = arr[++row][col];
		}
		else {
			return 1;
		}
	}
	return 0;
}
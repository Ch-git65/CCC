#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

//Ϊ��ʵ������������������
//��ʵ��һ��������һ������һ���ַ�
//��ʵ��һ��������һ������N���ַ�

void LeftRotateOne(char str[], int size)
{
	//�������Ϊ1����û��Ҫ
	if (size == 1) {
		return;
	}
	//������ȳ���1
	//1.�Ȱ�0���±��Ԫ�ر�����
	char tmp = str[0];
	//2.�ٰ�1���±꿪ʼ��Ԫ�����������ƶ�
	for (int i = 1; i < size; i++)
	{
		str[i - 1] = str[i];
	}
	//3.�Ѹղű��ݵ��ַ��ŵ����һ��Ԫ�ص�λ������
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
	//���԰�str1�����������ɴΣ�ÿ�������󶼺�str2�Ƚ�
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
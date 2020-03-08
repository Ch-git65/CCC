#define _CRT_SECURE_NO_WARNINGS 1

//高精度加法
//#include<stdio.h>
//#include<string.h>
//
//typedef struct HA {
//	char num[102];
//	int size;
//}HighAcc;
//
//HighAcc dealNum(char* num) {
//	int i = 0;
//	int len = strlen(num);
//	HighAcc tem = { 0 };
//	for (; i < len; i++) {
//		tem.num[i] = num[len - 1 - i] - '0';
//	}
//	tem.size = len;
//	return tem;
//}
//
//HighAcc add(HighAcc num1, HighAcc num2)
//{
//	int longer = num1.size > num2.size ? num1.size : num2.size;
//	HighAcc res = { 0 };
//	int i, tmp;
//	for (i = 0; i < longer; i++)
//	{
//		tmp = num1.num[i] + num2.num[i] + res.num[i];
//		res.num[i] = tmp % 10;
//		res.num[i + 1] = tmp / 10;
//	}
//	res.size = longer + res.num[i];
//	return res;
//}
//
//void PrintNum(HighAcc num)
//{
//	for (int i = num.size - 1; i >= 0; i--)
//	{
//		printf("%d",num.num[i]);
//	}
//}
//
//int main()
//{
//	char num[102] = { 0 };
//	scanf("%s", num);
//	HighAcc num1 = dealNum(num);
//	scanf("%s", num);
//	HighAcc num2 = dealNum(num);
//	HighAcc res = add(num1, num2);
//	PrintNum(res);
//	return 0;
//}

//高精度乘法
//#include<stdio.h>
//#include<string.h>
//
//typedef struct Hh {
//	char num[102];
//	int size;
//}HighAcc;
//
//HighAcc dealNum(char* num) {
//	int i = 0;
//	int len = strlen(num);
//	HighAcc tem = { 0 };
//	for (; i < len; i++) {
//		tem.num[i] = num[len - 1 - i] - '0';
//	}
//	tem.size = len;
//	return tem;
//}
//
//HighAcc Mul(HighAcc num1, HighAcc num2)
//{
//	HighAcc res = { 0 };
//	if (num1.size == 1 && num1.num[0] == 0 ||
//		num2.size == 1 && num2.num[0] == 0)
//	{
//		res.size = 1;
//		return res;
//	}
//	int i, j, tmp;
//	for (i = 0; i < num1.size; i++)
//	{
//		for (j = 0; j < num2.size; j++)
//		{
//			tmp = num1.num[i] * num2.num[j] + res.num[i + j];
//			res.num[i + j] = tmp % 10;
//			res.num[i + j + 1] += tmp / 10;
//		}
//	}
//	res.size = i + j - !res.num[i + j - 1 ];
//	return res;
//}
//
//void PrintNum(HighAcc num)
//{
//	for (int i = num.size - 1; i >= 0; i--)
//	{
//		printf("%d", num.num[i]);
//	}
//}
//
//int main()
//{
//	char num[102] = { 0 };
//	scanf("%s", num);
//	HighAcc num1 = dealNum(num);
//	scanf("%s", num);
//	HighAcc num2 = dealNum(num);
//	HighAcc res = Mul(num1, num2);
//	PrintNum(res);
//	return 0;
//}

//高精度减法
//#include <stdio.h>
//#include <string.h>
//
//typedef struct HA {
//	char num[102];
//	int size;
//	char minusflag;
//}HighAcc;
//
//HighAcc dealNum(char* src)
//{
//	int i = 0, len = strlen(src);
//	HighAcc tmp = { 0 };
//	for (; i < len; i++){
//		tmp.num[i] = src[len - 1 - i] - '0';
//	}
//	tmp.size = len;
//	tmp.minusflag = 0;
//	return tmp;
//}
//
//HighAcc add(HighAcc num1, HighAcc num2)
//{
//	int longer = num1.size > num2.size ? num1.size : num2.size;
//	HighAcc res = { 0 };
//	int i;
//	int tmp;
//	for (i = 0; i < longer; i++)
//	{
//		tmp = num1.num[i] + num2.num[i] + res.num[i];
//		res.num[i] = tmp % 10;
//		res.num[i + 1] = tmp / 10;
//	}
//	res.size = longer + res.num[i];
//	return res;
//}
//
//int hacmp(HighAcc num1, HighAcc num2)
//{
//	if (num1.size > num2.size){
//		return 1;
//	}
//	else if (num1.size < num2.size){
//		return -1;
//	}
//	int i;
//	for (i = num1.size - 1; i >= 0; i--){
//		if (num1.num[i] > num2.num[i]){
//			return 1;
//		}
//		else if (num1.num[i] < num2.num[i]){
//			return -1;
//		}
//	}
//	return 0;
//}
//
//HighAcc sub(HighAcc num1, HighAcc num2)
//{
//	HighAcc res = { 0 };
//	HighAcc bigger = num1;
//	HighAcc smaller = num2;
//	int ret = hacmp(num1, num2);
//	if (ret == 0)
//	{
//		res.size = 1;
//		return res;
//	}
//	else if (ret < 0)
//	{
//		res.minusflag = 1;
//		bigger = num2;
//		smaller = num1;
//	}
//	int i;
//	int tmp;
//	for (i = 0; i < bigger.size; i++)
//	{
//		tmp = 10 + bigger.num[i] - smaller.num[i] + res.num[i];
//		res.num[i] = tmp % 10;
//		res.num[i + 1] = tmp / 10 - 1;
//	}
//	res.size = bigger.size;
//	for (i = bigger.size - 1; res.num[i] == 0; i--)
//	{
//		res.size--;
//	}
//	return res;
//}
//
//HighAcc mul(HighAcc num1, HighAcc num2)
//{
//	HighAcc res = { 0 };
//
//	if (num1.size == 1 && num1.num[0] == 0 ||
//		num2.size == 1 && num2.num[0] == 0)
//	{
//		res.size = 1;
//		return res;
//	}
//	int i, j;
//	int tmp;
//	for (i = 0; i < num1.size; i++){
//		for (j = 0; j < num2.size; j++){
//			tmp = num1.num[i] * num2.num[j] + res.num[i + j];
//			res.num[i + j] = tmp % 10;
//			res.num[i + j + 1] += tmp / 10;
//		}
//	}
//	res.size = i + j - !res.num[i + j - 1];
//	return res;
//}
//
//void printNum(HighAcc tmp)
//{
//	int i;
//	if (tmp.minusflag){
//		putchar('-');
//	}
//
//	for (i = tmp.size - 1; i >= 0; i--){
//		printf("%d", tmp.num[i]);
//	}
//}
//int main()
//{
//	char tmp[102] = { 0 };
//	scanf("%s", tmp);
//	HighAcc num1 = dealNum(tmp);
//	scanf("%s", tmp);
//	HighAcc num2 = dealNum(tmp);
//	HighAcc res = sub(num1, num2);
//	printNum(res);
//	return 0;
//}

高精度除法
#include <stdio.h>
#include <string.h>

typedef struct HA {
	char num[102];
	int size;
	char minusflag;
}HighAcc;

HighAcc dealNum(char* src)
{
	int i = 0, len = strlen(src);
	HighAcc tmp = { 0 };
	for (; i < len; i++){
		tmp.num[i] = src[len - 1 - i] - '0';
	}
	tmp.size = len;
	tmp.minusflag = 0;
	return tmp;
}

int hacmp(char* num1, int size1, char* num2, int size2)
{
	if (size1 > size2){
		return 1;
	}
	else if (size1 < size2){
		return -1;
	}
	int i;
	for (i = size1 - 1; i >= 0; i--){
		if (num1[i] > num2[i]){
			return 1;
		}
		else if (num1[i] < num2[i]){
			return -1;
		}
	}
	return 0;
}

int sub(char* num1, int size1, char* num2, int size2)
{
	HighAcc res = { 0 };
	int i;
	int tmp;
	for (i = 0; i < size1; i++)	{
		tmp = 10 + num1[i] - num2[i] + res.num[i];
		res.num[i] = tmp % 10;
		res.num[i + 1] = tmp / 10 - 1;
	}
	int count = 0;
	for (i = size1 - 1; res.num[i] == 0 && i >= 0; i--)	{
		count++;
		num1[i] = 0;
	}
	for (; i >= 0; i--)	{
		num1[i] = res.num[i];
	}
	return count;
}

HighAcc div(HighAcc num1, HighAcc num2)
{
	int i;
	int count = 0;
	HighAcc res = { 0 };
	int flag = 0;
	for (i = num1.size - 1; i >= 0; i--){
		while (hacmp(num1.num + i, num1.size - i, num2.num, num2.size) >= 0 && i < num1.size){
			num1.size -= sub(num1.num + i, num1.size - i, num2.num, num2.size);
			count++;
		}
		if (flag == 0 && count != 0）{
			flag = 1;
			res.size = i + 1;
		}
		res.num[i] = count;
		count = 0;
	}
	return res;
}

HighAcc mod(HighAcc num1, HighAcc num2)
{
	int i;
	for (i = num1.size - 1; i >= 0; i--){
		while (hacmp(num1.num + i, num1.size - i, num2.num, num2.size) >= 0 && i < num1.size){
			num1.size -= sub(num1.num + i, num1.size - i, num2.num, num2.size);
		}
	}
	if (num1.size == 0)	{
		num1.size = 1;
	}
	return num1;
}

void printNum(HighAcc tmp)
{
	int i;
	if (tmp.minusflag){
		putchar('-');
	}
	for (i = tmp.size - 1; i >= 0; i--)	{
		printf("%d", tmp.num[i]);
	}
}

int main()
{
	char tmp[102] = { 0 };
	scanf("%s", tmp);
	HighAcc num1 = dealNum(tmp);
	scanf("%s", tmp);
	HighAcc num2 = dealNum(tmp);
	HighAcc res1 = div(num1, num2);
	HighAcc res2 = mod(num1, num2);
	printNum(res1);
	putchar('\n');
	printNum(res2);
	return 0;
}

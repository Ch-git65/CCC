#define _CRT_SECURE_NO_WARNINGS 1
//指针函数
//a个学生，每个学生有b门成绩
//输入学号既能输出所有成绩
//#include<stdio.h>
//int main()
//{
//	float score[][4] = { {60,70,80,90},{56,89,67,88},{34,78,90,66} };
//	float *search(float(*pointer)[4], int n);
//	float *p;
//	int i, k;
//	printf("enter the number of student:");
//	scanf("%d", &k);
//	printf("the scores of no.%d are:\n", k);
//	p = search(score, k);
//	for (i = 0; i < 4; i++)
//		printf("%5.2f\t", *(p + i));
//	printf("\n");
//	return 0;
//}
//float *search(float(* pointer)[4],int n)
//{
//	float *pt;
//	pt = *(pointer+n);
//	return(pt);
//	return 0;
//}
//将数组a中n个整数按相反顺序放
//#include<stdio.h>
//int main()
//{
//	void inv(int *x, int n);
//	int i, a[10] = { 3,7,9,11,0,6,7,5,4,2 };
//	printf("The qriginal array:\n");
//	for (i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	inv(a, 10);
//	printf("The array has been inveerted:\n");
//	for (i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	return 0;
//}
//void inv(int *x, int n)
//{
//	int *p, temp, *i, *j, m = (n - 1) / 2;
//	i = x; j = x + n - 1; p = x + m;
//	for (; i <= p; i++, j--)
//	{
//		temp = *i;
//		*i = *j;
//		*j = temp;
//	}
//	return;
//}
//#include<stdio.h>
//struct
//{
//
//	int num;
//	char name[10];
//	char sex;
//	char job;
//	union
//	{
//		int class;
//		char position[10];
//	}category;
//}	person[2];
//int main()
//{
//	int i;
//	for (i = 0; i < 2; i++)
//	{
//		printf("please enter the data of person:\n");
//		scanf("%d %c %c %c", &person[i].num, &person[i].name, person[i].sex, person[i].job);
//		if (person[i].job == 's')
//			scanf("%d", &person[i].category.class);
//		else if (person[i].job == 't')
//			scanf("%c", person[i].category.position);
//		else
//			printf("input error!");
//	}
//	printf("\n");
//	printf("no.   name     sex job class/position\n");
//	for (i = 0; i < 2; i++)
//	{
//		if (person[i].job == 's')
//			printf("%-6d%-10c%-4c%-4c%-10d\n", person[i].num, person[i].name,person[i].sex,
//				person[i].job, person[i].category.class);
//		else
//			printf("%-6d%-10c%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex,
//			person[i].job, person[i].category.position);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char arr[20] = { "gao zhi qiang is sb" };
//	char s[2] = { "is" };
//	int n = strlen(arr), i;
//	for (i = 0; i < n; i++)
//		if (arr[i] == s[2])
//			arr[i] = '0';
//	printf("%c", arr[20]);
//	return 0;
//}
//
//#include<stdio.h>
//
//void enter_string(char str[80])
//{
//	gets(str);
//}
//
//void delete_string(char str[], char ch)
//{
//	int i, j;
//	for (i = j = 0; str[i] != '\0'; i++)
//		if (str[i] != ch)
//			str[j++] = str[i];
//	str[j] = '\0';
//}
//
//void print_string(char str[])
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	char c, str[80];
//	enter_string(str);
//	scanf("%c", &c);
//	delete_string(str, c);
//	print_string(str, c);
//	return 0;
//}

//给定b值，输入a,m ,求a*b, a^m;
#include<stdio.h>
int A;
int main()
{
	int power(int);
	int b = 3, c, d, m;
	printf("enter the number a and its power m:\n");
	scanf("%d %d", &A, &m);
	c = A*b;
	printf("%d * %d=%d\n", A, b, c);
	d = power(m);
	printf("%d * * %d=%d\n", A, m, d);
	return 0;
}

extern  A;
int power(int n)
{
	int i, y = 1;
	for (i = 1; i <= n; i++)
		y *= A;
	return(y);
}
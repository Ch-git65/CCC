#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int nums(int x[3][3])
//{
//	int b[3][3];
//	int i, j;
//	int m=0, n=0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			b[m][n] = x[i][j];
//			m++;
//		}
//		n++;
//	}
//	return b[m][n];
//}
//int main()
//{
//	int a[3][3] = { {1,2,3},{1,2,3},{1,2,3} };
//	printf("%d ", nums(a[3][3]));
//	return 0;
//}
//#include<stdio.h>
//void nums(char name, int n)
//{
//	printf("input teachers name and date:");
//	for (int j = 0; j < 10;j++)
//		scanf("%c %d", &name, &n);
//		for (int i = 0; i < 10; i++);
//			printf("%c %d", name, n);
//}
//void sort(int n[10], int m)
//{
//	int i,j,k, t;
//	for (i = 0; i < 10; i++)
//	{
//		k = i;
//		for (j = i + 1; j < 10; j++)
//			if (n[j] < n[k])
//				k = j;
//		t = n[k];
//		n[k] = n[j];
//		n[j] = t;
//}
//int main()
//{
//	char name = {0};
//	int n=0;
//	nums(name, n);
//	//sort(n[10], m);
//	//for (i = 0; i < 10;i++)
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[10];
//	int *p, i;
//	printf("please enter 10 interger number:");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (p = a; p < (a + 10); p++)
//	{
//		printf("%d", *p);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	void inv(int x[], int n);
//	int i, a[10] = { 3,7,9,11,0,6,7,5,4,2 };
//	printf("The original array:\n");
//	for (i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	inv(a, 10);
//	printf("The array has been inverted:\n");
//	for (i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	return 0;
//}
//void inv(int x[], int n)
//{
//	int temp, i, j, m = (n - 1) / 2;
//	for (i = 0; i <=m; i++)
//	{
//		j = n - 1 - i;
//		temp = x[i];
//		x[i] = x[j];
//		x[j] = temp;
//	}
//	return;
//}
//#include<stdio.h>
//void inv(int *x, int n)
//{
//	int *p,temp, *i, *j, m = (n - 1) / 2;
//	i = x; 
//	j = x + n - 1; 
//	p = x + m;
//	for (; i <= p; i++, j--)
//	{
//		temp = *i;
//		*i = *j;
//		*j = temp;
//	}
//}
//int main()
//{
//	int i;
//	int a[10] = { 3,7,9,1,0,6,7,5,4,2 };
//	printf("The original array:\n");
//	for (i = 0; i < 10; i++)
//		printf("%2d", a[i]);
//	printf("\n");
//	inv(a, 10);
//	printf("The array has been inverted:\n");
//	for (i = 0; i < 10; i++)
//		printf("%2d", a[i]);
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//void sort(int x[], int n)
//{
//	int i, j, k, t;
//	for (i = 0; i < n - 1; i++)
//	{
//		k = i;
//		for (j = i + 1; j < n; j++)
//		{
//			if (x[j] > x[k]) k = j;
//			if (k != i)
//			{
//				t = x[i];
//				x[i] = x[k];
//				x[k] = t;
//			}
//		}
//	}
//}
//int main()
//{
//	int i, *p, a[10];
//	p = a;
//	printf("please enter 10 integer numbers:");
//	for (i = 0; i < 10; i++)
//		scanf("%d", p++);
//	p = a;
//	sort(p, 10);
//	for (p = a, i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
//	int *p;
//	for (p = a[0]; p < a[0] + 12; p++)
//	{
//		if ((p - a[0]) % 4 == 0)  printf("\n");
//		printf("%4d", *p);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
//	int(*p)[4], i, j;                            //指针变量p指向包含4个整型元素的一堆数组
//	p = a;                                       //p指向二维数组的0行
//	printf("please enter row and colun:");
//	scanf("%d,%d", &i, &j);
//	printf("a[%d,%d]=%d\n", i, j, *(*(p+i)+j)); //输出a[i][j]的值
//	return 0;
//}
//#include<stdio.h>
//void search(float(*p)[4], int n)
//{
//	int i, j, flag;
//	for (j = 0; j < 4; j++)
//	{
//		flag = 0;
//		for (i = 0; i < 4;i++)
//		    if (*(*(p + j) + i) < 60) flag = 1;
//	    if (flag == 1)
//	    {
//		    printf("No.%d fails,his score are:\n", j + 1);
//			for (i = 0; i < 4; i++)
//				printf("%5.1f", *(*(p + j) + i));
//		    printf("\n");
//	    }
//	}
//}
//int main()
//{
//	float score[3][4] = { {65,57,70,60},{58,87,90,81},{90,99,100,98} };
//	search(score, 3);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a[] = "I am a student.", b[20];
//	int i;
//	for (i = 0; *(a + i) != '\0'; i++)
//		*(b + i) = *(a + i);
//	*(b + i) = '\0';
//	printf("string a is:%s\n", a);
//	printf("string b is:");
//	for (i = 0; b[i] != '\0'; i++)
//		printf("%c", b[i]);
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a[] = "I am a boy.", b[20], *p1, *p2;
//	p1 = a;
//	p2 = b;
//	for (; *p1 != '\0'; p1++, p2++)
//		*p2 = *p1;
//	*p2 = '\0';
//	printf("string a is:%s\n", a);
//	printf("string b is:%s\n", b);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int max(int, int);
	int(*p)(int, int);
	int a, b, c;
	p = max;
	printf("please enter a and b:");
	scanf("%d,%d", &a, &b);
	c = (*p)(a,b);
	printf("a=%d\nb=%d\nmax=%d\n", a, b, c);
	return 0;
}
int max(int x, int y)
{	
	int z;
	if (x > y) z = x;
	else z = y;
	return(z);
}
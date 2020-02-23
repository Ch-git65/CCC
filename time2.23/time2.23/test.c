#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//    int nums[5] = {1,2,3,4};
//	int val = 2;
//	int k = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		if (nums[i] != val)
//		{
//			nums[k] = nums[i];
//			k++;
//			printf("%d ", nums[k]);
//		}
//		//printf("%d\n", nums[k]);
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr[] = {1,2,3,4};
//	int n = 3;
//	int l = sizeof(arr)/sizeof(arr[0]);
//	//printf("%d\n", l);
//	for (int i = 0; i < l; i++)
//	{
//		if (arr[i] == n)
//			printf("%d\n", i);
//	}
//	printf("%d\n", l);
//	return 0;
//}
//ÅÐ¶Ï»ØÎÄÊý
//#include<stdio.h>
//int main()
//{
//	int x=0;
//	long long n = 0, a=0;
//	int y = x;
//	printf("please input numbers:");
//	scanf("%d", &x);
//	if (x < 0)  printf("error");
//	while (y != 0)
//	{
//		a = y % 10;
//		n = n * 10 + a;
//		y /= 10;
//	}
//	if (n == x)
//		printf("succeed\n");
//	else
//		printf("error\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[9][9];
//	int i = 0, j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		a[i][i] = 1;
//		a[i][0] = 1;
//	}
//	for (i = 2; i < 10; i++)
//	{
//		for (j = 0; j < i - 1; j++)
//		{
//			a[i][j] = a[i - 1][j] + a[i - 1][j-1];
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%4d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include<stdio.h>
void fun(int a[], int n)
{
	int i, j, t;
	for (i = 0; i <= n - 1; i++)
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
}
int main()
{
	int a[10] = {12,45,7,8,96,4,10,48,2,46}, n=10, i;
	FILE *f;
	if ((f = fopen("myf2.out", "w")) == NULL)
		printf("open file myf2.out failed!\n");
	fun(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%4d",a[i]);
		fprintf(f,"%4d",a[i]);
	}
	fclose(f);
}

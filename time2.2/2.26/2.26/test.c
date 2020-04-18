#include<stdio.h>
int main() 
{
	int i, j, a[10][10];
	for (i = 0; i < 10; i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (i = 2; i < 10; i++)
	{
		for (j = 0; j = i - 1; j++)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	}
	for (i = 0; i < 10; i++) 
	{
		for (j = 0; j < 10; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	return 0;
}
//#include<stdio.h>
//int main()
//{
//	int i = 10;
//printf("%d\n", i);
//	return 0;
//}

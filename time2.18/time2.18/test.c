#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i,j, n,sum=0;
//	for (i = 1; i < 21;i++)
//	{
//		j = i + i;
//		n = j / i;
//		sum += n;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//�������� ����
//#include<stdio.h>
//int main()
//{
//	int a[10];
//	int i, j, k;
//	printf("input 10 numbers :\n");
//	for (i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	printf("\n");
//		for (j = 0; j < 9;j++)
//		{
//			for (i = 0; i < 9 - j; i++)
//			{
//				if (a[i] > a[i + 1])
//				{
//					k = a[i];
//					a[i] = a[i + 1];
//					a[i + 1] = k;
//				}
//			}
//		}
//		printf("the sorted numbers :\n");
//		for (i = 0; i < 10; i++)
//			printf("%d ", a[i]);
//		printf("\n");
//	return 0;
//}

//������Fibonci ����
//#include<stdio.h>
//int main()
//{
//	int i;
//	int f[20] = { 1,1 };//����ǰ�������ֵ����ֵ1
//	for (i = 2; i < 20; i++)
//	{
//		f[i] = f[i - 1] + f[i - 2];   //�Ⱥ����f2��f19��ֵ
//	}
//	for (i = 0; i < 20; i++)
//	{
//		if (i % 5 == 0) printf("\n"); //�������5������
//		printf("%12d",f[i]);
//	}
//	printf("\n");
//	return 0;
//}

//�������л���
//#include<stdio.h>
//int main()
//{
//	int a[2][3] = { {1,2,3},{4,5,6} };
//	int b[3][2], i, j;
//	printf("array a:\n");
//	for (i = 0; i < 2; i++)      //����a��һ�и�Ԫ��
//	{
//		for (j = 0; j < 3; j++)  //����a����Ԫ��
//		{
//			printf("%5d", a[i][j]);
//			b[j][i] = a[i][j];
//		}
//		printf("\n");
//	}
//	printf("array b:\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			printf("%5d", b[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//�����������������������
//#include<stdio.h>
//int main()
//{
//	int a[3][4] = { {1,2,3,4},{9,8,7,6},{-10,10,-5,2} };
//	int i, j, max, row = 0, colum;
//	max = a[0][0];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (a[i][j]>max)
//			{
//				max = a[i][j];
//				row = i;
//				colum = j;
//			}
//		}
//	}
//	printf("max=%d\nrow=%d\ncolum=%d\n", max, row, colum);
//	return 0;
//}
//����
#include<stdio.h>
//int main()
//{
//	char nums[][5] = { {' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},
//	{' ','*',' ','*'},{' ',' ','*'} };
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%c",nums[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//ͳ���ַ��е��ʣ�����
//#include<stdio.h>
//int main()
//{
//	char string[81];
//	int i, num = 0, word = 0;
//	char c;
//	gets(string);
//	for (i = 0; (c = string[i]) != '\0'; i++)
//	{
//		if (c == ' ') word = 0;
//		else if (word == 0)
//		{
//			word = 1;
//			num++;
//		}
//	}
//	printf("There are %d words in this line.\n", num);
//	return 0;
//}
//3*3���ζԽ�֮��
//#include<stdio.h>
//int main()
//{
//	int i, j, sum = 0, sun=0;
//	int s=0;
//	int arr[3][3] = { {1,2,3},{1,2,3},{1,2,3} };
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			if (i == j) sum += arr[i][j];
//		}
//	}
//	for (i = 0,j=2; i < 3; i++,j--)
//	{
//			sun += arr[i][j];
//	}
//	s = sum + sun;
//	printf("%d\n", s);
//	return 0;
//}

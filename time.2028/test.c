#define _CRT_SECURE_NO_WARNINGS 1
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
//#include<stdio.h>
//#include<string.h>
//#include<Windows.h>
//#include<stdlib.h>
//int fun(char str1[], char str2[])
//{
//	int n1 = strlen(str1);
//	//int n2 = strlen(str2);
//	int i, j;
//	//if (n1 != n2)  return 0;
//	for (i = 1; i <= n1; i++)
//	{
//        {
//            int tem = str1[0];
//            for (j = 0; i < n1 - 1; j++)
//            {
//                str1[j] = str1[j + 1];
//            }
//            str1[n1 - 1] = tem;
//        }
//        if (0 == strcmp(str1, str2))
//        {
//            return 1;
//        }
//    }
//    return 0;
//}
//int main()
//{
//    char s1[10] = "AABCD";
//    char s2[10] = "BCDAA";
//    printf("%s\n", s1);
//    printf("%s\n", s2);
//    printf("%d\n", fun(s1, s2));
//    system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<Windows.h>
//void left_move(char* str, int k)//����str�ַ���
//{
//	while (k != 0){
//		char* cur = str;
//		char tmp = *cur;
//		while ((*(cur + 1)) != '\0'){
//			*cur = *(cur + 1);
//			cur++;
//		}
//		*(cur) = tmp;
//		k--;
//	}
//}
//int Judge_string(char* str, const char* p)//�жϺ���
//{
//	int i;
//	if (strlen(str) != strlen(p)){  return 0;  }
//	for (i = 1; i <= strlen(str); i++){
//		left_move(str, 1);
//		if (strcmp(str, p) == 0)//strcmp�����ж�str�ַ����Ƿ���p�ַ�����ͬ		
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char str1[] = "abcd";
//	char str2[] = "cdab";
//	printf("%d\n", Judge_string(str1, str2));
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//void left_move(char* p, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		char tmp = *p;
//		int j = 0;
//		while (*(p + 1 + j))
//		{
//			*(p + j) = *(p + j + 1);
//			j++;
//		}
//		*(p + j) = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "ABCD";
//	int num = 0;
//	printf("������ת����:");
//	scanf("%d", &num);
//	left_move(arr, num);
//	printf("��ת���ַ�����");
//	printf("%s\n", arr);
//	return 0;
//}
//#include<stdio.h>
//#define ROW 4
//#define COL 4
//int Yang(int arr[ROW][COL], int n) {
//	int i = 0, j = COL-1;
//	int tmp = arr[i][j];
//	while (1) {
//		if (tmp == n) { return 1; }
//		else if (tmp < n && j >= 0)
//		{
//			tmp = arr[++i][j];
//		}
//		else if (tmp > n&& j >= 0)
//		{
//			tmp = arr[i][--j];
//		}
//		else { return 0; }
//	}
//}
//int main()
//{
//	int a[ROW][COL] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
//	int i = 0, j = 0, num;
//	printf("array is:\n");
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			printf("%5d", a[i][j]);
//		}
//		printf("\n");
//	}
//	printf("please enter:");
//	scanf("%d", &num);
//	if (Yang(a, num)) { 
//		printf("%d�ڸ�������\n", num);
//	}
//	else
//	{
//		printf("%d���ڸ�������\n", num);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    char c = '0';
//    printf("%d %d", sizeof(c), sizeof(char));
//    return 0;
//}
#include<stdio.h>
int main()
{
	int  i = 1, j = 1, k = 2;  
	if ((j++ || k++) && i++) 
		printf("%d,%d,%d\n", i, j, k);
	return 0;
}
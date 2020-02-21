#define _CRT_SECURE_NO_WARNINGS 1
//接受一个字符串参数，将其中的大写字母改为小写字母
#/*include<stdio.h>
int main()
{
	char str[10];
	int i;
	printf("input one :");
	scanf("%s", &str);
	int n = strlen(str);
	for (i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	printf("%d\n", n);
	printf("%s\n", str);
	return 0;
}*/
//字符串按字母顺序输出
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	void sort(char *name[], int n);
//	void print(char *name[],int n);
//	char *name[] = {"Follow me", "BASIC", "Great Wall", "CCtalk" };
//	int n = 4;
//	sort(name,n);
//	print(name, n);
//	return 0;
//}
//void sort(char *name[], int n)
//{
//	char *temp;
//	int i, j, k;
//	for (i = 0; i < n - 1; i++)
//	{
//		k = i;
//		for (j = i + 1; j < n; j++)
//			if (strcmp(name[k], name[j])>0)  k = j;
//		if (k != i)
//		{
//			temp = name[i];
//			name[i] = name[k];
//			name[k] = temp;
//		}
//	}
//}
//void print(char *name[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//		printf("%s\n", name[i]);
//}
//#include<stdio.h>
//int main()
//{
//	char password[20];
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("please input:");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("succeed\n");
//			break;
//		}
//		else
//			printf("again\n");
//	}
//	if (i == 3)
//		printf("error\n");
//	return 0;
//}
#include<stdio.h>
int main()
{
	int i, j,n;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			n = i*j;
			printf("%d*%d=%d\t", i, j, n);
		}
		printf("\n");
	}
	return 0;
}
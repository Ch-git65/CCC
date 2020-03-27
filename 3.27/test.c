#define _CRT_SECURE_NO_WARNINGS 1 
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str[] = "We";
//	int n = strlen(str);
//	for (int i = 0; i < n; i++)
//	{
//		if (str[i] >= 'A' && str[i] < 'Z')
//		{
//			str[i] += 32;
//		}
//	}
//	printf("%s\n", str);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4};
	int n;
	int l = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int nu = arr[l-1];
		for (int j = l-1; j>0;j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = nu;
	}
	for (int i = 0; i < l; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
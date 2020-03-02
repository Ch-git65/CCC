#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char password[20];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("please input:");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("succeed\n");
//			break;
//		}
//		else printf("again\n");
//	}
//	if (i == 3) printf("default\n");
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<time.h>
//void menu()   //”Œœ∑ΩÁ√Ê
//{
//	printf("****************************\n");
//	printf("********* 1.play  **********\n");
//	printf("********* 0.exit  **********\n");
//	printf("****************************\n");
//}
//void game()
//{
//	int guess= rand() % 100 + 1;
//	int input = 0;
//	while (1) {
//		printf("input:");
//		scanf("%d", &input);
//		if (guess < input)
//		{
//			printf("big\n");
//		}
//		else if (guess > input)
//		{
//			printf("small\n");
//		}
//		else
//		{
//			printf("yes\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	menu();
//	rand((unsigned)time(NULL));
//	int n =0;
//	printf("choice:");
//	scanf("%d", &n);
//	if (n == 0) printf("end\n");
//	if (n == 1)
//	{
//		game();
//	}
//	else printf("error\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i, j,sum=0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j < 10; j++)
//		{
//			sum = i * j;
//			printf("%3d*%d=%d", i, j ,sum);
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int find_num=0;
	scanf("%d", &find_num);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > find_num)
		{
			right = mid - 1;
		}
		else if (arr[mid] < find_num)
		{
			left = mid + 1;
		}
		else
			break;
	}
	if (left <= right) printf("find it:%d\n", mid);
	else printf("nothing\n");
	return 0;
}
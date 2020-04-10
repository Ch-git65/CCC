//数组OJ

//原地删除所有val
//int removeElement(int *nums, int numsSize, int val)
//{
//	int count=0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != val)
//		{
//			nums[count] = nums[i];
//			count++;
//		}
//	}
//	return count;
//}


//删除数组中的重复项
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 0) return 0;
//	int count = 0;
//	for (int i = 1; i < numsSize; i++)
//	{
//		if(nums[i]==nums[i--])
//		{
//			nums[++count]=nums[i];
//		}
//	}
//	return count+1;
//}n
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

void menu()
{
	printf("***************************\n");
	printf("********* 1.play **********\n");
	printf("********* 0.exit **********\n");
	printf("***************************\n");
}

void game()
{
	int x;
	int y = rand() % 100+1;
	while (1) 
	{
		printf("请输入你要猜的数:");
		scanf("%d", &x);
		if (x == y) {
			printf("恭喜你猜对了!\n");
			break;
		}
		else if (x > y)
		{
			printf("猜大了!\n");
		}
		else {
			printf("猜小了!\n");
		}
		//system("cls");
	}
}
int main()
{
	menu();
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 1)
		{
			system("cls");
			printf("开始游戏!\n");
			game();
		}
		else if (n == 0)
		{
			system("cls");
			printf("退出游戏!\n");
			break;
		}
		else {
			printf("输入有误!\n");
		}
	}
	return 0;
}
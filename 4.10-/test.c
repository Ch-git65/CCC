//����OJ

//ԭ��ɾ������val
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


//ɾ�������е��ظ���
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
		printf("��������Ҫ�µ���:");
		scanf("%d", &x);
		if (x == y) {
			printf("��ϲ��¶���!\n");
			break;
		}
		else if (x > y)
		{
			printf("�´���!\n");
		}
		else {
			printf("��С��!\n");
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
			printf("��ʼ��Ϸ!\n");
			game();
		}
		else if (n == 0)
		{
			system("cls");
			printf("�˳���Ϸ!\n");
			break;
		}
		else {
			printf("��������!\n");
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
////������
//#include<stdio.h>
//
////������ж�
//int Leap(int year) {
//	if (year % 400 == 0) { return 1; }
//	if (year % 4 == 0 && year % 100 != 0) { return 1; }
//	return 0;
//}
//
////����������Ҫ������֮ǰ���������ж����죬
//int DayCount(int year) {
//	int count = 0;
//	count = 365 * (year - 1900);//�����1900�굽���������֮ǰ��������
//	for (int i = 1900; i < year; i++) {
//		if (Leap(i) == 1) {
//			count++;
//		}
//	}
//	return count;
//}
//
//void LayOut(int year, int month) {
//	int i, n;
//	int M[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int daysum = 0;
//	daysum = DayCount(year);
//	if (month <= 2) {//���Ƕ��£�ֻ��Ҫ����һ�µ�����
//		daysum += 31;
//	}
//	if (month > 2) {//���ڶ��£��Ƚ��������꣬�������1��
//		daysum += Leap(year);
//		for (i = 0; i < month; i++)
//		{
//			daysum += M[i];
//		}
//	}
//	n = (daysum % 7) + 1;//�������ڼ�
//	printf("�� һ �� �� �� �� �� \n");
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("   ");
//		count += 1;
//	}
//	for (i = 1; i < M[month]; i++) {
//		printf("%-2d ", i);
//		count += 1;
//		if (count % 7 == 0) {
//			printf("\n");
//		}
//	}
//}
//int main() {
//	int year = 0;
//	int month = 0;
//	printf("��������Ҫ�鿴���������� ��:");
//	scanf("%d %d", &year, &month);
//	LayOut(year, month);
//	return 0;
//}

//�߼�������Ϸ
#include<stdio.h>
#include<time.h>
#include<windows.h>

//����������ĸ����ظ�����
void slashCard(int arr[]) {
	srand((unsigned int)time(NULL));//����ʱ���
	int s;
	int str[10] = {0,1,2,3,4,5,6,7,8,9};
	int i;
	for (i = 0; i < 4; i++) {
		s = rand() % 10;//ȡ0-9����
		while (str[s] == -1) {//��������ȡ������ȡ��һλ
			s++;
			if (s == 10)
			{
				s = 0;
			}
		}
		arr[i] = str[s];//��ȡ������ֵ����
		str[s] = -1;//����ȥ�ߵĵ�ֵ�û�Ϊ-1
	}
}

//��ӡ����
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

//�жϺ���
int judgeAns(int ans[], int arr[])
{
	int i, j;
	int countA = 0;//���������Ŀ��ֵ��������
	int countB = 0;//������������
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			if (ans[i] == arr[j]) {
				countB++;
				break;
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (ans[i] == arr[i])
		{
			countA++;
		}
	}
	countB = countB - countA;
	printf("%dA%dB\n", countA, countB);
	if (countA == 4)
	{
		return 1;
	}
	return 0;
}

int main() {
	int i, j;
	int arr[4];
	slashCard(arr);//����ʱ�����������ĸ�����
	int ans[4];
	for (i = 1; i < 9; i++) {//�ش����
		printf("��%d������:\n", i);
		for (j = 0; j < 4; j++) {
			scanf("%d", &ans[j]);//�����Լ��µ��ĸ���
		}
		if (judgeAns(ans, arr))//�ж�
		{
			break;
		}
	}
	if (i == 9) {
		printf("���Ĵ������þ�!\n");
		printf("��ȷ��Ϊ:\n");
		printArray(arr, 4);
	}
	else
	{
		printf("��ϲ�㣬��ս�ɹ���\n");
	}
	return 0;
}

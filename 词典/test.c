#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
#include<string.h>

//�Ժ�����ʿ�ֱ�Ӹ������Ｔ��
#define FILE_NAME "dictionary.txt"
//֮���Խ�����������Ϊ�곣����Ϊ���Ժ���ķ���
#define SUM 8000

//����һ���ṹ���������ÿ�����ʵ���Ϣ
typedef struct {
	char english[25];
	char chinese[50];
	char my_class[20];
}words;

//���ﶨ��һ���ṹ��������Ϊ�˽�Ӳ���еĴʿ���ص��ڴ��ϣ���߲����ٶ�
words library[SUM] = { 0 };
int number = 0;

int binary_find(const char* English)
{
	int low = 0;
	int high = SUM - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (strcmp(English, library[mid].english) < 0)
		{
			high = mid - 1;
		}
		else if (strcmp(English, library[mid].english) > 0)
		{
			high = mid + 1;
		}
		else if (strcmp(English, library[mid].english) == 0)
		{
			return mid;
		}
	}
	return -1;
}


void find_print(char* English)
{
	int key = -1;
	key = binary_find(English);
	if (key == -1)
	{
		printf("%s not found!\n", English);
	}
	else
	{
		printf("%s %s %s\n", library[key].english, library[key].chinese, library[key].my_class);
	}
}

void print_menu(void)
{
	printf("\n*************************************************\n");
	printf("****       ����һ�����׵������õĴʵ�       *****\n");
	printf("*****     ->   ������������ѡ��:  <-      *******\n");
	printf("*******        1>    ��ѯ����           *********\n");
	printf("********       2>    �˳�����         ***********\n");
	printf("*************************************************\n");
}

int main(void)
{
	char English[25] = { 0 };
	FILE* fp = fopen(FILE_NAME, "r");
	int choice = 0;
	if (fp == NULL)
	{
		perror("file");
		exit(1);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%s",
			library[number].english,
			library[number].chinese,
			library[number].my_class);
	}
	while (1)
	{
		system("cls");
		print_menu();
		printf("����������ѡ��:>");
		scanf("%d", &choice);
		//ffiush(stdin);
		scanf("%*[^\n]"); scanf("%*c");
		if (2 == choice) {
			exit(1);
		}
		else
		{
			printf("��������Ҫ��ѯ�ĵ���:>");
			scanf("%s", English);
			//fflush(stdin);
			scanf("%*[^\n]"); scanf("%*c");
			find_print(English);
			system("pause");
		}
		fclose(fp);
	}
	return 0;
}
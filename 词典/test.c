#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
#include<string.h>

//以后更换词库直接更改这里即可
#define FILE_NAME "dictionary.txt"
//之所以将单词数定义为宏常量是为了以后更改方便
#define SUM 8000

//定义一个结构体用来存放每条单词的信息
typedef struct {
	char english[25];
	char chinese[50];
	char my_class[20];
}words;

//这里定义一个结构体数组是为了将硬盘中的词库加载到内存上，提高查找速度
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
	printf("****       这是一个简易但是有用的词典       *****\n");
	printf("*****     ->   你有以下两个选择:  <-      *******\n");
	printf("*******        1>    查询单词           *********\n");
	printf("********       2>    退出程序         ***********\n");
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
		printf("请输入您的选择:>");
		scanf("%d", &choice);
		//ffiush(stdin);
		scanf("%*[^\n]"); scanf("%*c");
		if (2 == choice) {
			exit(1);
		}
		else
		{
			printf("请输入您要查询的单词:>");
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
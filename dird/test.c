#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//void func() {
//	//free要求参数必须是动态内存申请出来的
//	int* p = (int*)malloc(sizeof(int)*10);
//	p++;
//	free(p); 
//}
////void GetMemoary(char* p)
////{
////	p = (char*)malloc(100);
////}
//int main()
//{
//	func();
//	return 0;
//}	

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE* fp;
	char str[3][10], temp[10];
	int i, j, k, n = 3;
	printf("Enter strings:\n");
	for (i = 0; i < n; i++)
	{
		gets(str[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (strcmp(str[k], str[i]) > 0)
				k = j;
		if (k != i)
		{
			strcpy(temp, str[i]);
			strcpy(str[i], str[k]);
			strcpy(str[k], temp);
		}
		if (fp = fopen("D:\\CC\\string.dat", "w") == NULL)
		{
			printf("can't open file!\n");
			exit(0);
		}
		printf("\nThe new sequence:\n");
		for (i = 0; i < n; i++)
		{
			fputs(str[i], fp);
			fputs("\n", fp);
			printf("%s\n", str[i]);
		}
	}
	return 0;
}
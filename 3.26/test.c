#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	int a[3][4] = {
//		{1,2,3,4},
//	    {5,6,7,8},
//	    {9,10,11,12}
//	};
//	int num;
//	scanf("%d", &num);
//	int i = 0, j = 3;
//	while(1)
//	{
//		if (num > a[i][j]) {
//			i++;
//		}
//		else if (num < a[i][j])
//		{
//			j--;
//		}
//		else
//		{
//			printf("´æÔÚ\n");
//			break;
//		}
//	}
//	return 0;
//}

#include<stdio.h>
#include<string.h>
int main()
{
	char *str = { 0 };
	scanf("%s", &str);
	int length = strlen(str);
	int spacenum = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			spacenum++;
		}
	}
	for (int i = length; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			str[i + 2 * spacenum] = str[i];
		}
		else
		{
			spacenum--;
			str[i + 2 * spacenum] = '%';
			str[i + 2 * spacenum+1] = '2';
			str[i + 2 * spacenum+2] = '0';
		}
	}
	printf("%s", str);
	return 0;
}
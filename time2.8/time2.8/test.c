#define _CRT_SECURE_NO_WARNINGS 1
//
//// 1!+2!+...+n!
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;//�������ս��
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char password[20];
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//			break;
//	}
//	if (i == 3)
//		printf("�˳�\n");
//	else
//		printf("��½�ɹ�\n");
//	return 0;
//}

//�����ַ�������д��Сд��Сд���䣬���
#include<stdio.h>
int main()
{
	char str[20];
	int n = sizeof(str)/sizeof(str[0]);
	scanf("%s", &str);
	printf("n=%d\n", n);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char str[] = "ABCD", *p = str;
//	printf("%d\n", *(p+4));
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 100, b = 10;//�������ͱ���a,b������ʼ��
//	int *pointer_1, *pointer_2;//����ָ���������ݵ�ָ�����
//	pointer_1 = &a;//�ѱ���a�ĵ�ַ����ָ�����
//	pointer_2 = &b;
//	printf("a=%d,b=%d\n", a, b);
//	printf("*pointer_1=%d,*pointer_2=%d\n", *pointer_1, *pointer_2);
//	return 0;
//}
//������������������С˳�����
//#include<stdio.h>
//int main()
//{
//	int *p1, *p2, *p, a, b;
//	printf("������������:");
//	scanf("%d,%d", &a, &b);
//	p1 = &a;
//	p2 = &b;
//	if (a < b)
//	{
//		p = p1;
//		p1 = p2;
//		p2 = p;
//	}
//	printf("a=%d,b=%d\n", a, b);
//	printf("max=%d,min=%d\n", *p1, *p2);
//	return 0;
//}
//����һ���������飬�����ȫ��Ԫ��
//#include<stdio.h>
//int main() {
//	int a[10];
//	int i;
//	printf("������ʮ����:");
//	for (i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	for (i = 0; i < 10; i++)
//		scanf("%d", a[i]);
//	printf("%\n");
//	return 0;
//}
//
#include<stdio.h>
int main()
{
	int i = 0;
	char password[20];
	for (i = 0; i < 3; i++)
	{
		printf("����������:");
		scanf("password", &password);
		if (strcmp(password, "123456") == 0)
			printf("��½�ɹ�\n");
			break;
	}
	if (i == 3)
		printf("��½ʧ��\n");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	int n = 10;
//	char *pc = (char*)&n;
//	int *pi = &n;
//	printf("%p\n", &n);   //012FFEAC
//	printf("%p\n", pc);   //012FFEAC
//	printf("%p\n", pc+1); //012FFEAD
//	printf("%p\n", pi);   //012FFEAC
//	printf("%p\n", pi+1); //012FFEBO
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0x11223344;
//	char *pc = (char *)&n;
//	char *pi = &n;
//	*pc = 0x55;
//	*pi = 0;
//	printf("%p\n", pc);
//	printf("%p\n", pi);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int *p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p <====> p+%d = %p\n", i, arr[i], i, p+i );
//	}
//	return 0;
//}
//��ָ���������
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int *p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	return 0;
//}

//�ṹ���Ա�ķ���
//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//};
//void print(struct Stu* ps)
//{
//	printf("name=%s age=%d\n", (*ps).name, (*ps).age);
//	//�ýṹ��ָ�����ָ�����ĳ�Ա
//	printf("name=%s age=%d\n", ps->name, ps->age);
//}
//int main()
//{
//	struct Stu s = {"haha", 20};
//	print(&s);//�ṹ���ַ����
//	return 0;
//}

//�ṹ�崫��
//#include<stdio.h>
//struct S
//{
//	int data[1000];
//	int num;
//};
//
//struct S s = { {1,2,3,4}, 1000 };
////�ṹ�崫��
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////�ṹ���ַ����
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s); //���ṹ��
//	print2(&s);//����ַ
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char password[20];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:");
//		scanf("%s", &password);
//		if (strcmp(password, "123456") == 0)
//			break;
//	}
//	if (i == 3)
//		printf("��½ʧ��\n");
//	else
//		printf("��½�ɹ�\n");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("************************\n");
	printf("*******  1.play   ******\n");
	printf("*******  2.exit   ******\n");
	printf("************************\n");
}
void game()
{
     //��������Ϸ��ʵ��
     //1.���������
     //0-32767
	 //ʱ���
	int ret = 0;
	int guess = 0;
	ret = rand() % 100 + 1;
	//printf("%d\n",ret);
	//2.������
	while (1)
	{
		printf("�������:");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//�˵�
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
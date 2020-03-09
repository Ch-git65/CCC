#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<windows.h>
#include<string.h>

#define N 10

enum Sex//ö���Ա�����ֿ���
{
	male, female
};

struct Student {
	char name[20];
	int num;      //100-109
	char sex[10];
	int Math;
}stu[N] = { {"����", 100, "male" , 100},
{"����", 101, "male", 56},
{"����", 102, "female", 78}
};

void PrintUi()
{
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U                                                              �U\n");
	printf("\t�U                                                              �U\n");
	printf("\t�U                 ._______________________.                    �U\n");
	printf("\t�U                 | _____________________ |                    �U\n");
	printf("\t�U                 | I                   I |                    �U\n");
	printf("\t�U                 | I    ��ѧ����ϵͳ   I |                    �U\n");
	printf("\t�U                 | I                   I |                    �U\n");
	printf("\t�U                 | I___________________I |                    �U\n");
	printf("\t�U                 !_______________________!                    �U\n");
	printf("\t�U                     ._[__________]_.                         �U\n");
	printf("\t�U                 .___|_______________|___.                    �U\n");
	printf("\t�U                  |:::  ____            |                     �U\n");
	printf("\t�U                  |     ���룺          |                     �U\n");
	printf("\t�U                  !_____________________!                     �U\n");
	printf("\t�U                                                              �U\n");
	printf("\t�U                                                              �U\n");
	printf("\t�U                                                              �U\n");
	printf("\t�U                                                              �U\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}

int Land() //��½����
{
	printf("���������ĵ�½����:");
	int password;
	int a = 123456;
	for (int n = 1; n <= 3; n++)
	{
		scanf("%d", &password);
		if (password == a) {
			system("cls");
			printf("�������������ȷ!\n");
			printf("���ڵ�½�����Ե�....\n");
			Sleep(4000);//��¼��ʱ���������ݵĵ�½״̬
			system("cls");
			return 1;
		}
		else
		{
			printf("�������������������������!\n");
		}
		if (n == 3) {
			printf("���Ļ������þ�!\n");
			return -1;
		}
	}
	return 0;
}

void PrintMode() {//ϵͳ�˵�ҳ��
	printf("**************************************\n");
	printf("**************************************\n");
	printf("******                        ********\n");
	printf("******       �� ѧ ϵ ͳ      ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("******     1. ¼ �� �� Ϣ     ********\n");
	printf("******     2. �� �� �� Ϣ     ********\n");
	printf("******     3. �� ѯ �� Ϣ     ********\n");
	printf("******     4. �� �� �� ��     ********\n");
	printf("******     0. �� �� ϵ ͳ     ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("**************************************\n");
	printf("**************************************\n");
}

int Welcome() //��ӭ����
{
	PrintUi(); //��ӡ�����溯��
	int i = Land();
	if (i == 1) {
		PrintMode();
		return 0;
	}
	else
	{
		return -1;
	}
}

int Search(int i)//��ѯ������Ϊ�˺�������ض�����Ϣ������ѧ�ŵĲ���
{
	for (int n = 0; n < N; n++)
	{
		if (i == stu[n].num) {
			return n;
		}
	}
	return -1;
}

void InPut()
{
	int i;
	printf("��ʾ������ ѧ�ţ�100-109�� �Ա�male,female�� ��ѧ�ɼ���100���ƣ�\n");
	printf("������ȫ����ѧ����Ϣ��\n");
	for (i = 0; i < N; i++)
	{
		scanf("%s %d %s %d", &stu[i].name, &stu[i].num, &stu[i].sex, &stu[i].Math);
	}
}

void SpecialPut()
{
	int i, c;
	printf("��������Ҫ���ҵ�ѧ�ţ�100-109��:");
	while (1)
	{
		scanf("%d", &i);
		c = Search(i);
		if (c == -1)
		{
			printf("������������!\n");
			continue;
		}
		printf("������%s\nѧ�ţ�%d\n�Ա�%s\n��ѧ��%d\n", stu[c].name, stu[c].num, stu[c].sex, stu[c].Math);
		break;
	}
}

void OutPut() {
	int i;
	printf("----------------------------------------------\n");
	printf("|������   |ѧ�ţ�    |�Ա�   |��ѧ��   |\n");
	for (i = 0; i < N; i++) {
		printf("|%s       |%d        |%s       |%d       |\n", stu[i].name, stu[i].num, stu[i].sex, stu[i].Math);
	}
	printf("----------------------------------------------\n");
}

void Rand()
{
	int i, j, num, math;
	char name[20], sex[10];
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (stu[j].Math > stu[i].Math) {
				math = stu[j].Math;//����ѧ�ɼ����е���
				stu[j].Math = stu[i].Math;
				stu[i].Math = math;

				strcpy(name, stu[j].name);//�����ַ������ܹ�����ֱ��ת������Ϊָ����ָ���ֻ���ַ������׵�ַ
				strcpy(stu[j].name, stu[i].name);//���ʹ��strcpy�����������ַ����ĸ���
				strcpy(stu[i].name, name);

				num = stu[j].num;//�ͳɼ�����
				stu[j].num = stu[i].num;
				stu[i].num = num;

				strcpy(sex, stu[j].sex);//�Ա����������
				strcpy(stu[j].sex, stu[i].sex);
				strcpy(stu[i].sex, sex);
			}
		}
	}
	printf("�ɼ�����Ϊ:\n");
	OutPut();
}

int main()
{
	int c = Welcome();
	if (c == 0)
	{
		int choice;
		printf("��������Ҫ���еĲ������:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:InPut();
			break;
		case 2:OutPut();
			break;
		case 3: SpecialPut();//��ѧ�Ų��Ҳ������ѧ������Ϣ
			break;
		case 4: Rand();//��Ŀ�ɼ�����
			break;
		case 0://�˳�ϵͳ
			system("cls");
			printf("��ѡ���˳�ϵͳ!");
			break;
		}
	}
	return 0;
}

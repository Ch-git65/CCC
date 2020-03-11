#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//�ַ�ת����
int Trans(char c)
{
	return (c - 48);
}

//������ʽ���
int CheckFormat(char* id)
{
	if (strlen(id) != 18)
	{
		printf("�������!\n");
		return 0;
	}
	for (int i = 0; i < 18; i++)
	{
		if (id[i] > '9' || id[i] < 0)
		{
			printf("������󣬳��ַ����֣�\n");
			return 0;
		}
	}
	if ((id[17] > '9' || id[17] < '0') && id[17] != 'X')
	{
		printf("������󣬵�18λ�������ֻ�X����������ԣ�\n");
		return 0;
	}
	return 1;
}

//�������ڼ��
int CheckDate(int year, int month, int day)
{
	int sign = 1;
	if (month > 12 || month < 1) sign = 0;
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29 || day < 1)sign = 0;
		}
		else if (day > 28 || day < 1)sign = 0;
	}
	switch (month)//�����·����ж��·������Ƿ�ϸ�
	{//�˶���Ϊ����
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31 || day < 1)sign = 0; break;
	case 4://�����ΪС��
	case 6:
	case 9:
	case 11:
		if (day > 30 || day < 1)sign = 0; break;
	}
	if (sign == 0)
	{
		printf("�����֤�ų������ڸ�ʽ����ȷ����������ԣ�\n");
		return 0;
	}
	return 1;
}

int CheckCode(char* id)
{//������һ���Ӻ����Ķ��壬�ܶ��˿��ܻ᲻�������ǿ��Խ��аٶ������������֤У��Ĺ���Ϳ�������
	int r[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	int check;
	char code[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3','2' };
	int sum = 0;
	for (int i = 0; i < 17; i++)
	{
		sum += (Trans(id[i])) * r[i];
	}
	check = sum % 11;
	if (id[17] != code[check])
	{
		printf("�����֤��δͨ��ISOУ��,�������һλ������\n");
		return 0;
	}

	return 1;
}

//��ס�������ڵ��������
void FindAddress(char* id)//�������֤ǰ��λ�������Ӧ�ĵ�ַ
{
	int address;
	address = Trans(id[0]) * 100000 + Trans(id[1]) * 10000
		+ Trans(id[2]) * 1000 + Trans(id[3]) * 100
		+ Trans(id[4]) * 10 + Trans(id[5]);
	printf("��ס�������ڵأ�");
	//DataBase(address);//���û������ݼ��ǰ��λ����Ӧ�ĵ�ַ
	printf("\n");
}

//-- - �Ա��������------ -
//���֤�ĵ�17λ������Ϊ�У�ż��ΪŮ��ͨ����2���������ж�
void FindSex(char* id)
{
	int sex = Trans(id[16]);
	printf("�Ա�");
	if (sex % 2 == 1)printf("��\n");
	if (sex % 2 == 0)printf("Ů\n");
}

//---- - ����ͳ��������������------ -
//void FindBirthday(int year, int month, int day)//�����������֤����Ӧ�ĳ����������������Ӧ������
//{
	//time_t timep;
	//struct tm* p;
	//time(&timep);
	//p = gmtime(&timep);//��ȡϵͳʱ���е����
	//printf("���䣺%d��\n", (1900 + p->tm_year) - year);
	//printf("�������ڣ�%4d��%2d��%2d��\n", year, month, day);
//}

//˳�����������------ -
void FindCode(char* id)//��ʾ��ͬ��ͬ�ճ������˽��б�ŵ�15-17λԭ���������
{
	printf("����ͬ��ͬ��ͬ�ճ����ĵ�%c%c%c������\n", id[14], id[15], id[16]);
}

//���������������ݿ�------ -
void DataBase(int address)
{
	switch (address)
	{
	case 110000:printf("������"); break;
	case 110100:printf("��������Ͻ��"); break;
	case 110101:printf("��������Ͻ��������"); break;
	case 110102:printf("��������Ͻ��������"); break;
	case 710000:printf("̨��ʡ"); break;
	case 810000:printf("����ر�������"); break;
	case 820000:printf("�����ر�������"); break;
	default:
		printf("���ݿ����޴���������"); break;
	}
}


int main()
{
	char id[20] = { 0 };
	char choose;
	int year, month, day;
	printf("���֤��У��or��ѯϵͳ\n");
start:
	printf("������������������������\n");
	printf("��������Ҫ��ѯ�����֤�ţ�\n");
	scanf("%18s", id);
	if (CheckFormat(id) == 0) goto start;  //����Ƿ�18λ
	year = Trans(id[6]) * 1000 + Trans(id[7]) * 100 + Trans(id[8]) * 10 + Trans(id[9]);
	month = Trans(id[10]) * 10 + Trans(id[11]);
	day = Trans(id[12]) * 10 + Trans(id[13]);
	if (CheckDate(year, month, day) == 0)goto start;
	if (CheckCode(id) == 0) goto start;
	printf("�����֤���ǺϷ���!\n");
	printf("������������������������\n");
	printf("��Ϣ����:\n");
	FindAddress(id);
	FindSex(id);
	//FindBirthday(id);
	FindCode(id);
	printf("������������������������\n");
	printf("�Ƿ�Ҫ�ٴβ�ѯ����Y���������������˳���\n");
	scanf("%c", &choose);
	if (choose == 'Y' || choose == 'y')goto start;
	return 0;
}
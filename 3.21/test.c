
//atoi��ģ��ʵ��
//#include<stdio.h>
//#include<ctype.h>
//int my_atoi(char s[])
//{
//	int i, n, sign;
//	for (i = 0; isspace(s[i]); i++) {  //�����հ�
//		return 0;
//	}
//	sign = (s[i] == '-') ? -1 : 1;
//	if (s[i] == '+' || s[i] == '-') {  //��������λ
//		i++;
//	}
//	for (n = 0; isdigit(s[i]); i++) {  //�������ַ�ת������������
//		n = 10 * n + (s[i] - '0');
//	}
//	return sign * n;
//}
//int main()
//{
//	char s[100];
//	gets(s);
//	printf("%d\n", my_atoi(s));
//	return 0;
//}

//strncatģ��ʵ��
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//char* my_strncat(char* dest, const char* src, int count)
//{
//	assert(dest);
//	assert(src);
//	char* tmp = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while ((count--) && (*src))
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return tmp;
//}
//int main() {
//	char a[20]="abcdef";
//	char b[] = "ab";
//	my_strncat(a, b, 1);
//	printf("%s\n", a);
//	return 0;
//}

//strncpyģ��ʵ��
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strncpy(char* dest, const char* src, int count)
//{
//	assert(dest);
//	assert(src);
//	assert(count > 0);
//	char* temp = dest;
//	while (count--)
//	{
//		*dest++ = *src++;
//	}
//	return temp;
//}
//int main() {
//	char a[20] = "abcdefgh";
//	char* p = "1234";
//	my_strncpy(a, p, 2);
//	printf("%s\n", a);
//	return 0;
//}

//����
//#include<stdio.h>
//typedef struct Num
//{
//	int num1;
//	int num2;
//}Num;
//Num Find_notdouble(int arr[], int size)
//{
//	Num n;
//	n.num1 = 0;
//	n.num2 = 0;
//	//����������������Ľ�����ǲ���ͬ����������
//	int tmp = 0;
//	int pos = 0;
//	for (int i = 0; i < size; i++)
//	{
//		tmp ^= arr[i];
//	}
//	//�ҳ��������bitΪ1��λ������
//	for (int i = 0; i < sizeof(int) * 8; i++)
//	{
//		if (((tmp >> i) & 1) == 1)
//		{
//			pos = i;//��bitΪ1����һλ��λ�ñ���
//			break;
//		}
//	}
//	for (int i = 0; i < size; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			n.num1 ^= arr[i];
//		}
//		else
//		{
//			n.num2 ^= arr[i];
//		}
//	}
//	return n;
//}
//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,4,5 };
//	Num _num = Find_notdouble(arr, sizeof(arr) / sizeof(arr[0]));
//	printf("����:");
//	printf("%d %d", _num.num1, _num.num2);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1000


typedef struct PersonInfo //����һ����ϵ��
{
	char name[20];
	char sex[20];
	char age[20];
	char address[20];
	char phone[20];
}PersonInfo;

typedef struct AddressBook //ʹ��������֯������ϵ��
{
	PersonInfo persons[MAX_SIZE];
	int size;
	int i;
}AddressBook;


void Init(AddressBook* addr)//��ʼ��ͨѶ¼�ṹ��
{
	addr->size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		strcpy(addr->persons[i].name, "");
		strcpy(addr->persons[i].sex, "");
		strcpy(addr->persons[i].age, "");
		strcpy(addr->persons[i].address, "");
		strcpy(addr->persons[i].phone, "");
	}
}
int Menu()
{
	printf("==========================\n");
	printf(" 1.������ϵ��\n");
	printf(" 2.ɾ����ϵ��\n");
	printf(" 3.������ϵ��\n");
	printf(" 4.�޸���ϵ��\n");
	printf(" 5.��ӡȫ����ϵ��\n");
	printf(" 6.ɾ��������ϵ��\n");
	printf(" 7.�������ķ�ʽ����\n");
	printf(" 0.�˳�\n");
	printf("==========================\n");
	printf("���������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void AddpersonInfo(AddressBook* addr_book) {
	printf("���һ�����û���\n");
	if (addr_book->size >= MAX_SIZE) {
		printf("ͨѶ¼����!����ʧ��!\n");
	}
	PersonInfo* Info = &addr_book->persons[addr_book->size];
	printf("������һ���û���:");
	scanf("%s", Info->name);
	printf("�������Ա�:");
	scanf("%s", Info->sex);
	printf("����������:");
	scanf("%s", Info->age);
	printf("�������ַ:");
	scanf("%s", Info->address);
	printf("������绰����:");
	scanf("%s", Info->phone);
	addr_book->size++;
	printf("����ɹ�!\n");
}

void DelPersonInfo(AddressBook* addr_book)
{
	printf("ɾ��ָ����¼��\n");
	if (addr_book->size <= 0) {
		printf("ͨѶ¼Ϊ�գ�ɾ��ʧ�ܣ�\n");
		return;
	}
	printf("������Ҫɾ����ϵ�˵ı��:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size) {
		printf("��������ɾ��ʧ�ܣ�\n");
		return;
	}
	PersonInfo* last_info = &addr_book->persons[addr_book->size - 1];
	PersonInfo* to_delete = &addr_book->persons[id];
	*to_delete = *last_info;
	addr_book->size--;
	printf("ɾ���ɹ�!\n");
}

void FindPersonInfo(AddressBook* addr_book)
{
	printf(" ����ָ����ϵ�ˣ�\n");
	printf(" ������Ҫ���ҵ���ϵ������:");
	char name[20] = { 0 };
	scanf("%s", name);
	for (int i = 1; i < addr_book->size; i++)
	{
		PersonInfo* info = &addr_book->persons[i];
		if (strcmp(name, info->name)==0 ) {
			printf("[%d] %s %s %s %s %s\n", i, info->name, info->sex, info->age, info->address, info->phone);
		}
		else
		{
			printf("û���ҵ�����ϵ��\n");
		}
	}
}
void ModiyPersonInfo(AddressBook* addr_book)
{
	if (addr_book->size <= 0) {
		printf("ͨѶ¼Ϊ�գ��޸�ʧ�ܣ�\n");
		return;
	}
	int id = 0;
	printf("������Ҫ�޸ĵ���ϵ�����:");
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size) {
		printf(" �������ŷǷ�!�޸�ʧ�ܣ�\n");
		return;
	}
	PersonInfo* info = &addr_book->persons[id];
	printf("�������޸ĺ������(* ��ʾ����):");
	char name[20] = { 0 };
	scanf("%s", info->name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("�������޸ĺ���Ա�(* ��ʾ����):");
	char sex[20] = { 0 };
	scanf("%s", info->sex);
	if (strcmp(sex, "*") != 0) {
		strcpy(info->sex, sex);
	}
	printf("�������޸ĺ������(* ��ʾ����):");
	char age[20] = { 0 };
	scanf("%s", info->age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}
	printf("�������޸ĺ�ĵ�ַ(* ��ʾ����):");
	char address[20] = { 0 };
	scanf("%s", info->address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address, address);
	}
	printf("�������޸ĺ�ĺ���(* ��ʾ����):");
	char phone[20] = { 0 };
	scanf("%s", info->phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	printf(" �޸ĳɹ�!\n");
}

void PrintPersonInfo(AddressBook* addr_book)
{
	printf("��ӡ������ϵ��:\n");
	for (int i = 0; i < addr_book->size; i++)
	{
		PersonInfo* info = &addr_book->persons[i];
		printf(" [%d] %s %s %s %s %s\n", i, info->name, info->sex, info->age, info->address, info->phone);
	}
	printf("��ǰ����ӡ %d ����¼!\n", addr_book->size);
}

void ClearPersonInfo(AddressBook* addr_book)
{
	printf("ɾ��ȫ����¼!\n");
	printf("�����ȷ���� Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0) {
		addr_book->size = 0;
		printf("ɾ���ɹ�\n");
		return;
	}
	else {
		printf("ɾ���Ѿ�ȡ��!\n");
		return;
	}
}
void Sort(AddressBook* addr_book)   //����������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < addr_book->size - 1; i++)
	{
		for (j = 0; j < addr_book->size - i - 1; j++)
		{
			if (strcmp(addr_book->persons[j].name, addr_book->persons[j + 1].name) > 0)
			{
				PersonInfo tmp;
				tmp = addr_book->persons[j];
				addr_book->persons[j] = addr_book->persons[j + 1];
				addr_book->persons[j + 1] = tmp;
			}
		}
	}
}

int main() {
	AddressBook address_book;
	Init(&address_book);
	typedef void(*Func)(AddressBook*);
	Func func_table[] = {
		NULL,//��������ռλ�ã�Ϊ���ú����������±���û������������һһ��Ӧ
		AddpersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModiyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
		Sort
	};
	while (1) {//ͨ�����ѭ�����û����н���
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(func_table) / sizeof(func_table[0]))
		{
			printf("������������!\n");
			continue;
		}
		if (choice == 0)
		{
			printf(" goodbye!\n");
		}
		func_table[choice](&address_book);
	}
	return 0;
}
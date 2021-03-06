
//atoi的模拟实现
//#include<stdio.h>
//#include<ctype.h>
//int my_atoi(char s[])
//{
//	int i, n, sign;
//	for (i = 0; isspace(s[i]); i++) {  //跳过空白
//		return 0;
//	}
//	sign = (s[i] == '-') ? -1 : 1;
//	if (s[i] == '+' || s[i] == '-') {  //跳过符号位
//		i++;
//	}
//	for (n = 0; isdigit(s[i]); i++) {  //将数字字符转换成整形数字
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

//strncat模拟实现
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

//strncpy模拟实现
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

//单身狗
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
//	//先所有数字异或，异或的结果就是不相同的两个数字
//	int tmp = 0;
//	int pos = 0;
//	for (int i = 0; i < size; i++)
//	{
//		tmp ^= arr[i];
//	}
//	//找出异或结果中bit为1的位置所在
//	for (int i = 0; i < sizeof(int) * 8; i++)
//	{
//		if (((tmp >> i) & 1) == 1)
//		{
//			pos = i;//将bit为1的那一位的位置保存
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
//	printf("单身狗:");
//	printf("%d %d", _num.num1, _num.num2);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1000


typedef struct PersonInfo //描述一个联系人
{
	char name[20];
	char sex[20];
	char age[20];
	char address[20];
	char phone[20];
}PersonInfo;

typedef struct AddressBook //使用数组组织若干联系人
{
	PersonInfo persons[MAX_SIZE];
	int size;
	int i;
}AddressBook;


void Init(AddressBook* addr)//初始化通讯录结构体
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
	printf(" 1.新增联系人\n");
	printf(" 2.删除联系人\n");
	printf(" 3.查找联系人\n");
	printf(" 4.修改联系人\n");
	printf(" 5.打印全部联系人\n");
	printf(" 6.删除所有联系人\n");
	printf(" 7.以姓名的方式排序\n");
	printf(" 0.退出\n");
	printf("==========================\n");
	printf("请输入你的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void AddpersonInfo(AddressBook* addr_book) {
	printf("添加一个新用户！\n");
	if (addr_book->size >= MAX_SIZE) {
		printf("通讯录已满!新增失败!\n");
	}
	PersonInfo* Info = &addr_book->persons[addr_book->size];
	printf("请输入一个用户名:");
	scanf("%s", Info->name);
	printf("请输入性别:");
	scanf("%s", Info->sex);
	printf("请输入年龄:");
	scanf("%s", Info->age);
	printf("请输入地址:");
	scanf("%s", Info->address);
	printf("请输入电话号码:");
	scanf("%s", Info->phone);
	addr_book->size++;
	printf("输入成功!\n");
}

void DelPersonInfo(AddressBook* addr_book)
{
	printf("删除指定记录！\n");
	if (addr_book->size <= 0) {
		printf("通讯录为空！删除失败！\n");
		return;
	}
	printf("请输入要删除联系人的编号:");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size) {
		printf("输入有误！删除失败！\n");
		return;
	}
	PersonInfo* last_info = &addr_book->persons[addr_book->size - 1];
	PersonInfo* to_delete = &addr_book->persons[id];
	*to_delete = *last_info;
	addr_book->size--;
	printf("删除成功!\n");
}

void FindPersonInfo(AddressBook* addr_book)
{
	printf(" 查找指定联系人！\n");
	printf(" 请输入要查找的联系人姓名:");
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
			printf("没有找到该联系人\n");
		}
	}
}
void ModiyPersonInfo(AddressBook* addr_book)
{
	if (addr_book->size <= 0) {
		printf("通讯录为空！修改失败！\n");
		return;
	}
	int id = 0;
	printf("请输入要修改的联系人序号:");
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size) {
		printf(" 输入的序号非法!修改失败！\n");
		return;
	}
	PersonInfo* info = &addr_book->persons[id];
	printf("请输入修改后的姓名(* 表示不变):");
	char name[20] = { 0 };
	scanf("%s", info->name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("请输入修改后的性别(* 表示不变):");
	char sex[20] = { 0 };
	scanf("%s", info->sex);
	if (strcmp(sex, "*") != 0) {
		strcpy(info->sex, sex);
	}
	printf("请输入修改后的年龄(* 表示不变):");
	char age[20] = { 0 };
	scanf("%s", info->age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}
	printf("请输入修改后的地址(* 表示不变):");
	char address[20] = { 0 };
	scanf("%s", info->address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address, address);
	}
	printf("请输入修改后的号码(* 表示不变):");
	char phone[20] = { 0 };
	scanf("%s", info->phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	printf(" 修改成功!\n");
}

void PrintPersonInfo(AddressBook* addr_book)
{
	printf("打印所有联系人:\n");
	for (int i = 0; i < addr_book->size; i++)
	{
		PersonInfo* info = &addr_book->persons[i];
		printf(" [%d] %s %s %s %s %s\n", i, info->name, info->sex, info->age, info->address, info->phone);
	}
	printf("当前共打印 %d 条记录!\n", addr_book->size);
}

void ClearPersonInfo(AddressBook* addr_book)
{
	printf("删除全部记录!\n");
	printf("您真的确定吗？ Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0) {
		addr_book->size = 0;
		printf("删除成功\n");
		return;
	}
	else {
		printf("删除已经取消!\n");
		return;
	}
}
void Sort(AddressBook* addr_book)   //以名字排序
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
		NULL,//纯属用来占位置，为了让后续函数的下标和用户输入的命令能一一对应
		AddpersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModiyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
		Sort
	};
	while (1) {//通过这个循环和用户进行交互
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(func_table) / sizeof(func_table[0]))
		{
			printf("您的输入有误!\n");
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
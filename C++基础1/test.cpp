#include<stdio.h>
#include<iostream>
using namespace std;

namespace bite
{
	void print(int a)
	{
		printf("%d\n", a);
	}

	int a;
	int b;
	//Ƕ�׶���
	namespace bite_69
	{
		void fun1(int a)
		{
			printf("%d\n", a);
		}
		int a;
		int b;
	}
}


//���Էֶζ��壬��������ϲ���ͬ�������ռ�
//��ͬ�������ռ䲻�ܶ����ظ��ı����ͺ���
namespace bite
{
	int c;
	int d;
	void fun2()
	{
		printf("fun2()\n");
	}
	void fun3()
	{
		printf("fun3()\n");
	}
}

void fun2()
{
	printf("fun2()\n");
}

void fun1(int a)
{
	printf("%d\n", a);
}

void print(int a)
{
	printf("%d\n", a);
}

int a;
int b;

//�����ռ��Ա��ʹ�÷�ʽ
//1.�����ռ� + :: + ��Ա
//2.�����Ա using + �����ռ� + :: +��Ա:   ����ʹ�ó�Աʱ������Ҫ��������
//3.չ�������ռ� using + �����ռ� : 
//using bite::fun3;
//using bite::a;
//using namespace bite;

void test()
{
	bite::a = 1;
	bite::print(bite::a);//bite�����ռ��µĳ�Աa
	bite::print(a);//ȫ��a
	bite::bite_69::a = 2;
}

void fun3(int a)
{
	a = 10;//�ֲ���
	bite::a = 20;//�����ռ���
	bite::bite_69::a = 30;//�����ռ���
	::a = 40;//ȫ��������
}


//ȱʡ����: ����������һ��Ĭ��ֵ��ʵ��ʹ��ʱ�����û�д��Σ���Ӧ���β�ʹ��Ĭ��ֵ

//ȫȱʡ
void fun5(int a = 1, int b = 2, int c = 3)
{
	std::cout << a << b << c << std::endl;
}

//��ȱʡ
void fun6(int a, int b = 1, int c = 2)
{
	std::cout << a << b << c << std::endl;
}

//��ȱʡ����: ���������������������ֵ���м䲻���м��
//ȱʡֵֻ�ܳ�������������ĵط�������ͬʱ����


//��������: ��������ͬ��������ͬ������ͬһ�������� C��֧��
//������ͬ: ���ͣ�������˳��ͬ
//�����Ƿ���ֵ��ͬ�����ܹ��ɺ�������


void test6()
{
	//����: ���� + & +��������
	int a = 10;
	//a�ı���
	int& ra = a;
	int& ra2 = a;
	ra2 = 30;
	ra = 100;
	a = 1000;

	cout << &a << endl;
	cout << &ra << endl;
	cout << &ra2 << endl;
	//���ö���ʱ�����ʼ��
	//int &ra3
	int b = -1;
	ra = b;//��ֵ�����ö���֮�󣬲�����ȥ����ʵ���ָ��
	ra = -100;

}


void test7()
{
	//const����
	const int a = 10;
	const int& ra = a;
	const int& r = 10;
	double d = 2.0;
	double& ra = d;
	int c = d;
	//d��ʽ����ת��������һ����ʱ�����α���
	const int& rd2 = d;
}

int main()
{
	test6();
}
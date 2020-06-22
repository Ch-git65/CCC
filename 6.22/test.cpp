#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
T Add(T& a, T& b)
{
	return a + b;
}

template <>
char* Add<char*>(char*& a, char*& b)
{
	stract(a, b);
	return a;
}

//���ں���ģ�岻�ܴ�����������ͣ� һ��ᶨ��һ�������͵���ͨ����
//����ģ����ػ��Ƚ�����
char* Add(char*& a, char*& b)
{
	stract(a, b);
	return a;
}

template <class T1, class T2>
T1 sub(T1& a, T2& b)
{
	cout << "sub(T1, T2)" << endl;
	return a;
}

void test()
{
	int a = 1, b = 2;
	float c = 1.5, d = 2.5;
	char e = 'a', f = 'b';
	char* ptr = new char[100];
	strcpy(ptr, "123");
	char* ptr2 = new char[100];
	strcpy(ptr2, "abc");

	Add(a, b);
	Add(c, d);
	Add(e, f);
	Add(ptr, ptr2);

	int* pa = &a;
	int* pb = &b;
}

//ģ�����������ģ�������class�� typename), ������ģ���������ֵ���ͣ�
//������ģ�������������Ϊ����ʹ�ã�����ֵ��Ҫ�ڱ���ʱȷ��
template <class T, size_t N>
class Array
{
private:
	T _array[N];
};

void test2()
{
	Array<int, 20> array;
}

//��ģ����ػ�
//1. ȫ�ػ�   ���еĲ�����Ϊ��������

//�ػ�֮ǰ��Ҫ���ڻ�����ģ��
template <class T1, class T2>
class A
{
public:
	A()
	{
		cout << "A(T1, T2)" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

//ȫ�ػ�
template <>
class A<int, char>
{
public:
	A()
	{
		cout << "A(int, char)" << endl;
	}
private:
	int _t1;
	char _t2;
};

//2.ƫ�ػ�  �����ػ�     ��ģ���������һ��������
template <class T1>
class A<T1, double>
{
public:
	A()
	{
		cout << "A(T1, double)" << endl;

	}
private:
	T1 _t1;
	double _t2;
};
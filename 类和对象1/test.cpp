#pragma pack(8)  //�޸Ķ�����
#include<iostream>
using namespace std;
//���е����Ա����������
struct A
{
public: //Ĭ��public
	int _a;
	void fun()
	{
		cout << "struct A fun()" << endl;
	}
};

class B
{
private: //Ĭ��˽��
	int _a;
	void fun()
	{
		cout << "class B fun()" << endl;
	}

	void fun2();
};

void fun2()
{
	cout << "fun2()" << endl;
}

void B::fun2()
{
	cout << "B::fun2()" << endl;
}

void test()
{
	//���ʵ����������һ�������͵ı����Ĺ���
	//������ ���� --> �Զ������͵ı���һ��ϰ�߳�Ϊ����
	A a;
	B b;
	//struct����ĳ�ԱĬ�Ϸ���Ȩ��Ϊpublic
	a._a = 1;
	a.fun();

	//class ����ĳ�ԱĬ�Ϸ���Ȩ��Ϊprivate
	//b._a=1;
	//b.fun();
}

class C
{
	int _c;
};
class D
{
	int _c;
	void fun1()
	{
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class E
{
	void fun1()
	{
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class F
{};

void test()
{
	cout << sizeof(C) << " " << sizeof(D) << endl;
}

//��Ĵ�СҲ��ѭ�ڴ����Ĺ���
class G
{
	char _c; //1
	double _d; //16
	int _a; //20
	char _c2;//21
	//24
	//Ƕ���౾����ѭ�ڴ�����ԭ��
	class H
	{
		double _d; //8
		char _c; //9
		int _a; //16
		char _c1;//17
		//24
	};
	H _h;
};

struct I
{
	char _c; //1
	double _d;//16
	int _a; //20
	char _c2;//21
};

union U
{
	int _a;
	char _c;
};


class Date
{
public:
	//void Display(Date* const this) ʼ��ָ��ǰ���ô˺����Ķ���ָ�򲻻ᷢ������
	//thisָ������  ������*const
	//thisָ��ֻ�����ڳ�Ա������
	//thisʼ����Ϊ��Ա�����ĵ�һ������
	//�������Զ����ݣ�����Ҫ��ʾ����˲���
	//this������ĳ�Ա��ֻ��һ��������ʽ��һ�����ջ�ϣ�һ������Ż������ڼĴ�����
	void Display()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
		//this=nullptr;
		this->_year = 2020;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void fun1()
	{
		cout << "Date::fun1()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

class AA
{
	//6����Ա����
public:
	//Ĭ�Ϲ���
	AA()
	{}
	AA(int a)
	{}
};

class Date
{
public:
	//���캯��: ��������������ͬ�� �޷���ֵ���������أ��������ڴ���ʱ�Զ�����
	//ֻ�е���û�ж����κι��캯��ʱ���������ڻ��Զ�����һ���޲ι��죬��������Ѿ������˹��캯��
	//�������������Զ�����

	//Ĭ�Ϲ��죺 ֻ�ܴ���һ��
	//1.������Ĭ������
	//2.��ʽ������޲ι���
	//3.ȫȱʡ���캯��

	//ȫȱʡĬ�Ϲ���
	Date(int y = 2020, int m = 5, int d = 20)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	//���صĹ��캯��
	Date(float f)
	{

	}

	void Display()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
		//this = nullptr;
		this->_year = 2022;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void fun1()
	{
		cout << "Date::fun1()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	//������д����Զ����Ա�����캯�����Զ������Զ����Ա��Ĭ�Ϲ��죬����Զ����Ա�ĳ�ʼ��
	//����Զ����Աû��Ĭ�Ϲ��캯�����������������
	AA _aa;
};
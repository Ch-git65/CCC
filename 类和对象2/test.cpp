#include<iostream>
using namespace std;

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	int _a;
};

class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		_year = y;
		_month = m;
		_day = d;
	}
	
	//�������죺���캯��һ��������ʽ��Ҳ���ڴ�������ʱ�Զ�����
	//���ó�������һ���Ѿ����ڵĶ���ȥ����һ���µĶ���
	//���ͱ��������ã��������������ݹ�
	//������Ĭ�����ɵĿ�������Ϊ�ֽڿ���

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "const Date& d" << endl;
	}

	//һ������ع���
	Date(const Date& d, const Date& d2)
	{
		_year = d._year;
		_month = d._month;
		_day = d2._day;

		cout << "const Date& d" << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
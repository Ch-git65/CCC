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
	
	//拷贝构造：构造函数一种重载形式，也是在创建对象时自动调用
	//调用场景：用一个已经存在的对象去创建一个新的对象
	//类型必须是引用，否则会引发无穷递归
	//编译器默认生成的拷贝构造为字节拷贝

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "const Date& d" << endl;
	}

	//一般的重载构造
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
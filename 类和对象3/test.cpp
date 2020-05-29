#include<iostream>
using namespace std;

//int cnt = 0;  安全性较低，容易篡改
class Date
{
public:
	//友元函数尽量少用，它是一种突破封装的语法
	//友元函数： friend + 正常函数的定义/声明
	//友元函数可以访问类的私有成员
	//友元函数不是类的成员函数，它是普通的非成员函数
	//只需要在类中声明友元函数，不需要再类中定义
	//友元函数可以声明再类的任何地方，不受访问限定符的限制

	friend ostream& operator<<(ostream& outputS, Date& d);
	friend istream& operator>>(istream& inputS, Date& d);

	friend class B;

	Date(int year = 2020, int month = 12, int day = 25)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		++cnt;
		cout << "Date(int,int,int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._month)
	{
		++cnt;
		cout << "Date(const Date&)" << endl;
	}


	//静态成员函数：函数内部无this指针
	static int getCount()
	{
		return cnt;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//非静态成员函数可以访问静态成员函数/变量
		getCount();
		cout << cnt << endl;
	}

private:
	//C++11初始化方式：相当于给一个缺省值
	//最后一个候选
	int _year = 1;
	int _month = 1;
	int _day = 1;
	//静态成员变量， 所有对象共享此成员变量， 可以看成类成员
	//静态成员变量不能在声明的时候给默认
	//静态成员不在对象模型中，一般存放在数据段, 不能在初始化列表中初始化
	//static int cnt = 0;
public:
	static int cnt;

};

//静态成员必须在类外初始化
int Date::cnt = 0;

//返回输出流是为了支持连续赋值
ostream& operator<<(ostream& outputS, Date& d)
{
	outputS << d._year << "-" << d._month << "-" << d._day << endl;
	return outputS;
}

istream& operator >> (istream& inputS, Date& d)
{
	inputS >> d._year >> d._month >> d._day;
	return inputS;
}


Date fun(Date d) //拷贝构造
{
	cout << &d.cnt << endl;
	return d; //拷贝构造
}

void test()
{
	Date d;
	Date d2(2020, 5, 26);
}

void test2()
{
	Date d;//构造
	Date d2 = fun(d); //拷贝构造 fun：进行优化

	//静态成员变量/函数访问方式
	//1.对象访问
	cout << d.getCount() << endl;
	cout << d2.getCount() << endl;
	cout << &d.cnt << endl;
	cout << &d2.cnt << endl;

	//2.类名+作用域限定符
	cout << &Date::cnt << endl;
	cout << Date::cnt << endl;
	cout << Date::getCount() << endl;

	//普通成员只能通过对象访问，不能通过类名访问
	d.Display();

}

class B
{
	//友元关系是单向的
	//如果一个类是另一个类的友元类，则此类中的所有成员函数即为另一个类的成员函数
	//友元关系不能传递
public:
	//disPlay, fun, fun1都是Date类的友元函数

	void disPlay(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}


	void fun(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}

	void fun1(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}
};

enum Color
{
	BLACK,
	WHITE
};

class C
{
public:
	//内部类：在一个类内部定义一个新的类
	//内部类天然的作为外部类的友元类
	//内部类作为一个独立的类存在，不附属于外部类
	//外部类不能看作内部类的友元类，对于内部类的成员没有特殊的访问权限，需要遵循访问限定符的限制

	class D
	{
	public:
		void fun(const C& c)
		{
			//可以通过外部类对象访问外部类的私有成员
			cout << c._color << endl;
			cout << c._c << endl;
			cout << c._sc << endl;
			cout << C::_sc << endl;
			//可以直接访问外部类的static成员
			cout << _sc << endl;

		}
	private:
		int _d;
	};
private:
	int _c;
	static int _sc;
	Color _color;
	//内部类可以在类的任何地方定义
	class E
	{
	private:
		int _e;
	};
};

class Solution {
public:
	//内部类
	class Sum
	{
	public:
		Sum()
		{
			//内部类直接访问外部类的私有成员
			_sum += _num;
			++_num;
			cout << "Sum" << endl;
		}
	};
	int Sum_Solution() {
		//重置
		_sum = 0;
		_num = 1;
		Sum sumArray[100];  //调用n次Sum类的构造函数，创建Sum对象数组
		return _sum;
	}
	//private:
	static int _sum;
	static int _num;
};

int Solution::_sum = 0;
int Solution::_num = 1;

void test5()
{
	Solution s;
	int sum = s.Sum_Solution();
	cout << Solution::_num << endl;
	cout << sum << endl;
}

int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}
#pragma pack(8)  //修改对齐数
#include<iostream>
using namespace std;
//所有的类成员都属于类域
struct A
{
public: //默认public
	int _a;
	void fun()
	{
		cout << "struct A fun()" << endl;
	}
};

class B
{
private: //默认私有
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
	//类的实例化：创建一个类类型的变量的过程
	//变量： 对象 --> 自定义类型的变量一般习惯称为对象
	A a;
	B b;
	//struct定义的成员默认访问权限为public
	a._a = 1;
	a.fun();

	//class 定义的成员默认访问权限为private
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

//类的大小也遵循内存对齐的规则
class G
{
	char _c; //1
	double _d; //16
	int _a; //20
	char _c2;//21
	//24
	//嵌套类本身遵循内存对齐的原则
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
	//void Display(Date* const this) 始终指向当前调用此函数的对象，指向不会发生变量
	//this指针类型  类类型*const
	//this指针只存在于成员函数中
	//this始终作为成员函数的第一个参数
	//编译器自动传递，不需要显示定义此参数
	//this不是类的成员，只是一个函数形式，一般存在栈上，一般会做优化，存在寄存器中
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
	//6个成员函数
public:
	//默认构造
	AA()
	{}
	AA(int a)
	{}
};

class Date
{
public:
	//构造函数: 函数名和类名相同， 无返回值，可以重载，编译器在创建时自动调用
	//只有当类没有定义任何构造函数时，编译器在会自动生成一个无参构造，如果类中已经定义了构造函数
	//编译器不会再自动生成

	//默认构造： 只能存在一个
	//1.编译器默认生成
	//2.显式定义的无参构造
	//3.全缺省构造函数

	//全缺省默认构造
	Date(int y = 2020, int m = 5, int d = 20)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	//重载的构造函数
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
	//如果类中存在自定义成员，则构造函数会自动调用自定义成员的默认构造，完成自定义成员的初始化
	//如果自定义成员没有默认构造函数，则会产生编译错误
	AA _aa;
};
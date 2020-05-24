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

//拷贝构造: 构造函数一中重载函数，也是在创建对象时自动调用
//调用场景：用一个已经存在的对象去创建一个新的对象，创建的新对象和当前对象的内容相同
//类型必须是引用，否则会引发无穷递归，编译器语法检查，不支持传值类型
//编译器默认生成的高倍构造为字节构造，浅拷贝（只拷贝对象模型中的内容，不拷贝资源）
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

    //析构函数:清理资源， 不是销毁对象，在对象生命周期结束的时候，编译器自动调用
    //如果没有资源需要清理，可以不用显示写析构函数，直接使用编译器默认生成的析构函数

   ~Date()
   {
	   //自动调用自定义类型的析构函数，完成自定义类型成员的资源清理工作
	   cout << "~Date()" << endl;
   }
private:
	int _year;
	int _month;
	int _day;
};

class String
{
public:
	String(const char* str = "bite")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	//如果有资源，必须显示定义拷贝构造，完成深拷贝

	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};

Date fun()
{
	Date d;
	return d;
}

void test1()
{
	Date d;
	Date d2(2020, 4, 1);
	Date& rd = d;

	Date copy(d);

	Date copy2(Date(2020, 5, 20));

	Date copy3(fun());
}


class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}
	
	bool isEqual(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day = d._day;
	}

	//运算符重载函数：增强代码可读性
	//函数名特殊，定义和使用方式和普通函数一样
	//返回值 operator + 需要重载的运算符从（参数列表） {}
	//运算符重载函数如果时成员函数，则参数的个数比运算符需要的少一个，这里编译器会传入this指针作为第一个参数
	//this指针始终占据运算符操作数的第一个位置

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	//赋值; d=d2
	//赋值运算符重载函数：修改已经存在的对象的内容，不是去创建新的对象
	//如果不写，编译器也会默认生成，默认生成的也是字节拷贝，即浅拷贝
	//如果当前类中有资源，则必须显式定义赋值运算符重载函数，完成深拷贝
	Date& operator=(const Date& d2)
	{
		//判断是否给自己赋值
		if (this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}

		cout << "operator=(const Date& d2)" << endl;
		//返回当前调用此函数的对象本身
		return *this;
	}

//private:
	int _year;
	int _month;
	int _day;
		
};

//普通的运算符重载函数，参数的个数和运算符需要的个数一致
//bool operator==(const Date& d1, const Date& d)
//{
//	return d1._year == d._year
//		&& d1._month == d._month
//		&& d1._day == d._day;
//}
//输出运算符重载函数
//ostream& operator<<(ostream& _cout, const Date& date)
//{
//	_cout << date._year << " " << date._month << " " << date._day << endl;
//	return _cout;
//}
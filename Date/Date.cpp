#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		//判断日期是否合法
		if (year > 0 && month > 0 && month < 13
			&& day>0 && day <= getMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期不合法：" << year << "-" << month << "-" << day << endl;
			cout << "重置为默认值：2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}
	}

	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//如果是2月且是闰年， +1
		if (month == 2
			&& (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
			++day;
		return day;
	}

	// a += b
	Date& operator+=(int day)
	{
		//a += -b --> a -=b
		if (day < 0)
			return *this -= -day;
		_day += day;
		//判断日期是否溢出，溢出需要进位
		while (_day > getMonthDay(_year, _month))
		{
			//减去当月的天数，月份进位
			_day -= getMonthDay(_year, _month);
			++_month;
			//判断月份是否溢出
			if (_month == 13)
			{
				//进位到下一年的1月
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	//前置++： ++d 首先++， 返回++之后的值
	Date& operator++()
	{
		return *this += 1;
	}

	//后置++  返回++之前的值
	//都属于单目运算符

	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;
		_day -= day;

		//判断_day是否为负值或0， 退位

		while (_day <= 0)
		{
			//月份退位
			--_month;
			if (_month == 0)
			{
				_month = 12;
				--_year;
			}

			_day += getMonthDay(_year, _month);
		}

		return *this;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date& operator--(int)
	{
		Date ret = *this;
		*this -= -1;
		return ret;
	}

	Date& operator+(int day)
	{
		Date ret = *this;
		ret += day;
		return ret;
	}

	Date operator-(int day)
	{
		Date ret = *this;
		ret -= day;
		return ret;
	}

	bool operator==(const Date& date)
	{
		return _year == date._year
			&& _month == date._month
			&& _day == date._day;
	}

	bool operator>(const Date& date)
	{
		if (_year > date._year)
			return true;
		else if (_year == date._year)
		{
			if (_month > date._month)
				return true;
			else if (_month == date._month)
			{
				if (_day > date._day)
					return true;
			}
		}
		return false;
	}

	bool operator>=(const Date& date)
	{
		return (*this > date) || (*this == date);
	}

	bool operator<(const Date& date)
	{
		return !(*this >= date);
	}

	bool operator<=(const Date& date)
	{
		return !(*this > date);
	}

	bool operator!=(const Date& date)
	{
		return !(*this == date);
	}

	void printD() //printD(Date* const this)
	{
		cout << _year << " " << _month << " " << _day << endl;
		//可修改内容
		//this->_year=100；
		//可调用const成员函数
		fun();
	}
	//const成员函数中的const修饰的为第一个参数，即this指针
	//const成员函数内部不能修改成员变量的值
	void printD() const //printfD(const Date* const this)
	{
		cout << _year << " " << _month << " " << _day << endl;
		//不能修改内容
		//this->_year = 100;
		//补能调用非const成员函数，读写的权限不能被放大
		//++*this;

	}

	void fun()const
	{

	}

	int operator-(Date& date)
	{
		Date d1(*this);
		Date d2(date);
		//d1 - d2
		int num = 0;
		if (d1 > d2)
		{
			while (d1 > d2)
			{
				--d1;
				++num;
			}
			return num;
		}
		else
		{
			//d1 <= d2
			while (d1 < d2)
			{
				++d1;
				++num;
			}
			return -num;
		}
	}

	/*Date operator-(Date& date)
	{

	}*/

	//取地址运算符重载函数: operator&
	//一般不需要显示定义，直接用默认即可
	Date* operator&()
	{
		//return (Date*) 0x1234;
		return this;
	}

	const Date* operator&() const
	{
		//return nullptr;
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};


//ostream& operator<<(ostream& _cout, const Date& date)
//{
//	_cout << date._year << " " << date._month << " " << date._day << endl;
//	return _cout;
//}
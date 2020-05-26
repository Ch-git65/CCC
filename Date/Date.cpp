#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		//�ж������Ƿ�Ϸ�
		if (year > 0 && month > 0 && month < 13
			&& day>0 && day <= getMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "���ڲ��Ϸ���" << year << "-" << month << "-" << day << endl;
			cout << "����ΪĬ��ֵ��2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}
	}

	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//�����2���������꣬ +1
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
		//�ж������Ƿ�����������Ҫ��λ
		while (_day > getMonthDay(_year, _month))
		{
			//��ȥ���µ��������·ݽ�λ
			_day -= getMonthDay(_year, _month);
			++_month;
			//�ж��·��Ƿ����
			if (_month == 13)
			{
				//��λ����һ���1��
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	//ǰ��++�� ++d ����++�� ����++֮���ֵ
	Date& operator++()
	{
		return *this += 1;
	}

	//����++  ����++֮ǰ��ֵ
	//�����ڵ�Ŀ�����

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

		//�ж�_day�Ƿ�Ϊ��ֵ��0�� ��λ

		while (_day <= 0)
		{
			//�·���λ
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
		//���޸�����
		//this->_year=100��
		//�ɵ���const��Ա����
		fun();
	}
	//const��Ա�����е�const���ε�Ϊ��һ����������thisָ��
	//const��Ա�����ڲ������޸ĳ�Ա������ֵ
	void printD() const //printfD(const Date* const this)
	{
		cout << _year << " " << _month << " " << _day << endl;
		//�����޸�����
		//this->_year = 100;
		//���ܵ��÷�const��Ա��������д��Ȩ�޲��ܱ��Ŵ�
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

	//ȡ��ַ��������غ���: operator&
	//һ�㲻��Ҫ��ʾ���壬ֱ����Ĭ�ϼ���
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
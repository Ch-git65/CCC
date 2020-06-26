#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}

	void showId(int a)
	{
		cout << _id << endl;
	}
public:
	int _id = 1;

protected:
	string _name = "peter";

	int _age = 18;
};

void showId(int a)
{
	cout << "全局函数： void showId()" << endl;
}

//父类，子类的作用域都是独立的，不同的作用域中可以有同名的成员
class Student : public Person
{
public:
	void setNum(int num)
	{
		this->_num = num;
	}

	void showId()
	{
		//同名隐藏：父类中的同名成员被子类中的同名成员隐藏
		cout << _id << endl;
		cout << Person::_id << endl;
		//只要函数名，就会构成同名隐藏，不是函数重载
		//showId(10)

		//全局函数
		//::showId(10);
		//showId(0;
	}

	//子类的本身的showId()和showId(int)构成函数重载
	void etId(int id)
	{
		//成员id赋值
		_id = id;

		//全局id赋值
		//::_id = id;
	}

public:
	int _id = 100;
	int _num = 2020;
};

void test()
{
	Student st;
	cout << st._num << endl;
	st.setNum(1999);
	cout << st._num << endl;

	cout << sizeof(Person) << endl;
	cout << sizeof(Student) << endl;
	st.showId();
}

class Person
{
public:
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int , int)" << endl;
	}

	Person(int id, int age, int num)
	{
		cout << "Person(int ,int ,int)" << endl;
	}

	Person(const Person& p)
		:_id(p._id)
		, _age(p._age)
	{
		cout << "Person(const Person&)" << endl;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_id = p._id;
			_age = p._age;
		}

		cout << "Person& operator=(const Person&)" << endl;
		return *this;
	}

	~Person()
	{
		cout << "~Person()" < , endl;
	}

protected:
	int _id;
	int _age;
};
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
	cout << "ȫ�ֺ����� void showId()" << endl;
}

//���࣬������������Ƕ����ģ���ͬ���������п�����ͬ���ĳ�Ա
class Student : public Person
{
public:
	void setNum(int num)
	{
		this->_num = num;
	}

	void showId()
	{
		//ͬ�����أ������е�ͬ����Ա�������е�ͬ����Ա����
		cout << _id << endl;
		cout << Person::_id << endl;
		//ֻҪ���������ͻṹ��ͬ�����أ����Ǻ�������
		//showId(10)

		//ȫ�ֺ���
		//::showId(10);
		//showId(0;
	}

	//����ı����showId()��showId(int)���ɺ�������
	void etId(int id)
	{
		//��Աid��ֵ
		_id = id;

		//ȫ��id��ֵ
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
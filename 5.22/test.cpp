#include<iostream>
using namespace std;
//所有类成员都属于类域

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
	cout << "fun2()" << endl;
}

void test()
{
	//类的实例化：创建一个类类型的变量的过程
	//变量： 对象--> 自定义类型的变量 一般习惯称为对象
	A a;
	B b;
	//struct定义的成员默认访问权限为public
	a._a = 1;
	a.fun();
	//class定义的成员默认访问权限为private

}
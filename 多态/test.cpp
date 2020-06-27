#include <iostream>
using namespace std;


//多态
//1. 继承
//2. 虚函数， 子类完成虚函数的重写
//3. 调用虚函数的类型必须是指针/引用, 一般都是用父指针/引用指向父类以及子类实体


class A
{};

class B : public A
{

};

class Person {
public:
	Person()
	{
		cout << "开辟Person对象的资源" << endl;
	}
	virtual void BuyTicket() {
		cout << "买票-全价" << endl;
	}

	virtual ~Person()
	{
		cout << "清理Person对象资源" << endl;

	}
};

class Student : public Person {
public:
	Student()
	{
		cout << "开辟Student对象新加的资源" << endl;
	}

	//虚函数的重写：重写函数逻辑
	//构成虚函数的重写条件：子类含有和父类接口完全相同的函数

	virtual void BuyTicket(int a = 10) {
		cout << "买票-半价" << endl;
		
	}

	//协变：返回值类型可以不同，但是返回值类型必须是父子关系的指针引用
	/*virtual B& BuyTicket() {
		cout << "买票-半价" << endl;
		return B();
	}*/

	//子类析构函数和父类析构函数底层同名，所以只要父类析构是虚函数，则子类析构重新父类析构
	~Student()
	{
		cout << "清理Student对象新加的资源" << endl;
	}
};
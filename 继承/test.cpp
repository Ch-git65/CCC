#include <iostream>
#include <string>
using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public:
//	int _id = 1;
//
//	//protected: 类外不可见，类内部和子类可见
//protected:
//	string _name = "peter";
//private:
//	int _age = 18;
//};


//继承;  类代码复用
//class/struct 类名： 需要继承的类
//    子类/派生类   父类/基类
class Student : public Person
	//class Student: public Person
	//class Student: private Person
	//class定义的类， 默认继承方式：private
	//class Student: Person
	//strut定义的类： 默认继承方式： public
	//struct Student: Person

//{
//public:
//	void show()
//	{
//		cout << _name << "/t" << _id << endl;
//		//父类private成员在子类中不可见，但子类确实有父类的成员
//		//cout << _age << endl;
//	}
//	//protected:
//public:
//	int _num = 2020;
//};

//class Empty
//{};
//
//void test()
//{
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	cout << sizeof(Empty) << endl;
//
//	Person p;
//	//Print, id在父类中的访问权限位public
//	p.Print();
//	p._id = 3;
//
//	Student st;
//	//子类继承方式为protected/private, 从父类继承下来的所有成员的最低访问权限为protected/private
////	//所以在子类外不可见
//	st.Print();
//	st._id = 2;
//	//st._name="123";
//	//st._age = 18;
//}

//void test2()
//{
//	Person p;
//	Student st;
//
//	//切片： 子类对象，指针，引用可以直接赋值给父类对象
//	//指针，引用， 此处不是隐式类型转换
//	
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	//父类对象不能赋值给子类对象
//	//st = (Student)p;
//	//父类指针， 引用不能直接赋值给子类指针，引用。可以通过强转类型转换，进行赋值
//	//但是强转类型转换不安全，可能会导致访问越界
//	//一般不进行强转类型转换，而是采用动态转换
//
//	Student& rp = (Student&)p;
//	Student* ptrp = (Student*)&p;
//
//	cout << rp._nnum << endl;
//	cout << ptrp->_num << endl;
//
//	Student& rs2 = (Student&)rs;
//	cout << rs2._num << endl;
//	Student* ptrs2 = (Student*)ptrs;
//	cout << ptrs2->_num < , endl;
//}
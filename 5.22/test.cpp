#include<iostream>
using namespace std;
//�������Ա����������

struct A
{
public: //Ĭ��public
	int _a;
	void fun()
	{
		cout << "struct A fun()" << endl;
	}
};

class B
{
private: //Ĭ��˽��
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
	//���ʵ����������һ�������͵ı����Ĺ���
	//������ ����--> �Զ������͵ı��� һ��ϰ�߳�Ϊ����
	A a;
	B b;
	//struct����ĳ�ԱĬ�Ϸ���Ȩ��Ϊpublic
	a._a = 1;
	a.fun();
	//class����ĳ�ԱĬ�Ϸ���Ȩ��Ϊprivate

}
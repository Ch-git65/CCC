#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class A
{
public:
	A(int a, int b)
		:_a(a)
		, _b(b)
	{}

	A(int a)
		:_a(a)
		,_b(0)
	{}

private:
	int _a;
	int _b;
};

template<class T>
class Vector
{
public:
	Vector(int n, int a)
		:_array(new T[n])
		, _size(0)
		, _capacity(n)
	{}

	Vector(const initializer_list<T>& lst)
		:_array(new T[lst.size()])
		, _size(0)
		, _capacity(lst.size())
	{
		for (auto& e : lst)
			_array[_size++] = e;
	}

private:
	T* _array;
	int _size;
	int _capacity;
};

void test()
{
	int array[] = { 1,2,3,4,5 };
	//C++11  ֧���������͵��б��ʼ��
	int a = 1;
	int b = { 1 };
	int c{ 1 };
	float d = { 1.2f };

	//C++  ֧���Զ������͵��б��ʼ��
	vector<int>array3{ 1,2,3,4,5 };
	vector<int>array2 = { 1,2 };
	pair<int, int>m ={1,1};
	map<int, int>m = { {1,1}, {2,2}, {3,3} };
	
	//�Զ�������  ������������
	A a3 = { 1,2 };
	A a2(3, 4);

	//���ι��캯������ʽ����ת��
	A a4 = 5;

	//�Զ������ͣ���ʼ�����Ԫ��
}
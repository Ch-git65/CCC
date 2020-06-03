#include<string>
#include<iostream>
using namespace std;

void test7()
{
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	//reserve: 调整容量，一定不修改size和内容, 
	//如果减小容量，是按需减小，如果要减小的容量小于size,不做任何操作，如果减小的容量大于size，则进行减小的操作
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test8()
{
	string s;
	//容量和实际申请的空间可能不同： 字符串特点：以'\0'结束，需要给'\0'预留空间
	//PJ版string 增容过程： 如果为空字符串对象，初始容量大小为15，第一次增容2倍，后续按照1.5倍增容
	int size = s.size();
	//使用reserve提前开好空间，后续可以节省增容的开销，提高代码效率
	s.reserve(200);
	int cap = s.capacity();

	cout << "初始容量：" << cap << endl;
	for (int i = 0; i < 200; ++i)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << cap << endl;
		}
	}
}

void test9()
{
	string s;
	s.reserve(100);
	int size = s.size();
	int cap = s.capacity();
	s.resize(13);
	s.reserve(10);
	size = s.size();
	cap = s.capacity();

	s.shrink_to_fit();
	size = s.size();
	cap = s.capacity();

	s.reserve(10000);
	size = s.size();
	cap = s.capacity();

	s.reserve(15);
	size = s.size();
	cap = s.capacity();
}

void test10()
{
	string str("0123456789");

	//1. 迭代器
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//2. operator[]: 可读可写接口，如果越界，非法访问
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.operator[](i) << " ";
		str[i] = 'a';
	}
	cout << endl;
	//operator[]简写
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
	}

	//str[100] = 'c';
	cout << endl;
	//at:可读可写， 但是可读性不强, 如果越界，抛异常
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//str.at(100) = 'c';
	//3. 范围for遍历: 支持读写, 如果需要修改，则接收类型为引用类型
	//   底层通过迭代器实现
	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;

	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;
}
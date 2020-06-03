#include<string>
#include<iostream>
using namespace std;

void test7()
{
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	//reserve: ����������һ�����޸�size������, 
	//�����С�������ǰ����С�����Ҫ��С������С��size,�����κβ����������С����������size������м�С�Ĳ���
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
	//������ʵ������Ŀռ���ܲ�ͬ�� �ַ����ص㣺��'\0'��������Ҫ��'\0'Ԥ���ռ�
	//PJ��string ���ݹ��̣� ���Ϊ���ַ������󣬳�ʼ������СΪ15����һ������2������������1.5������
	int size = s.size();
	//ʹ��reserve��ǰ���ÿռ䣬�������Խ�ʡ���ݵĿ�������ߴ���Ч��
	s.reserve(200);
	int cap = s.capacity();

	cout << "��ʼ������" << cap << endl;
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

	//1. ������
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//2. operator[]: �ɶ���д�ӿڣ����Խ�磬�Ƿ�����
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.operator[](i) << " ";
		str[i] = 'a';
	}
	cout << endl;
	//operator[]��д
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
	}

	//str[100] = 'c';
	cout << endl;
	//at:�ɶ���д�� ���ǿɶ��Բ�ǿ, ���Խ�磬���쳣
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//str.at(100) = 'c';
	//3. ��Χfor����: ֧�ֶ�д, �����Ҫ�޸ģ����������Ϊ��������
	//   �ײ�ͨ��������ʵ��
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
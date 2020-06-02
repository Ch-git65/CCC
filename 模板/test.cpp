#include<iostream>
#include<string>
#include<vector>
using namespace std;
template <class T>
T add(const T& a, const T& b)
{
	return a + b;
}

template <class T1, class T2>
T2 Add(const T1& a, const T2& b)
{
	return a + b;
}

void test()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	add(a, b);

	add<int>(a, c);

	Add(a, c);

	Add(a, b);
}

int Add(const int& a, const int& b)
{
	return a + b;
}

void test1()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	//��ͨ������ģ�庯������ʱ�������ͨ�����Ĳ������Ϳ�����ȫƥ��
	//��ִ����ͨ������������ģ�庯����ʵ����
	//ֱ�ӳ��ֳɵķ�
	Add(a, b);

	//��ͨ������ģ�庯������ʱ����ͨ�����Ĳ������Ͳ�����ȫƥ��
	//��ʵ�����ĺ���������ȫƥ��������ͣ������ʵ����
	//�����óԣ�������
	Add(a, c);

	//��ͨ������ģ�庯������ʱ������ָ������Ҫʵ�����������ʵ����
	Add<int>(a, b);
}

//��ģ��
template <class T1, class T2, class T3>
class Date
{
public:
	Date(T1 year, T2 month, T3 day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void Display();

private:
	T1 _year;
	T2 _month;
	T3 _day;

};

//��������ⶨ����ģ��ĳ�Ա��������Ҫ���Ϸ��͵�����
//������Ϊ "����<���Ͳ���>"
template <class T1, class T2, class T3>
void Date<T1, T2, T3>::Display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

void test2()
{
	//��ģ�岻�ܽ�����ʽʵ����
	//Date d;
	//��ģ��
	//���ͺ�������ͬ
	//���ͣ�����<ģ��ʵ�ʲ�������>

	Date<int, int, int> d(2020, 5, 31);
	d.Display();
}

void test3()
{
	string str; //""
	string str2("123"); //"123"
	string str3 = "abc"; //"abc"
	string str4("0123456789", 5); //"01234"
	string cpy(str3); //"abc"
	
	string str5(str4, 2, 2); //"23"
	string str6(10, 'a'); //"aaaaaaaaaa"

	str6 = str5;
	str6 = "111";
	str6 = 'X';

}

void test4()
{
	string str("0123456789");
	//�������ı�����ʽ
	//��������һ���ɶ���д�Ľӿ�
	string::iterator it = str.begin();
	while (it != str.end())
	{
		//������������
		cout << *it << " ";
		//�޸�Ԫ������
		//*it='a';
		//����������ƶ�
		++it;
	}
	cout << endl;

	it = str.begin();
	while (it != str.end())
	{
		//������������
		cout << *it << " ";
		//����������ƶ�
		++it;
	}
	cout << endl;

	cout << "reverse_iterator:" << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit << " ";
		//�����������ǰ�ƶ�
		++rit;
	}
	cout << endl;
	cout << "const_iterator:" << endl;

	string::const_iterator cit = str.begin();
	//const����������ʹ��const�ӿڻ�ȡ�� c...()
	string::const_iterator cit2 = str.cbegin();
	while (cit != str.end())
	{
		cout << *cit << " ";
		//const��������֧��д��������Ϊֻ��������
		//*cit = '1';
		++cit;
	}
	cout << endl;

	/*vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>::iterator vit = vec.begin();
	while (vit != vec.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;*/
}

void prntString(const string& str)
{
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		//*it = 'a';
		++it;
	}
}

void test5()
{
	string str("0123456789");
	//size: ������Ч�ַ��ĸ���
	int ret = str.size();
	//length��������Ч�ַ��ĸ���
	ret = str.length();
	//capacity: ���Դ�ŵ������Ч�ַ��ĸ���
	ret = str.capacity();
	size_t maxSize = str.max_size();

	//clear ֻ������ݣ����ı�����
	str.clear();
	ret = str.size();
	ret = str.capacity();

}

void test6()
{
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();
	//resize(n)
	//1.��n>size,n>capacity  ����(���µĿռ� + ���� + �ͷ�ԭ�пռ䣩 + �µ�λ�ø�ֵ�����û�и���ֵ�ַ���Ĭ�ϸ�ֵ'\0' + �޸�size
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	//2.�� n < size: ֻ�޸�size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	//3. �� n > size, �� n < capacity: �µ�λ�ø�ֵ�����û�и���ֵ�ַ���Ĭ�ϸ�ֵ'\0' + �޸�size
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();

}
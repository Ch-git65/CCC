#include <string>
#include <iostream>
using namespace std;

class String
{
	 
	//������  һ�ַ�������Ԫ�صĻ��ƣ����ַ�װ�����ԣ�
	//����Ҫ��ע������ʵ��ϸ�ڣ��Ϳ���ֱ�ӷ��ʣ��ɶ���д��Ԫ��
	//ʹ�÷�ʽ�� ������ָ��Ĳ���
	//  1. �����á���> ��ȡָ��λ�õ�����
	//  2. λ���ƶ�����> ָ������λ��

	// string ������ ��ͨ��ָ��ʵ��
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		//��һ��Ԫ�ص�λ��
		return _str;
	}

	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	const_iterator begin() const
	{
		//��һ��Ԫ�ص�λ��
		return _str;
	}

	const_iterator end() const
	{
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	String()
		:_str(new char[16])
		, _size(0)
		, _capacity(0)
	{
		_str[_size] = '\0';
		_capacity = 15;
	}

	String(const char* str)
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	String(const String& str)
		:_str(new char[str._capacity + 1])
		, _size(str._size)
		, _capacity(str._capacity)
	{
		//����� ��Դ����
		strcpy(_str, str._str);
		cout << "String(const String&)" << endl;
	}
	

	//�������죻 �ִ�д�������븴��
	String(const String& str)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		//���ù��캯��
		string tmp(str._str);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	////��������� Ч�ʵ�
	//void Swap(String& str)
	//{
	//	//��������
	//	String tmp = str;
	//	str = *this;
	//	*this = tmp;
	//}

	//String& operator=(const String& str)
	//{
	//	if (this != &str)
	//	{
	//		//���ռ�
	//		char* tmp = new char[str._capacity + 1];

	//		//���ݿ���
	//		strcpy(tmp, str._str);

	//		//�ͷ�ԭ�пռ�
	//		delete[] _str;

	//		_str = tmp;
	//		_size = str._size;
	//		_capacity = str._capacity;
	//	}
	//	return *this;

	//}

	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	const char* c_str() const
	{
		return _str;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_size = _capacity = 0;
			_str = nullptr;
		}
		cout << "~String" << endl;
	}

	void pushBack(const char& ch)
	{
		////�������
		//if (_size == _capacity)
		//{
		//	size_t newC = _capacity == 0 ? 1 : 2 * _capacity;
		//	reserve(newC);
		//}
		////β��
		//_str[_size] = ch;
		//++_size;
		//_str[_size] = '\0';
		insert(_size, ch);
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//���ռ� +1-->���\0
			char* tmp = new char[n + 1];
			//����
			strcpy(tmp, _str);
			//�ͷ�ԭ�пռ�
			delete[] _str;

			_str = tmp;
			//��������
			_capacity = n;
		}
	}

	char& operator[](size_t pos) 
	{
		if (pos < _size)
			return _str[pos];
	}

	const char& operator[](size_t pos)const
	{
		if (pos < _size)
			return _str[pos];
	}

	size_t size() const
	{
		return _size;
	}

	void Append(const char* str)
	{
		//int len = strlen(str);
		////�������
		//if (_size + len > _capacity)
		//{
		//	reserve(_size + len);
		//}
		////β��
		//strcpy(_str + _size, str);

		////�޸�size
		////_size+=len;
		insert(_size, str);
	}


	String& operator+=(const char& ch)
	{
		pushBack(ch);
		return *this;
	}

	String& operator+=(const char& str)
	{
		pushBack(str);
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		if (pos > _size)
		{
			return;
		}

		if (_size == _capacity)
		{
			size_t newC = _capacity = 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		//�ƶ�Ԫ��[pos, _size]: �Ӻ���ǰ�ƶ��������ƶ����Ҷ˵��ַ�
		size_t end = _size + 1;
		//end>=pos  ��pos=0ʱ����ѭ��������Խ��
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}

		_str[pos] = ch;
		++_size;
	}


	void insert(size_t pos, const char* str)
	{
		if (pos > _size)
			return;
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//�ƶ�Ԫ��[pos, _size]
		size_t end = _size + len;
		//size --> size + len,  pos ---> pos + len
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		//����
		for (int i = 0; i < len; ++i)
		{
			_str[i + pos] = str[i];
		}

		_size += len;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};





#include <string>
#include <iostream>
using namespace std;

class String
{
	 
	//迭代器  一种访问容器元素的机制，体现封装的特性，
	//不需要关注容器的实现细节，就可以直接访问（可读可写）元素
	//使用方式： 类似于指针的操作
	//  1. 解引用——> 获取指向位置的内容
	//  2. 位置移动——> 指向其它位置

	// string 迭代器 ：通过指针实现
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		//第一个元素的位置
		return _str;
	}

	iterator end()
	{
		//最后一个元素的下一个位置
		return _str + _size;
	}

	const_iterator begin() const
	{
		//第一个元素的位置
		return _str;
	}

	const_iterator end() const
	{
		//最后一个元素的下一个位置
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
		//深拷贝： 资源拷贝
		strcpy(_str, str._str);
		cout << "String(const String&)" << endl;
	}
	

	//拷贝构造； 现代写法，代码复用
	String(const String& str)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		//调用构造函数
		string tmp(str._str);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	////深拷贝交换： 效率低
	//void Swap(String& str)
	//{
	//	//拷贝构造
	//	String tmp = str;
	//	str = *this;
	//	*this = tmp;
	//}

	//String& operator=(const String& str)
	//{
	//	if (this != &str)
	//	{
	//		//开空间
	//		char* tmp = new char[str._capacity + 1];

	//		//内容拷贝
	//		strcpy(tmp, str._str);

	//		//释放原有空间
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
		////检查容量
		//if (_size == _capacity)
		//{
		//	size_t newC = _capacity == 0 ? 1 : 2 * _capacity;
		//	reserve(newC);
		//}
		////尾插
		//_str[_size] = ch;
		//++_size;
		//_str[_size] = '\0';
		insert(_size, ch);
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//开空间 +1-->存放\0
			char* tmp = new char[n + 1];
			//拷贝
			strcpy(tmp, _str);
			//释放原有空间
			delete[] _str;

			_str = tmp;
			//更新容量
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
		////检查容量
		//if (_size + len > _capacity)
		//{
		//	reserve(_size + len);
		//}
		////尾插
		//strcpy(_str + _size, str);

		////修改size
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

		//移动元素[pos, _size]: 从后向前移动，首先移动最右端的字符
		size_t end = _size + 1;
		//end>=pos  当pos=0时，死循环，访问越界
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
		//移动元素[pos, _size]
		size_t end = _size + len;
		//size --> size + len,  pos ---> pos + len
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		//插入
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





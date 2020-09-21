//只在堆上创建对象的类

// 构造函数私有
// 提供一个静态的堆上创建对象的方法
// 防拷贝  拷贝构造声明为私有，且不实现，或声明为delete的函数

class HeapOnly
{
public:
	static HeapOnly* getInstance()
	{
		//堆上创建对象
		return new HeapOnly;
	}

private:
	HeapOnly()
	{}

	//HeapOnly(const HeapOnly& ho);
	HeapOnly(const HeapOnly& ho) = delete;
};

//HeapOnly g;
void test()
{
	//HeadOnly ho;
	HeapOnly* ptr = HeapOnly::getInstance();

	//HeapOnly copy(*ptr);
}


//只在栈上创建对象的类
// 构造函数私有
// 提供一个公有的静态的栈上创建对象的方法
class StaclOnly
{
public:
	static StaclOnly getInstance()
	{
		return StaclOnly();
	}
private:
	StaclOnly()
	{};
};

//StackOnly so;
void testStackOnly()
{
	//StackOnly* ptr = new StackOnly;
	StaclOnly so = StaclOnly::getInstance();
}

// 2
// 构造函数私有
// 提供一个公有的静态的栈上创建对象的方法
// 把operator new函数声明为delete函数
class StaclOnly2
{
public:
	static StaclOnly2 getInstance()
	{
		return StaclOnly2();
	}

	void* operator new(size_t n) = delete;
private:
	StaclOnly2() {};
};


//禁止拷贝的类
// 拷贝构造和赋值运算符声明为delete函数， 或声明为私有，且不实现
class NoCopy
{
public:
	NoCopy() {};
private:

	NoCopy(const NoCopy& nc) = delete;
	NoCopy& operator=(const NoCopy& nc) = delete;
};

//不能被继承的类
// 父类的构造声明为私有
class NoH
{
private:
	NoH() {};
};

class NoH2 final
{};

//class sub : public NoH
class sub /*:public NoH2*/
{

};

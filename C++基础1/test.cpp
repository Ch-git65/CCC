#include<stdio.h>
#include<iostream>
using namespace std;

namespace bite
{
	void print(int a)
	{
		printf("%d\n", a);
	}

	int a;
	int b;
	//嵌套定义
	namespace bite_69
	{
		void fun1(int a)
		{
			printf("%d\n", a);
		}
		int a;
		int b;
	}
}


//可以分段定义，编译器会合并相同的命名空间
//相同的命名空间不能定义重复的变量和函数
namespace bite
{
	int c;
	int d;
	void fun2()
	{
		printf("fun2()\n");
	}
	void fun3()
	{
		printf("fun3()\n");
	}
}

void fun2()
{
	printf("fun2()\n");
}

void fun1(int a)
{
	printf("%d\n", a);
}

void print(int a)
{
	printf("%d\n", a);
}

int a;
int b;

//命名空间成员的使用方式
//1.命名空间 + :: + 成员
//2.引入成员 using + 命名空间 + :: +成员:   后面使用成员时，不需要加作用域
//3.展开命名空间 using + 命名空间 : 
//using bite::fun3;
//using bite::a;
//using namespace bite;

void test()
{
	bite::a = 1;
	bite::print(bite::a);//bite命名空间下的成员a
	bite::print(a);//全局a
	bite::bite_69::a = 2;
}

void fun3(int a)
{
	a = 10;//局部域
	bite::a = 20;//命名空间域
	bite::bite_69::a = 30;//命名空间域
	::a = 40;//全局作用域
}


//缺省参数: 给参数定义一个默认值，实际使用时，如果没有传参，对应的形参使用默认值

//全缺省
void fun5(int a = 1, int b = 2, int c = 3)
{
	std::cout << a << b << c << std::endl;
}

//半缺省
void fun6(int a, int b = 1, int c = 2)
{
	std::cout << a << b << c << std::endl;
}

//半缺省参数: 必须从右向左依次连续赋值，中间不能有间隔
//缺省值只能出现在声明或定义的地方，不能同时出现


//函数重载: 函数名相同，参数不同，且在同一个作用域， C不支持
//参数不同: 类型，个数，顺序不同
//仅仅是返回值不同，不能构成函数重载


void test6()
{
	//引用: 类型 + & +引用名称
	int a = 10;
	//a的别名
	int& ra = a;
	int& ra2 = a;
	ra2 = 30;
	ra = 100;
	a = 1000;

	cout << &a << endl;
	cout << &ra << endl;
	cout << &ra2 << endl;
	//引用定义时必须初始化
	//int &ra3
	int b = -1;
	ra = b;//赋值，引用定义之后，不会在去更改实体的指向
	ra = -100;

}


void test7()
{
	//const引用
	const int a = 10;
	const int& ra = a;
	const int& r = 10;
	double d = 2.0;
	double& ra = d;
	int c = d;
	//d隐式类型转换，生成一个临时的整形变量
	const int& rd2 = d;
}

int main()
{
	test6();
}
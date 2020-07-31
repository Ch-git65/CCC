#include<iostream>
using namespace std;

//加法
class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0)
		{
			int sum = num1 ^ num2;
			int carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		return num1;
	}
};


//三角形
#include<iostream>
#include<string>
#define ADD(x,y) ((x)+(y))
#define CMP(x,y) ((x)>(y))
int main()
{
	double a, b, c;
	while (std::cin >> a >> b >> c)
	{
		if (CMP(ADD(a, b), c) && CMP(ADD(a, c), b) && CMP(ADD(c, b), a))
		{
			std::cout << "Yes" << std::endl;
		}
		else
			std::cout << "No" << std::endl;
	}
	return 0;
}
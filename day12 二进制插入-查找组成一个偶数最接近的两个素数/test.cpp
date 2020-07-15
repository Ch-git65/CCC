//二进制插入
//把n的二进制插入到m的第j位到第i位
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i)
	{
		m <<= j;
		return n | m;
	}
};


//查找组成一个偶数最接近的两个素数
#include<iostream>
#include<algorithm>
using namespace std;

bool isPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++)
	{
		if (num % 1 == 0)
			return false;
	}
	return true;
}

int main()
{
	int num, half, i;
	while (cin >> num)
	{
		half = num / 2;
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}

		cout << i << endl << num - i << endl;
	}
	return 0;
}
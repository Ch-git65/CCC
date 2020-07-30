//星际密码
//n对应的值是矩阵x的n次方的左上角，若不足4位用0填充，若大于4位只输出后四位
#include<iostream>
#include<vector>
std::vector<int> a = { 1,1 };
void init()
{
	int i;
	for (i = 2; i < 10005; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
}

int main()
{
	int n, t;
	init();
	while (std::cin >> n)
	{
		while (n--)
		{
			std::cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}


//数根
// 24  2+4 = 6  6是一位数， 6是24的数根
// 39  3+9 = 12   1+2=3   3是29的数根
#include<iostream>
#include<string>
int numroot(int num)
{
	int n = 0;
	while (num > 0)
	{
		n += num % 10;
		num /= 10;
	}
	while (n > 9)
	{
		n = numroot(n);
	}
	return n;
}
int main()
{
	std::string a;
	while (std::cin >> a)
	{
		int sum = 0;
		for (int i = 0; i < a.length(); i++)
		{
			sum += a[i] - '0';
		}
		std::cout << numroot(sum) << std::endl;
	}
	return 0;
}
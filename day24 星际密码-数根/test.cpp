//�Ǽ�����
//n��Ӧ��ֵ�Ǿ���x��n�η������Ͻǣ�������4λ��0��䣬������4λֻ�������λ
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


//����
// 24  2+4 = 6  6��һλ���� 6��24������
// 39  3+9 = 12   1+2=3   3��29������
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
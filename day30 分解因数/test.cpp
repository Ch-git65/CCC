//分解因数
//90=2*3*3*5
#include<iostream>
#include<cmath>
#include<cstdio>
int main()
{
	size_t n;
	while (std::cin >> n)
	{
		printf(" %d =", n);
		for (size_t i = 2; i <= std::sqrt(n); i++)
		{
			while (n % i == 0 && n != i)
			{
				printf("%u *", i);
				n /= i;
			}
		}
		printf("%d\n",n);
	}
	return 0;
}
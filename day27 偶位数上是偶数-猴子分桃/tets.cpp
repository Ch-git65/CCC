//偶位数上都是偶数或奇位数是奇数

#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
	void odd(std::vector<int>&arr, int len)
	{
		long i = 0, j = 1;
		while (i < len && j < len)
		{
			if ((arr[i] % 2) == 0)
			{
				i += 2;
				continue;
			}
			if ((arr[i] % 2) != 0)
			{
				j += 2;
				continue;
			}
			std::swap(arr[i], arr[j]);
		}
	}
};


//猴子分桃
//每次分5堆会多出一个给老猴
#include<iostream>
#include<string>
#include<math.h>
int main()
{
	int n;
	while (std::cin >> n)
	{
		if (n == 0)
			break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		std::cout << total << " " << left << std::endl;
	}
	return 0;
}
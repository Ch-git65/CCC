//正整数组的最小不可组成和
// arr = { 3, 2, 5}  min=2  max=10, 在[2,10]上， 4
#include<iostream>
#include<vector>
class Solution {
public:
	int get(std::vector<int>& arr, int length)
	{
		int sum = 0, min = arr[0];
		int i, j;
		for (int i = 0; i < length; i++)
		{
			sum += arr[i];
			min = arr[i] < min ? arr[i] : min;
		}
		std::vector<int>dp(sum + 1, 0);

		for (i = 0; i < length; i++)
		{
			for (j = sum; j >= arr[i]; j--)
			{
				if (dp[j] < dp[j - arr[i]] + arr[i])
					dp[j] = dp[j - arr[i]] + arr[i];
				else
					dp[j] = dp[j];
			}
		}

		for (i = min; i <= sum; i++)
		{
			if (i != dp[i])
				return 1;
		}
		return sum + 1;
	}
};


//有假币
//用天平 重量不同
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	long long n;
	int cnt;
	while ((scanf("lld", &n)) != EOF)
	{
		if (n == 0)
			break;
		cnt = 0;
		while (n >= 2)
		{
			if (n % 3)
			{
				n = n / 3 + 1;
			}
			else
			{
				n /= 3;
			}
			cnt++;
		}

		printf("%d\n",cnt);
	}
	return 0;
}
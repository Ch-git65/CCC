//字符串计数
//求字典序列s1-s2之间，长度在len1-len2的字符串的个数
// ab ce 1 2
// 56
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000007
#include <math.h>
using namespace std;

int main()
{
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));

		vector<int>array;
		for (int i = 0; i < len2; i++)
			array.push_back(s2[i] - s1[i]);

		int result = 0;
		for (int i = len1; i <= len2; i++)
		{
			for (int k = 0; k < i; k++)
				result += array[k] * pow(26, i - 1 - k);
		}
		cout << result - 1 << endl;
	}
	return 0;
}


//最长公共子序列
//有两个字符串m和n， 若它们的子串a和b内容相同，则a，b是m和n的公共子序列
// abcfbc abfcab
// 4
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int n1 = A.length();
		int n2 = B.length();
		vector<vector<int>>dp(n1, vector<int>(n2, 0));

		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < n1; i++)
		{
			dp[i][0] = (A[0] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}

		for (int j = 1; j < n2; j++)
		{
			dp[0][j] = (A[0] == B[0]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}

		for (int i = 1; i < n1; i++)
		{
			for (int j = 1; j < n2; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[n1 - 1][n2 - 1] << endl;

	}
	return 0;
}
//字符串反转
#include<iostream>
#include<string>
using namespace std;

string reverse(string s)
{
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
	    ++start;
		--end;
	}
	return s;
}

int main()
{
	string s;
	getline(cin, s);
	cout << reverse(s) << endl;
	return 0;
}


//公共字符串计算
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int max = 0;
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int n1 = s1.size();
		int n2 = s2.size();
		int max = 0;

		vector < vector<int>> dp(n1, vector<int>(n2, 0));
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				if (s1[i] == s2[i])
				{
					if (i >= 1 && j >= 1)
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						dp[i][j] = 1;
				}

				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		cout << max << endl;
	}
	return 0;
}
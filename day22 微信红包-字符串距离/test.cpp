//Î¢ÐÅºì°ü
//class Gift {
//public:
//	int getValue(vector<int>gifts, int n)
//	{
//		map<int, int>count;
//		int middle = gifts.size() / 2;
//
//		for (const auto& e : gifts)
//			++count[e];
//
//		for (const auto& e : gifts)
//			if (e.second >= middle)
//				return e.first;
//		return 0;
//	}
//};


//¼ÆËã×Ö·û´®µÄ¾àÀë

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int mins(string s1, string s2)
{
	if (s1.empty() || s2.empty())
		return max(s1.size(), s2.size());

	int n1 = s1.size();
	int n2 = s2.size();
	vector<vector<int>> f(1 + n1, vector<int>(1 + n2, 0));

	for (int i = 0; i < n1; ++i)
		f[i][0] = i;

	for (int i = 0; i < n2; ++i)
		f[0][i] = i;

	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j < n2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);

				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}

			else
			{
				f[i][j] = 1 + min(f[i][j-1], f[i-1][j]);

				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
		}
	}
	return f[n1][n2];
}


int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << mins(s1, s2) << endl;
	return 0;
}
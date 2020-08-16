//发邮件
//给n个人发邮件，没人发1件，有多少情况下所有人都收到错误的？

#include<iostream>
using namespace std;
int main()
{
	long long der[21] = { 0,0,1 };
	for (int i = 3; i < 21; i++)
	{
		der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
	}

	int n;
	while (cin >> n)
	{
		cout << der[n] << endl;
	}
	return 0;
}



//最长上升子序列
// 1 7 3 5 9 4 8
// 4        1 3 5 9     1 3 4 8
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> height[i];
		}

		vector<int> f(n, 1);

		int result = 1;

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (height[i] > height[j])
					f[i] = max(f[i], f[j] + 1);
			}
			result = max(result, f[i]);
		}
		cout << result << endl;
	}
	return 0;
}
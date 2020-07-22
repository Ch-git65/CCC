//汽水瓶
//3个空汽水瓶换一瓶
#include<iostream>
#include<string>
using namespace std;

int num(int n)
{
	int sum = 0;
	while (n > 1)
	{
		int result = n / 3;
		int reminder = n % 3;

		sum += result;
		n = result + reminder;

		if (n == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << num(n) << endl;
	}
	return 0;
}


//查找两个字符串中的最长公共子串
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;

	if (str1.size() > str2.size())
		swap(str1, str2);

	int n1 = str1.size(), n2 = str2.size();
	int i, j, start=0, max = 0;

	vector<vector<int>> MCS(n1 + 1, vector<int>(n2 + 1, 0));
	for (i = 1; i <= n1; i++)
	{
		for (j = 1; j <= n2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;

			if (MCS[i][j] > max)
			{
				max = MCS[i][j];

				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}
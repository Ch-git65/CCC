//统计回文
//输出一个数字，表示把字符串B插入字符串A后构成回文串的方法数
// aba
// b
// 2

#include<iostream>
#include<string>
using namespace std;

bool huiwen(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;

		++begin;
		--end;
	}
	return true;
}

int main()
{
	std::string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;

	for (size_t i = 0; i <= str1.size(); ++i)
	{
		string str = str1;
		str.insert(i, str2);
		if (huiwen(str))
			++count;
	}
	cout << count << endl;
	return 0;

}

//连续最大和
// 3 -1 2 1
// 3

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int>nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];

	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}

	cout << result << endl;
	return 0;
}
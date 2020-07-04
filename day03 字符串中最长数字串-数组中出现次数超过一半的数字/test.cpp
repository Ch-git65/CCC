//字符串中最长数字串
// abcd12345ed125ss123456789
// 123456789

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str, res, cur;
//	cin >> str;
//	for (int i = 0; i <= str.length(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			cur += str[i];
//		}
//		else
//		{
//			if (res.size() < cur.size())
//				res = cur;
//			else
//				cur.clear();
//		}
//	}
//	cout << res;
//	return 0;
//}


//数组中出现次数超过一半的数字

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;

		sort(numbers.begin(), numbers.end());
		int middle = numbers[numbers.size() / 2];

		int count = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == middle)
				++count;
		}

		return (count > numbers.size() / 2) ? middle : 0;
	}
};
//兔子总数
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int first = 1;
		int second = 1;
		int result;
		for (int i = 3; i <= n; ++i)
		{
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	}
	return 0;
}


//字符串通配符
#include<iostream>
#include<string>
using namespace std;

bool match(const char* pattern, const char* str)
{
	if (*pattern == '\0' && *str == '\0')
		return true;

	if (*pattern == '\0' || *str == '\0')
		return false;

	if (*pattern == '?')
	{
		return match(pattern + 1, str + 1);
	}

	else if (*pattern == '*')
	{
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}

	else if (*pattern == *str)
	{
		return match(pattern + 1, str + 1);
	}

	return false;
}

int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
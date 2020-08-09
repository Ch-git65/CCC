//剪花布条
//一条花布条，里面有图案，另有一块直接可用的小饰条，里面也有图案，
//对于给定的花布条和小饰条，计算可从花布条中剪几块小饰条
// abcde a3               0
// aaaaaa aa              3
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		//依次在s中查找t即可，知道找不到
		if ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();//跳过t串整体的长度
			++res;
		}
		cout << res << endl;
	}
	return 0;
}



//客似云来
//客人只要来这家店吃过一次饭，就会每天过来，并且在吃了两天后，就会带新朋友
//
#include<iostream>
using namespace std;
#define MAX 83

void solve(long long num[])
{
	for (int i = 2; i < MAX; i++)
	{
		num[i] = num[i - 1] + num[i - 2];
	}
}

//遍历
long long sum_traversal(long long num[], int from, int to)
{
	long long ans = 0;
	for (int i = from - 1; i < to; i++)
	{
		ans += num[i];
	}
	return ans;
}

//公式
long long sum_fromula(long long num[], int from, int to)
{
	return num[to + 1] - num[from];
}

int main()
{
	int from, to;
	long long num[MAX] = { 1,1 };
	solve(num);
	while (cin >> from >> to)
	{
		cout << sum_fromula(num, from, to) << endl;
	}
	return 0;
}
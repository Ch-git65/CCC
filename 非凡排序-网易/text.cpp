//要求 a[i] * a[i + 1] <= a[i + 1] * a[i + 2]
//根据正负去分别判断，保证乘积为负的放左边，乘积为正的放右边。
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
#include "limits.h"
#include "math.h"
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main(int argc, const char* argv[])
{
	//输入有正负
	int n, num;
	cin >> n;
	vector<int> posi;
	vector<int> nega;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num < 0)
			nega.push_back(num);
		else
			posi.push_back(num);
	}

	//正数更多，整个正数升序排序
	//（负 正 负 正），正数逆序，负数正序 +（正....正）正数升序排列
	if (posi.size() >= nega.size())
	{
		sort(posi.begin(), posi.end()); //升序
		sort(nega.begin(), nega.end());
		int i = 0, j = nega.size() - 1;

		for (;i<nega.size(); i++,j--)
			cout << nega[i] << " " << posi[i] << " ";

		for (; i < posi.size(); i++)
			cout << posi[i] << " ";

		cout << endl;
	}
	else
	{
		//负数整体逆序
		//（正 负 正 负）正数逆序 负数升序 （负....负）负数逆序
		sort(posi.begin(), posi.end(), cmp); // 逆序
		sort(nega.begin(), nega.end(), cmp);
		int i = 0, j = posi.size() - 1;
		for (; j < posi.size(); i++, j--)
			cout << posi[i] << " " << nega[j] << " ";

		for (; j < nega.size(); i++)
			cout << nega[i] << " ";

		cout << endl;
	}
	return 0;
}
//计算糖果
// A-B, B-C, A+B, B+C
// A B C
#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 != B2)
		cout << "No";
	else
		cout << "A" << " " << B1 << " " << C;
	return 0;
}



//进制转换
// 将十进制数转换为N进制数
// 7 2
// 111

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;

	//如果是负数，转正并标记
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}

	//按进制换算成对应的字符添加到s
	while (m)
	{
		s += table[m % n];
		m /= n;
	}

	if (flag)
		s += '-';

	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}
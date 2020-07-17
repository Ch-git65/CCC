//计算日期到天数转换
#include<iostream>
using namespace std;
int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;
	int sum;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month - 2];
		sum += day;

		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				sum += 1;
		}
		cout << sum << endl;
	}
}


//幸运的袋子
//当所有球的和大于积
// 3
// 1 1 1
// 2   多少种不同
#include<iostream>
#include<algorithm>
using namespace std;

int get(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		multi *= x[i];

		if (sum > multi)
			count += 1 + get(x, n, i + 1, sum, multi);

		else if (x[i] == 1)
			count += get(x, n, i + 1, sum, multi);
		else
			break;

		sum -= x[i];
		multi /= x[i];

		while (i < n - 1 && x[i] == x[i + 1])
			i++;

	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int x[111111];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		cout << get(x, n, 0, 0, 1) << endl;
	}
	return 0;
}
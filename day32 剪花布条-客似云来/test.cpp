//��������
//һ����������������ͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��ͼ����
//���ڸ����Ļ�������С����������ɴӻ������м�����С����
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
		//������s�в���t���ɣ�֪���Ҳ���
		if ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();//����t������ĳ���
			++res;
		}
		cout << res << endl;
	}
	return 0;
}



//��������
//����ֻҪ����ҵ�Թ�һ�η����ͻ�ÿ������������ڳ�������󣬾ͻ��������
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

//����
long long sum_traversal(long long num[], int from, int to)
{
	long long ans = 0;
	for (int i = from - 1; i < to; i++)
	{
		ans += num[i];
	}
	return ans;
}

//��ʽ
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
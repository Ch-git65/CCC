//�����������
//��ʾ���������ڵ�����Ĺ������ڵ�
//      1
//   2    3
// 4  5  6  7

// 2  7
// 7/2=3 -> 3/2=1 �� 2/2=1
// 1
class LCA
{
public:
	int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};


//�������bit��
//��һ��bite���ֶ�Ӧ�Ķ�����������1�����������
// 3
// 2
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;
		//n����32Ϊ0
		while (n)
		{
			//��ȡ��ǰλ�Ķ�����ֵ
			if (n & 1)
			{
				//���1��ֵ�����������ۼӣ����Ҹ���������
				++count;
				maxcount = max(count, maxcount);
			}

			else
			{
				//���1��ֵ�������������ۼ�
				count = 0;
			}

			//����һ�Σ�Ϊ��ȡ��һλ������ֵ��׼��
			n = n >> 1;

		}
		cout << maxcount << endl;
	}
	return 0;
}
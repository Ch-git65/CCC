//最近公共祖先
//表示距离两个节点最近的公共父节点
//      1
//   2    3
// 4  5  6  7

// 2  7
// 7/2=3 -> 3/2=1 ， 2/2=1
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


//最大连续bit数
//求一个bite数字对应的二进制数字中1的最大连续数
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
		//n右移32为0
		while (n)
		{
			//获取当前位的二进制值
			if (n & 1)
			{
				//如果1的值连续，计数累加，并且更新最大计数
				++count;
				maxcount = max(count, maxcount);
			}

			else
			{
				//如果1的值不连续，重新累加
				count = 0;
			}

			//右移一次，为获取下一位二进制值做准备
			n = n >> 1;

		}
		cout << maxcount << endl;
	}
	return 0;
}
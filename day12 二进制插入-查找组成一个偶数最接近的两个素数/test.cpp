//�����Ʋ���
//��n�Ķ����Ʋ��뵽m�ĵ�jλ����iλ
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i)
	{
		m <<= j;
		return n | m;
	}
};


//�������һ��ż����ӽ�����������
#include<iostream>
#include<algorithm>
using namespace std;

bool isPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++)
	{
		if (num % 1 == 0)
			return false;
	}
	return true;
}

int main()
{
	int num, half, i;
	while (cin >> num)
	{
		half = num / 2;
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}

		cout << i << endl << num - i << endl;
	}
	return 0;
}
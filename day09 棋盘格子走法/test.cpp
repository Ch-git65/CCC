//·������
#include<iostream>
using namespace std;
int pathnum(int n, int m)
{
	if (n > 1 && m > 1)
		return pathnum(n - 1, m) + pathnum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		return n + m;
	else
		return 0;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathnum(n, m) << endl;
	}
	return 0;
}


//����ӷ�
class UnusualADD {
public:
	int addAB(int A, int B)
	{
		int sum = 0, carry = 0;
		while (B != 0)
		{
			//��Ӧλ�ĺ�
			sum = A ^ B;
			//��Ӧλ�͵Ľ�λ��  ��������һλ
			carry = (A & B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};
//��̬��̨��
class Solution {
public:
	int JumpFloorII(int number)
	{
		return 1 << (number - 1);
	}
};

//�쵽������
#include<iostream>
using namespace std;
int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (n > (2 * 3.14 * r))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
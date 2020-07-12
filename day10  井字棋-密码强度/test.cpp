//井字棋

#include<iostream>
#include<vector>
using namespace std;

class Board {
public:
	bool checkWon(vector<vector<int>> board)
	{
		int row = board.size();
		int i, j, sum;
		//检查每一行的和是否等于row
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}

		//检查每一列的和是否等于row
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}

		//检查主对角线和
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
			return true;

		//检查副对角线和
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][row-i-1];
		}
		if (sum == row)
			return true;
		return false;
	}
};


//密码强度
int numchar(string str, int k)
{
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			big++;
		}
		else if (str[i] >= 97 && str[i] <= 122)
			small++;
	}

	if ((small + big) == 0)
		return 0;
	else if (small == k || big == k)
		return 10;
	else(small > 0 && big > 0)
		return 20;
	return 0;
}


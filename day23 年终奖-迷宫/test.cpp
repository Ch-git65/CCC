#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���ս�
class Bonus {
public:
	int getMost(vector<vector<int>> board)
	{
		int length = board.size();
		int width = board[0].size();
		vector<vector<int>> allPrice;
		for (int i = 0; i < length; i++)
		{
			vector<int>tmp(width, 0);
			allPrice.push_back(tmp);
		}

		allPrice[0][0] = board[0][0];
		for (int i = 0; i < length; i++)
			for (int j = 0; j < length; j++)
				if (i == 0 && j == 0)
					continue;
				else if (i == 0)
					allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
				else if (j == 0)
					allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
				else
					allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i-1][j] + board[i][j] );
		return allPrice[length - 1][width - 1];
	}
};


//�Թ�����
#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> maze; //�Թ�����
vector<vector<int>> temp; //�洢��ǰ·��
vector<vector<int>> best; //�洢���·��

void Maze(int i, int j)
{
	maze[i][j] = 1;
	temp.push_back({ i,j });

	if (i == N - 1 && j == M - 1) //�Ƿ��յ�
		if (best.empty() || temp.size() < best.size())
			best = temp;

	if (i - 1 >= 0 && maze[i - 1][j] == 0) //�����߿���
		Maze(i - 1, j);

	if (i + 1 < N && maze[i + 1][j] == 0) //��
		Maze(i + 1, j);

	if (j - 1 >= 0 && maze[i][j - 1] == 0)
		Maze(i, j - 1);

	if (j + 1 < M && maze[i][j + 1] == 0)
		Maze(i, j + 1);

	maze[i][j] = 0;
	temp.pop_back();
}

int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		temp.clear();
		best.clear();
		for (auto& i : maze)
			for (auto& j : i)
				cin >> j;

		Maze(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
	}
	return 0;
}

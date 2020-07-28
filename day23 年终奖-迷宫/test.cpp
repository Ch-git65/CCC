#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//年终奖
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


//迷宫问题
#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> maze; //迷宫矩阵
vector<vector<int>> temp; //存储当前路径
vector<vector<int>> best; //存储最佳路径

void Maze(int i, int j)
{
	maze[i][j] = 1;
	temp.push_back({ i,j });

	if (i == N - 1 && j == M - 1) //是否到终点
		if (best.empty() || temp.size() < best.size())
			best = temp;

	if (i - 1 >= 0 && maze[i - 1][j] == 0) //向上走可行
		Maze(i - 1, j);

	if (i + 1 < N && maze[i + 1][j] == 0) //下
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

		Maze(0, 0);//回溯寻找迷宫最短通路
		for (auto i : best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
	}
	return 0;
}

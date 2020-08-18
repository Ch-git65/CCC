//Ω‚∂¡√‹¬Î
//&Ts!47&*s456 a23* +B9k
//47456239
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			if (s[i] <= '9' && s[i] >= '0')
				cout << s[i];
		}
		cout << endl;
	}
	return 0;
}

//◊ﬂ√‘π¨
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

struct pos{int x, y, level;};

int bfs(vector<vector<char>>& map)
{
	const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pos> que;
	int m = map.size(), n = map[0].size();
	vector<vector<bool>> visit(m, vector<bool>(n, false));

	pos start{ 0,1,0 }, end{ 9,8,0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty())
	{
		pos cur = que.front(), next;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][0];
			next.level = cur.level + 1;

			if (next.x == end.x && next.y == end.y)
				return next.level;

			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n &&
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
	return 0;
}

int main()
{
	vector<vector<char>>  map(10, vector<char>(10));
	while (cin >> map[0][0])
	{
		for(int i=0;i<10;i++)
			for (int j = 0; j < 10; j++)
			{
				if (i == 0 && j == 0) continue;
				cin >> map[i][j];
			}
		cout << bfs(map) << endl;
	}
	return 0;
}
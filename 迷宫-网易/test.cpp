// ��һ���Թ����㲻֪�����������ֻ������̽��
// ��0, 1, 2, 3�ֱ�����ϣ��£����ҡ�ÿ����̽��
// ��������ߣ�����1�������ߵ���̽��λ�ã�
// ����������ߣ�˵�����ϰ�������Ǳ߽磬����ԭ�ء�
// һ����̽��n�Σ�n <= 1000, 000����֤���һ����̽�ߵ����յ㣬����Ϊ1
// �����Լ��㵽�յ�����·�������Ƕ��٣�
// T�����룬T <= 100, ÿ�������һ��Ϊn��������̽�Ĵ�����n <= 1E6��ÿ�������㵽�յ�����ٲ�

// 3
// 10
// 0 1
// 0 - 1
// 1 1
// 1 1
// 1 - 1
// 0 1
// 2 1
// 2 - 1
// 3 1
// 3 1
//
// 2
// 3 1
// 3 1
// 8
// 0 1
// 0 1
// 3 1
// 3 1
// 1 1
// 1 1
// 2 1
// 0 1

// 1
// 2
// 2

#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e6 + 100;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,0 };
map<pair<int, int>, int> mp; //ÿ������ı��
vector<pair<int, int>> v;    //���-�����꣬ ������
map<pair<int, int>, int>no;  //����Щ�㲻���ߣ���ʵû���ֹ��ľͲ����ߣ�
int cnt = 0;
struct P
{
	pair<int, int> pos;
	int step;
	P() {}
	P(pair<int, int>p, int st)
	{
		pos = p;
		step = st;
	}
};

map<pair<int, int>, int> vis;
int bfs()
{
	if (cnt - 1 == 0)
		return 0;
	vis.clear();
	queue<P> Q;  // first:id, second step
	pair<int, int> st(0,0);
	pair<int, int>ed = v[cnt - 1];

	Q.push(P(st,0));
	vis[st] = 1;
	while (!Q.empty())
	{
		pair<int, int> now = Q.front().pos;
		int step = Q.front().step;
		Q.pop();
		int x = now.first, y = now.second;
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			pair<int, int> to(xx, yy);
			if (no.find(to) != no.end() || mp.find(to) == mp.end())
				continue;
			if (to == ed)
				return step + 1;
			if (vis.find(to) != vis.end())
				continue;
			vis[to] = 1;
			Q.push(P(to,step+1));
		}
	}
	return -1;
}


int main(void)
{
	freopen("inC.txt", "r", stdin);
	int T, n;
	scanf("%d", &T);
	while (T--) {
		v.clear();
		mp.clear();
		no.clear();
		scanf("%d", &n);
		cnt = 0;
		int x = 0, y = 0;
		pair<int, int> pr(0, 0);
		v.push_back(pr);
		mp[pr] = cnt++;
		int op, res;
		while (n--) {
			scanf("%d%d", &op, &res);
			if (res == -1) {
				no[make_pair(x + dx[op], y + dy[op])] = 1;
				continue;
			}
			int xx = x + dx[op];
			int yy = y + dy[op];
			pr.first = xx; pr.second = yy;
			auto it = mp.find(pr);
			if (it == mp.end()) {
				v.push_back(pr);
				mp[pr] = cnt++;
			}
			x = xx; y = yy;
		}
		printf("%d\n", bfs());
	}
	return 0;
}

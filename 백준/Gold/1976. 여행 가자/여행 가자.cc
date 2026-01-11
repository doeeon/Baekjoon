#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int Find(int x, vector<int>& parent)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x], parent);
}

bool Unite(int x, int y, vector<int>& parent, vector<int>& sz)
{
	x = Find(x, parent);
	y = Find(y, parent);

	if (x == y) return false;
	if (sz[x] < sz[y]) swap(x, y);
	parent[y] = x;
	sz[x] += sz[y];
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> parent(N + 1);
	vector<int> sz(N + 1, 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	vector<vector<int>> graph(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j])
				Unite(i, j, parent, sz);
		}
	
	int route;
	int p;
	for (int i = 0; i < M; i++)
	{
		cin >> route;
		if (i == 0)
			p = Find(route, parent);

		if (p != Find(route, parent))
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}
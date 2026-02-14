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

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N >> M;

		vector<pair<int, int>> edge(M);
		for (int i = 0; i < M; i++)
			cin >> edge[i].first >> edge[i].second;

		vector<int> parent(N + 1);
		vector<int> sz(N + 1, 1);
		for (int i = 1; i <= N; i++)
			parent[i] = i;

		int answer = 0;
		for (auto e : edge)
			if (Unite(e.first, e.second, parent, sz))
				answer++;

		cout << answer << '\n';
	}
	return 0;
}
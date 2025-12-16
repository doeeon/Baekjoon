#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Edge
{
	int u;
	int v;
	int w;
};

bool cmp(Edge& a, Edge& b)
{
	return a.w < b.w;
}

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Edge> edges(M + 1); // {u, v, w}
	for (int i = 0; i < M; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	
	sort(edges.begin(), edges.end(), cmp);

	vector<int> parent(N + 1, 0);
	vector<int> sz(N + 1, 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int cnt = 0;
	int answer = 0;
	for (auto& e : edges)
	{
		if (cnt == N - 2)
			break;

		if (Unite(e.u, e.v, parent, sz))
		{
			answer += e.w;
			cnt++;
		}
	}
	
	cout << answer;

	return 0;
}
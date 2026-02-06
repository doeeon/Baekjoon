#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

struct EDGE {
	int u;
	int v;
	int w;

	bool operator <(const EDGE& other) const {
		if (w != other.w)
			return w < other.w;
		if (u != other.u)
			return u < other.u;
		return v < other.v;
	}
};

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

int Kruskal(int V, int E, vector<EDGE>& edges)
{
	vector<int> parent(V + 1);
	vector<int> sz(V + 1, 1);
	for (int i = 1; i <= V; i++)
		parent[i] = i;

	int cnt = 0;
	int sum = 0;
	for (auto e : edges)
	{
		if (Unite(e.u, e.v, parent, sz))
		{
			cnt++;
			sum += e.w;
		}

		if (cnt == V - 1)
			break;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<EDGE> edges(E);
	for (int i = 0; i < E; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	
	sort(edges.begin(), edges.end());

	cout << Kruskal(V, E, edges);

	return 0;
}
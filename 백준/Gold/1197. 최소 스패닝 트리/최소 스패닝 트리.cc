#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	return a[2] < b[2];
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
	
	if (sz[x] < sz[y])
		swap(x, y);
	
	parent[y] = x;
	sz[x] += sz[y];
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<vector<int>> edges(E, { 0, 0, 0 }); //{u, v, w}
	
	for (int i = 0; i < E; i++)
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	
	vector<int> parent(V + 1);
	vector<int> sz(V + 1, 1);
	for (int v = 1; v <= V; v++)
		parent[v] = v;

	sort(edges.begin(), edges.end(), cmp);

	int answer = 0;
	int cnt = 0;
	for (auto e : edges)
	{
		if (Unite(e[0], e[1], parent, sz))
		{
			answer += e[2];
			cnt++;
		}

		if (cnt == V - 1)
			break;
	}

	cout << answer;

	return 0;
}
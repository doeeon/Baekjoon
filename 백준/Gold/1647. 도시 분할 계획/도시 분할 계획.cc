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

	vector<vector<int>> edges(M + 1, { 0, 0, 0 }); // {u, v, w}
	for (int i = 0; i < M; i++)
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	
	sort(edges.begin(), edges.end(), cmp);

	vector<int> parent(N + 1, 0);
	vector<int> sz(N + 1, 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int cnt = 0;
	int answer = 0;
	for (vector<int> e : edges)
	{
		if (Unite(e[0], e[1], parent, sz))
		{
			answer += e[2];
			cnt++;
		}

		if (cnt == N - 2)
			break;
	}
	
	cout << answer;

	return 0;
}
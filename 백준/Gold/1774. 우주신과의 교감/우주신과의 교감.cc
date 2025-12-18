#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v;
	double w;

	bool operator < (const Edge& other) const {
		return w < other.w;
	}
};

double GetDistance(pair<int, int>& a, pair<int, int>& b)
{
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	double result = dx * dx + dy * dy;
	return sqrt(result);
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

	if (x == y)	 return false;

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

	vector<pair<int, int>> star(N+1, { 0, 0 });
	for (int i = 1; i <= N; i++)
		cin >> star[i].first >> star[i].second;

	vector<Edge> edges;
	for (int i = 1; i <= N - 1; i++)
		for (int j = i + 1; j <= N; j++)
			edges.push_back({ i, j, GetDistance(star[i], star[j])});

	vector<int> parent(N + 1);
	vector<int> sz(N + 1, 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	
	double answer = 0;
	int cnt = 0;
	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		if (Unite(u, v, parent, sz))
			cnt++;
	}

	sort(edges.begin(), edges.end());
	for (auto const& e : edges)
	{
		if (cnt >= N - 1)
			break;

		if (Unite(e.u, e.v, parent, sz))
		{
			answer += e.w;
			cnt++;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << answer;
	return 0;
}
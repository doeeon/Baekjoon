// 4386번 별자리 만들기
// 기본적인 MST 구하기 - Kruskal 알고리즘
// 입력 : 별의 좌표 -> 거리를 따로 구해야 한다.
// 간선 : n(n-1)/2 개 만들어진다.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
	int u, v;
	double w;

	bool operator <(const Edge& other) const {
		return w < other.w;
	}
};

double GetDistance(int a, int b, vector<pair<double, double>>& stars)
{
	double result = 0;
	result = (stars[a].first - stars[b].first) * (stars[a].first - stars[b].first) + (stars[a].second - stars[b].second) * (stars[a].second - stars[b].second);
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

	int N;
	cin >> N;

	vector<pair<double, double>> stars(N, { 0, 0 }); //{x, y}
	for (int i = 0; i < N; i++)
		cin >> stars[i].first >> stars[i].second;

	vector<Edge> edges;
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			edges.push_back({ i, j, GetDistance(i, j, stars) });

	sort(edges.begin(), edges.end());

	vector<int> parent(N);
	vector<int> sz(N, 1);
	for (int i = 0; i < N; i++)
		parent[i] = i;

	double answer = 0;
	int cnt = 0;
	for (const auto& e : edges)
	{
		if (cnt == N - 1)
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
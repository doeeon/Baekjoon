#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct EDGE {
	int x;
	int y;
	int w;

	bool operator <(const EDGE& other) const {
		if (w != other.w)
			return w < other.w;
		if (x != other.x)
			return x < other.x;
		return y < other.y;
	}
};

int Find(int a, vector<int>& parent)
{
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a], parent);
}

bool Unite(int a, int b, vector<int>& parent, vector<int>& sz)
{
	a = Find(a, parent);
	b = Find(b, parent);

	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int N, M;
		cin >> M >> N;
		if (N == 0 && M == 0) break;

		int answer = 0;
		vector<EDGE> edges(N);
		for (int i = 0; i < N; i++)
		{
			cin >> edges[i].x >> edges[i].y >> edges[i].w;
			answer += edges[i].w;
		}

		sort(edges.begin(), edges.end());

		vector<int> parent(M);
		vector<int> sz(M, 1);
		for (int i = 0; i < M; i++)
			parent[i] = i;

		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (Unite(edges[i].x, edges[i].y, parent, sz))
			{
				sum += edges[i].w;
				cnt++;
			}

			if (cnt == M - 1)
				break;
		}

		cout << answer - sum << '\n';
	}
	return 0;
}
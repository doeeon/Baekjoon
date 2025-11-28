#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;

	for (int t = 0; t < TC; t++)
	{
		int N, M, W;
		cin >> N >> M >> W;

		vector<vector<int>> edges; // start, end, cost

		int u, v, w;
		for (int i = 0; i < M; i++)
		{
			cin >> u >> v >> w;
			edges.push_back({ u, v, w });
			edges.push_back({ v, u, w });
		}

		for (int i = 0; i < W; i++)
		{
			cin >> u >> v >> w;
			edges.push_back({ u, v, -w });
		}

		// 모든 노드를 시작점으로 가정 (음수 사이클 존재만 확인하면 되므로)
		vector<int> dist(N + 1, 0);
		for (int i = 1; i <= N - 1; i++)
			for (auto e : edges)
				if (dist[e[1]] > dist[e[0]] + e[2])
					dist[e[1]] = dist[e[0]] + e[2];

		bool HasNegativeCycle = false;
		for (auto e : edges)
			if (dist[e[1]] > dist[e[0]] + e[2])
			{
				HasNegativeCycle = true;
				break;
			}

		if (HasNegativeCycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
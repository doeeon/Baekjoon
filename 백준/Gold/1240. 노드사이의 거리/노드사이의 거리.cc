#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int start, int finish, int N, vector<vector<pair<int, int>>>& graph)
{
	queue<pair<int, int>> q;
	vector<bool> visited(N + 1, false);

	q.push({start, 0}); // {node, dist}
	visited[start] = true;

	while (!q.empty())
	{
		int curr = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (curr == finish)
			return dist;

		for (auto e : graph[curr])
		{
			if (!visited[e.first])
			{
				visited[e.first] = true;
				q.push({e.first, dist+e.second});
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N + 1);
	int u, v, w;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		cout << BFS(u, v, N, graph) << '\n';
	}
	return 0;
}
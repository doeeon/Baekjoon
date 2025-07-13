#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 2000000

using namespace std;

void Dijkstra(int start, int N, vector<vector<pair<int, int>>>& graph, vector<int>& dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start }); //cost, node
	dist[start] = 0;

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		if (cost > dist[curr])
			continue;

		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i].first;

			if (dist[next] > dist[curr] + graph[curr][i].second)
			{
				dist[next] = dist[curr] + graph[curr][i].second;
				pq.push({ dist[next], next });
			}
		}
	}

	return;
}

int main()
{
	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> graph(N + 1);
	vector<vector<pair<int, int>>> r_graph(N + 1); // 역방향 그래프

	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		r_graph[v].push_back({ u, w });
	}

	vector<int> dist(N + 1, INF); // X -> A
	vector<int> r_dist(N + 1, INF); // A -> X
	Dijkstra(X, N, graph, dist);
	Dijkstra(X, N, r_graph, r_dist);

	vector<int> answer(N + 1);
	for (int i = 1; i <= N; i++)
		answer[i] = r_dist[i] + dist[i];

	cout << *max_element(answer.begin(), answer.end());
	return 0;
}
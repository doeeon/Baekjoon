#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

int Dijkstra(int start, int end, int N, vector<vector<pair<int, int>>>& graph, vector<int>& dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push({ 0, start }); // cost, node
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

	return dist[end];
}
int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N + 1);
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	int start, end;
	cin >> start >> end;
	
	vector<int> dist(N + 1, INF);
	cout << Dijkstra(start, end, N, graph, dist);

	return 0;
}
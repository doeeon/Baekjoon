#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100000000

using namespace std;

void Dijkstra(int start, int end, int N, vector<vector<pair<int, int>>>& graph, vector<int>& dist, vector<int>& route)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> prev(N + 1, -1);
	pq.push({ 0, start }); // cost, node
	dist[start] = 0;
	prev[start] = 0;

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
				prev[next] = curr;
				pq.push({ dist[next], next });
			}
		}
	}

	route.push_back(end);
	int n = end;
	while (prev[n] > 0)
	{
		route.push_back(prev[n]);
		n = prev[n];
	}

	return;
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
	vector<int> route;
	Dijkstra(start, end, N, graph, dist, route);

	cout << dist[end] << '\n' << route.size() << '\n';
	for (int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << ' ';
	return 0;
}
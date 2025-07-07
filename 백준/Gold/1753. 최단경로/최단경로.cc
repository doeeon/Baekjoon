#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& dis)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push({ 0, start }); // 

	dis[start] = 0;

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (cost > dis[curr])
			continue;

		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i].first;
			int n_cost = graph[curr][i].second;
			if (dis[next] > dis[curr] + graph[curr][i].second)
			{
				dis[next] = dis[curr] + graph[curr][i].second;
				pq.push({ dis[next], next });
			}
		}
	}
}
int main() {
	int V, E, K;
	cin >> V >> E >> K;
	
	vector<vector<pair<int, int>>> graph(V+1);
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	vector<int> dis(V + 1, 2000000);
	//dis[i] == 시작 지점에서 i번째 지점까지의 최단 경로값
	Dijkstra(K, graph, dis);

	for (int i = 1; i <= V; i++) {
		if (dis[i] == 2000000)
			cout << "INF\n";
		else
			cout << dis[i] << '\n';
	}
	return 0;
}
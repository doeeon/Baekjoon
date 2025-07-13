#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000

using namespace std;

void Dijkstra(int start, int N, vector<vector<pair<int, int>>>& graph, vector<int>& dist)
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

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, E;
	cin >> N >> E;

	vector<vector<pair<int, int>>> graph(N + 1);
	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c; // 양방향 route
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> dist_start(N + 1, INF);
	vector<int> dist_v1(N + 1, INF);
	vector<int> dist_v2(N + 1, INF);

	Dijkstra(1, N, graph, dist_start);
	Dijkstra(v1, N, graph, dist_v1);
	Dijkstra(v2, N, graph, dist_v2);

	int result1 = dist_start[v1] + dist_v1[v2] + dist_v2[N];
	int result2 = dist_start[v2] + dist_v2[v1] + dist_v1[N];

	int answer = result1 < result2 ? result1 : result2;

	if (answer >= INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}
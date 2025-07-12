#include <iostream>
#include <vector>
#include <queue>

#define INF 300000

using namespace std;

void Dijkstra(int X, int K, vector<vector<int>>& graph, vector<int>& dist, vector<int>& answer)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, X }); //cost, node
	dist[X] = 0;

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cost > dist[curr])
			continue;

		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i];
			if (dist[next] > dist[curr] + 1)
			{
				dist[next] = dist[curr] + 1;
				pq.push({ dist[next], next });
			}
		}
	}

	for (int i = 1; i < dist.size(); i++)
		if (dist[i] == K)
			answer.push_back(i);

	return;
}

int main()
{
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	
	int u, v;
	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
	}


	vector<int> dist(N + 1, INF);
	vector<int> answer;
	Dijkstra(X, K, graph, dist, answer);
	if (answer.size() == 0)
		cout << -1;
	else
		for (int i = 0; i<answer.size(); i++)
			cout << answer[i] << '\n';

	return 0;
}
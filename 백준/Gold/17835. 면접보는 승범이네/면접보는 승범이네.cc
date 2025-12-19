#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e11;

vector<long long> Dijkstra(int N, int K, vector<vector<pair<int, int>>>& edge, vector<int>& interview)
{
	vector<long long> dist(N + 1, INF);

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // {cost, node} min-heap
	for (int i = 0; i < interview.size(); i++)
	{
		pq.push({ 0, interview[i] });
		dist[interview[i]] = 0;
	}

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[curr] < cost)
			continue;

		for (int i = 0; i < edge[curr].size(); i++)
		{
			int next = edge[curr][i].first;
			int ncost = edge[curr][i].second;

			if (dist[next] > dist[curr] + ncost)
			{
				dist[next] = dist[curr] + ncost;
				pq.push({ dist[next], next });
			}
		}
	}

	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<pair<int, int>>> edge(N + 1);
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		edge[v].push_back({ u, w }); // {node, cost}
		// 역방향으로 저장 (면접장 -> 도시로 다익스트라 진행 예정)
	}

	vector<int> interview(K);
	for (int i = 0; i < K; i++)
		cin >> interview[i];
	
	vector<long long> dist = Dijkstra(N, K, edge, interview);
	auto iter = max_element(dist.begin() + 1, dist.end());

	cout << iter - dist.begin() << '\n' << *iter;
	return 0;
}
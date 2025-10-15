#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INF 200000000

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& dist, int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int current = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (dist[current] < cost)
			continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			if (dist[graph[current][i].first] > dist[current] + graph[current][i].second)
			{
				dist[graph[current][i].first] = dist[current] + graph[current][i].second;
				pq.push({ dist[graph[current][i].first], graph[current][i].first });
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n, d, c;
		cin >> n >> d >> c;

		vector<vector<pair<int, int>>> graph(n + 1);
		vector<int> dist(n + 1, INF);
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;

			graph[b].push_back({ a, s }); //node, cost
		}

		Dijkstra(graph, dist, c);

		int cnt = 0;
		int time = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] != INF)
			{
				cnt++;
				time = max(time, dist[i]);
			}
		}

		cout << cnt << ' ' << time << '\n';
	}

	return 0;
}
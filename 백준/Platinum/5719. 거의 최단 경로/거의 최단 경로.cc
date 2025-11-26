#include <iostream>
#include <vector>
#include <queue>

#define INF 200000000

using namespace std;

void Dijkstra(int S, int N, vector<vector<pair<int, int>>>& route, vector<int>& dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, S }); // {cost, node}
	dist[S] = 0;

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (cost > dist[curr])
			continue;

		for (int i = 0; i < route[curr].size(); i++)
		{
			int next = route[curr][i].first;
			int ncost = route[curr][i].second;

			if (dist[next] > dist[curr] + ncost)
			{
				dist[next] = dist[curr] + ncost;
				pq.push({ dist[next], next });
			}
		}
	}
}

void RemoveRoute(int S, int D, vector<vector<pair<int ,int>>>& route, vector<vector<pair<int, int>>>& reverse_route, vector<int>& dist)
{
	queue<int> q;
	q.push(D);

	while (!q.empty())
	{
		int curr = q.front();

		q.pop();

		for (int i = 0; i < reverse_route[curr].size(); i++)
		{
			int prev = reverse_route[curr][i].first;
			int pcost = reverse_route[curr][i].second;
			if (dist[prev] + pcost == dist[curr])
			{
				reverse_route[curr][i].second = INF;
				for (int j = 0; j < route[prev].size(); j++)
					if (route[prev][j].first == curr)
						route[prev][j].second = INF;

				q.push(prev);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		int S, D;
		cin >> S >> D;

		vector<vector<pair<int, int>>> route(N);
		vector<vector<pair<int, int>>> reverse_route(N);
		int u, v, w;
		for (int i = 0; i < M; i++)
		{
			cin >> u >> v >> w;
			route[u].push_back({ v, w }); // {node, cost}
			reverse_route[v].push_back({ u, w });
		}

		vector<int> dist(N, INF);
		vector<vector<int>> parent(N);

		Dijkstra(S, N, route, dist);
		RemoveRoute(S, D, route, reverse_route, dist);
	
		vector<int> almostdist(N, INF);
		Dijkstra(S, N, route, almostdist);

		if (almostdist[D] == INF)
			cout << -1 << endl;
		else
			cout << almostdist[D] << endl;
	}

	return 0;
}
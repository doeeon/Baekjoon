#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define INF 200000000

using namespace std;


void Dijkstra(int start, vector<vector<pair<int, int>>>& route, vector<int>& dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push({ 0, start });
	dist[start] = 0;

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
				pq.push({ dist[next], next});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n, m, d;
		cin >> n >> m >> d;

		int s, g, h;
		cin >> s >> g >> h;

		int g_to_h = 0;

		vector<vector<pair<int, int>>> route(n + 1);
		int a, b, c;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			route[a].push_back({ b, c });
			route[b].push_back({ a, c });
			if ((a == g && b == h) || (a == h && b == g))
				g_to_h = c;
		}

		vector<int> candi_end;
		int e;
		for (int i = 0; i < d; i++)
		{
			cin >> e;
			candi_end.push_back(e);
		}

		vector<int> s_dist(n + 1, INF);
		vector<int> g_dist(n + 1, INF);
		vector<int> h_dist(n + 1, INF);

		Dijkstra(s, route, s_dist);
		Dijkstra(g, route, g_dist);
		Dijkstra(h, route, h_dist);

		vector<int> answer;

		for (int i = 0; i < candi_end.size(); i++)
		{
			int s_to_t = s_dist[candi_end[i]];

			int route_a = s_dist[g] + g_to_h + h_dist[candi_end[i]];
			int route_b = s_dist[h] + g_to_h + g_dist[candi_end[i]];

			if (s_to_t == min(route_a, route_b))
				answer.push_back(candi_end[i]);
		}

		sort(answer.begin(), answer.end());

		for (auto a : answer)
			cout << a << ' ';
		cout << endl;
	}

	return 0;
}
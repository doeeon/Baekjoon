#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INF 1000000

using namespace std;

int Dijkstra(int N, vector<vector<int>>& map)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	vector<vector<int>> dist(N, vector<int>(N, INF));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	
	pq.push({ map[0][0], {0, 0}}); // cost, node(y, x)
	dist[0][0] = map[0][0];
	
	while (!pq.empty())
	{
		int cx = pq.top().second.second;
		int cy = pq.top().second.first;
		int cost = pq.top().first;

		pq.pop();

		if (cost > dist[cy][cx])
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[ny][nx] > dist[cy][cx] + map[ny][nx])
			{
				dist[ny][nx] = dist[cy][cx] + map[ny][nx];
				pq.push({ dist[ny][nx], {ny, nx} });
			}
		}

	}

	return dist[N - 1][N - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	while (1)
	{
		int N;
		cin >> N;

		if (N == 0)
			break;

		vector<vector<int>> map(N, vector<int>(N, 0));
		int a;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> a;
				map[i][j] = a;
			}

		int answer = Dijkstra(N, map);
		cout << "Problem " << t << ": " << answer << '\n';
		t++;
	}

	return 0;
}
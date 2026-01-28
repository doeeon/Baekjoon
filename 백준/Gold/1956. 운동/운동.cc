#include <iostream>
#include <vector>

#define INF 1e9
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));
	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
		{
			if (dist[i][k] == INF) continue;
			for (int j = 1; j <= V; j++)
			{
				if (dist[k][j] == INF) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}

	int answer = INF;
	for (int i = 1; i <= V; i++)
		answer = min(answer, dist[i][i]);
	
	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}
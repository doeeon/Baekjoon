#include <iostream>
#include <vector>
#include <cmath>

#define INF 300000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N;

	vector<pair<int, int>> lines;
	lines.push_back({ 0, 0 });
	int l, r;
	for (int i = 0; i < N; i++)
	{
		cin >> l >> r;
		lines.push_back({ l, r });
	}

	vector<vector<int>> dis(N + 1, vector<int>(N+1, INF));
	for (int i = 1; i <= N; i++)
		dis[i][i] = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			//if (i == j) continue;
			if ((lines[j].first >= lines[i].first && lines[j].first <= lines[i].second) ||
				(lines[j].second >= lines[i].first && lines[j].second <= lines[i].second) || 
				(lines[j].first < lines[i].first && lines[j].second >lines[i].second))
			{
				dis[i][j] = 1;
				dis[j][i] = 1; //무방향 그래프
			}
		}
	}

	//Floyd-Warshall
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (dis[i][k] == INF) continue;
			for (int j = 1; j <= N; j++)
			{
				if (dis[k][j] == INF) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	cin >> Q;
	int a, b;
	for (int i = 0; i < Q;i++)
	{
		cin >> a >> b;
		if (dis[a][b] == INF)
			cout << -1 << '\n';
		else
			cout << dis[a][b] << '\n';
	}

	return 0;
}
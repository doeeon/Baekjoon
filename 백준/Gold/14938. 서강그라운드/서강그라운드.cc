#include <iostream>
#include <vector>
#include <cmath>

#define INF 2000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	vector<vector<int>> dis(n+1, vector<int>(n+1, INF));
	vector<int> item(n+1, 0);
	int t;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		item[i] = t;
		dis[i][i] = 0;
	}

	int a, b, l;
	for (int i = 0; i < r; i++)
	{
		cin >> a >> b >> l;
		dis[a][b] = l;
		dis[b][a] = l;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (dis[i][k] == INF) continue;
			for (int j = 1; j <= n; j++)
			{
				if (dis[k][j] == INF) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (dis[i][j] <= m)
				cnt += item[j];

		answer = max(answer, cnt);
	}

	cout << answer;
	return 0;
}
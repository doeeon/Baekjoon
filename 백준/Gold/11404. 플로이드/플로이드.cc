#include <iostream>
#include <vector>

#define INF 200000000
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N+1, vector<int>(N+1, INF));
	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;


	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
		{
			if (graph[i][k] == INF)
				continue;
			for (int j = 1; j <= N; j++)
			{
				if (graph[k][j] == INF) 
					continue;
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}
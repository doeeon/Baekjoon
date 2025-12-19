#include <iostream>
#include <vector>
#include <deque>
#include <string>

#define INF 2000000

using namespace std;

int BFS(int N, int M, vector<vector<int>>& map)
{
	int dy[4] = { 0, 0, 1, -1 };
	int dx[4] = { 1, -1, 0, 0 };
	vector<vector<int>> dist(N, vector<int>(M, INF));

	deque<pair<int, int>> dq;
	dq.push_front({ 0, 0 });
	dist[0][0] = 0;

	while (!dq.empty())
	{
		int cy = dq.front().first;
		int cx = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				if (dist[ny][nx] > dist[cy][cx] + map[ny][nx])
				{
					dist[ny][nx] = dist[cy][cx] + map[ny][nx];
					if (map[ny][nx])
						dq.push_back({ ny, nx });
					else
						dq.push_front({ ny, nx });
				}
		}
	}

	return dist[N - 1][M - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> M >> N;

	vector<vector<int>> map(N, vector<int>(M, 0));
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			if (str[j] == '1')
				map[i][j] = 1;
	}


	cout << BFS(N, M, map);

	return 0;
}
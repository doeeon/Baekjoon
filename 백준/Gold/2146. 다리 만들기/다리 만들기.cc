#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INF 10001

using namespace std;

void BFS_Indexing(int y, int x, int num, int N, vector<vector<int>>& map, vector<vector<bool>>& visited)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;
	map[y][x] = num;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				map[ny][nx] = num;
				q.push({ ny, nx });
			}
		}
	}

	return;
}


int BFS_Expansion(int N, vector<vector<int>>& map)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	vector<vector<int>> dist(N, vector<int>(N, -1));
	queue<pair<int, int>> q;
	int result = INF;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] != 0)
			{
				q.push({ i, j });
				dist[i][j] = 0;
			}

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int n = 0; n < 4; n++)
			{
				int ny = cy + dy[n];
				int nx = cx + dx[n];

				if (ny >= 0 && ny < N && nx >= 0 && nx < N)
				{
					if (map[ny][nx] == 0 && dist[ny][nx] == -1)
					{
						q.push({ ny, nx });
						map[ny][nx] = map[cy][cx];
						dist[ny][nx] = dist[cy][cx] + 1;
					}
					else if (map[ny][nx] != map[cy][cx])
						result = min(result, dist[cy][cx] + dist[ny][nx]);
				}
			}
		}

		if (result != INF)
			return result;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];


	int island_cnt = 0;
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] && !visited[i][j])
			{
				island_cnt++;
				BFS_Indexing(i, j, island_cnt, N, map, visited);
			}

	cout << BFS_Expansion(N, map);

	return 0;
}
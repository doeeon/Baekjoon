#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

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

void Print(vector<vector<int>>& map)
{
	cout << endl;
	for (auto a : map)
	{
		for (auto b : a)
			cout << b << ' ';
		cout << endl;
	}
}

int BFS_Expansion(int idx, int N, vector<vector<int>>& map, vector<vector<bool>> visited)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	queue<pair<int, int>> q;

	int dist = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == idx)
				for (int n = 0; n < 4; n++)
				{
					int ny = i + dy[n];
					int nx = j + dx[n];

					if (ny >= 0 && ny < N && nx >= 0 && nx < N && !map[ny][nx] && !visited[ny][nx])
					{
						q.push({ ny, nx });
						visited[ny][nx] = true;
					}
				}
	dist++;

	while (!q.empty())
	{
		int size = q.size();
		for (int s = 0; s < size; s++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int n = 0; n < 4; n++)
			{
				int ny = cy + dy[n];
				int nx = cx + dx[n];

				if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx])
				{
					if (map[ny][nx] == 0)
					{
						q.push({ ny, nx });
						visited[ny][nx] = true;
					}
					else if (map[ny][nx] != idx)
					{
						return dist;
					}
				}
			}
		}

		dist++;
	}

	return dist;
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

	visited.assign(N, vector<bool>(N, false));
	int min_distance = 10001;
	for (int i = 1; i <= island_cnt; i++)
		min_distance = min(min_distance, BFS_Expansion(i, N, map, visited));

	cout << min_distance;

	return 0;
}
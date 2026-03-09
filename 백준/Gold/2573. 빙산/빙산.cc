#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void Melting(int N, int M, vector<vector<int>>& map)
{
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	vector<vector<int>> cp_map(map);

	for (int i = 1; i < N-1; i++)
		for (int j = 1; j < M-1; j++)
			if (cp_map[i][j])
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < N && nx >= 0 && nx < M && !cp_map[ny][nx])
						cnt++;
				}

				map[i][j] = max(map[i][j] - cnt, 0);
			}
}

int BFS(int y, int x, int N, int M, vector<vector<int>>& map, vector<vector<bool>>& visited)
{
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && map[ny][nx])
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int answer = 0;
	while (1)
	{
		answer++;
		Melting(N, M, map);

		int cnt = 0;
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		for (int i = 1; i < N; i++)
			for (int j = 1; j < M; j++)
				if (map[i][j] && !visited[i][j])
					cnt += BFS(i, j, N, M, map, visited);

		if (cnt > 1)
			break;
		else if (cnt == 0)
		{
			answer = 0;
			break;
		}
	}

	cout << answer;

	return 0;
}
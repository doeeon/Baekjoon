#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int y, int x, vector<vector<int>>& map, vector<vector<bool>>& visited)
{
	int cnt = 0;
	int n = map.size();
	int m = map[0].size();
	int dx[4] = { 1, -1, 0 ,0 };
	int dy[4] = { 0, 0, 1, -1 };
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && map[ny][nx])
			{
				visited[ny][nx] = true;
				q.push({ nx, ny });
			}
		}

		q.pop();
	}

	return 1;
}

int main() {
	int T;
	int m, k, n;
	cin >> T;
	
	for (int t = 0; t < T; t++)
	{
		cin >> m >> n >> k;
		vector<vector<int>> map(n, vector<int>(m, 0));
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		int x, y;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			map[y][x] = 1;
		}

		int answer = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] && !visited[i][j])
					answer += BFS(i, j, map, visited);

		cout << answer << '\n';
	}
	return 0;
}
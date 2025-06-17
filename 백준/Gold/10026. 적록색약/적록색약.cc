#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void BFS(int x, int y, int N, vector<vector<char>>& map, vector<vector<bool>>& visited) {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	char color;
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[y][x] = true;
	color = map[y][x];

	while (!q.empty())
	{
		if (map[q.front().second][q.front().first] == 'G')
			map[q.front().second][q.front().first] = 'R';
		for (int i = 0; i < 4; i++)
		{
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx] && map[ny][nx] == color)
			{
				q.push({ nx, ny });
				visited[ny][nx] = true;
			}
		}
		q.pop();
	}

	return;
}

int main() {
	int N;
	cin >> N;

	vector<vector<char>> map(N, vector<char>(N, 0));
	char c;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			map[i][j] = c;
		}

	int normal_ans = 0;
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j])
			{
				BFS(j, i, N, map, visited);
				normal_ans++;
			}

	int color_blindness_ans = 0;
	vector<vector<bool>> visited2(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited2[i][j])
			{
				BFS(j, i, N, map, visited2);
				color_blindness_ans++;
			}

	cout << normal_ans << ' ' << color_blindness_ans;
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int x, int y, int N, int M, vector<vector<int>>& map, vector<vector<bool>>& visited, vector<vector<int>>& answer)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int dis = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty())
	{
		dis++;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int nx = q.front().first + dx[j];
				int ny = q.front().second + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && map[ny][nx] == 1)
				{
					q.push({ nx, ny });
					visited[ny][nx] = true;
					answer[ny][nx] = dis;
				}
			}
			q.pop();
		}
	}
	return;
}

int main() {
	int N, M;
	cin >> N >> M;

	int n;
	vector<vector<int>> answer(N, vector<int>(M, 0));
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	int x, y;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> n;
			map[i][j] = n;
			if (n == 2)
			{
				x = j;
				y = i;
			}
			else if (n == 0)
				visited[i][j] = true;
		}

	BFS(x, y, N, M, map, visited, answer);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j])
				answer[i][j] = -1;
		}

	for (auto a : answer)
	{
		for (auto b : a)
			cout << b << ' ';

		cout << endl;
	}

	return 0;
}
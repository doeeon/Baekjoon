#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool IsInside(int y, int x, int N, int M)
{
	return (y >= 0 && y < N && x >= 0 && x < M);
}

void BFS(int y, int x, int cnt, vector<string>& map, vector<vector<int>>& idx, vector<vector<bool>>& visited)
{
	int N = map.size();
	int M = map[0].size();

	int dy[4] = { -1, 1, 0, 0 }; // U, D, L, R
	int dx[4] = { 0, 0, -1, 1 }; // U, D, L, R
	char rev[4] = { 'D', 'U', 'R', 'L' };

	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;
	idx[y][x] = cnt;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		idx[cy][cx] = cnt;
		q.pop();

		if (map[cy][cx] == 'U' && !visited[cy - 1][cx])
		{
			q.push({ cy - 1, cx });
			visited[cy - 1][cx] = true;
		}
		else if (map[cy][cx] == 'D' && !visited[cy+1][cx])
		{
			q.push({ cy + 1, cx });
			visited[cy + 1][cx] = true;
		}
		else if (map[cy][cx] == 'L' && !visited[cy][cx - 1])
		{
			q.push({ cy, cx - 1 });
			visited[cy][cx - 1] = true;
		}
		else if (map[cy][cx] == 'R' && !visited[cy][cx + 1])
		{
			q.push({ cy, cx + 1 });
			visited[cy][cx + 1] = true;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (IsInside(ny, nx, N, M) && map[ny][nx] == rev[i] && !visited[ny][nx])
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}	
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> map(N);
	for (int i = 0; i < N; i++)
		cin >> map[i];

	vector<vector<bool>> visited(N, vector<bool>(M, false));
	vector<vector<int>> idx(N, vector<int>(M, 0));
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visited[i][j])	
				BFS(i, j, ++cnt, map, idx, visited);

	cout << cnt;
	return 0;
}
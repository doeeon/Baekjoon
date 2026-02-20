#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int sy, int sx, int ey, int ex, int N)
{
	int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	queue<pair<int, int>> q;
	int cnt = 0;

	q.push({ sy, sx });
	visited[sy][sx] = true;

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			if (cy == ey && cx == ex)
				return cnt;

			for (int n = 0; n < 8; n++)
			{
				int ny = cy + dy[n];
				int nx = cx + dx[n];

				if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx])
				{
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}
		cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		int sy, sx, ey, ex;
		cin >> sy >> sx >> ey >> ex;

		cout << BFS(sy, sx, ey, ex, N) << '\n';

	}
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Status {
	int y;
	int x;
	int d;
};

bool IsPossible(int y, int x, int d, int N, vector<vector<int>>& map)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;

	if (map[y][x])
		return false;

	if (d == 2) {
		if (map[y - 1][x] || map[y][x - 1])
			return false;
	}

	return true;
}

int BFS(int N, vector<vector<int>>& map)
{
	int dy[3][3] = { {0, 1}, {1, 1}, {0, 1, 1} };
	int dx[3][3] = { {1, 1}, {0, 1}, {1, 0, 1} };
	int dir[3][3] = { {0, 2}, {1, 2}, {0 ,1 ,2} };
	int dsize[3] = { 2, 2, 3 };

	int cnt = 0;
	queue<Status> q;
	q.push({ 0, 1, 0 }); // {y, x, direction}


	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int cd = q.front().d;
		q.pop();

		if (cy == N - 1 && cx == N - 1)
		{
			cnt++;
			continue;
		}

		for (int n = 0; n < dsize[cd]; n++)
		{
			int ny = cy + dy[cd][n];
			int nx = cx + dx[cd][n];
			int nd = dir[cd][n];

			if (IsPossible(ny, nx, nd, N, map))
				q.push({ ny, nx, nd });
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	cout << BFS(N, map);

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coordinate {
	int y;
	int x;
	int c;
};

int BFS(vector<vector<int>>& map, int N, int M, int K)
{
	int dy[4] = { 0, 0, 1, -1 };
	int dx[4] = { 1, -1, 0, 0 };
	queue<coordinate> q;
	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K+1, false)));

	q.push({ 0, 0, 0 });
	visited[0][0][0] = true;
	int cnt = 0;

	while (!q.empty())
	{
		int size = q.size();
		cnt++;
		for (int i = 0; i < size; i++)
		{
			coordinate curr = q.front();
			q.pop();

			if (curr.y == N - 1 && curr.x == M - 1)
				return cnt;

			for (int n = 0; n < 4; n++)
			{
				int nx = curr.x + dx[n];
				int ny = curr.y + dy[n];

				if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				{
					if (map[ny][nx] == 0 && !visited[ny][nx][curr.c])
					{
						q.push({ ny, nx, curr.c });
						visited[ny][nx][curr.c] = true;
					}
					else if (map[ny][nx] == 1 && curr.c < K && !visited[ny][nx][curr.c + 1])
					{
						q.push({ ny, nx, curr.c + 1 });
						visited[ny][nx][curr.c + 1] = true;
					}
				}
			}
		}	
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> map(N, vector<int>(M, 0));
	char c;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			map[i][j] = c-'0';
		}

	cout << BFS(map, N, M, K);
	
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int BFS(vector<vector<int>>& map, int y, int x)
{
	int dx[4] = { 1, -1, 0 ,0 };
	int dy[4] = { 0, 0, 1, -1 };
	
	int N = map.size();
	int M = map[0].size();

	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
	queue<vector<int>> q;

	q.push({ 0, 0, 0 }); // y, x, 벽 부순 횟수
	visited[0][0][0] = true;


	int dist = 0;
	while (!q.empty())
	{
		int size = q.size();
		dist++;
		for (int i = 0; i < size; i++)
		{
			if (q.front()[0] == N - 1 && q.front()[1] == M - 1)
				return dist;
			
			for (int n = 0; n < 4; n++)
			{
				int ny = q.front()[0] + dy[n];
				int nx = q.front()[1] + dx[n];

				if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				{
					if (q.front()[2] == 1 && visited[ny][nx][1] == false && map[ny][nx] == 0)
					{
						q.push({ ny, nx, 1 });
						visited[ny][nx][1] = true;
					}
					else if (q.front()[2] == 0 && visited[ny][nx][0] == false)
					{
						if (map[ny][nx] == 0)
						{
							q.push({ ny, nx, 0 });
							visited[ny][nx][0] = true;
						}
						else
						{
							q.push({ ny, nx, 1 });
							visited[ny][nx][1] = true;
						}

					}
				}
			}

			q.pop();
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M, 0));
	char c;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			map[i][j] = c - '0';
		}
	
	cout << BFS(map, 0, 0);


	return 0;
}
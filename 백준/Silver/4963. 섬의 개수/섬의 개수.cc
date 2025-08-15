#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int y, int x, vector<vector<int>>& map, vector<vector<bool>>& visited)
{
	int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
	int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
	int h = map.size();
	int w = map[0].size();

	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < h && nx >= 0 && nx < w && map[ny][nx] && !visited[ny][nx])
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}

	return 1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> answer;
	while (1)
	{
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		vector<vector<int>> map(h, vector<int>(w, 0)); // 인접행렬
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		int n;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> n;
				map[i][j] = n;
			}
	
		int cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (map[i][j] && !visited[i][j])
					cnt += BFS(i, j, map, visited);

		answer.push_back(cnt);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}
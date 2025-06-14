#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int N, int M, vector<vector<int>>& map)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	int cnt = 0;
	queue<pair<int, int>> q;

	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty())
	{
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int nx = q.front().first + dx[j];
				int ny = q.front().second + dy[j];
				if (nx == M - 1 && ny == N - 1)
					return cnt + 1;
				
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 1 && !visited[ny][nx])
				{
					q.push({ nx, ny });
					visited[ny][nx] = true;
				}

			}
			q.pop();
		}
	}

	return cnt;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M, 0));
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			map[i][j] = str[j] - '0';
	}

	cout << BFS(N, M, map);
	return 0;
}
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int BFS(int x, int y, vector<vector<char>>& map, vector<vector<bool>>& visited)
{
	int cnt = 0;
	int dx[4] = { 1, -1, 0, 0 };
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

			if (ny >= 0 && ny < map.size() && nx >= 0 && nx < map[0].size() && !visited[ny][nx] && map[ny][nx] != 'X')
			{
				q.push({ nx, ny });
				visited[ny][nx] = true;
				if (map[ny][nx] == 'P')
					cnt++;
			}
		}
		q.pop();
	}

	return cnt;
}

int main() {
	int N, M;
	cin >> N >> M;


	int x, y;
	string str;
	vector<vector<char>> map(N, vector<char>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			map[i][j] = str[j];
			if (str[j] == 'I')
			{
				x = j;
				y = i;
			}
		}
	}

	int answer = BFS(x, y, map, visited);

	if (answer == 0)
		cout << "TT";
	else
		cout << answer;

	return 0;
}
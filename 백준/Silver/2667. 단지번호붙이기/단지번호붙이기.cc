#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int BFS(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited)
{
	queue<pair<int, int>> q;
	int cnt = 1;
	q.push({ x, y });
	visited[y][x] = true;

	int N = map.size();
	while (!q.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[ny][nx] != 0 && !visited[ny][nx])
			{
				q.push({ nx, ny });
				visited[ny][nx] = true;
				cnt++;
			}
		}
		q.pop();
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> answer;
	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N, 0));
	
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			map[i][j] = str[j]-'0';
	}

	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] != 0 && !visited[i][j])
				answer.push_back(BFS(j, i, map, visited));

	
	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}
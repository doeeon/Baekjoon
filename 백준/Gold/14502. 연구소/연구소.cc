#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> blank;
vector<pair<int, int>> source;
int answer = 0;

int BFS()
{
	int cnt = blank.size() - 3;
	int N = map.size();
	int M = map[0].size();
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };

	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<pair<int, int>> q;

	for (auto s : source)
	{
		q.push(s);
		visited[s.first][s.second] = true;
	}

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int n = 0; n < 4; n++)
		{
			int ny = cy + dy[n];
			int nx = cx + dx[n];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && map[ny][nx] == 0)
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
				cnt--;
			}
		}
	}

	return cnt;
}

void Backtracking(int idx, vector<int>& selected)
{
	if (selected.size() == 3)
	{
		for (int s : selected)
			map[blank[s].first][blank[s].second] = 1;

		answer = max(answer, BFS());

		for (int s : selected)
			map[blank[s].first][blank[s].second] = 0;

		return;
	}

	for (int i = idx; i < blank.size(); i++)
	{
		selected.push_back(i);
		Backtracking(i + 1, selected);
		selected.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	map.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				blank.push_back({ i, j });
			else if (map[i][j] == 2)
				source.push_back({ i, j });
		}

	vector<int> selected;
	Backtracking(0, selected);

	cout << answer;
	return 0;
}
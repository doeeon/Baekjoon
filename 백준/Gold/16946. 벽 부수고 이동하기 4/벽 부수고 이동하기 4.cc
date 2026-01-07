#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int BFS(int y, int x, int idx, vector<vector<int>>& map)
{
	int N = map.size();
	int M = map[0].size();
	int width = 0;
	queue<pair<int, int>> q;
	
	q.push({ y, x });
	map[y][x] = idx;
	
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		width++;

		for (int n = 0; n < 4; n++)
		{
			int ny = cy + dy[n];
			int nx = cx + dx[n];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 0)
			{
				q.push({ ny, nx });
				map[ny][nx] = idx;
			}
		}
	}

	return width;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M));

	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
			map[i][j] = input[j] - '0';
	}	
	
	vector<vector<int>> answer(map);
	vector<int> zero_area(2); //{0, 0, ...} [0], [1]은 사용X(map에서 이미 사용되는 index)
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0)
				zero_area.push_back(BFS(i, j, zero_area.size(), map));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1)
			{
				unordered_set<int> s;
				for (int n = 0; n < 4; n++)
				{
					int ny = i + dy[n];
					int nx = j + dx[n];

					if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] != 1)
						s.insert(map[ny][nx]);
				}

				for (auto idx : s)
					answer[i][j] += zero_area[idx];
			}

	for (auto a : answer)
	{
		for (auto b : a)
			cout << b%10;
		cout << '\n';
	}
	return 0;
}
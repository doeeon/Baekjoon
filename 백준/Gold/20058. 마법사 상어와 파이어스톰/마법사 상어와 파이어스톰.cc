#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void Rotate(vector<vector<int>>& map)
{
	// 시계방향 90도 회전
	int size = map.size();
	vector<vector<int>> result(size, vector<int>(size, 0));
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			result[i][j] = map[size - 1 - j][i];

	map = result;
}

void RotateMap(vector<vector<int>>& map, int L)
{
	if (L == 0)
		return;
	
	int map_size = map.size();
	int part_size = pow(2, L);

	for (int i = 0; i < map_size; i += part_size)
		for (int j = 0; j < map_size; j += part_size)
		{
			//부분 격자 추출
			vector<vector<int>> part(part_size, vector<int>(part_size, 0));
			for (int y = i; y < i + part_size; y++)
				for (int x = j; x < j + part_size; x++)
					part[y - i][x - j] = map[y][x];

			//시계방향 90도 회전
			Rotate(part);

			//map에 삽입
			for (int y = i; y < i + part_size; y++)
				for (int x = j; x < j + part_size; x++)
					map[y][x] = part[y - i][x - j];
		}
}

void CalculateIce(vector<vector<int>>& map)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int size = map.size();

	vector<vector<int>> result(size, vector<int>(size, 0));

	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
		{
			if (map[y][x] > 0)
			{
				int cntAdj = 0;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx >= 0 && nx < size && ny >= 0 && ny < size && map[ny][nx])
						cntAdj++;
				}

				if (cntAdj >= 3)
					result[y][x] = map[y][x];
				else
					result[y][x] = map[y][x] - 1;
			}
			else
				result[y][x] = 0;
		}

	map = result;
}

int BFS(int y, int x, vector<vector<int>>& map, vector<vector<bool>>& visited)
{
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int size = map.size();
	int cnt = 0;
	queue<pair<int, int>> q;

	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = q.front().second + dx[i];
			int ny = q.front().first + dy[i];

			if (nx >= 0 && nx < size && ny >= 0 && ny < size && map[ny][nx] && !visited[ny][nx])
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}

		q.pop();
	}

	return cnt;
}

void CalculateResult(vector<vector<int>>& map)
{
	int size = map.size();
	int sum = 0;
	int area = 0;
	
	vector<vector<bool>> visited(size, vector<bool>(size, false));
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			sum += map[i][j];
			if (map[i][j] && !visited[i][j])
				area = max(area, BFS(i, j, map, visited));
		}

	cout << sum << '\n' << area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	
	int map_size = pow(2, N);
	vector<vector<int>> map(map_size, vector<int>(map_size, 0));

	int a;
	for (int i = 0; i < map_size; i++)
		for (int j = 0; j < map_size; j++)
		{
			cin >> a;
			map[i][j] = a;
		}


	int L;
	for (int t = 0; t < Q; t++)
	{
		cin >> L;
		RotateMap(map, L);

		CalculateIce(map);
	}

	CalculateResult(map);
	return 0;
}
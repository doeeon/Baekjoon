#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct CCTV
{
	int y;
	int x;
	int type; //1, 2, 3, 4, 5
};

int Update(CCTV cctv, int D, vector<vector<vector<int>>>& dir, vector<vector<int>>& map)
{
	int cnt = 0;

	if (dir[cctv.type][D][0]) // 상
	{
		for (int i = cctv.y; i >= 0; i--)
		{
			if (map[i][cctv.x] == 6)
				break;
			else if (map[i][cctv.x] == 0)
			{
				map[i][cctv.x] = 8;
				cnt++;
			}
		}
	}
	if (dir[cctv.type][D][1]) // 하
	{
		for (int i = cctv.y; i < map.size(); i++)
		{
			if (map[i][cctv.x] == 6)
				break;
			else if (map[i][cctv.x] == 0)
			{
				map[i][cctv.x] = 8;
				cnt++;
			}
		}
	}
	if (dir[cctv.type][D][2]) // 좌
	{
		for (int j = cctv.x; j >= 0; j--)
		{
			if (map[cctv.y][j] == 6)
				break;
			else if (map[cctv.y][j] == 0)
			{
				map[cctv.y][j] = 8;
				cnt++;
			}
		}
	}
	if (dir[cctv.type][D][3]) // 우
	{
		for (int j = cctv.x; j < map[0].size(); j++)
		{
			if (map[cctv.y][j] == 6)
				break;
			else if (map[cctv.y][j] == 0)
			{
				map[cctv.y][j] = 8;
				cnt++;
			}
		}
	};

	return cnt;
}

void Search(int level, int D, vector<CCTV> cctv, vector<vector<vector<int>>>& dir, vector<vector<int>> map, int cnt, int& answer)
{
	// map에 감시 영역 표시 '8'
	cnt += Update(cctv[level], D, dir, map);

	if (level + 1 == cctv.size())
	{
		answer = max(answer, cnt);
		return;
	}

	for (int i = 0; i < dir[cctv[level + 1].type].size(); i++)
		Search(level + 1, i, cctv, dir, map, cnt, answer);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	int answer = 0;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<CCTV> cctv;
	int n;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> n;
			map[i][j] = n;
			if (n > 0 && n < 6) // CCTV면
				cctv.push_back({ i, j, n });
			else if (n == 0)
				answer++;
		}
	}

	vector<vector<vector<int>>> direction;
	direction.push_back({ {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} });
	direction.push_back({ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
	direction.push_back({ {1, 1, 0, 0}, {0, 0, 1, 1} });
	direction.push_back({ {1, 0, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 0, 1} });
	direction.push_back({ {1, 1, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 1, 1} });
	direction.push_back({ {1, 1, 1, 1} });
	
	if (cctv.size() > 0)
	{
		//cctv type 5는 map에 '8' 미리 표시 & answer update
		for (int i = 0; i < cctv.size(); i++)
			if (cctv[i].type == 5)
				answer -= Update(cctv[i], 0, direction, map);

		int cnt = 0;
		int total_cnt = 0;
		for (int i = 0; i < direction[cctv[0].type].size(); i++)
			Search(0, i, cctv, direction, map, cnt, total_cnt);

		cout << answer - total_cnt;
	}
	else
		cout << answer;

	return 0;
}
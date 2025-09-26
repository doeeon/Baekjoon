#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool Check(int y, int x, int N)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	return false;
}

void Rotate(vector<vector<int>>& map, int cnt)
{
	vector<vector<int>> tmp(5, vector<int>(5, 0));
	for (int n = 0; n < cnt; n++)
	{
		//시계방향 90도 회전
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				tmp[i][j] = map[5 - 1 - j][i];

		map = tmp;
	}
}

void CalculateSand(int y, int x, vector<vector<int>>& map, int N, int dir)
{	
	// (y, x) == 토네이동 이동 후 최종 좌표
	// dir = 0-좌, 1-하, 2-우, 3-상
	vector<vector<int>> mask = { {0, 0, 2, 0, 0},
								{0, 10, 7, 1, 0},
								{5, 0, 0, 0, 0},
								{0, 10, 7, 1, 0},
								{0, 0, 2, 0, 0} };

	int sand = map[y][x];
	int left = sand;
	map[y][x] = 0;

	switch (dir) {
	case 0:
		//Rotate(mask, 0);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (Check(y + i - 2, x + j - 2, N))
					map[y + i - 2][x + j - 2] += sand * mask[i][j] / 100;

				left -= sand * mask[i][j] / 100;
			}
		
		if (Check(y, x - 1, N))
			map[y][x - 1] += left;

		break;
	case 1:
		Rotate(mask, 3);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (Check(y + i - 2, x + j - 2, N))
					map[y + i - 2][x + j - 2] += sand * mask[i][j] / 100;

				left -= sand * mask[i][j] / 100;
			}

		if (Check(y + 1, x, N))
			map[y + 1][x] += left;

		break;
	case 2:
		Rotate(mask, 2);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (Check(y + i - 2, x + j - 2, N))
					map[y + i - 2][x + j - 2] += sand * mask[i][j] / 100;

				left -= sand * mask[i][j] / 100;
			}

		if (Check(y, x + 1, N))
			map[y][x + 1] += left;

		break;
	case 3:
		Rotate(mask, 1);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (Check(y + i - 2, x + j - 2, N))
					map[y + i - 2][x + j - 2] += sand * mask[i][j] / 100;

				left -= sand * mask[i][j] / 100;
			}

		if (Check(y -1, x, N))
			map[y -1][x] += left;

		break;
	default:
		break;
	}
}

void MoveTornado(vector<vector<int>>& map, int N)
{
	// 좌 -> 하 -> 우 -> 상
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	int cx = N / 2;
	int cy = N / 2; //가운데 칸부터 시작

	int cnt = 0;
	int factor = 0;
	bool finish = false;
	while (!finish)
		for (int i = 0; i < 4 && !finish; i++)
		{
			factor = cnt / 2 + 1;
			cnt++;
			for (int j = 0; j < factor && !finish; j++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (ny == 0 && nx == 0)
					finish = true;

				CalculateSand(ny, nx, map, N, i);

				cx = nx;
				cy = ny;
			}
		}
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N, 0));
	int before_sand = 0;
	int after_sand = 0;

	int n;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> n;
			map[i][j] = n;
			before_sand += n;
		}

	MoveTornado(map, N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			after_sand += map[i][j];

	cout << before_sand - after_sand;

	return 0;
}
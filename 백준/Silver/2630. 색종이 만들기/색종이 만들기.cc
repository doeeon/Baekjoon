#include <iostream>
#include <vector>

using namespace std;

void Count(int& blue, int& white, int n, vector<vector<int>>& map)
{
	// 4등분 -> 각각 탐색(안되면 재귀, 되면 cnt++)
	int dy[4] = { 0, 0, n / 2, n / 2 };
	int dx[4] = { 0, n / 2, 0, n / 2 };
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;
		for (int x = dx[i]; x < dx[i] + (n / 2); x++)
			for (int y = dy[i]; y < dy[i] + (n / 2); y++)
				sum += map[y][x];

		if (sum == 0)
			white++;
			
		else if (sum == n * n / 4)
			blue++;

		else
		{
			vector<vector<int>> v(n/2, vector<int>(n/2, 0));
			for (int x = 0; x < (n / 2); x++)
				for (int y = 0; y < (n / 2); y++)
					v[y][x] = map[dy[i] + y][dx[i] + x];

			Count(blue, white, n / 2, v);
		}
	}


	return;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N, 0));
	int tmp;
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			map[i][j] = tmp;
			sum += tmp;
		}

	int blue = 0;
	int white = 0;
	
	if (sum == 0)
		white = 1;
	else if (sum == N * N)
		blue = 1;
	else
		Count(blue, white, N, map);

	cout << white << '\n' << blue;

	return 0;
}
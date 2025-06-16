#include <iostream>
#include <vector>

using namespace std;

int Ground(int h, vector<vector<int>>& map, int B)
{
	int time = 0;
	for (int i = 0; i < map.size(); i++)
		for (int j = 0;j < map[i].size(); j++)
		{
			if (map[i][j] > h) // 땅 파기
			{
				time += (map[i][j] - h) * 2;
				B += map[i][j] - h;
			}
			else if(map[i][j] < h) // 땅 세우기
			{
				time += h - map[i][j];
				B -= h - map[i][j];
			}
		}
	
	if (B < 0)
		return -1; // impossible
	return time;
}

int main() {
	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> map(N, vector<int>(M, 0));
	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			map[i][j] = num;
		}
	}

	vector<int> answer(2, 0);
	answer[0] = 500 * 500 * 255 * 2;
	answer[1] = -1;
	for (int h = 0; h <= 256; h++)
	{
		int t = Ground(h, map, B);
		if (t >= 0 && t <= answer[0])
		{
			answer[0] = t;
			answer[1] = h;
		}
	}


	cout << answer[0] << ' ' << answer[1];
	return 0;
}
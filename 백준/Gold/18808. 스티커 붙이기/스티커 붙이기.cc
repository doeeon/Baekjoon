#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Rotate(vector<vector<int>> sticker)
{
	int r = sticker.size();
	int c = sticker[0].size();
	vector<vector<int>> result(c, vector<int>(r, 0));

	//for (int i = 0; i < r; i++)
	//	for (int j = 0; j < c; j++)
	//		result[j][r - i - 1] = sticker[i][j];

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			result[i][j] = sticker[r - j - 1][i];

	return result;
}

void Attach(int y, int x, vector<vector<int>>& map, vector<vector<int>>& sticker)
{
	for (int i = y; i < y + sticker.size(); i++)
		for (int j = x; j < x + sticker[0].size(); j++)
			map[i][j] |= sticker[i - y][j - x];

	return;
}

bool Check(int y, int x, vector<vector<int>>& map, vector<vector<int>>& sticker)
{
	for (int i = y; i < y + sticker.size(); i++)
		for (int j = x; j < x + sticker[0].size(); j++)
			if (sticker[i - y][j - x] == 1 && map[i][j] == 1)
				return false;

	return true;
}

void Find(vector<vector<int>>& map, vector<vector<int>>& sticker)
{
	vector<vector<int>> tmp(sticker);
	int N = map.size();
	int M = map[0].size();

	for (int n = 0; n < 4; n++)
	{
		if (n > 0)
			tmp = Rotate(tmp);

		int R = tmp.size();
		int C = tmp[0].size();

		if (R > N || C > M)
			continue;

		for (int i = 0; i <= N - R; i++)
			for (int j = 0; j <= M - C; j++)
				if (Check(i, j, map, tmp) == true)
				{
					Attach(i, j, map, tmp);
					return;
				}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<vector<int>>> stickers;
	int r, c;
	int n;
	for (int i = 0; i < K; i++)
	{
		cin >> r >> c;
		vector<vector<int>> tmp(r, vector<int>(c, 0));
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
			{
				cin >> n;
				tmp[j][k] = n;
			}

		stickers.push_back(tmp);
	}

	for (int i = 0; i < stickers.size(); i++)
		Find(map, stickers[i]);

	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j])
				answer++;

	cout << answer;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> symmetry(vector<vector<int>> type)
{
	if (type.size() == 3) // 3x2
		for (int i = 0; i < 3; i++)
			swap(type[i][0], type[i][1]);
	else // 2x3
		for (int i = 0; i < 3; i++)
			swap(type[0][i], type[1][i]);

	return type;
}

vector<vector<int>> rotate(vector<vector<int>>& type)
{
	int N = type.size();
	int M = type[0].size();

	vector<vector<int>> tmp(M, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[j][N - i - 1] = type[i][j];
	
	return tmp;
}

int Search(vector<vector<int>>& map, vector<vector<int>>& mask)
{
	int answer = 0;
	int h = mask.size();
	int w = mask[0].size();

	for (int i = 0; i < map.size()-h+1; i++)
		for (int j = 0; j < map[i].size()-w+1; j++)
		{
			int sum = 0;
			for (int y = 0; y < h; y++)
				for (int x = 0; x < w; x++)
					sum += map[i+y][j+x] * mask[y][x];

			answer = max(answer, sum);
		}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int n;
	vector<vector<int>> map(N, vector<int>(M, 0));
	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> n;
			map[i][j] = n;
		}

	vector<vector<vector<int>>> tetromino;

	tetromino.push_back(vector<vector<int>>(2, vector<int>(2, 1)));
	tetromino.push_back(vector<vector<int>>(1, vector<int>(4, 1)));
	tetromino.push_back(vector<vector<int>>(4, vector<int>(1, 1)));
	vector<vector<int>> type = { {1,0},{1,0},{1,1} }; // 3 rotate, 4 symmetry
	vector<vector<int>> type2 = { {1,0},{1,1},{0,1} }; // 1 rotate, 2 symmetry
	vector<vector<int>> type3 = { {1,0},{1,1},{1,0} }; // 1 rotate, 2 symmetry

	tetromino.push_back(type);
	for (int i = 0; i < 3; i++)
	{
		tetromino.push_back(symmetry(tetromino.back()));
		tetromino.push_back(rotate(tetromino.back()));
	}
	tetromino.push_back(symmetry(tetromino.back()));

	tetromino.push_back(type2);
	tetromino.push_back(symmetry(tetromino.back()));
	tetromino.push_back(rotate(type2));
	tetromino.push_back(symmetry(tetromino.back()));

	tetromino.push_back(type3);
	tetromino.push_back(symmetry(tetromino.back()));
	tetromino.push_back(rotate(type3));
	tetromino.push_back(symmetry(tetromino.back()));


	int answer = 0;
	for (int i = 0; i < tetromino.size(); i++)
		answer = max(answer, Search(map, tetromino[i]));

	cout << answer;
	return 0;
}
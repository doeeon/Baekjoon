#include <iostream>
#include <vector>

using namespace std;

int white = 0;
int blue = 0;
void Cut(int y, int x, int N, vector<vector<int>>& map)
{
	int sum = 0;
	for (int i = y; i < y+N; i++)
		for (int j = x; j < x + N; j++)
			sum += map[i][j];

	if (sum == N * N)
		blue++;
	else if (sum == 0)
		white++;
	else
	{
		Cut(y, x, N / 2, map);
		Cut(y, x + N / 2, N / 2, map);
		Cut(y + N / 2, x, N / 2, map);
		Cut(y + N / 2, x + N / 2, N / 2, map);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	int n;
	vector<vector<int>> map(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> n;
			map[i][j] = n;
		}

	Cut(0, 0, N, map);

	cout << white << '\n' << blue;

	return 0;
}
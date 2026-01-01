#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int Find(int x, vector<int>& parent)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x], parent);
}

bool Unite(int x, int y, vector<int>& parent, vector<int>& sz)
{
	x = Find(x, parent);
	y = Find(y, parent);

	if (x == y)	return false;
	if (sz[x] < sz[y]) swap(x, y);
	parent[y] = x;
	sz[x] += sz[y];
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> map(N);
	for (int i = 0; i < N; i++)
		cin >> map[i];

	vector<int> parent(N * M);
	vector<int> sz(N * M, 1);
	for (int i = 0; i < N * M; i++)
		parent[i] = i;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			int ny = y;
			int nx = x;

			if (map[y][x] == 'U') ny--;
			else if (map[y][x] == 'D') ny++;
			else if (map[y][x] == 'L') nx--;
			else if (map[y][x] == 'R') nx++;

			Unite((y * M + x), (ny * M + nx), parent, sz);
		}

	int answer = 0;
	for (int i = 0; i < parent.size(); i++)
		if (parent[i] == i)
			answer++;

	cout << answer;
	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool CheckRow(int r, int n, vector<string>& map)
{
	for (int i = 0; i < 9; i++)
		if (map[r][i] - '0' == n)
			return false;

	return true;
}

bool CheckColumn(int c, int n, vector<string>& map)
{
	for (int i = 0; i < 9; i++)
		if (map[i][c] - '0' == n)
			return false;

	return true;
}

bool CheckGrid(int r, int c, int n, vector<string>& map)
{
	for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
		for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
			if (map[i][j] - '0' == n)
				return false;

	return true;
}

bool Check(int r, int c, int n, vector<string>& map)
{
	return CheckRow(r, n, map) && CheckColumn(c, n, map) && CheckGrid(r, c, n, map);
}

bool Backtracking(int idx, vector<pair<int, int>>& blank, vector<string>& map)
{
	if (idx == blank.size())
	{
		for (string s : map)
			cout << s << '\n';

		return true;
	}

	for (int n = 1; n <= 9; n++)
	{
		if (Check(blank[idx].first, blank[idx].second, n, map))
		{
			map[blank[idx].first][blank[idx].second] = n + '0';
			if (Backtracking(idx + 1, blank, map))	
				return true;
			map[blank[idx].first][blank[idx].second] = '0';
		}
	}

	return false;
}

int main()
{
	vector<string> map(9);
	vector<pair<int, int>> blank;
	for (int i = 0; i < 9; i++)
	{
		cin >> map[i];
		for (int j = 0; j < 9; j++)
			if (map[i][j] - '0' == 0)
				blank.emplace_back(i, j);
	}

	Backtracking(0, blank, map);
	return 0;
}
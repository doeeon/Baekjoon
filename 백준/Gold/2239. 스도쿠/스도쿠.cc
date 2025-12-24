#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool CheckRow(int r, vector<string>& map)
{
	int cnt[10] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		if (map[r][i] == '0')
			continue;
		cnt[map[r][i] - '0']++;
		if (cnt[map[r][i] - '0'] > 1)
			return false;
	}

	return true;
}

bool CheckColumn(int c, vector<string>& map)
{
	int cnt[10] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		if (map[i][c] == '0')
			continue;

		cnt[map[i][c] - '0']++;
		if (cnt[map[i][c] - '0'] > 1)
			return false;
	}
	return true;
}

bool CheckGrid(int r, int c, vector<string>& map)
{
	int cnt[10] = { 0 };
	for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
	{
		for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
		{
			if (map[i][j] == '0')
				continue;

			cnt[map[i][j]-'0']++;
			if (cnt[map[i][j]-'0'] > 1)
				return false;
		}
	}

	return true;
}

bool Check(int r, int c, int n, vector<string>& map)
{
	map[r][c] = n + '0';
	bool result = CheckRow(r, map) && CheckColumn(c, map) && CheckGrid(r, c, map);
	map[r][c] = '0';
	return result;
}

pair<int, int> NextBlank(pair<int, int> rc, vector<string>& map)
{
	for (int i = rc.first; i < 9; i++)
	{
		int j = 0;
		if (i == rc.first)	j = rc.second;
		for (; j < 9; j++)
			if (map[i][j] == '0')
				return { i, j };
	}

	return { -1, -1 };
}

bool finish = false;
void Backtracking(pair<int, int> rc, vector<string>& map)
{
	if (rc.first == -1 && rc.second == -1)
	{
		for (string s : map)
			cout << s << '\n';
		finish = true;
		return;
	}

	for (int n = 1; n <= 9; n++)
	{
		if (finish)
			return;

		if (Check(rc.first, rc.second, n, map))
		{
			map[rc.first][rc.second] = n + '0';
			Backtracking(NextBlank({ rc.first, rc.second + 1 }, map), map);
			map[rc.first][rc.second] = '0';
		}
	}
}


int main()
{
	int blank = 0;
	vector<string> map(9);
	for (int i = 0; i < 9; i++)
		cin >> map[i];

	Backtracking(NextBlank({ 0, 0 }, map), map);
	return 0;
}
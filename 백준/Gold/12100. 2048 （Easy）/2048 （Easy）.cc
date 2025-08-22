#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector<vector<int>> Move(vector<vector<int>>& map, int dir)
{
	//dir 0(up), 1(down), 2(left), 3(right)
	int N = map.size();
	vector<vector<int>> result(N, vector<int>(N, 0));

	if (dir == 0) //Up
	{
		for (int j = 0; j < N; j++)
		{
			vector<int> tmp;
			queue<int> q;
			for (int i = 0; i < N; i++)
				if (map[i][j] > 0)
					q.push(map[i][j]);
					//tmp.push_back(map[i][j]);

			while (!q.empty())
			{
				int curr = q.front();
				q.pop();

				if (!q.empty() && curr == q.front())
				{
					tmp.push_back(2 * curr);
					q.pop();
				}
				else
					tmp.push_back(curr);
			}

			for (int k = 0; k < tmp.size(); k++)
				if(tmp[k])
					result[k][j] = tmp[k];
		}
	}
	else if (dir == 1) // Down
	{
		for (int j = 0; j < N; j++)
		{			
			vector<int> tmp;
			queue<int> q;
			for (int i = N - 1; i >= 0; i--)
				if (map[i][j] > 0)
					q.push(map[i][j]);

			while (!q.empty())
			{
				int curr = q.front();
				q.pop();

				if (!q.empty() && curr == q.front())
				{
					tmp.push_back(2 * curr);
					q.pop();
				}
				else
					tmp.push_back(curr);
			}

			for (int k = 0; k < tmp.size(); k++)
				if(tmp[k])
					result[N - k - 1][j] = tmp[k];
		}

	}
	else if (dir == 2) // Left
	{
		for (int i = 0; i < N; i++)
		{
			vector<int> tmp;
			queue<int> q;
			for (int j = 0; j < N; j++)
				if (map[i][j] > 0)
					q.push(map[i][j]);

			while (!q.empty())
			{
				int curr = q.front();
				q.pop();

				if (!q.empty() && curr == q.front())
				{
					tmp.push_back(2 * curr);
					q.pop();
				}
				else
					tmp.push_back(curr);
			}

			for (int k = 0; k < tmp.size(); k++)
				if(tmp[k])
					result[i][k] = tmp[k];
		}
	}
	else if (dir == 3) // Right
	{
		for (int i = 0; i < N; i++)
		{
			vector<int> tmp;
			queue<int> q;
			for (int j = N - 1; j >= 0; j--)
				if (map[i][j] > 0)
					q.push(map[i][j]);

			while (!q.empty())
			{
				int curr = q.front();
				q.pop();

				if (!q.empty() && curr == q.front())
				{
					tmp.push_back(2 * curr);
					q.pop();
				}
				else
					tmp.push_back(curr);
			}

			for (int k = 0; k < tmp.size(); k++)
				if(tmp[k])
					result[i][N - k - 1] = tmp[k];
		}
	}

	return result;
}

bool IsSame(vector<vector<int>>& a_map, vector<vector<int>>& b_map)
{
	int N = a_map.size();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (a_map[i][j] != b_map[i][j])
				return false;

	return true;
}

int FindMax(vector<vector<int>>& map)
{
	int result = 0;
	int N = map.size();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] > result)
				result = map[i][j];

	return result;
}

void Backtracking(int depth, vector<vector<int>>& map, int& max_value)
{
	if (depth == 5)
	{
		max_value = max(max_value, FindMax(map));
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			// 상하좌우 move
			vector<vector<int>> moved_map = Move(map, i);
			// backtracking
			if (IsSame(map, moved_map))
				continue;
			else
				Backtracking(depth + 1, moved_map, max_value);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N, 0));
	int a;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			map[i][j] = a;
		}

	int answer = FindMax(map);

	Backtracking(0, map, answer);

	cout << answer;
	return 0;
}
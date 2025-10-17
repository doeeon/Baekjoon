#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	if (a[0] == b[0])
	{
		if (a[1] == b[1])
		{
			if (a[2] == b[2])
				return a[3] > b[3];
			else
				return a[2] > b[2];
		}
		else
			return a[1] < b[1];
	}
	else
		return a[0] < b[0];
}

int DateCompare(int m1, int d1, int m2, int d2)
{
	if (m1 == m2)
	{
		if (d1 == d2)
			return 0;
		else if (d1 < d2)
			return -1;
		else
			return 1;
	}
	else if (m1 < m2)
		return -1;
	else
		return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	vector<vector<int>> flower;

	int a, b, c, d;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c >> d;
		flower.push_back({ a, b, c, d });
	}

	sort(flower.begin(), flower.end(), cmp);

	
	int end_month = 3;
	int end_date = 1;
	int cnt = 0;
	int idx = 0;
	while (end_month < 12)
	{
		int max_month = end_month;
		int max_date = end_date;
		bool found = false;

		for (; idx < N; idx++)
		{
			if (DateCompare(flower[idx][0], flower[idx][1], end_month, end_date) > 0)
				break;

			if (DateCompare(flower[idx][2], flower[idx][3], max_month, max_date) > 0)
			{
				max_month = flower[idx][2];
				max_date = flower[idx][3];
				found = true;
			}
		}

		if (found)
		{
			cnt++;
			end_month = max_month;
			end_date = max_date;
		}
		else
		{
			cnt = 0;
			break;
		}
	}

	if (end_month < 12)
		cnt = 0;
	
	cout << cnt;
	return 0;
}
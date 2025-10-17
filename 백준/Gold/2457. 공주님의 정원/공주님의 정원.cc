#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> flower;

	int a, b, c, d;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c >> d;
		flower.push_back({ a * 100 + b, c * 100 + d });
	}

	sort(flower.begin(), flower.end(), cmp);


	int end = 301;
	int cnt = 0;
	int idx = 0;

	while (idx < N && end < 1201)
	{
		int max = end;
		bool found = false;
		for (; idx < N; idx++)
		{
			if (flower[idx].first > end)
			{
				break;
			}

			if (flower[idx].second > max)
			{
				max = flower[idx].second;
				found = true;
			}
		}

		if (found)
		{
			end = max;
			cnt++;
		}
		else
		{
			cnt = 0;
			break;
		}
	}

	if (end < 1201)
		cnt = 0;

	cout << cnt;
	return 0;
}
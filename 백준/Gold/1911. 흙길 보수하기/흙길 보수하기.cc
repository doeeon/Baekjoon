#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;
	cin >> N >> L;

	vector<pair<int, int>> water;

	int s, e;
	for (int n = 0; n < N; n++)
	{
		cin >> s >> e;
		water.push_back({ s, e });
	}

	sort(water.begin(), water.end(), cmp);

	int answer = 0;
	int last = -1;

	for (int i = 0; i < water.size(); i++)
	{
		if (last >= water[i].second)
			continue;
		else
		{
			if (last >= water[i].first)
			{
				int cnt = (water[i].second - (last + 1)) / L;
				if ((water[i].second - (last+1)) % L != 0)
					cnt++;

				last = (last + 1) + cnt * L - 1;
				answer += cnt;
			}
			else
			{
				int cnt = (water[i].second - water[i].first) / L;
				if ((water[i].second - water[i].first) % L != 0)
					cnt++;

				last = water[i].first + cnt * L - 1;
				answer += cnt;
			}
		}
	}

	cout << answer;

	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C, N;
	cin >> C >> N;

	int min_idx = -1;
	double min_effic = 1000000;
	vector<pair<int, int>> city(N, {0, 0});
	for (int i = 0; i < N; i++)
	{
		cin >> city[i].first >> city[i].second; // {cost, value}
		if (min_effic > (double)city[i].second / city[i].first)
		{
			min_effic = (double)city[i].second / city[i].first;
			min_idx = i;
		}
	}

	int u_bound;
	u_bound = (C / city[min_idx].second) * city[min_idx].first;
	if (C % city[min_idx].second != 0)
		u_bound += city[min_idx].first;


	vector<int> dp(u_bound + 1, 0); // dp[i] : cost가 i일때 최대 value 값

	for (int i = 1; i <= u_bound; i++)
		for (int n = 0; n < N; n++)
			if (i - city[n].first >= 0)
				dp[i] = max(dp[i], dp[i - city[n].first] + city[n].second);

	int answer = 0;
	for (int w = 0; w < dp.size(); w++)
		if (dp[w] >= C)
		{
			answer = w;
			break;
		}

	cout << answer;
	
	return 0;
}
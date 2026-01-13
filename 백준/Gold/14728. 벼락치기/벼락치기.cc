#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, T;
	cin >> N >> T;

	vector<pair<int, int>> list(N);
	for (int i = 0; i < N; i++)
		cin >> list[i].first >> list[i].second;

	vector<int> dp(T + 1, -1);
	dp[0] = 0;
	for (int i = 0; i < N; i++)
		for (int t = T; t >= list[i].first; t--)
			if (dp[t - list[i].first] >= 0)
				dp[t] = max(dp[t], dp[t - list[i].first] + list[i].second);

	cout << *max_element(dp.begin(), dp.end());
	return 0;
}
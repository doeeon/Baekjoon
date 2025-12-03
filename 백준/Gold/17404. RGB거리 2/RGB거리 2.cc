#include <iostream>
#include <cmath>
#include <vector>

#define INF 200000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> cost(N+1, vector<int>(3, 0));
	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	int answer = INF;
	for (int first = 0; first < 3; first++)
	{
		vector<vector<int>> dp(N + 1, vector<int>(3, INF));
		dp[1][first] = cost[1][first]; // 1번 집 색깔 고정

		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int last = 0; last < 3; last++)
			if(last != first)
				answer = min(answer, dp[N][last]);
	}

	cout << answer;

	return 0;
}
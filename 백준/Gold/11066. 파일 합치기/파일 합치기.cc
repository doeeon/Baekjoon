#include <iostream>
#include <vector>
#include <cmath>

// #define INF 1e9
const long long INF = 1e18;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int K;
		cin >> K;

		vector<int> file(K+1);
		vector<long long> prefix_sum(K+1);
		for (int i = 1; i <= K; i++)
		{
			cin >> file[i];
			prefix_sum[i] = prefix_sum[i - 1] + file[i];
		}

		vector<vector<long long>> dp(K + 1, vector<long long>(K + 1, INF));
		for (int i = 1; i <= K; i++)
			dp[i][i] = 0;

		for (int diff = 1; diff < K; diff++)
			for (int i = 1; i <= K - diff; i++)
			{
				int j = i + diff;
				for (int n = i; n < j; n++)
					dp[i][j] = min(dp[i][j], dp[i][n] + dp[n + 1][j] + (prefix_sum[j] - prefix_sum[i - 1]));
			}

		cout << dp[1][K] << '\n';
	}
	return 0;
}
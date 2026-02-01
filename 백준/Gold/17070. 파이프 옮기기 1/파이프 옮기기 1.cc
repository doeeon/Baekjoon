#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(3, 0)));
	for (int i = 1; i < N; i++)
	{
		if (map[0][i]) break;
		dp[0][i][0] = 1;
	}


	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (map[i][j]) continue;

			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
			
			if (map[i - 1][j] == 0 && map[i][j - 1] == 0)
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
		}
	}

	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];


	return 0;
}
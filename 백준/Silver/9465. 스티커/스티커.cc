#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
	
		vector<vector<int>> dp(2, vector<int>(N, 0));
		vector<vector<int>> arr(2, vector<int>(N, 0));
		int num;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> num;
				arr[i][j] = num;
			}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + dp[1][0];
		dp[1][1] = arr[1][1] + dp[0][0];

		for (int i = 2; i < N; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}
		
		cout << max(dp[0][N-1], dp[1][N-1]) << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> dp(N+1, vector<int>(10, 0));
	
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[N][i]) % 1000000000;

	cout << sum;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(K + 1, vector<int>(N+1, 0));
	// dp[i][j] : 정수 i개를 써서 총합 j를 만들 수 있는 경우의 수
	dp[0][0] = 1;

	for (int i = 1; i <= K; i++)
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
				if (dp[i-1][j - k] > 0)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000000;
		}

	cout << dp[K][N];
	return 0;
}
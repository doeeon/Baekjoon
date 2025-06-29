#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> arr(N+1, vector<int>(N+1, 0));
	int num;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> num;
			arr[i][j] = num;
		}

	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= N; i++)
	{
		dp[1][i] = dp[1][i - 1] + arr[1][i];
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}

	for (int i = 2; i <= N; i++)
		for (int j = 2; j <= N; j++)
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1];

	int answer;
	int x1, x2, y1, y2;
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		answer = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
		cout << answer << '\n';
	}
	return 0;
}
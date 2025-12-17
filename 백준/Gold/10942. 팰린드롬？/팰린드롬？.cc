#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N+1, 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
	for (int i = 1; i <= N; i++)
		dp[i][i] = 1;

	for (int i = 1; i <= N - 1; i++)
	{
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
		else
			dp[i][i + 1] = 0;
	}

	for (int diff = 2; diff <= N - 1; diff++)
		for (int i = 1; i <= N - diff; i++)
		{
			int j = i + diff;
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}

	int M;
	cin >> M;
	
	int start, end;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		cout << dp[start][end] << '\n';
	}

	return 0;
}
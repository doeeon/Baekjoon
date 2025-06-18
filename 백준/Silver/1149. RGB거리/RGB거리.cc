#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> house(N, vector<int>(3, 0));
	int r, g, b;
	for (int i = 0; i < N; i++)
	{
		cin >> r >> g >> b;
		house[i][0] = r;
		house[i][1] = g;
		house[i][2] = b;
	}

	vector<vector<int>> dp(N, vector<int>(3));
	
	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}

	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			cin >> num;
			v[i][j] = num;
		}

	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = v[0][0];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + v[i][0];
		dp[i][i] = dp[i - 1][i - 1] + v[i][i];
		for (int j = 1; j < i; j++)
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
	return 0;
}
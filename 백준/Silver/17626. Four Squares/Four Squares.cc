#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, 4);

	dp[0] = 0;
	dp[1] = 1;

	for (int x = 2; x<= n; x++)
	{
		for (int i = 1; i * i <= x; i++)
			dp[x] = min(dp[x], 1 + dp[x - i * i]);
	}

	cout << dp[n];

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	
	vector<int> dp(n, 0);
	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%15746;

	cout << dp[n-1];
	return 0;
}
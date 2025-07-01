#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int num;
	vector<int> wine(n+1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		wine[i] = num;
	}

	vector<int> dp(n + 1, 0);
	// dp[i] : i번째 포도주 잔을 고려했을 때 마실 수 있는 최대의 양 (i번째를 반드시 마실 필요는 없음)
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n;i++)
		dp[i] = max(max((dp[i - 3] + wine[i - 1] + wine[i]), (dp[i - 2] + wine[i])), dp[i-1]);

	cout << dp[n];
	return 0;
}
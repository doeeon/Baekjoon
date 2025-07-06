#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 0;
int cnt2 = 0;
int fib1(int n)
{
	if (n == 1 || n == 2)
	{
		cnt1++;
		return 1;
	}
	else
		return (fib1(n - 1) + fib1(n - 2));
}

int fib2(int n)
{
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		cnt2++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	int res;
	res = fib1(n);
	res = fib2(n);

	cout << cnt1 << ' ' << cnt2;

	return 0;
}
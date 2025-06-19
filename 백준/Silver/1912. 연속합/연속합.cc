#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	vector<int> dp(n, 0);
	dp[0] = arr[0];
	int answer = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		answer = max(answer, dp[i]);
	}

	cout << answer;
	return 0;
}
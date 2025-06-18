#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int num;
	vector<int> score(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		score[i] = num;
	}
	vector<int> dp(N, 0);

	dp[0] = score[0];
	dp[1] = dp[0] + score[1];
	dp[2] = max(dp[0], score[1]) + score[2];

	for (int i = 3; i < N; i++)
		dp[i] = score[i] + max(dp[i - 3] + score[i - 1], dp[i - 2]);

	cout << dp[N - 1];
	return 0;
}
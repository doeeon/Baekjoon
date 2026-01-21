#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> coin(N);
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	vector<int> dp(K + 1);

	dp[0] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= K; j++)
			if (j - coin[i] >= 0 && dp[j - coin[i]])
				dp[j] += dp[j - coin[i]];

	cout << dp[K];
	return 0;
}
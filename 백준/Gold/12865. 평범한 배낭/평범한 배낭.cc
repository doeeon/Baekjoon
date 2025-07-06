#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> item;
	int w, v;
	for (int i = 0; i < N; i++)
	{
		cin >> w >> v;
		item.push_back({ w, v });
	}

	vector<int> dp(K + 1, 0);
	//dp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		if (item[i].first <= K)
		{
			for (int j = K; j >= item[i].first; j--)
			{
				dp[j] = max(dp[j], dp[j - item[i].first] + item[i].second);
			}
		}
	}

	cout << dp[K];
	return 0;
}
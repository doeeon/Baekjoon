#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int T = 0; T < 3; T++)
	{
		int N;
		cin >> N;

		vector<int> coins;

		int total = 0;
		int cost, cnt;
		for (int i = 0; i < N; i++)
		{
			cin >> cost >> cnt;
			total += cost * cnt;

			for (int j = 1; cnt > 0; j *= 2) //2진수 분할
			{
				int num = min(j, cnt);
				coins.push_back(cost * num);
				cnt -= num;
			}
		}

		if (total % 2 != 0)
		{
			cout << "0\n";
			continue;
		}

		vector<bool> dp(total / 2 + 1, false);
		dp[0] = true;

		for (auto coin : coins)
		{
			for (int i = total / 2; i >= coin; i--)
				if (dp[i - coin])
					dp[i] = true;
			
			if (dp[total / 2])
				break;
		}

		if (dp[total / 2])
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}
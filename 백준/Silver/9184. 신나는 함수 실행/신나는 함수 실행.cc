#include <iostream>
#include <vector>

using namespace std;

int W(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
	{
		a = 20;
		b = 20;
		c = 20;
	}
	vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, 1)));
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			for (int k = 1; k <= c; k++)
			{
				if (i < j && j < k)
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				else
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
			}
		}
	}

	return dp[a][b][c];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << '\n';
	}

	return 0;
}
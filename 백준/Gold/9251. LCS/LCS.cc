#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	s1 = " " + s1;
	s2 = " " + s2;
	vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));

	for (int i = 1; i < s1.size(); i++)
	{
		for (int j = 1; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[s1.size() - 1][s2.size() - 1];
	return 0;
}
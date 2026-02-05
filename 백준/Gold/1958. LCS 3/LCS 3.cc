#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string A, B, C;
	cin >> A >> B >> C;

	A = " " + A;
	B = " " + B;
	C = " " + C;
	vector<vector<vector<int>>> dp(A.size(), vector<vector<int>>(B.size(), vector<int>(C.size())));

	for (int i = 1; i < A.size(); i++)
	{
		for (int j = 1; j < B.size(); j++)
		{
			for (int k = 1; k < C.size(); k++)
			{
				if (A[i] == B[j] && A[i] == C[k])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}

	cout << dp[A.size() - 1][B.size() - 1][C.size() - 1];
	return 0;
}
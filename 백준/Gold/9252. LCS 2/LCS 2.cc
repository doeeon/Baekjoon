#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	int N = A.size();
	int M = B.size();
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (A[i-1] == B[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}


	//2. dp table의 마지막부터 역추적하자.
	int answer = 0;
	string answer_str = "";

	int n = N;
	int m = M;

	while (dp[n][m] > 0)
	{
		if (A[n - 1] == B[m - 1])
		{
			answer++;
			answer_str += A[n - 1];
			n--;
			m--;
		}
		else
		{
			if (dp[n - 1][m] > dp[n][m - 1])
				n--;
			else
				m--;
		}
	}

	reverse(answer_str.begin(), answer_str.end());
	cout << answer << '\n' << answer_str;
	
	return 0;
}
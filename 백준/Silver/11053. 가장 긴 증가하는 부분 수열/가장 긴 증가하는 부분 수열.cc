#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> num(N, 0);
	vector<int> dp(N, 1);
	
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		num[i] = n;
		for (int j = 0; j < i; j++)
			if (num[i] > num[j])
				dp[i] = max(dp[j] + 1, dp[i]);
    }


	cout << *max_element(dp.begin(), dp.end());
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int num;
	vector<int> input(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		input[i] = num;
	}

	vector<int> dp(N, 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (input[i] > input[j])
				dp[i] = max(dp[i], dp[j] + 1);


	cout << *max_element(dp.begin(), dp.end());
	return 0;
}
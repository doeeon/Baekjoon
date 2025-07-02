#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> num(N, 0);
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		num[i] = n;
	}

	vector<int> left(N, 1);
	vector<int> right(N, 1);
	vector<int> dp(N, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[i] > num[j])
				left[i] = max(left[i], left[j] + 1);

			if (num[N - i - 1] > num[N - j - 1])
				right[N - i - 1] = max(right[N - i - 1], right[N - j - 1] + 1);
		}
	}
	
	for (int i = 0; i < N; i++)
		dp[i] = left[i] + right[i] - 1;

	cout << *max_element(dp.begin(), dp.end());
	return 0;
}
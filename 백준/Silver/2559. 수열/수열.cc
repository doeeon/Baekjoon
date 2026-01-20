#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> num(N);
	vector<int> prefix_sum(N-K+1);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		if (i < K)
			prefix_sum[0] += num[i];
	}

	
	for (int i = 1; i < N - K + 1; i++)
		prefix_sum[i] = prefix_sum[i - 1] - num[i - 1] + num[i + K - 1];

	cout << *max_element(prefix_sum.begin(), prefix_sum.end());

	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
	int K, N;
	cin >> K >> N;

	long long tmp;
	long long left = 1;
	long long right = 0;
	vector<int> wire(K, 0);
	for (int i = 0; i < K; i++)
	{
		cin >> tmp;
		wire[i] = tmp;
		right = max(right, tmp);
	}

	right++;

	while (left < right)
	{
		long long mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < wire.size(); i++)
			cnt += wire[i] / mid;

		if (cnt >= N)
			left = mid + 1;
		else
			right = mid;
	}

	long long answer = right - 1;
	cout << answer;
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long Cut(vector<int>& trees, int h)
{
	long long ans = 0;
	for (int i = 0; i < trees.size(); i++)
		if (trees[i] > h)
			ans += trees[i] - h;

	return ans;
}

int main() {
	int answer = 0;
	int N, M;
	cin >> N >> M;

	int t;
	int max_t = 0;
	vector<int> trees(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		trees[i] = t;
		max_t = max(max_t, t);
	}


	int left = 0;
	int right = max_t;
	while (left < right) {
		int mid = (left + right) / 2;
		if (Cut(trees, mid) >= M)
			left = mid + 1;
		else
			right = mid;
	}

	answer = left - 1;
	cout << answer;
	return 0;
}
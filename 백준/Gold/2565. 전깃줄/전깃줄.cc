#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> num;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		num.push_back({ a, b });
	}

	sort(num.begin(), num.end(), cmp);

	vector<int> dp_b(N, 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (num[i].second > num[j].second)
				dp_b[i] = max(dp_b[i], dp_b[j] + 1);

	int answer = N - *max_element(dp_b.begin(), dp_b.end());
	cout << answer;
	return 0;
}
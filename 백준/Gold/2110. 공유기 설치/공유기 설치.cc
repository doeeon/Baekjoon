#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Simulate(int d, vector<int>& house, int C)
{
	int cnt = 1;
	int last_idx = 0;
	int curr_idx = 0;
	while (curr_idx < house.size())
	{
		if (house[curr_idx] - house[last_idx] >= d)
		{
			cnt++;
			last_idx = curr_idx;
		}

		curr_idx++;
	}

	if (cnt < C)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> house(N);
	for (int i = 0; i < N; i++)
		cin >> house[i];

	sort(house.begin(), house.end());

	int answer = 0;
	int left = 1;
	int right = house.back() - house.front();
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (Simulate(mid, house, C))
		{
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}
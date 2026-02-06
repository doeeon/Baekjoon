#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	long long people = 0;
	vector<pair<int, int>> village(N);
	for (int i = 0; i < N; i++)
	{
		cin >> village[i].first >> village[i].second;
		people += (long long) village[i].second;
	}

	sort(village.begin(), village.end());

	long long prefix_sum = 0;
	for (int i = 0; i < N; i++)
	{
		prefix_sum += (long long) village[i].second;
		if (prefix_sum >= (people + 1) / 2)
		{
			cout << village[i].first;
			break;
		}
	}

	return 0;
}
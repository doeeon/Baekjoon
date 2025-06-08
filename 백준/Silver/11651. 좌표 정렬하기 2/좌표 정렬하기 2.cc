#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> input;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		input.push_back({ x, y });
	}

	sort(input.begin(), input.end(), cmp);

	for (int i = 0; i < input.size(); i++)
		cout << input[i].first << ' ' << input[i].second << '\n';

	return 0;
}
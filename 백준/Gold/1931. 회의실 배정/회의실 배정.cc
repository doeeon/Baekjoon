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
	
	int start, end;
	vector<pair<int, int>> list;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		list.push_back({ start, end });
	}

	sort(list.begin(), list.end(), cmp);

	int t_end = 0;
	int answer = 0;
	for (int i = 0; i < list.size(); i++)
		if (t_end <= list[i].first)
		{
			answer++;
			t_end = list[i].second;
		}

	cout << answer;
	return 0;
}
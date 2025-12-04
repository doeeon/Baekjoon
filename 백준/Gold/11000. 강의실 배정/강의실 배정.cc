#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> lecture(N, {0, 0});
	for (int i = 0; i < N; i++)
		cin >> lecture[i].first >> lecture[i].second;
	
	sort(lecture.begin(), lecture.end(), cmp);

	int answer = 1;
	priority_queue<int, vector<int>, greater<>> pq; // min-heap
	
	for (int i = 0; i < N; i++)
	{
		if (pq.empty())
			pq.push(lecture[i].second);
		else
		{
			while (pq.top() <= lecture[i].first)
				pq.pop();
			
			pq.push(lecture[i].second);
		}

		answer = max(answer, (int)pq.size());
	}

	cout << answer;

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> meeting(N, { 0, 0 });
	for (int i = 0; i < N; i++)
		cin >> meeting[i].first >> meeting[i].second;
	
	sort(meeting.begin(), meeting.end());

	int answer = 0;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; i++)
	{
		if (pq.empty())
			pq.push(meeting[i].second);
		else
		{
			while (!pq.empty() && pq.top() <= meeting[i].first)
				pq.pop();

			pq.push(meeting[i].second);
		}

		answer = max(answer, (int)pq.size());
	}

	cout << answer;
	return 0;
}
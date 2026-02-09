#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> lecture(N);
	int n;
	for (int i = 0; i < N; i++)
		cin >> n >> lecture[i].first >> lecture[i].second;

	sort(lecture.begin(), lecture.end());

	int answer = 0;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; i++)
	{
		while (!pq.empty() && lecture[i].first >= pq.top())
			pq.pop();

		pq.push(lecture[i].second);
		answer = max(answer, (int)pq.size());
	}

	cout << answer;
	return 0;
}
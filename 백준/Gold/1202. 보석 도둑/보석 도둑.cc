#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first > b.first;
	else
		return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	vector<pair<int, int>> jewel(N, { 0, 0 }); // {price, weight}
	for (int i = 0; i < N; i++)
		cin >> jewel[i].second >> jewel[i].first;

	vector<int> bag(K, 0);
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(jewel.begin(), jewel.end(), cmp); // 무게 기준 오름차순
	sort(bag.begin(), bag.end()); // 무게 기준 오름차순

	priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // max-heap {price, weight}
	
	int j_idx = 0; // jewel index
	long long answer = 0; // max : 300000 *1000000 = 3*1e11
	for (int i = 0; i < bag.size(); i++)
	{
		while (j_idx < jewel.size() && jewel[j_idx].second <= bag[i])
		{
			pq.push({ jewel[j_idx].first, jewel[j_idx].second }); // {price, weight}
			j_idx++;
		}

		if (pq.empty()) // 해당 가방에 넣을 수 있는 보석이 없다면 건너뛴다.
			continue;

		answer += pq.top().first;
		pq.pop();
	}

	cout << answer;
	return 0;
}
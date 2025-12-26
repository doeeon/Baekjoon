#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int TopologicalSort(int N, vector<int>& edge)
{
	int cnt = 0;
	queue<int> q;
	vector<int> indeg(N + 1, 0);
	for (int i = 1; i <= N; i++)
		indeg[edge[i]]++;

	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cnt++;

		indeg[edge[cur]]--;
		if (indeg[edge[cur]] == 0)
			q.push(edge[cur]);
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		vector<int> edge(N + 1);
		int v;
		for (int i = 1; i <= N; i++)
			cin >> edge[i];

		cout << TopologicalSort(N, edge) << '\n';
	}
	return 0;
}
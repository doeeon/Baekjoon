#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> TopologicalSort(int N, vector<vector<int>>& edge)
{
	vector<int> result;
	priority_queue<int, vector<int>, greater<>> pq;
	vector<int> indeg(N + 1, 0);

	for (int i = 1; i <= N; i++)
		for (int e : edge[i])
			indeg[e]++;
	
	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			pq.push(i);

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		result.push_back(cur);

		for (int e : edge[cur])
		{
			indeg[e]--;
			if (indeg[e] == 0)
				pq.push(e);
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> edge(N + 1);
	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		edge[u].emplace_back(v);
	}

	vector<int> answer = TopologicalSort(N, edge);
	for (int n : answer)
		cout << n << ' ';
	return 0;
}
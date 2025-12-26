#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int TopologicalSort(int N, vector<vector<int>>& edge)
{
	int cnt = 0;
	queue<int> q;
	vector<int> indeg(N + 1, 0);
	for (int i = 1; i <= N; i++)
		for (int e : edge[i])
			indeg[e]++;
	
	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cnt++;

		for (int e : edge[cur])
		{
			indeg[e]--;
			if (indeg[e] == 0)
				q.push(e);
		}
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

		vector<vector<int>> edge(N + 1);
		int v;
		for (int i = 1; i <= N; i++)
		{
			cin >> v;
			edge[i].push_back(v);
		}

		cout << TopologicalSort(N, edge) << '\n';
	}
	return 0;
}
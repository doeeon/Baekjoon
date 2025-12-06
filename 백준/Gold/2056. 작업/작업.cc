#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int Topological_Sort(int N, vector<vector<int>>& graph, vector<int>& cost)
{
	vector<int> dp = cost;
	vector<int> indeg(N + 1, 0);
	queue<int> q;

	for (int i = 1; i <= N; i++)
		for (int node : graph[i])
			indeg[node]++;
	
	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int next : graph[curr])
		{
			indeg[next]--;
			dp[next] = max(dp[next], dp[curr] + cost[next]);
			if (indeg[next] == 0)
				q.push(next);
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	vector<vector<int>> graph(N + 1);
	vector<int> cost(N + 1, 0);

	int t, M, m;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i] >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> m;
			graph[m].push_back(i);
		}
	}

	int answer = Topological_Sort(N, graph, cost);
	cout << answer;
	return 0;
}
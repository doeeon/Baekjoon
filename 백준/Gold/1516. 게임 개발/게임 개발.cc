#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> Topological_Sort(int N, vector<vector<int>>& graph, vector<int>& cost)
{
	vector<int> dp = cost;
	queue<int> q;

	vector<int> indeg(N + 1, 0);
	for (int i = 1; i <= N; i++)
		for (int node : graph[i])
			indeg[node]++;

	for(int i=1; i<=N; i++)
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

	return dp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> graph(N + 1);
	vector<int> cost(N + 1, 0);
	int n;
	for (int i = 1; i <= N; i++)
	{
		cin >> n;
		cost[i] = n;

		while (1)
		{
			cin >> n;
			if (n == -1)
				break;
			graph[n].push_back(i);
		}
	}

	vector<int> result = Topological_Sort(N, graph, cost);
	for (int i = 1; i <= N; i++)
		cout << result[i] << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int Topological_Sort(int N, int E, vector<vector<int>>& graph, vector<int>& cost)
{
	vector<int> dp = cost;
	vector<int> indeg(N + 1, 0);
	for (int i = 1; i <= N; i++)
		for (int n = 0; n < graph[i].size(); n++)
			indeg[graph[i][n]]++;
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (curr == E)
			break;

		for (int n = 0; n < graph[curr].size(); n++)
		{
			indeg[graph[curr][n]]--;
			dp[graph[curr][n]] = max(dp[graph[curr][n]], dp[curr] + cost[graph[curr][n]]);
			if (indeg[graph[curr][n]] == 0)
				q.push(graph[curr][n]);
		}
	}

	return dp[E];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, K;
		cin >> N >> K;

		vector<int> cost(N + 1, 0);
		vector<vector<int>> graph(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> cost[i];

		int x, y;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
		}

		int W;
		cin >> W;

		cout << Topological_Sort(N, W, graph, cost) << '\n';
	}
	return 0;
}
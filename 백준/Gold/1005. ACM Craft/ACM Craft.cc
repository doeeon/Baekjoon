#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
void Topological_Sort(int N, vector<vector<int>>& graph, vector<int>& time, vector<int>& dp)
{
	queue<int> q;
	vector<int> indeg(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		dp[i] = time[i];
		for (int next : graph[i])
			indeg[next]++;
	}

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
			dp[next] = max(dp[next], dp[curr] + time[next]);
			if (indeg[next] == 0)
				q.push(next);
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, K;
		cin >> N >> K;

		vector<int> time(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> time[i];

		vector<vector<int>> graph(N + 1);
		int x, y;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
		}

		int W;
		cin >> W;

		vector<int> dp(N + 1);
		Topological_Sort(N, graph, time, dp);

		cout << dp[W] << '\n';
	}
	return 0;
}
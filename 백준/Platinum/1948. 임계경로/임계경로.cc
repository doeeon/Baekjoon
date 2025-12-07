#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

void Topological_Sort(int N, int S, vector<vector<pair<int, int>>>& graph, vector<int>& dp)
{
	queue<int> q; // node
	vector<int> indeg(N + 1, 0);

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < graph[i].size(); j++)
			indeg[graph[i][j].first]++;

	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i].first;
			int cost = graph[curr][i].second;
			dp[next] = max(dp[next], dp[curr] + cost);
			indeg[next]--;
			if (indeg[next] == 0)
				q.push(next);
		}
	}
}

int CountPath(int N, int E, vector<vector<pair<int, int>>>& graph, vector<int>& dp)
{
	int answer = 0;
	vector<bool> visited(N + 1, false);
	queue<int> q;
	q.push(E);
	visited[E] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++)
		{
			int prev = graph[curr][i].first;
			int cost = graph[curr][i].second;

			if (dp[curr] == dp[prev] + cost)
			{
				answer++;
				if (!visited[prev])
				{
					q.push(prev);
					visited[prev] = true;
				}
			}
		}
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N + 1);
	vector<vector<pair<int, int>>> r_graph(N + 1); // 역방향 그래프
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w }); // node, cost
		r_graph[v].push_back({ u, w });
	}

	int S, E;
	cin >> S >> E;

	vector<int> dp(N + 1, 0);
	Topological_Sort(N, S, graph, dp);

	int answer_time = dp[E];
	int answer_road = CountPath(N, E, r_graph, dp);

	cout << answer_time << '\n' << answer_road;
	return 0;
}
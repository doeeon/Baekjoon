#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> Topological_Sort(int N, vector<vector<int>>& graph)
{
	queue<int> q;
	vector<int> result;
	vector<int> indeg(N + 1, 0);

	for (int i = 1; i <= N; i++)
		for (int v : graph[i])
			indeg[v]++;

	for (int i=1; i<=N; i++)
		if (indeg[i] == 0)
			q.push(i);
	
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		result.push_back(curr);

		for (int i = 0; i < graph[curr].size(); i++)
		{
			indeg[graph[curr][i]]--;
			if (indeg[graph[curr][i]] == 0)
				q.push(graph[curr][i]);
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

	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < M; i++)
	{
		int len;
		cin >> len;
		int u = 0, v = 0;
		cin >> u;
		for (int j = 0; j < len-1; j++)
		{
			cin >> v;
			graph[u].push_back(v);
			u = v;
		}
	}

	vector<int> answer = Topological_Sort(N, graph);
	if (answer.size() < N)
		cout << 0;
	else
		for (int n : answer)
			cout << n << '\n';

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Topological_Sort(int N, vector<vector<int>> graph)
{
	vector<int> result;
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
		
		result.push_back(curr);

		for (int i = 0; i < graph[curr].size(); i++)
		{
			indeg[graph[curr][i]]--;
			if(indeg[graph[curr][i]] == 0)
				q.push(graph[curr][i]);
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}

	vector<int> answer = Topological_Sort(N, graph);

	for (int student : answer)
		cout << student << ' ';
	return 0;
}
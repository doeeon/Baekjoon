#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int X, int N, int K, vector<vector<int>>& graph, vector<int>& answer)
{
	int level = 0;
	vector<bool> visited(N + 1, false);
	queue<int> q;
	q.push(X);
	visited[X] = true;

	while (!q.empty())
	{
		int size = q.size();
		if (level == K)
			break;
		for (int i = 0; i < size; i++)
		{
			int curr = q.front();
			q.pop();

			for (int j = 0; j < graph[curr].size(); j++)
			{
				int next = graph[curr][j];
				if (!visited[next])
				{
					q.push(next);
					visited[next] = true;
				}
			}
		}

		level++;
	}

	while (!q.empty())
	{
		answer.push_back(q.front());
		q.pop();
	}
	sort(answer.begin(), answer.end());
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	
	int u, v;
	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
	}


	vector<int> answer;
	BFS(X, N, K, graph, answer);
	if (answer.size() == 0)
		cout << -1;
	else
		for (int i = 0; i<answer.size(); i++)
			cout << answer[i] << '\n';

	return 0;
}
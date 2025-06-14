#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int BFS(int x, vector<vector<int>>& map, vector<bool>& visited)
{
	queue<int> q;
	q.push(x);
	visited[x] = true;
	
	while (!q.empty())
	{
		int n = q.front();
		for (int i = 0; i < map[n].size(); i++)
			if (!visited[map[n][i]])
			{
				q.push(map[n][i]);
				visited[map[n][i]] = true;
			}

		q.pop();
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int answer = 0;
	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N+1);
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	vector<bool> visited(N+1, false);
	for (int i = 1; i <= N; i++)
		if (!visited[i])
			answer += BFS(i, map, visited);

	cout << answer;

	return 0;
}
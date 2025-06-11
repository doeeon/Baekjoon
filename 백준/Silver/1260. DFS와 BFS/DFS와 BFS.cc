#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
void DFS(int V, vector<vector<bool>> nodes, vector<bool> visited)
{
	stack<int> st;
	st.push(V);

	while (!st.empty())
	{
		int cur = st.top();
		st.pop();

		//노드를 꺼낼 때 방문처리를 해야 탐색 순서가 꼬이지 않는다.
		if (visited[cur])
			continue;
		visited[cur] = true;

		cout << cur << ' ';
		for (int i = nodes[cur].size()-1; i >= 1; i--)
			if (nodes[cur][i] && !visited[i])
				st.push(i);
	}

	return;
}

void BFS(int V, vector<vector<bool>> nodes, vector<bool> visited)
{
	queue<int> q;
	q.push(V);
	visited[V] = true;

	while (!q.empty())
	{
		cout << q.front() << ' ';
		for (int i = 1; i < nodes[q.front()].size(); i++)
			if (nodes[q.front()][i] && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}

		q.pop();
	}

	return;
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	int a, b;
	vector<vector<bool>> nodes(N+1, vector<bool>(N+1, 0));
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		nodes[a][b] = true;
		nodes[b][a] = true;
	}

	vector<bool> visited(N+1, false);
	DFS(V, nodes, visited);
	cout << '\n';
	BFS(V, nodes, visited);


	return 0;
}
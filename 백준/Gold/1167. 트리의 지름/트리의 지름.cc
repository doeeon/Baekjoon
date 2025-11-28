#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

pair<int, int> DFS(int start, int N, vector<vector<pair<int, int>>>& tree)
{
	vector<int> visited(N + 1, false);

	stack<pair<int, int>> st;
	st.push({ start, 0 });
	visited[start] = true;

	pair<int, int> max_dist = st.top();
	while (!st.empty())
	{
		int curr = st.top().first;
		int cost = st.top().second;
		st.pop();

		for (int i = 0; i < tree[curr].size(); i++)
		{
			int next = tree[curr][i].first;
			int ncost = tree[curr][i].second;

			if (!visited[next])
			{
				visited[next] = true;
				st.push({ next, cost + ncost });
				if (max_dist.second < cost + ncost)
					max_dist = st.top();
			}
		}
	}

	return max_dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<pair<int, int>>> tree(N + 1);
	int n, a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> n;

		cin >> a;
		while (a != -1)
		{
			cin >> b;
			tree[n].push_back({ a, b });
			cin >> a;
		}
	}

	pair<int, int> nodeA = DFS(1, N, tree);
	pair<int, int> result = DFS(nodeA.first, N, tree);

	cout << result.second;
	return 0;
}
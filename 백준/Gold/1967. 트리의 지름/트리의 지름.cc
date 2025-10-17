#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

pair<int, int> DFS(vector<vector<pair<int, int>>>& tree, int N, int root)
{
	stack<pair<int, int>> st;
	//vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
	vector<bool> visited(N + 1, false);

	st.push({ root, 0 });
	visited[root] = true;

	pair<int, int> max_dist = st.top();
	while (!st.empty())
	{
		int curr = st.top().first;
		int weight = st.top().second;
		st.pop();

		for (int i = 0; i < tree[curr].size(); i++)
		{
			if (!visited[tree[curr][i].first])
			{
				visited[tree[curr][i].first] = true;
				st.push({ tree[curr][i].first, weight + tree[curr][i].second });
				if (max_dist.second < weight + tree[curr][i].second)
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

	vector<vector<pair<int, int>>> tree(N + 1); // 무방향 그래프처럼 삽입해야 할 듯?

	int s, e, w;
	for (int i = 0; i < N-1; i++)
	{
		cin >> s >> e >> w;
		tree[s].push_back({ e, w });
		tree[e].push_back({ s, w });
	}

	pair<int, int> nodeA = DFS(tree, N, 1);
	pair<int, int> result = DFS(tree, N, nodeA.first);

	cout << result.second;

	return 0;
}
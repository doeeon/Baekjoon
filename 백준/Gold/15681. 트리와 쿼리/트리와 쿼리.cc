#include <iostream>
#include <vector>

using namespace std;

void MakeTree(int currentNode, vector<vector<int>>& connect, vector<int>& parent, vector<vector<int>>& child)
{
	for (int node : connect[currentNode])
	{
		if (node != parent[currentNode])
		{
			child[currentNode].push_back(node);
			parent[node] = currentNode;
			MakeTree(node, connect, parent, child);
		}
	}
}

void CountSubtreeNodes(int currentNode, vector<vector<int>>& child, vector<int>& size)
{
	size[currentNode] = 1;

	for (int node : child[currentNode])
	{
		CountSubtreeNodes(node, child, size);
		size[currentNode] += size[node];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;

	vector<vector<int>> connect(N + 1);

	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		connect[u].push_back(v);
		connect[v].push_back(u);
	}

	vector<int> parent(N + 1, -1);
	vector<vector<int>> child(N + 1);
	vector<int> size(N + 1);

	parent[R] = 0; // root node

	MakeTree(R, connect, parent, child);
	CountSubtreeNodes(R, child, size);

	for (int q = 0; q < Q; q++)
	{
		cin >> u;
		cout << size[u] << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool DFS(int cur, int cost, vector<int>& visited, int N, vector<int>& fee, vector<vector<int>>& graph)
{
	if (cost < 0)
		return false;

	if (cur == N)
		return true;

	for (int i : graph[cur])
	{
		int ncost;
		if (fee[i] < 0)
			ncost = cost + fee[i];
		else
			ncost = max(cost, fee[i]);

		if (visited[i] < ncost)
		{
			visited[i] = ncost;
			if (DFS(i, ncost, visited, N, fee, graph))
				return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int N;
		cin >> N;
		if (N == 0)	break;

		vector<int> fee(N + 1, 0);
		vector<vector<int>> graph(N + 1);

		char c;
		int n;
		for (int i = 1; i <= N; i++)
		{
			cin >> c;
			cin >> n;

			if (c == 'L')
				fee[i] = n;
			else if (c == 'T')
				fee[i] = -n;

			while (1)
			{
				cin >> n;
				if (n == 0)	break;
				graph[i].push_back(n);
			}
		}
		
		vector<int> visited(N + 1, -1);
		bool answer = DFS(1, fee[1], visited, N, fee, graph);

		if (answer)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int n, vector<pair<int, int>>& net) {
	int cnt = 0;
	queue<int> q;
	vector<bool> visited(n+1, false);

	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		for (int i = 0; i < net.size(); i++)
		{
			if (net[i].first == q.front() && !visited[net[i].second])
			{
				q.push(net[i].second);
				visited[net[i].second] = true;
				cnt++;
			}
			else if (net[i].second == q.front() && !visited[net[i].first])
			{
				q.push(net[i].first);
				visited[net[i].first] = true;
				cnt++;
			}
		}

		q.pop();
	}

	return cnt;
}

int main() {
	int answer = 0;
	int n, m;
	vector<pair<int, int>> net;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		net.push_back({ a, b });
	}

	answer = BFS(n, net);
	cout << answer;

	return 0;
}
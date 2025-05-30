#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int n, int k, vector<int>& parent) {
	int time = 0;
	queue<int> q;
	queue<int> empty;
	vector<bool> visited(100001, false);

	q.push(n);
	visited[n] = true;
	parent[n] = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			if (q.front() == k)
			{
				q.swap(empty);
				break;
			}

			int tmp = q.front();

			if (tmp + 1 <= 100000 && !visited[tmp + 1]) {
				q.push(tmp + 1);
				visited[tmp + 1] = true;
				parent[tmp + 1] = tmp;
			}
			if (tmp - 1 >= 0 && tmp - 1 <= 100000 && !visited[tmp - 1]) {
				q.push(tmp - 1);
				visited[tmp - 1] = true;
				parent[tmp - 1] = tmp;
			}
			if (tmp * 2 <= 100000 && !visited[tmp * 2]) {
				q.push(tmp * 2);
				visited[tmp * 2] = true;
				parent[tmp * 2] = tmp;
			}

			q.pop();
		}

		if (!q.empty())
			time++;
	}

	return time;
}

int main() {
	int n, k;
	cin >> n >> k;

	int answer = 0;
	vector<int> parent(100001, -1);
	answer = BFS(n, k, parent);

	cout << answer << endl;

	int idx = k;
	vector<int> route;
	while (1)
	{
		route.push_back(idx);
		if (idx == n)
			break;
		idx = parent[idx];
	}
	reverse(route.begin(), route.end());
	for (int i = 0; i < route.size(); i++)
		cout << route[i] << ' ';
	return 0;
}
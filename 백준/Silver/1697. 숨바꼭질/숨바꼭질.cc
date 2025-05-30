#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int n, int k) {
	int time = 0;
	queue<int> q;
	queue<int> empty;
	vector<bool> visited(100001, false);

	q.push(n);
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
				visited[tmp + 1] = true;;
			}
			if (tmp - 1 >= 0 && tmp - 1 <= 100000 && !visited[tmp - 1]) {
				q.push(tmp - 1);
				visited[tmp - 1] = true;
			}
			if (tmp * 2 <= 100000 && !visited[tmp * 2]) {
				q.push(tmp * 2);
				visited[tmp * 2] = true;
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
	answer = BFS(n, k);

	cout << answer;

	return 0;
}
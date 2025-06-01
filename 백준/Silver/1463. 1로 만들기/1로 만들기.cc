#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int n)
{
	int cnt = 0;
	queue<int> q;
	queue<int> empty;
	vector<bool> visited(n+1, false);

	q.push(n);
	visited[n] = true;

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			if (q.front() == 1)
			{
				q.swap(empty);
				break;
			}

			if (q.front() % 3 == 0 && !visited[q.front() / 3])
			{
				q.push(q.front() / 3);
				visited[q.front() / 3] = true;
			}
			if (q.front() % 2 == 0 && !visited[q.front() / 2])
			{
				q.push(q.front() / 2);
				visited[q.front() / 2] = true;
			}
			if (!visited[q.front() - 1])
			{
				q.push(q.front() - 1);
				visited[q.front() - 1] = true;
			}

			q.pop();
		}
		cnt++;
	}

	return cnt - 1;
}

int main() {
	int n;
	cin >> n;

	int answer;
	answer = BFS(n);

	cout << answer;

	return 0;
}